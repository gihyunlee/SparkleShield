// Adapted from the FastLED library - http://fastled.io

#include <FastLED.h>
#include <SparkleShield.h>

#define BRIGHTNESS 16

SparkleShield sparkle;

void DrawOneFrame(byte startHue8, int8_t yHueDelta8, int8_t xHueDelta8) {
  byte lineStartHue = startHue8;
  for (byte y = 0; y < kMatrixHeight; y++) {
    lineStartHue += yHueDelta8;
    byte pixelHue = lineStartHue;
    for (byte x = 0; x < kMatrixWidth; x++) {
      pixelHue += xHueDelta8;
      sparkle.set(x, y, CHSV(pixelHue, 255, 255));
    }
  }
}

void loop() {
  uint32_t ms = millis();
  int32_t yHueDelta32 = ((int32_t)cos16(ms * (27 / 1) ) * (350 / kMatrixWidth));
  int32_t xHueDelta32 = ((int32_t)cos16(ms * (39 / 1) ) * (310 / kMatrixHeight));
  DrawOneFrame(ms / 65536, yHueDelta32 / 32768, xHueDelta32 / 32768);
  sparkle.show();
}

void setup() {
  sparkle.setBrightness(BRIGHTNESS);
}
