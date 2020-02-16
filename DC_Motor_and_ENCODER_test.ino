#include <Encoder.h>

// Change these pin numbers to the pins connected to your encoder.
//   Best Performance: both pins have interrupt capability
//   Good Performance: only the first pin has interrupt capability
//   Low Performance:  neither pin has interrupt capability
#define MOTOR_IN1 6
#define MOTOR_IN2 7
Encoder knobLeft(11, 12);
//Encoder knobRight(7, 8);


void setup() {
  pinMode(MOTOR_IN1, OUTPUT);
  pinMode(MOTOR_IN2, OUTPUT);
//   avoid using pins with LEDs attached
  Serial.begin(9600);
  Serial.println("Encoder and Motor Test:");


}

long positionLeft  = -999;
//long positionRight = -999;

void loop() {

  // ramp up forward
digitalWrite(MOTOR_IN1, LOW);

analogWrite(MOTOR_IN2, 255);
delay(10);

  long newLeft, newRight;
  newLeft = knobLeft.read();
  //newRight = knobRight.read();
 // if (newLeft != positionLeft || newRight != positionRight) {
    if (newLeft != positionLeft) {
    Serial.print("Left = ");
    Serial.print(newLeft);
    //Serial.print(", Right = ");
    //Serial.print(newRight);
    //Serial.println();
    positionLeft = newLeft;
    //positionRight = newRight;
  }
  // if a character is sent from the serial monitor,
  // reset both back to zero.
  if (Serial.available()) {
    Serial.read();
    Serial.println("Reset value to zero");
    knobLeft.write(0);
    //knobRight.write(0);
  }
}
