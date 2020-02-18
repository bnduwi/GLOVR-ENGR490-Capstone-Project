#include <Encoder.h>
#include "Motor_Control.h"

// Change these pin numbers to the pins connected to your encoder.
//   Best Performance: both pins have interrupt capability
//   Good Performance: only the first pin has interrupt capability
//   Low Performance:  neither pin has interrupt capability
#define MOTOR_IN1 6
#define MOTOR_IN2 7
//Encoder knobLeft(11, 12);
motor motor1(6,7,6.5,50,11,12,28.0);
//Encoder knobRight(7, 8);


void setup() {

  Serial.begin(9600);
  Serial.println("Encoder and Motor Test:");

}


void loop() {

  double motorPosition;
  motor1.setVoltage(-6.5);
  motorPosition = motor1.readEncoder();

  Serial.print("\nMotorPosition = ");
  Serial.print(motorPosition);
  
    Serial.print("\nMotorSpeed = ");
  Serial.print(motor1.speed());



}
