#include <Arduino.h>

#include "config.h"

#ifndef GPIO_H
#pragma once

boolean mixingStarted = false;
unsigned long lastMixingMillis = 0;

void startMixing() {
  digitalWrite(RELAY_PIN, 0);
  mixingStarted = true;
  lastMixingMillis = millis();
}

#endif