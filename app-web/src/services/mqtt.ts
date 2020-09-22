import { getRandomShortUid } from '@/utils/utils';
import { connect, MqttClient } from 'mqtt';

const BROKER_URL = 'ws://localhost:8083/mqtt';

export const connectMqtt = (token: string, uid: string) => {
  return new Promise<MqttClient>((resolve, reject) => {
    const client = connect(BROKER_URL, {
      clientId: 'web_' + getRandomShortUid(),
      username: uid,
      password: token,
      protocolVersion: 5,
    });
    client.on('connect', () => {
      resolve(client);
    });
    client.on('error', reject);
  });
};
