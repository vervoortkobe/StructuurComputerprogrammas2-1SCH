#include <M5Unified.h>

#include <stdlib.h>
#include <stdint.h>
#include "EEPROM.h"

uint16_t black_color = M5.Lcd.color565(0, 0, 0);
uint16_t red_color = M5.Lcd.color565(255, 0, 0);

void setup() {
  M5.begin();
  M5.Imu.init();
  Serial.begin(115200);
  Serial.flush();
  EEPROM.begin(512);
  M5.Lcd.fillScreen(black_color);
}

void loop() {
  M5.update();
  delay(20);
}