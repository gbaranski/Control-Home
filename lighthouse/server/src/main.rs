mod connection;
mod rpc;
pub mod tcp;

#[tokio::main]
async fn main() {
    env_logger::init();
    let connection_store = connection::Store::new();
    tokio::select! {
        _ = tcp::run("127.0.0.1:8080".parse().expect("Invalid TCP server address"), connection_store.clone()) => {}
        _ = rpc::run("127.0.0.1:8081".parse().expect("Invalid RPC server address"), connection_store.clone()) => {}
    };
}
