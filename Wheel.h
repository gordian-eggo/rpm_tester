#ifndef WHEEL_H
#define WHEEL_H

#include "AFMotor_R4.h"
#include <Arduino.h>

// 24-10-2026: successfully replicated error in sisa_body. 
//             Fucking now what??

class Wheel {
  private:
    const int diskSlots = 20;

  public:
    int sensorPin;
    int prevReading = 0;
    int holes = 0;
    AF_DCMotor motor;
    
     Wheel(AF_DCMotor motor, int sensorPin) : motor(motor) {
        this->sensorPin = sensorPin;
     }

     void forward() {
        calculateRPS();
        motor.setSpeed(200);
        motor.run(FORWARD);
     }

     void calculateRPS() {
         int currValue = digitalRead(this->sensorPin);
         Serial.print("currValue: ");
         Serial.println(currValue);
  
         if (prevReading < currValue) {
            ++holes;
         }
         prevReading = currValue;
  
     }
     
};

#endif
