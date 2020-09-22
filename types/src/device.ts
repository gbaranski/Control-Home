import { Alarmclock, Watermixer } from '.';
import { DateTime, State, Uid } from './misc';

export type AnyDeviceData = Alarmclock.Data | Watermixer.Data;

export namespace Device {
  export type DeviceType = 'ALARMCLOCK' | 'WATERMIXER' | 'GATE' | 'GARAGE';

  export interface Request {
    correlationData: string;
  }

  export interface FirebaseDevice<
    DeviceData extends
      | Alarmclock.Data
      | Watermixer.Data
      | AnyDeviceData = AnyDeviceData
  > {
    uid: Uid;
    secret?: string;
    type: DeviceType;

    status: boolean;
    data: DeviceData;
    ip: string;
  }
}
