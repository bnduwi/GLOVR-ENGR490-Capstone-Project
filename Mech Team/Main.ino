//#include <Encoder.h>
#include "Motor_Control.h"
#include <Wire.h>
#include "LRA_Control.h"
#include "Hand.h"
#include "interrupts.h"

// Change these pin numbers to the pins connected to your encoder.
//   Best Performance: both pins have interrupt capability
//   Good Performance: only the first pin has interrupt capability
//   Low Performance:  neither pin has interrupt capability
#define MOTOR_IN1 6 
#define MOTOR_IN2 7

motor motor1(6,7,6.5,50,11,12,28.0,0x40);

LRA LRA0(0), LRA1(1), LRA2(2), LRA3(3), LRA4(4), LRA5(5), LRA6(6), LRA7(7);
int potPinss[16] = {A9,A8,A7,A6,A3,A2,A1,A0,A22,A21,A20,A19,A18,A17,A16,A15}; //
hand hand (potPinss);

 double motorCurrentAverage;
 
 double rad = PI/180;
 
 double angle = 0;
 
double initialposition = 0;

double initialtime = 0;

void setup() {

  Serial.begin(9600);
  Serial.print("Encoder and Motor Test:");

  startInterrupts();

}


void loop() {

//   //Serial.print("\n\nLoop Time = ,");
//   Serial.print("\n");
//   Serial.print(millis());

//   //Serial.print("\nTheta Value in degrees (for sinewave voltage input) = ,");
//   Serial.print(" ,");
//   Serial.print(angle);

//   double V = (6.5*sin(rad*angle));
//   //double V = (6.5);
//   angle = angle+5;
  
//   double motorPosition; //////this sequence isnt working, it will play the first and then not work

//   //Serial.print("\nVoltage Sent (V) = ,");
//   Serial.print(" ,");
//   Serial.print(V);

//motor1.setVoltage(6.5);

//   // delay(2000);

//   // motor1.setVoltage(6.5);

//   // delay(2000);

//   //motor1.brake();



 


  

//    motorPosition = motor1.readEncoder();


//   // int timeToRead = micros();
// double motorCurrentAverage = motor1.readCurrent();

//double motorVoltageAverage = motor1.readLoadVoltage();

  // int timeToRead2 = micros();


//if (motor1.reachedPositionFlag == 1){
//
//
//}
//  
//else{
//
//  motor1.incrementPosition(360.0);
//
//
//}




  // Serial.print("\nMotor Current = ,");
//   Serial.print(" ,");
//   Serial.print(motorCurrentAverage);

// //  Serial.print("\nMotorLoad = ");
// //  Serial.print(motorVoltageAverage);



//   // Serial.print("\nCurrent Encoder Count = ,");
//   Serial.print(" ,");
//   Serial.print(motorPosition);

Serial.print("\nthis is the speed = ");
Serial.print(motor1.speed());


//  Serial.print("\npositionIncrementFlag = ");
//  Serial.print(motor1.positionIncrementFlag);
//
//  Serial.print("\nreachedPositionFlag = ");
//  Serial.print(motor1.reachedPositionFlag);


  // Serial.print("\nthe last Pin is = ");
  // Serial.print(hand.fingers[4].potPin[3]);

  // Serial.print("\nand its position is = ");
  // Serial.print(hand.fingers[4].potCurrent[1]);


  // int timeToUpdate = millis();
  // hand.update();
  // delay(10);
  // int timeToUpdate2 = millis();

  // Serial.print("\ntime to update all pots is = ");
  // Serial.print(timeToUpdate2-timeToUpdate);



  // Serial.print("\ntime to read = ");
  // Serial.print(timeToRead2-timeToRead);

	// LRA0.playWaveform(52);

	// LRA1.playWaveform(52);

	// LRA2.playWaveform(52);

	// LRA3.playWaveform(52);

	// LRA4.playWaveform(52);

	// LRA5.playWaveform(52);

	// LRA6.playWaveform(52);

	//delay(2000);

	//LRA7.playWaveform(20);

	//delay(1000);
	//LRA1.test2();
  //int value = 0;

   Serial.print("The value = ");
   Serial.print(value);

   delay(100);


}
