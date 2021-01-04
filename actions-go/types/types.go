package types

import (
	"github.com/gbaranski/houseflow/actions/fulfillment"
	"go.mongodb.org/mongo-driver/bson/primitive"
)

// User struct, used to either creating user, or this one in DB
type User struct {
	ID        primitive.ObjectID `bson:"_id,omitempty" json:"id,omitempty" binding:"-"`
	FirstName string             `json:"firstName" bson:"firstName" form:"firstName" binding:"required"`
	LastName  string             `json:"lastName" bson:"lastName" form:"lastName" binding:"required"`
	Email     string             `json:"email" bson:"email" houseflow:"email" form:"email" binding:"required,email"`
	Password  string             `json:"password" bson:"password" form:"password" binding:"required,min=8,max=20"`
	Devices   []string           `bson:"devices" binding:"required"`
}

// Device is device from database
type Device struct {
	fulfillment.Device
	ID    primitive.ObjectID     `bson:"_id,omitempty" binding:"-"`
	State map[string]interface{} `bson:"state"`
}