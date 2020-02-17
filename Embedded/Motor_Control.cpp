#include "Motor_Control.h"
#include <arduino.h>
#include <Encoder.h>



void motor::setup(int IN1, int IN2, float motorInputVolts, int motorGR){

motorIN1 = IN1;

motorIN2 = IN2;

motorInputVoltage = motorInputVolts;

motorGearRatio = motorGR;

pinMode(motorIN1, OUTPUT);

pinMode(motorIN2, OUTPUT);

}

void motor::setVoltage(float voltage){

	if (voltage >= 0){

		int pulseWidth = (voltage/motorInputVoltage)*255;

		digitalWrite(motorIN1, LOW);

		analogWrite(motorIN2, abs(pulseWidth));


	}
	else{

		int pulseWidth = (voltage/motorInputVoltage)*255;

		digitalWrite(motorIN2, LOW);

		analogWrite(motorIN1, abs(pulseWidth));

	}

}


