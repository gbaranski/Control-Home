import WebSocket from 'ws';
import Device from '../';
import {
  Alarmclock,
  Device as DeviceType,
  AnyDeviceData,
} from '@gbaranski/types';
import { validateDeviceMessage } from '@/services/misc';
import { publishDeviceData } from '@/services/redis_pub';

export default class AlarmclockDevice extends Device<Alarmclock.Data> {
  constructor(
    ws: WebSocket,
    firebaseDevice: DeviceType.FirebaseDevice,
    activeDevice: DeviceType.ActiveDevice,
  ) {
    super(ws, firebaseDevice, activeDevice);
  }

  public handleMessage(message: WebSocket.Data): void {
    validateDeviceMessage(message);
    const parsedResponse = JSON.parse(
      message as string,
    ) as DeviceType.ResponseDevice<undefined>;
    if (parsedResponse.responseFor === 'GET_DATA') {
      const activeDevice: DeviceType.ActiveDevice = {
        ...this.activeDevice,
        data: (parsedResponse.data as unknown) as AnyDeviceData,
      };
      publishDeviceData(activeDevice);
      this.activeDevice = activeDevice;
    }
  }
}
