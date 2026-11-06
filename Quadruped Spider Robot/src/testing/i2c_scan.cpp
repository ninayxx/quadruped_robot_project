#include <Arduino.h>
#include <Wire.h>

void setup() {
  Wire.begin();
  Serial.begin(9600);
  for (byte a = 1; a < 127; a++) {
    Wire.beginTransmission(a);
    if (Wire.endTransmission() == 0) { Serial.print("Found 0x"); Serial.println(a, HEX); }
  }
  Serial.println("Done");
}

void loop() {}