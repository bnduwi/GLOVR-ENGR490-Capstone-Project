#include <Encoder.h>
#include <Adafruit_INA219.h>
//#include <IntervalTimer.h>

class motor {

private:

	int motorIN1, motorIN2, motorGearRatio, encoderPin1, encoderPin2;

	double encoderPulsePerRotation;

	float motorInputVoltage;

	Encoder *motorEncoder;

	Adafruit_INA219 *currentSensor;

public:

	int reachedPositionFlag = 0, positionIncrementFlag;

	motor(int motorIN1_Input, int motorIN2_Input, float motorInputVoltage_Input, int motorGearRatio_Input, 
		  int encoderPin1_Input, int encoderPin2_Input, double encoderPulsePerRotation_Input, int currentSensorAddress_Input);

	void setVoltage(double voltage); 

	void brake();

	int incrementPosition(double degrees); //This will require charecterising the motor

	//Void setTorque(int torque) // This will also require charecterisation

	double readEncoder();

	void setEncoder(int encoderSetValue);

	double speed(); //THIS FUNCTION HAS A DELAY OF 10ms IF THERE ARE ISSUES THIS MAY BE THE REASON

	double readCurrent();



};
