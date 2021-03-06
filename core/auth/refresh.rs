use crate::{ClientCommandState, Command, Tokens};
use async_trait::async_trait;

use clap::Clap;

#[derive(Clap)]
pub struct RefreshCommand {}

#[async_trait(?Send)]
impl Command<ClientCommandState> for RefreshCommand {
    async fn run(self, state: ClientCommandState) -> anyhow::Result<()> {
        let tokens = state.tokens.get().await?;
        let response = state
            .houseflow_api
            .refresh_token(&state.refresh_token().await?)
            .await??;
        let tokens = Tokens {
            refresh: tokens.refresh,
            access: response.access_token,
        };
        state.tokens.save(&tokens).await?;
        tracing::info!("✔ Succesfully refreshed token and saved to keystore");

        Ok(())
    }
}
