use bytes::BytesMut;
use lighthouse_proto::{
    frame::{self, Frame},
    FrameCodec,
};
use std::net::SocketAddr;
use structopt::StructOpt;
use tokio::io::{AsyncReadExt, AsyncWriteExt};
use tokio::net::TcpStream;
use tokio_util::codec::{Decoder, Encoder};

#[derive(StructOpt, Debug)]
struct Opt {
    /// Address of TCP Server to connect
    #[structopt(name = "address")]
    address: SocketAddr,

    /// Address of TCP Server to connect
    #[structopt(short = "id", long)]
    client_id: frame::ClientID,

    /// Verbose mode (-v, -vv, -vvv, etc.)
    #[structopt(short, long, parse(from_occurrences))]
    verbose: u8,
}

async fn run(
    mut stream: TcpStream,
    mut buf: BytesMut,
    mut codec: FrameCodec,
) -> Result<(), Box<dyn std::error::Error>> {
    loop {
        let n = stream
            .read_buf(&mut buf)
            .await
            .expect("Failed reading from ");
        if n == 0 {
            // Connection reset by peer
            return Ok(());
        }

        let frame = codec
            .decode(&mut buf)
            .expect("Failed reading frame")
            .expect("Received None when reading frame");
        match frame {
            Frame::Execute(frame) => {
                log::info!("Received execute frame: `{:?}`", frame);
            }
            _ => {
                log::error!("Received unexpected frame, opcode: {:X}", frame.opcode() as u8)
            }
        };
    }
}

#[tokio::main]
async fn main() {
    let opt = Opt::from_args();
    loggerv::init_with_verbosity(opt.verbose.into()).expect("invalid verbosity flag");
    let mut stream = TcpStream::connect(opt.address)
        .await
        .expect("Failed connecting to server");
    log::info!("Server accepted TCP Connection");
    let mut codec = FrameCodec::new();
    let mut buf = BytesMut::with_capacity(4096);
    let connect_frame = frame::connect::Frame {
        client_id: opt.client_id,
    };
    codec
        .encode(Frame::Connect(connect_frame), &mut buf)
        .expect("Failed encoding connect frame");

    stream
        .write_buf(&mut buf)
        .await
        .expect("Failed writing ConnectFrame to TCP Stream");

    stream
        .read_buf(&mut buf)
        .await
        .expect("Failed reading TCP Stream to buffer");

    let frame = codec
        .decode(&mut buf)
        .expect("Failed decoding Frame from TCP Stream")
        .expect("Decoded empty packet");

    let connack_frame = match frame {
        Frame::ConnACK(frame) => frame,
        _ => panic!(
            "Unexpected frame received with opcode: {:X}",
            frame.opcode() as u8
        ),
    };
    assert_eq!(
        connack_frame.response_code,
        frame::connack::ResponseCode::Accepted
    );
    log::info!("Server accepted connection");
    run(stream, buf, codec).await.unwrap();
}
