package config

import (
	"crypto/ed25519"
	"encoding/base64"
	"fmt"
	"os"

	"github.com/gbaranski/houseflow/devices/lights_go/utils"
	"github.com/joho/godotenv"
)

// Config is runtime configuration, PublicKey and PrivateKey are loeaded from .env or env variables
type Config struct {
	PublicKey       ed25519.PublicKey
	PrivateKey      ed25519.PrivateKey
	ServerPublicKey ed25519.PublicKey
	DeviceID        string
	BrokerURL       string
}

// Load loads config and returns it
func Load() (*Config, error) {
	err := godotenv.Load()
	if err != nil {
		return nil, err
	}
	pkeystr, exists := os.LookupEnv("PUBLIC_KEY")
	if !exists {
		return nil, fmt.Errorf("PUBLIC_KEY does not exist in .env")
	}
	pkeyDecoded, err := base64.StdEncoding.DecodeString(pkeystr)
	if err != nil {
		return nil, fmt.Errorf("PUBLIC_KEY is invalid %s", err.Error())
	}
	pkey := ed25519.PublicKey(pkeyDecoded)

	skeystr, exists := os.LookupEnv("PRIVATE_KEY")
	if !exists {
		return nil, fmt.Errorf("PRIVATE_KEY does not exist in .env")
	}
	skeySeedDecoded, err := base64.RawStdEncoding.DecodeString(skeystr)
	if err != nil {
		return nil, fmt.Errorf("PRIVATE_KEY is invalid %s", err.Error())
	}
	skey := ed25519.NewKeyFromSeed(skeySeedDecoded)

	serverPkeyStr, exists := os.LookupEnv("SERVER_PUBLIC_KEY")
	if !exists {
		return nil, fmt.Errorf("SERVER_PUBLIC_KEY does not exist in .env")
	}
	serverPkeyDecoded, err := base64.RawStdEncoding.DecodeString(serverPkeyStr)
	if err != nil {
		return nil, fmt.Errorf("SERVER_PUBLIC_KEY is invalid: %s", err.Error())
	}
	serverPkey := ed25519.PublicKey(serverPkeyDecoded)

	deviceID, exists := os.LookupEnv("DEVICE_ID")
	if !exists {
		return nil, fmt.Errorf("DEVICE_ID does not exist in .env")
	}
	match := utils.ObjectIDRegexp.MatchString(deviceID)
	if !match {
		return nil, fmt.Errorf("DEVICE_ID is invalid type of ObjectID")
	}

	brokerURL, exists := os.LookupEnv("BROKER_URL")
	if !exists {
		return nil, fmt.Errorf("BROKER_URL does not exist in .env")
	}

	return &Config{
		PublicKey:       pkey,
		PrivateKey:      skey,
		DeviceID:        deviceID,
		BrokerURL:       brokerURL,
		ServerPublicKey: serverPkey,
	}, nil
}