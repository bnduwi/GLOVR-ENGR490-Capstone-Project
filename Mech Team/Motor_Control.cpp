#include "Motor_Control.h"
#include <arduino.h>
#include <Encoder.h>
#include <Adafruit_INA219.h>

//#include <IntervalTimer.h>



motor::motor(int motorIN1_Input, int motorIN2_Input, float motorInputVoltage_Input, int motorGearRatio_Input, int encoderPin1_Input, int encoderPin2_Input, double encoderPulsePerRotation_Input, int currentSensorAddress_Input){

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

	currentSensor = new Adafruit_INA219(currentSensorAddress_Input);

	motor::currentSensor->begin();

	motor::currentSensor->setCalibration_16V_400mA(); // IF LARGER MOTORS ARE USED CHANGE THIS CALIBRATION


}

void motor::setVoltage(double voltage){

	if (voltage > 0){

		//int pulseWidth = (voltage/motorInputVoltage)*255;

		//double pulseWidth = 5.8073 * exp ( (.5593 * voltage) + (motorInputVoltage-6.5) );

		double pulseWidth = (5.8073 * exp ( ( .5593 * abs(voltage)  ) + (motorInputVoltage-6.5) )  );

		digitalWrite(motorIN1, LOW);

		analogWrite(motorIN2, abs(pulseWidth));

	}

	else if (voltage < 0){

		//int pulseWidth = (voltage/motorInputVoltage)*255;

		//double pulseWidth = 5.8073 * exp ( (.5593 * voltage) + (motorInputVoltage-6.5) );

		double pulseWidth = (5.8073 * exp ( ( .5593 * abs(voltage)  ) + (motorInputVoltage-6.5) )  );

		digitalWrite(motorIN2, LOW);

		analogWrite(motorIN1, abs(pulseWidth));

	}

	else{

		digitalWrite(motorIN2, LOW);

		digitalWrite(motorIN1, LOW);

	}

}


double motor::readEncoder(){

	return ((motor::motorEncoder->read()/encoderPulsePerRotation)/motorGearRatio)*360.0; //look into data types for encoder 

}

void motor::setEncoder(int encoderSetValue){


	motor::motorEncoder->write(encoderSetValue);

}


double motor::speed(){ ///THIS FUNCTION HAS A DELAY THAT MAY CAUSE ISSUES, LOOK INTO INTERUPTS AS ALTERNATIVE

	int delayValue = 100;

	int time1 = millis();

	double currentPosition = motor::readEncoder();

	delay(delayValue);

	double secondPosition = motor::readEncoder();

	int time2 = millis();

	double speed = ((secondPosition-currentPosition)/((time2-time1)*0.01))*1.62; //The 1.6 scalar value at the end... I dont understand why I need it but 
																				//without it the value of rpm is wrong
	
	return speed;
}

double motor::readCurrent(){ 

	int iterations = 40;

	double currentReadings = 0;

	for (int i = 0; i < iterations; i++){

		currentReadings += motor::currentSensor->getCurrent_mA();

	}

	return currentReadings/iterations;


}


