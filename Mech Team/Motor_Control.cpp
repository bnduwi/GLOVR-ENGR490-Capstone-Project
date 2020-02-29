#include "Motor_Control.h"
#include <arduino.h>
#include <Encoder.h>
#include <Adafruit_INA219.h>



Motor::Motor(int motorIN1_Input, int motorIN2_Input, float motorInputVoltage_Input, int motorGearRatio_Input, 
			 int encoderPin1_Input, int encoderPin2_Input, double encoderPulsePerRotation_Input, int currentSensorAddress_Input){

	motorIN1 = motorIN1_Input;

	motorIN2 = motorIN2_Input;

	motorInputVoltage = motorInputVoltage_Input;

	motorGearRatio = motorGearRatio_Input;

	encoderPin1 = encoderPin1_Input;

	encoderPin2 = encoderPin2_Input;

	encoderPulsePerRotation = encoderPulsePerRotation_Input;

	positionIncrementFlag = 0;

	pinMode(motorIN1, OUTPUT);

	pinMode(motorIN2, OUTPUT);

	motorEncoder = new Encoder(encoderPin1, encoderPin2);

	currentSensor = new Adafruit_INA219(currentSensorAddress_Input);

	Motor::currentSensor->begin();

	Motor::currentSensor->setCalibration_16V_400mA(); // IF LARGER MOTORS ARE USED CHANGE THIS CALIBRATION

  	shaftRev = 1.0/(encoderPulsePerRotation*motorGearRatio);

  	time1 = time2 = nowPosition = lastPosition = 0;

  	followthresholdSpeed = 5;

  	followthresholdCurrent = 75.0;

  	followFeedInValue = 4;

  	followFeedOutValue = 0;

  	followInputVoltage = 0.0;

  	forceInput = 4;

}

void Motor::setVoltage(double voltage){ ///35 is the cutoff pwm value

	if (voltage > 0){

		double pulseWidth = (5.8073 * exp ( ( .5593 * abs(voltage)  )  )  );

		analogWrite(motorIN1, LOW);

		analogWrite(motorIN2, abs(pulseWidth));

	}

	else if (voltage < 0){

		double pulseWidth = (5.8073 * exp ( ( .5593 * abs(voltage)  ) + (motorInputVoltage-6.5) )  );

		analogWrite(motorIN2, LOW);

		analogWrite(motorIN1, abs(pulseWidth));

	}

	else if (voltage == 0){

		analogWrite(motorIN2, LOW);

		analogWrite(motorIN1, LOW);

	}

}


double Motor::readEncoder(){

	return (Motor::motorEncoder->read())*shaftRev; //look into data types for encoder 

}

void Motor::setEncoder(int encoderSetValue){


	Motor::motorEncoder->write(encoderSetValue);

}


void Motor::speed(Motor *inputMotors, int motorNumber){ 

	inputMotors[motorNumber].nowPosition = inputMotors[motorNumber].readEncoder();
	  
	inputMotors[motorNumber].time2 = micros();
	 
	inputMotors[motorNumber].speedValue = (60*(inputMotors[motorNumber].nowPosition - inputMotors[motorNumber].lastPosition) / ((inputMotors[motorNumber].time2-inputMotors[motorNumber].time1)*0.000001));
	 
	inputMotors[motorNumber].lastPosition = inputMotors[motorNumber].nowPosition;

	inputMotors[motorNumber].time1 = inputMotors[motorNumber].time2;  



	  
}

double Motor::readCurrent(){ 

	int iterations = 100;

	double currentReadings = 0;

	for (int i = 0; i < iterations; i++){

		currentReadings += Motor::currentSensor->getCurrent_mA();

	}

	return currentReadings/iterations;


}


void Motor::brake(){

	analogWrite(motorIN2, HIGH);

	analogWrite(motorIN1, HIGH);


}


void Motor::followControl(){ //causes the motor to retract or unroll cable based on current and speed readings

	int currentReading = Motor::readCurrent();


	if ( (speedValue < 5) && (currentReading >= -followthresholdCurrent) ){

		followInputVoltage -= .3;

		if (followInputVoltage <= -6.5) followInputVoltage = -6.5; 

		// Serial.print("feeding In ");
		// Serial.print(currentReading);
		// Serial.print(" : ");
		// Serial.print(speedValue);
		// Serial.print("\n");

	}

	else {

		// followInputVoltage = 0;

		// Serial.print("feeding Out ");
		// Serial.print(currentReading);
		// Serial.print(" : ");
		// Serial.print(speedValue);
		// Serial.print("\n");

	}

	Motor::setVoltage(followInputVoltage);



}

void Motor::modeControl(){

	if (forceInput == 0){

		Motor::followControl();

	}

	else{


		Motor::setVoltage(forceInput);


	}


}


