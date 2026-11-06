#include <Arduino.h>
#include <Wire.h>
#include <PCA9685.h>

PCA9685 pca(0x40);  

uint16_t usToTicks(uint16_t us) {
  return (uint32_t)us * 4096 / 20000;
}

void moveServo(uint8_t channel, uint16_t us) {
  pca.setPWM(channel, usToTicks(us));
}

void setup() {
  Wire.begin();          
  pca.begin();
  pca.setFrequency(50); 
}

void loop() {
  moveServo(0, 1000); delay(1000);  // one side
  moveServo(0, 1500); delay(1000);  // middle
  moveServo(0, 2000); delay(1000);  // other side
}