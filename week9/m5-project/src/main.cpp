#include <M5Unified.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "EEPROM.h"

void setup() {
  M5.begin();
  M5.Imu.init();
  Serial.begin(115200);
  Serial.flush();
  EEPROM.begin(512);
  M5.Lcd.fillScreen(BLACK);
}

#define MEM_SIZE 512
uint8_t x = 0;
uint8_t y = 0;

  void save_Position() {
    int address  = 0;
    EEPROM.writeByte(address, x);
    address++;
    EEPROM.writeByte(address, y);
    EEPROM.commit();
  }
  void read_Position() {
    int address  = 0;
    x = EEPROM.readByte(address);
    address++;
    y = EEPROM.readByte(address);
  }

void loop() {
  M5.Lcd.fillScreen(BLACK);
  M5.update();
  if (M5.BtnA.wasPressed()) {
    x++;
    save_Position();
  }
  if (M5.BtnB.wasPressed()) {
    y++;
    save_Position();
  }
  if (M5.BtnC.wasPressed()) {
    x = 0;
    y = 0;
    save_Position();
  }
  read_Position();
  M5.Lcd.fillRect(x, y, 160, 80, RED);
  delay(20);
}