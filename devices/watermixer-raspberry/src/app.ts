import { MqttClient } from 'mqtt';
import { Watermixer } from '@gbaranski/types';
import { startMixing } from './services/relay';

export const onConnection = (mqtt: MqttClient) => {
  console.log('Initialized connection with MQTT');

  const startMixTopic = Watermixer.getStartMixingTopic(
    process.env.DEVICE_UID as string,
  );

  mqtt.subscribe(startMixTopic.request);

  mqtt.on('message', (topic, payload, packet) => {
    console.log({ topic, payload, packet });

    switch (topic) {
      case startMixTopic.request:
        startMixing();
        sendRequestResponse(startMixTopic.response, payload);
        break;
      default:
        console.log('Unrecognized topic');
        break;
    }
  });

  const sendRequestResponse = (topic: string, payload: Buffer) => {
    mqtt.publish(topic, payload);
  };
};
