import WebSocket from 'ws';
import {
  AnyDeviceData,
  DateTime,
  Device as DeviceType,
} from '@gbaranski/types';
import WatermixerDevice from './watermixer';
import AlarmclockDevice from './alarmclock';

export type AnyDeviceObject = WatermixerDevice | AlarmclockDevice;

export default abstract class Device<DeviceData extends AnyDeviceData> {
  private _status = false;

  public abstract handleMessage(message: WebSocket.Data): void;

  constructor(
    protected ws: WebSocket,
    public readonly firebaseDevice: DeviceType.FirebaseDevice,
    protected activeDevice: DeviceType.ActiveDevice,
  ) {
    this._status = true;
  }

  public requestDevice(
    type: DeviceType.RequestType,
    data?: DateTime | boolean,
  ): boolean {
    if (!this.ws) {
      throw new Error('Websocket is not defined');
    }
    if (!this.ws.OPEN) {
      throw new Error('Websocket is not at OPEN state');
    }
    if (!this._status) {
      throw new Error('Device status is false');
    }
    const requestData = {
      type,
      data,
    };
    console.log(requestData);
    this.ws.send(JSON.stringify(requestData));

    return true;
  }

  public terminateConnection(reason: string): void {
    this.ws.terminate();
    console.log(
      `Websocket error ${reason} ${this.firebaseDevice.type} UID: ${this.firebaseDevice.uid}`,
    );
  }

  set status(status: boolean) {
    this._status = status;
  }

  get status(): boolean {
    return this._status;
  }
}
