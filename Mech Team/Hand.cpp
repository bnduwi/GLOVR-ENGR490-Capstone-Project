
#include "hand.h"
#include <arduino.h>



hand::hand(int pins_Input[]){

	for (int i = 0; i < 5; i++){

		for(int s = 0; s < 3; s++){

		fingers[i].potPin[s] = pins_Input[((i * 3) + s)];

		}

	}

	fingers[4].potPin[3] = pins_Input[15];

}

void hand::update(){

	for (int i = 0; i < 5; i++){

		for(int s = 0; s < 3; s++){

		fingers[i].potCurrent[s] = analogRead(fingers[i].potPin[s]);                 //pins_Input[((i * 3) + s)];

		}

	}

	fingers[4].potCurrent[3] = analogRead(fingers[4].potPin[3]);

}