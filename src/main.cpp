#include <Arduino.h>
#include <ArduinoLog.h>

#include "rtl-433-receiver.h"
#include "ble-server.h"

#include "rtl-433-receiver.h"

void setup() {
    Serial.begin(921600);
    delay(2000);
#ifndef LOG_LEVEL
  LOG_LEVEL_SILENT
#endif
    Log.begin(LOG_LEVEL, &Serial);
    Log.notice(F(" " CR));
    Log.notice(F("****** setup ******" CR));
    rtl_433_receiver_init();
    ble_server_init();
    Log.notice(F("****** setup complete ******" CR));
}

void loop() {
    rtl_433_receiver_loop();
}
