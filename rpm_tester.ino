//#include "AFMotor_R4.h"
//#include <Arduino.h>
#include "Wheel.h"

#define FRONT A2
#define REAR A3

Wheel front(3, FRONT);
Wheel rear(2, REAR);

void setup() {
  pinMode(FRONT, INPUT);
  pinMode(REAR, INPUT);
  Serial.begin(9600);
}

void loop() {
  moveWheels();
  Serial.print("front: ");
  Serial.println(front.holes);
  Serial.print("rear: ");
  Serial.println(rear.holes);
  while (!Serial.available()) {
    // breakpoint
  }
  Serial.read();
}

void moveWheels() {
  front.forward();
  rear.forward();
}
