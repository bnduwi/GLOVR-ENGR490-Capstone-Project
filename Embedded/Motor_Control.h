#include <Encoder.h>
#include <Adafruit_INA219.h>
//#include <IntervalTimer.h>

class motor {

public:

int motorIN1, motorIN2, motorGearRatio, encoderPin1, encoderPin2;

double encoderPulsePerRotation;

float motorInputVoltage;

Encoder *motorEncoder;

motor(int motorIN1_Input, int motorIN2_Input, float motorInputVoltage_Input, int motorGearRatio_Input, int encoderPin1_Input, int encoderPin2_Input, double encoderPulsePerRotation_Input);

void setVoltage(float voltage);

double readEncoder();

void setEncoder(int encoderSetValue);

double speed(); //THIS FUNCTION HAS A DELAY OF 10ms IF THERE ARE ISSUES THIS MAY BE THE REASON

};
