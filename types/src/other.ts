import { AlarmclockData, WatermixerData, Alarmclock } from './';
import { Watermixer } from './watermixer';

export interface Devices {
  alarmclock: Alarmclock;
  watermixer: Watermixer;
}

export interface DateTime {
  hour: number;
  minute: number;
  second: number;
}

export enum RequestTypes {
  GET_DATA = 'GET_DATA',
  START_MIXING = 'START_MIXING',
  SET_TIME = 'SET_TIME',
  SET_STATE = 'SET_STATE',
  TEST_SIREN = 'TEST_SIREN',
  REBOOT = 'REBOOT',
  UNKNOWN = 'UNKNOWN',
}
export enum DeviceType {
  ALARMCLOCK = 'ALARMCLOCK',
  WATERMIXER = 'WATERMIXER',
  GATE = 'GATE',
  GARAGE = 'GARAGE',
}

export type DevicesTypes = keyof typeof DeviceType;

export type State = boolean;

export type AnyDeviceData = AlarmclockData | WatermixerData;

export type RequestDevice = ((type: RequestTypes.GET_DATA) => any) &
  ((type: RequestTypes.START_MIXING) => any) &
  ((type: RequestTypes.SET_TIME, data: DateTime) => any) &
  ((type: RequestTypes.SET_STATE, data: boolean) => any) &
  ((type: RequestTypes.REBOOT) => any);

export interface ResponseDevice<
  T extends AlarmclockData | WatermixerData | undefined
> {
  ok: boolean;
  responseFor: RequestTypes;
  data: T;
}

export interface TempHistory {
  unixTime: number;
  temperature: number;
}
export interface RequestHistory {
  user: string;
  requestPath: string;
  unixTime: number;
  ip: string;
  userAgent: string;
  country: string;
}
