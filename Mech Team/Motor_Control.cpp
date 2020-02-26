#include "Motor_Control.h"
#include <arduino.h>
#include <Encoder.h>
#include <Adafruit_INA219.h>

//#include <IntervalTimer.h>



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

  	shaftRev = 1.0/ (encoderPulsePerRotation*motorGearRatio);

}

void Motor::setVoltage(double voltage){ ///35 is the cutoff pwm value

	if (voltage > 0){

		//int pulseWidth = (voltage/motorInputVoltage)*255;

		//double pulseWidth = 5.8073 * exp ( (.5593 * voltage) + (motorInputVoltage-6.5) );

		double pulseWidth = (5.8073 * exp ( ( .5593 * abs(voltage)  )  )  );

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


double Motor::speed(){ ///THIS FUNCTION HAS A DELAY THAT MAY CAUSE ISSUES, LOOK INTO INTERUPTS AS ALTERNATIVE


		////////////TESTING PRINTS//////////

		//Serial.print("\nPrevious Position = ,");
		Serial.print(" ,");
		Serial.print(lastPosition);

	nowPosition = Motor::readEncoder();
	  
		//Serial.print("\nCurrent Position = ,");
		Serial.print(" ,");
		Serial.print(nowPosition);
		  
		//Serial.print("\nPrevious Time = ,");
		Serial.print(" ,");
		Serial.print(time1);
	  
	time2 = millis();
	 
		//Serial.print("\nCurrent Time = ,");
		Serial.print(" ,");
		Serial.print(time2);
	  
	//double speed = ((secondPosition-currentPosition)/((time2-time1)*0.01))*1.62; 
	double speed = ((nowPosition - lastPosition) / ((time2 - time1)*0.001));
	  
		//Serial.print("\nTime Step (ms) = ,");
		Serial.print(" ,");
		Serial.print(time2 - time1);
		  
		//Serial.print("\nPosition Difference (rev) = ,");
		Serial.print(" ,");
		Serial.print(nowPosition - lastPosition);
	  
	lastPosition = nowPosition;

	time1 = time2;
	  
		//Serial.print("\nSpeed (RPM) = ,");
		Serial.print(" ,");
		Serial.print(60*speed);
		  
		//Serial.print("\nProportional Encoder Steps per Shaft Rev = ,");
		Serial.print(" ,");
		Serial.print(encoderPulsePerRotation*motorGearRatio);

	return speed;
}

double Motor::readCurrent(){ 

	int iterations = 1000;

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


int Motor::incrementPosition(double degrees){

	if (positionIncrementFlag == 0){

		Motor::setEncoder(0);

		positionIncrementFlag = 1;		

	}





	if (degrees > 0.0){

		if(Motor::readEncoder() >= (0.4*degrees)){

			Motor::brake();

			reachedPositionFlag = 1;

			positionIncrementFlag = 0;

		}

		else{

			Motor::setVoltage(motorInputVoltage);


		}

	}







	if(degrees < 0){

		if(Motor::readEncoder() <= degrees){

			Motor::brake();

			reachedPositionFlag = 1;

			positionIncrementFlag = 0;

		}

		else{

			Motor::setVoltage(-motorInputVoltage);


		}

	}


}

