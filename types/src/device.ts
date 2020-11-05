import { GeoPoint } from '@firebase/firestore-types';
import { Light, Relay } from '.';

export type AnyDeviceData = Light.Data | Relay.Data;

export namespace Device {
  export type DeviceType =
    | 'ALARMCLOCK'
    | 'WATERMIXER'
    | 'GATE'
    | 'GARAGE'
    | 'LIGHT';

  export interface Request {
    correlationData: string;
    data?: unknown | undefined;
  }

  export interface Response {
    correlationData: string;
    data?: unknown | undefined;
  }

  export interface FirebaseDevice<
    DeviceData extends Light.Data | Relay.Data | AnyDeviceData = AnyDeviceData
  > {
    uid: string;
    secret?: string;
    type: DeviceType;
    geoPoint: GeoPoint;

    status: boolean;
    data: DeviceData;
    ip: string;
  }
}
