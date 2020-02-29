#include"Serial_Communication.h"
#include <arduino.h>
#include <string.h>
#include <stdlib.h> 




BeeriConnect::BeeriConnect(){

	Serial.begin(19200);

}

void BeeriConnect::updateRecieve(LRA *inputLRAs, Motor *inputMotors){


	if(Serial.available()){

		bytesRead = Serial.readBytesUntil('$', buffer, 256);

		char *strParse;

		int valNum, type, location;

		strParse = strtok (buffer, ",");

		type = *strParse;

		strParse = strtok (NULL, ",");

		location = *strParse;

		strParse = strtok (NULL, ",");

		valNum = atoi(strParse);

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

						inputMotors[0].forceInput = valNum;

						Serial.print(valNum);

						break;

					case 98:

						inputMotors[1].forceInput = valNum;
					
						break;

					case 99:

						inputMotors[2].forceInput = valNum;

						break;

					case 100:

						inputMotors[3].forceInput = valNum;

						break;

					case 101:

						inputMotors[4].forceInput = valNum;

						break;

					default: 

						break;

				}


			default:

				break;

		}

	}
	
}


void BeeriConnect::updateSend(Hand *inputHand){

	if (Serial.availableForWrite()){

		Serial.print("a1,");
		Serial.print(inputHand[0].fingers[0].potCurrent[0]);
		Serial.print(";");

		Serial.print("a2,");
		Serial.print(inputHand[0].fingers[0].potCurrent[1]);
		Serial.print(";");

		Serial.print("a3,");
		Serial.print(inputHand[0].fingers[0].potCurrent[2]);
		Serial.print(";");

		Serial.print("b1,");
		Serial.print(inputHand[0].fingers[1].potCurrent[0]);
		Serial.print(";");

		Serial.print("b2,");
		Serial.print(inputHand[0].fingers[1].potCurrent[1]);
		Serial.print(";");

		Serial.print("b3,");
		Serial.print(inputHand[0].fingers[1].potCurrent[2]);
		Serial.print(";");

		Serial.print("c1,");
		Serial.print(inputHand[0].fingers[2].potCurrent[0]);
		Serial.print(";");

		Serial.print("c2,");
		Serial.print(inputHand[0].fingers[2].potCurrent[1]);
		Serial.print(";");

		Serial.print("c3,");
		Serial.print(inputHand[0].fingers[2].potCurrent[2]);
		Serial.print(";");

		Serial.print("d1,");
		Serial.print(inputHand[0].fingers[3].potCurrent[0]);
		Serial.print(";");

		Serial.print("d2,");
		Serial.print(inputHand[0].fingers[3].potCurrent[1]);
		Serial.print(";");

		Serial.print("d3,");
		Serial.print(inputHand[0].fingers[3].potCurrent[2]);
		Serial.print(";");

		Serial.print("e1,");
		Serial.print(inputHand[0].fingers[4].potCurrent[0]);
		Serial.print(";");

		Serial.print("e2,");
		Serial.print(inputHand[0].fingers[4].potCurrent[1]);
		Serial.print(";");

		Serial.print("e3,");
		Serial.print(inputHand[0].fingers[4].potCurrent[2]);
		Serial.print(";");

		Serial.print("e4,");
		Serial.print(inputHand[0].fingers[4].potCurrent[3]);
		Serial.print(";");


		Serial.print("\n");



	}

}