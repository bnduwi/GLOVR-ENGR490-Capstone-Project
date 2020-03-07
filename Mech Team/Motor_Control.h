#ifndef MOTORCON
#define MOTORCON

#include <Encoder.h>
#include <Adafruit_INA219.h>
#include <IntervalTimer.h>

class Motor {

private:

  int motorIN1, motorIN2, motorGearRatio, encoderPin1, encoderPin2, followthresholdSpeed, followthresholdCurrent;

  double encoderPulsePerRotation, shaftRev, followInputPWM;

  float motorInputVoltage;

  Encoder *motorEncoder;

  Adafruit_INA219 *currentSensor;

  char averageCount = 100;

  float movingAverage, movingAverageSum;



public:

  double lastPosition, nowPosition, time1, time2, speedValue;
  
  int forceInput;

  Motor(int motorIN1_Input, int motorIN2_Input, float motorInputVoltage_Input, int motorGearRatio_Input, 
        int encoderPin1_Input, int encoderPin2_Input, double encoderPulsePerRotation_Input, int currentSensorAddress_Input);

  void setPWM(double PWM); 

  void brake();

  double readEncoder();

  void setEncoder(int encoderSetValue);

  static void speed( Motor *inputMotors, int motorNumber );

  double readCurrent();

  void modeControl(); //Selects either followControl or torqueControl based on sim input

  void followControl();

  void torqueControl();  

};

#endif