import { parse } from 'querystring';
import { DateTime, State } from '@gbaranski/types';
import { Moment } from 'moment';
import moment from 'moment';

/* eslint no-useless-escape:0 import/prefer-default-export:0 */
const reg = /(((^https?:(?:\/\/)?)(?:[-;:&=\+\$,\w]+@)?[A-Za-z0-9.-]+(?::\d+)?|(?:www.|[-;:&=\+\$,\w]+@)[A-Za-z0-9.-]+)((?:\/[\+~%\/.\w-_]*)?\??(?:[-\+=&;%@.\w_]*)#?(?:[\w]*))?)$/;

export const isUrl = (path: string): boolean => reg.test(path);

export const isAntDesignPro = (): boolean => {
  if (ANT_DESIGN_PRO_ONLY_DO_NOT_USE_IN_YOUR_PRODUCTION === 'site') {
    return true;
  }
  return window.location.hostname === 'preview.pro.ant.design';
};

// 给官方演示站点用，用于关闭真实开发环境不需要使用的特性
export const isAntDesignProOrDev = (): boolean => {
  const { NODE_ENV } = process.env;
  if (NODE_ENV === 'development') {
    return true;
  }
  return isAntDesignPro();
};

export const getPageQuery = () => {
  const { href } = window.location;
  const qsIndex = href.indexOf('?');
  const sharpIndex = href.indexOf('#');

  if (qsIndex !== -1) {
    if (qsIndex > sharpIndex) {
      return parse(href.split('?')[1]);
    }

    return parse(href.slice(qsIndex + 1, sharpIndex));
  }

  return {};
};

export function capitalizeFirst(string: string) {
  return string.charAt(0).toUpperCase() + string.slice(1);
}

export function parseSeconds(seconds: number) {
  return `${Math.floor((seconds / 60) % 60)}m ${seconds % 60}s`;
}

export function parseToTotalSeconds(dateTime: DateTime): number {
  return dateTime.hour * 3600 + dateTime.minute * 60 + dateTime.second;
}

export function parseWaterBoolean(state: boolean): string {
  return state ? 'Mixing!' : 'Idle';
}

export function parseAlarmclockBoolean(state: State): string {
  return state ? '/ON' : '/OFF';
}

export function parseDateTime(alarmTime: DateTime): string {
  return `${String(alarmTime.hour).padStart(2, '0')}:${String(alarmTime.minute).padStart(2, '0')}`;
}

export function getOnFinishTime(onFinish: DateTime): Moment {
  return moment(`${onFinish.hour}:${onFinish.minute}:${onFinish.second}`, 'HH:mm:ss');
}

export const getRandomShortUid = () => {
  return Math.random().toString(16).substr(2, 8);
};
