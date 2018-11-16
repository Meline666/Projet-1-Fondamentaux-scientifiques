#include <Arduino.h>
#include "cardio.h"

void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT);
}


void loop() {
  pouls();
}
