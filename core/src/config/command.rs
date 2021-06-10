use crate::{SetupCommand, Target};
use anyhow::Context;
use async_trait::async_trait;
use clap::Clap;

#[derive(Clap)]
pub enum ConfigCommand {
    /// Generates a new configuration for specified targets, if none specified then it will generate for all targets.
    Generate(ConfigGenerateCommand),
}

#[async_trait(?Send)]
impl SetupCommand for ConfigCommand {
    async fn run(&self) -> anyhow::Result<()> {
        match self {
            Self::Generate(cmd) => cmd.run().await,
        }
    }
}

#[derive(Clap)]
pub struct ConfigGenerateCommand {
    target: Option<Target>,

    #[clap(short = 'f', long = "force")]
    force: bool,
}

#[async_trait(?Send)]
impl SetupCommand for ConfigGenerateCommand {
    async fn run(&self) -> anyhow::Result<()> {
        let create_config = |target: Target| async move {
            let config = super::generate_config_string(&target);
            let path = target.config_path();
            if path.exists() && self.force == false {
                println!(
                    "{} config already exists, use -f argument to overwrite",
                    target
                );
                return Ok(());
            }
            tokio::fs::create_dir_all(path.parent().unwrap()).await?;

            use tokio::fs::File;
            use tokio::io::AsyncWriteExt;

            let mut file = File::create(&path).await?;
            file.write(config.as_bytes()).await?;
            println!(
                "✅ Generated {} config at {}",
                target,
                path.to_str().unwrap()
            );

            Ok(())
        };

        match self.target.clone() {
            Some(target) => create_config(target).await,
            None => {
                use futures::future::join_all;
                use strum::IntoEnumIterator;
                let iter = Target::iter()
                    .map(|target| async { (target.clone(), create_config(target).await) });
                let results = join_all(iter).await;
                for (target, result) in results {
                    result.with_context(|| format!("when generating {} config", target))?;
                }

                Ok(())
            }
        }
    }
}