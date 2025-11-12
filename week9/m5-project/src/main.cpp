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
uint8_t x = 0;
uint8_t y = 0;
void loop(){
  M5.update();
  delay(20);
  M5.Lcd.fillScreen(BLACK);
  if(M5.BtnA.isPressed() && M5.BtnB.isPressed()) {
    x = 0;
    y = 0;
  } else if(M5.BtnA.isPressed()) {
    x += 10;
  } else if(M5.BtnB.isPressed()) {
    y += 10;
  }
  if(x > M5.Lcd.width()) {
    x = 0;
  }
  if(y > M5.Lcd.height()) {
    y = 0;
  }
  M5.Lcd.fillRect(x, y, RECT_WIDTH, RECT_HEIGHT, RED);
}