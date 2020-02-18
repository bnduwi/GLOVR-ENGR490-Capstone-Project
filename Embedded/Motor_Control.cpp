#include "Motor_Control.h"
#include <arduino.h>
#include <Encoder.h>
#include <Adafruit_INA219.h>
//#include <IntervalTimer.h>



motor::motor(int motorIN1_Input, int motorIN2_Input, float motorInputVoltage_Input, int motorGearRatio_Input, int encoderPin1_Input, int encoderPin2_Input, double encoderPulsePerRotation_Input){

	motorIN1 = motorIN1_Input;

	motorIN2 = motorIN2_Input;

	motorInputVoltage = motorInputVoltage_Input;

	motorGearRatio = motorGearRatio_Input;

	encoderPin1 = encoderPin1_Input;

	encoderPin2 = encoderPin2_Input;

	encoderPulsePerRotation = encoderPulsePerRotation_Input;

	pinMode(motorIN1, OUTPUT);

	pinMode(motorIN2, OUTPUT);

	motorEncoder = new Encoder(encoderPin1, encoderPin2);

	//speedInterupt = new IntervalTimer;

}

void motor::setVoltage(float voltage){

	if (voltage >= 0){

		int pulseWidth = (voltage/motorInputVoltage)*255;

		digitalWrite(motorIN1, LOW);

		analogWrite(motorIN2, abs(pulseWidth));

		//motor::speedInterupt->begin(calculateSpeed, 100);


	}
	else{

		int pulseWidth = (voltage/motorInputVoltage)*255;

		digitalWrite(motorIN2, LOW);

		analogWrite(motorIN1, abs(pulseWidth));

	}

}

double motor::readEncoder(){

	return ((motor::motorEncoder->read()/encoderPulsePerRotation)/50.0)*360.0;

}

void motor::setEncoder(int encoderSetValue){


	motor::motorEncoder->write(encoderSetValue);


}

double motor::speed(){ ///THIS FUNCTION HAS A DELAY THAT MAY CAUSE ISSUES, LOOK INTO INTERUPTS AS ALTERNATIVE

	int delayValue = 100;

	double currentPosition = motor::readEncoder();

	delay(delayValue);

	double secondPosition = motor::readEncoder();

	double speed = ((secondPosition-currentPosition)/360)/(delayValue*0.00001);
	
	return speed;
}
