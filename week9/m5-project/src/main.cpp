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

#define RECT_WIDTH 50
#define RECT_HEIGHT 50

float x = -1;
float y = -1;
float z = 0;

void loop() {
  M5.update();

  float ax = 0, ay = 0, az = 0;
  M5.Imu.getAccelData(&ax, &ay, &az);

  if (x < 0) {
    x = (M5.Lcd.width() - RECT_WIDTH) / 2;
    y = (M5.Lcd.height() - RECT_HEIGHT) / 2;
    M5.Lcd.fillRect((int)x, (int)y, RECT_WIDTH, RECT_HEIGHT, RED);
  }

  M5.Lcd.fillRect((int)x, (int)y, RECT_WIDTH, RECT_HEIGHT, BLACK);

  const float threshold = 0.06f;
  const float scale = 15.0f;

  if (fabsf(ax) > threshold) x += ax * scale; // left/right tilt
  if (fabsf(ay) > threshold) y += ay * scale; // forward/back tilt

  if (x < 0) x = 0;
  if (y < 0) y = 0;
  if (x > M5.Lcd.width() - RECT_WIDTH) x = M5.Lcd.width() - RECT_WIDTH;
  if (y > M5.Lcd.height() - RECT_HEIGHT) y = M5.Lcd.height() - RECT_HEIGHT;

  M5.Lcd.fillRect((int)x, (int)y, RECT_WIDTH, RECT_HEIGHT, RED);

  float deltaX = (fabsf(ax) > threshold) ? ax * scale : 0.0f;
  if (deltaX != 0.0f) {
    M5.Lcd.fillRect((int)x, (int)y, RECT_WIDTH, RECT_HEIGHT, BLACK); // erase current
    x -= 2.0f * deltaX; // undo and invert
    if (x < 0) x = 0;
    if (x > M5.Lcd.width() - RECT_WIDTH) x = M5.Lcd.width() - RECT_WIDTH;
    M5.Lcd.fillRect((int)x, (int)y, RECT_WIDTH, RECT_HEIGHT, RED); // redraw at corrected pos
  }
  delay(20);
}