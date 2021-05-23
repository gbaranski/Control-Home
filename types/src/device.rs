use crate::common::Credential;
use semver::Version;
use std::collections::HashMap;

#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};

pub type DeviceID = Credential<16>;
pub type DevicePassword = Credential<32>;

#[derive(Debug, Clone)]
#[cfg_attr(feature = "serde", derive(Serialize, Deserialize))]
pub struct Device {
    // Identifier of the device
    pub id: DeviceID,

    /// Hashed password for device
    pub password_hash: String,

    /// Type of the device
    pub device_type: DeviceType,

    // Functionatily that the device has
    pub traits: Vec<DeviceTrait>,

    // Name of the device
    // pub name: String,

    // True if device will push state by itself, otherwise will use polling
    // pub will_push_state: bool,

    // Name of room(if available)
    // pub room_hint: Option<String>,

    // The model or SKU identifier of the device
    // pub model: String,

    // Specific version number of hardware of the device
    // pub hw_version: Version,

    // Specific version number of software of the device
    // pub sw_version: Version,

    // Aligned with per-trait attributes described in each trait schema reference.
    // pub attributes: HashMap<String, String>,
}

use std::str::FromStr;
use strum_macros::EnumString;

/// Traits defines what functionality device supports
#[derive(Debug, Clone, Hash, Eq, PartialEq, strum_macros::Display, EnumString)]
#[cfg_attr(feature = "serde", derive(Serialize, Deserialize))]
pub enum DeviceTrait {}

/// Type of the device
#[derive(Debug, Clone, strum_macros::Display, EnumString)]
#[cfg_attr(feature = "serde", derive(Serialize, Deserialize))]
pub enum DeviceType {}

