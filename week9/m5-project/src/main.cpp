#include <M5Unified.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "EEPROM.h"

// The setup routine runs once when M5StickC starts up
void setup() {
  
  // Initialize the M5StickC object
  M5.begin();
  M5.Imu.init();
  Serial.begin(115200);
  Serial.flush();
  EEPROM.begin(512);
  M5.Lcd.fillScreen(BLACK);
}

#define RECT_WIDTH 50
#define RECT_HEIGHT 50

// The loop routine keeps looping as long as the controller is on
uint8_t y = 0;
void loop(){
  M5.update();
  delay(20);
  M5.Lcd.fillScreen(BLACK);
  y++;
  M5.Lcd.fillRect(20, y, RECT_WIDTH, RECT_HEIGHT, RED);
  if (y > M5.Lcd.height()) {
    y = 0;
  }
}