const WSS_URL = 'ws://localhost:8001';

let websocket: WebSocket | undefined;

export const connectWebsocket = (token: string) => {
  websocket = new WebSocket(WSS_URL, token);
};

export const setupOnOpenListeners = (onMessage: (message: MessageEvent) => any) => {
  if (!websocket) throw new Error('Websocket is not defined');
  if (websocket.OPEN) {
    websocket.onmessage = onMessage;
    return;
  }
  websocket.onopen = () => {
    if (!websocket) throw new Error('Websocket is not defined');
    websocket.onmessage = onMessage;
  };
};

export const getWebsocket = (): WebSocket | undefined => {
  return websocket;
};
