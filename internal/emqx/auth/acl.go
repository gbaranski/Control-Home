package auth

import (
	"crypto/ed25519"
	"encoding/base64"
	"encoding/json"
	"log"
	"net/http"
	"strings"
)

// ACLRequest is sub/pub req
type ACLRequest struct {
	// 1 | 2
	// 1 = sub
	// 2 = pub
	Access     byte   `json:"access"`
	Username   string `json:"username"`
	ClientID   string `json:"clientID"`
	IP         string `json:"ip"`
	Topic      string `json:"topic"`
	MountPoint string `json:"mountpoint"`
}

func (a *Auth) onACL(w http.ResponseWriter, req *http.Request) {
	var r ACLRequest
	err := json.NewDecoder(req.Body).Decode(&r)
	if err != nil {
		w.WriteHeader(http.StatusUnprocessableEntity)
		w.Write([]byte(err.Error()))
		log.Printf("ACL: Client %s unauthorized topic %s\n", r.ClientID, r.Topic)
		return
	}
	pkey, err := base64.StdEncoding.DecodeString(r.Username)
	if err != nil {
		w.WriteHeader(http.StatusBadRequest)
		w.Write([]byte(err.Error()))
		log.Printf("ACL: Client %s unauthorized topic %s\n", r.ClientID, r.Topic)
		return
	}

	// Check if this client is some service
	if a.opts.ServerPublicKey.Equal(ed25519.PublicKey(pkey)) {
		w.Write([]byte("Authenticated"))
		log.Printf("ACL: Service %s authorized topic %s\n", r.ClientID, r.Topic)
		return
	}
	topicClientID := r.Topic[0:strings.IndexRune(r.Topic, '/')]
	if topicClientID != r.ClientID {
		w.WriteHeader(http.StatusUnauthorized)
		w.Write([]byte("Unauthorized for this topic"))
		log.Printf("ACL: Device %s unauthorized topic %s\n", r.ClientID, r.Topic)
		return
	}

	w.Write([]byte("Authenticated"))
	log.Printf("ACL: Device %s authorized topic %s\n", r.ClientID, r.Topic)
}
