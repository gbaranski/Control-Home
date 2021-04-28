use std::net::SocketAddr;
use tokio::net::TcpListener;

use super::connection;

#[derive(Debug)]
pub enum Error {
    IOError(std::io::Error),
}

impl From<std::io::Error> for Error {
    fn from(v: std::io::Error) -> Self {
        Self::IOError(v)
    }
}

pub async fn run(addr: SocketAddr, store: connection::Store) -> Result<(), Error> {
    log::info!("Starting TCP server at address: {}", addr);
    let listener = TcpListener::bind(addr).await?;
    accept_loop(listener, store).await
}

async fn accept_loop(listener: TcpListener, peers: connection::Store) -> Result<(), Error> {
    loop {
        let (stream, address) = listener.accept().await?;
        let peers = peers.clone();
        log::info!("Connection started from: `{}`", address);
        tokio::spawn(async move {
            match connection::run(stream.into_split(), address, peers).await {
                Ok(()) => log::info!("Connection closed from: `{}`", address),
                Err(err) => log::info!("Connection closed from: `{}` with error: {:?}", address, err),
            }
        });
    }
}
