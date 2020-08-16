import express from 'express';
import cors from 'cors';
import routes from '@/routes';
import { CORS_WHITELIST } from './config';
import { getIpStr, getCountryStr } from '@/services/misc';
import morgan from 'morgan';
import chalk from 'chalk';

const app = express();
app.use(cors({ origin: CORS_WHITELIST }));
morgan.token('code', (req: express.Request, res: express.Response) => {
  const code = res.statusCode;
  if (code === 401 || code === 403) {
    return chalk.red.bold(code);
  } else {
    return chalk.green.bold(code);
  }
});

morgan.token('country', (req: express.Request) => {
  const country = getCountryStr(getIpStr(req));
  if (country === 'unknown') {
    return chalk.gray.bold(country);
  } else {
    return chalk.magentaBright.blue.bold(country);
  }
});

morgan.token('devOrUsr', (req: express.Request) => {
  const username = req.header('username');
  const device = req.header('device');
  if (username || device) {
    return chalk.magenta(username || device);
  } else {
    return chalk.gray.bold('unknown');
  }
});

morgan.token('ip', (req: express.Request) => {
  return chalk.cyan.bold(getIpStr(req));
});

app.use(
  morgan((tokens, req, res) => {
    return [
      chalk.cyan(tokens.method(req, res)),
      chalk.cyan(tokens.url(req, res)),
      tokens.code(req, res),
      chalk.dim('-'),
      chalk.dim.bold(tokens['response-time'](req, res)),
      chalk.dim.bold('ms'),
      chalk.dim('-'),
      tokens.ip(req, res),
      chalk.dim('-'),
      chalk.gray.bold(tokens.country(req, res)),
      chalk.dim('-'),
      chalk.bold(tokens.devOrUsr(req, res)),
    ].join(' ');
  }),
);
app.use(express.json()); // for parsing application/json

app.use('/', routes);

export default app;
