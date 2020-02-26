#include"Serial_Communication.h"
#include <arduino.h>
#include <string.h>
#include <stdlib.h> 




BeeriConnect::BeeriConnect(){

	Serial.begin(19200);

}

void BeeriConnect::update(LRA *inputLRAs, Motor *inputMotors){


	if(Serial.available()){

		Serial.print("\nupdating");

		bytesRead = Serial.readBytesUntil('$', buffer, 256);

		buffer[bytesRead + 1] = NULL;

		char *strParse;

		int valNum, type, location;

		strParse = strtok (buffer, ",");

		type = *strParse;

		strParse = strtok (NULL, ",");

		location = *strParse;

		strParse = strtok (NULL, ",");

		valNum = atoi(strParse);

		Serial.print(type);

		Serial.print(" ");

		Serial.print(location);

		Serial.print(" ");

		Serial.print(valNum);

		switch(type){

			case 108:

				
				switch(location){


					case 97:

						inputLRAs[0].playWaveForm(valNum);

						break;

					case 98:

						inputLRAs[1].playWaveForm(valNum);

						break;

					case 99:

						inputLRAs[2].playWaveForm(valNum);

						break;

					case 100:

						inputLRAs[3].playWaveForm(valNum);

						break;

					case 101:

						inputLRAs[4].playWaveForm(valNum);

						break;

					case 102:

						inputLRAs[5].playWaveForm(valNum);

						break;

					case 103:

						inputLRAs[6].playWaveForm(valNum);

						break;

					case 104:

						inputLRAs[7].playWaveForm(valNum);

						break;

					default:
					
						break;	

				}


				break;

			case 102:

				switch(location){

					case 97:

						inputMotors[0].setVoltage(valNum);

						break;

					case 98:
					
						break;

					case 99:

						break;

					case 100:

						break;

					case 101:

						break;

					default: 

						break;

				}


			default:

				break;

		}

	}
	
}
