use structopt::StructOpt;
use serde::{Deserialize, Serialize};
use std::collections::HashMap;
use sqlx::FromRow;

#[derive(StructOpt, Debug)]
pub struct Add {
    #[structopt(long)]
    pub name: String,

    #[structopt(flatten)]
    pub db: crate::db::DatabaseOpts,
}

impl Add {
    fn run(self) {
        println!("adding device, name: {}", self.name);
    }
}

#[derive(StructOpt, Debug)]
pub enum Command {
    Add(Add),
}

impl Command {
    pub fn run(self) {
        match self {
            Command::Add(cmd) => cmd.run(),
        }

    }
}


/// Contains fields describing the device for use in one-off logic if needed.
/// e.g. 'broken firmware version X of light Y requires adjusting color', or 'security flaw requires notifying all users of firmware Z'.
#[derive(Serialize, Deserialize, FromRow)]
pub struct DeviceInfo {
    /// Especially useful when the developer is a hub for other devices. 
    /// Google may provide a standard list of manufacturers here so that e.g. TP-Link and Smartthings both describe 'osram' the same way.
    pub manufacturer: Option<String>,

    /// The model or SKU identifier of the particular device.
    pub model: Option<String>,

    /// Specific version number attached to the hardware if available.
    #[serde(rename = "hwVersion")]
    pub hw_version: Option<String>,

    /// Specific version number attached to the software/firmware, if available.
    #[serde(rename = "swVersion")]
    pub sw_version: Option<String>,
}

#[derive(Serialize, Deserialize, FromRow)]
pub struct OtherDeviceID {
    /// The agent's ID. Generally, this is the project ID in the Actions console.
    #[serde(rename = "agentId")]
    pub agent_id: Option<String>,
    
    #[serde(rename = "deviceId")]
    pub device_id: String
}


#[derive(Serialize, Deserialize, FromRow)]
pub struct DeviceName {
    /// List of names provided by the developer rather than the user, often manufacturer names, SKUs, etc.
    pub default_names: Option<Vec<String>>,

    /// Primary name of the device, generally provided by the user. This is also the name the Assistant will prefer to describe the device in responses.
    pub name: String,

    /// Additional names provided by the user for the device.
    pub nicknames: Option<Vec<String>>,
}

#[derive(Serialize, Deserialize, FromRow)]
pub struct Device {

    /// The ID of the device in the developer's cloud. 
    /// This must be unique for the user and for the developer, 
    /// as in cases of sharing we may use this to dedupe multiple views of the same device. 
    /// It should be immutable for the device; if it changes, the Assistant will treat it as a new device.
    pub id: String,

    /// The hardware type of device.
    #[serde(rename = "type")]
    pub device_type: String,

    /// List of traits this device has. 
    /// This defines the commands, attributes, and states that the device supports.
    pub traits: Vec<String>,

    /// Names of this device.
    pub name: DeviceName,

    /// Indicates whether this device will have its states updated by the Real Time Feed.
    /// true to use the Real Time Feed for reporting state, and false to use the polling model.
    #[serde(rename = "willReportState")]
    pub will_report_state: bool,

    /// Indicates whether notifications are enabled for the device.
    #[serde(rename = "notificationSupportedByAgent", default)]
    pub notification_support_by_agent: bool,

    /// Provides the current room of the device in the user's home to simplify setup.
    #[serde(rename = "roomHint")]
    pub room_hint: Option<String>,

    /// Contains fields describing the device for use in one-off logic if needed 
    /// e.g. 'broken firmware version X of light Y requires adjusting color', or 'security flaw requires notifying all users of firmware Z'.
    #[serde(rename = "deviceInfo")]
    pub device_info: Option<DeviceInfo>,

    /// Aligned with per-trait attributes described in each trait schema reference.
    pub attributes: Option<HashMap<String, String>>,

    /// Object defined by the developer which will be attached to future QUERY and EXECUTE requests
    /// Maximum of 512 bytes per device. 
    /// Use this object to store additional information about the device your cloud service may need, such as the global region of the device.
    /// Data in this object has a few constraints: 
    /// - No sensitive information, including but not limited to Personally Identifiable Information.
    #[serde(rename = "customData")]
    pub custom_data: Option<HashMap<String, String>>,

    /// List of alternate IDs used to identify a cloud synced device for local execution.
    #[serde(rename = "otherDeviceIds")]
    pub other_device_ids: Option<Vec<OtherDeviceID>>,


    #[serde(skip)]
    pub pkey_base64: String,

}
