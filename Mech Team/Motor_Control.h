#ifndef MOTORCON
#define MOTORCON

#include <Encoder.h>
#include <Adafruit_INA219.h>
#include <IntervalTimer.h>

class Motor {

private:

  int motorIN1, motorIN2, motorGearRatio, encoderPin1, encoderPin2, followthresholdSpeed, followthresholdCurrent, followFeedInValue, 
      followFeedOutValue;

  double encoderPulsePerRotation, shaftRev, followInputVoltage;

  float motorInputVoltage;

  Encoder *motorEncoder;

  Adafruit_INA219 *currentSensor;

public:

  volatile double lastPosition, nowPosition, time1, time2, speedValue;
  
  int reachedPositionFlag = 0, positionIncrementFlag;

  Motor(int motorIN1_Input, int motorIN2_Input, float motorInputVoltage_Input, int motorGearRatio_Input, 
        int encoderPin1_Input, int encoderPin2_Input, double encoderPulsePerRotation_Input, int currentSensorAddress_Input);

  void setVoltage(double voltage); 

  void brake();

  double readEncoder();

  void setEncoder(int encoderSetValue);

  static void speed( Motor *inputMotors, int motorNumber );

  double readCurrent();

  void modeControl();

  void followControl();

  void torqueControl(int torque);

};

#endif