
#include "hand.h"
#include <arduino.h>



Hand::Hand(int pins_Input[]){

	for (int i = 0; i < 5; i++){

		for(int s = 0; s < 3; s++){

		fingers[i].potPin[s] = pins_Input[((i * 3) + s)];

		}
	}

	fingers[4].potPin[3] = pins_Input[15];
}

void Hand::update(Motor *Motors){


	for (int i = 0; i < 5; i++){

		for(int s = 0; s < 3; s++){


			if (smoothingCounter == smoothingValue){

				fingers[i].potPrevious[s] = fingers[i].potCurrent[s];

				fingers[i].potCurrent[s] = (fingers[i].potAverage[s]/smoothingValue);

				fingers[i].potAverage[s] = 0;

				// Serial.print(fingers[0].potCurrent[0] - fingers[0].potPrevious[0]);

				// Serial.print("\n");

				if((fingers[i].potCurrent[s] - fingers[i].potPrevious[s]) > 3 ) Motors[i].modeFlag = 1;

				if((fingers[i].potCurrent[s] - fingers[i].potPrevious[s]) < -3 ) Motors[i].modeFlag = 0;



			}

			else{

				double mapping = (analogRead(fingers[i].potPin[s])/1023.0)*180.000000;

				fingers[i].potAverage[s] = mapping + fingers[i].potAverage[s];

			}
		}
	}

	if(smoothingCounter == smoothingValue){

		fingers[4].potPrevious[3] = fingers[4].potCurrent[3];

		fingers[4].potCurrent[3] = (fingers[4].potAverage[3]/smoothingValue);

		fingers[4].potAverage[3] = 0;

		smoothingCounter = 0;

		if((fingers[4].potCurrent[3] - fingers[4].potPrevious[3]) > 3 ) Motors[4].modeFlag = 1;

		if((fingers[4].potCurrent[3] - fingers[4].potPrevious[3]) < -3 ) Motors[4].modeFlag = 0;

	}

	else{

		double mappings = (analogRead(fingers[4].potPin[3])/1023.0)*180.0;

		fingers[4].potAverage[3] += mappings;

		smoothingCounter++;	

	}
}