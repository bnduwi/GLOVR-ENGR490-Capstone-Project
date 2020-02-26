#include "Object_Declerations.h"

// Change these pin numbers to the pins connected to your encoder.
//   Best Performance: both pins have interrupt capability
//   Good Performance: only the first pin has interrupt capability
//   Low Performance:  neither pin has interrupt capability
#define MOTOR_IN1 6 
#define MOTOR_IN2 7



BeeriConnect Beeri;


double motorCurrentAverage;
 
double rad = PI/180;
 
double angle = 0;
 
double initialposition = 0;

double initialtime = 0;

void setup() {

 // Serial.begin(9600);
 // Serial.print("Encoder and Motor Test:");

  startInterrupts();


}


void loop() {

  Beeri.update(&LRAa);

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

// Serial.print("\nthis is the speed = ");
// Serial.print(Motor1.speed());


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





	//delay(1000);
	//LRA1.test2();
  //int value = 0;

   // Serial.print("The value = ");
   // Serial.print(value);

   delay(1000);


}
