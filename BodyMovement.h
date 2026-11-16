#include "Wheel.h"

void moveForward(Wheel first, Wheel second) {
  first.forward();
  second.forward();
}

void calculateAllRPS(Wheel first, Wheel second) {
  first.calculateRPS();
  second.calculateRPS();
}
