#include <Encoder.h>
#include "Motor_Control.h"
#include <wire.h>
#include "LRA_Control.h"

// Change these pin numbers to the pins connected to your encoder.
//   Best Performance: both pins have interrupt capability
//   Good Performance: only the first pin has interrupt capability
//   Low Performance:  neither pin has interrupt capability
#define MOTOR_IN1 6
#define MOTOR_IN2 7
//Encoder knobLeft(11, 12);
motor motor1(6,7,6.5,50,11,12,28.0,0x40);
LRA LRA0(0), LRA1(1), LRA2(2), LRA3(3), LRA4(4), LRA5(5), LRA6(6), LRA7(7);

//Encoder knobRight(7, 8);

  double motorCurrentAverage;


void setup() {

  Serial.begin(9600);
  Serial.println("Encoder and Motor Test:");

}


void loop() {

  double motorPosition;
  motor1.setVoltage(-3.25);
  motorPosition = motor1.readEncoder();


  // int timeToRead = micros();
  motorCurrentAverage = motor1.readCurrent();
  // int timeToRead2 = micros();



  // Serial.print("\nMotorPosition = ");
  // Serial.print(motorPosition);
  
  Serial.print("\nMotorSpeed = ");
  Serial.print(motor1.speed());

  Serial.print("\nMotorCurrentAverage = ");
  Serial.print(motorCurrentAverage);

  // Serial.print("\ntime to read = ");
  // Serial.print(timeToRead2-timeToRead);

	LRA0.playWaveform(20);

	LRA1.playWaveform(20);

	LRA2.playWaveform(20);

	LRA3.playWaveform(20);

	LRA4.playWaveform(20);

	LRA5.playWaveform(20);

	LRA6.playWaveform(20);

	delay(1000);

	LRA7.playWaveform(20);

	delay(1000);
	//LRA1.test2();


}
