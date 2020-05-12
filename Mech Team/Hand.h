#ifndef HANDS
#define HANDS

#include "Motor_Control.h"

struct Finger {

	int potPin[4];

	int potOpen[4];

	int potClosed[4];

	int potCurrent[4];

	int potPrevious[4];

	int potAverage[4];

};


class Hand {

public:

	int smoothingCounter = 0, smoothingValue = 150;

	Finger fingers[5];

	Hand(int pins_Input[]); //Takes input pins in same order as the documentation except for the extra thumb pin 
							//which is placed at the end of the array;
	void calibrate();

	void update(Motor *Motors);

};


#endif