use houseflow_auth_api::Auth;
use houseflow_fulfillment_types::{SyncRequest, SyncResponse};
use houseflow_types::Device;
use reqwest::Client;
use url::Url;

pub struct Fulfillment {
    url: Url,
    auth: Auth,
}

#[derive(Debug, thiserror::Error)]
pub enum Error {
    #[error("Auth API Error: `{0}`")]
    AuthError(#[from] houseflow_auth_api::Error),

    #[error("Sending request failed: `{0}`")]
    ReqwestError(#[from] reqwest::Error),
}

impl Fulfillment {
    pub fn new(url: Url, auth: Auth) -> Self {
        Self { url, auth }
    }

    pub async fn sync(&self) -> Result<Vec<Device>, Error> {
        let access_token = self.auth.access_token().await?;
        let client = Client::new();
        let url = self.url.join("sync").unwrap();
        let response = client
            .post(url)
            .json(&SyncRequest::default())
            .bearer_auth(access_token.into_base64())
            .send()
            .await?
            .json::<SyncResponse>()
            .await?;

        Ok(response)
    }
}