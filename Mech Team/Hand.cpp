
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

void Hand::update(){


	for (int i = 0; i < 5; i++){

		for(int s = 0; s < 3; s++){


			if (smoothingCounter == smoothingValue){

				fingers[i].potCurrent[s] = (fingers[i].potPrevious[s]/smoothingValue);

				fingers[i].potPrevious[s] = 0;

			}

			else{

				//int mapping = map(analogRead(fingers[i].potPin[s]), 0, 1023, 0, 180);

				double mapping = (analogRead(fingers[i].potPin[s])/1023.0)*180.000000;

				fingers[i].potPrevious[s] = mapping + fingers[i].potPrevious[s];

			}

		}

	}

	if(smoothingCounter == smoothingValue){

		fingers[4].potCurrent[3] = (fingers[4].potPrevious[3]/smoothingValue);

		fingers[4].potPrevious[3] = 0;

		smoothingCounter = 0;

	}

	else{

		//int mappings = map(analogRead(fingers[4].potPin[3]), 0, 1023, 0, 180);

		double mappings = (analogRead(fingers[4].potPin[3])/1023.0)*180.0;

		fingers[4].potPrevious[3] += mappings;

		smoothingCounter++;	

	}
	

}