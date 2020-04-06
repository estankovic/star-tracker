// first, include the library :)

#include <CheapStepper.h>

CheapStepper stepper(2, 3, 4, 5);
// here we declare our stepper using default pins:
// arduino pin <--> pins on ULN2003 board:
// 8 <--> IN1
// 9 <--> IN2
// 10 <--> IN3
// 11 <--> IN4

const int UP = 11;
const int DOWN = 12;

// let's create a boolean variable to save the direction of our rotation

int stepperDelay = 2490;

void setup() {
  pinMode(UP, INPUT_PULLUP);
  pinMode(DOWN, INPUT_PULLUP);
}

void loop() {

  int movingUp = digitalRead(UP);
  int movingDown = digitalRead(DOWN);

  // moving up
  if (movingUp == 0) {
    stepper.step(true);
    delayMicroseconds(stepperDelay);
  }

  // moving down
  if (movingDown == 0) {
    stepper.step(false);
    delayMicroseconds(stepperDelay);
  }
}

