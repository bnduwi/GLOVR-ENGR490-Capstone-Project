#ifndef SERIALCOM
#define SERIALCOM

#include "LRA_Control.h"
#include "Motor_Control.h"
#include "Hand.h"

class BeeriConnect{

private:

	char buffer[256];

	int bytesRead;

public:

	BeeriConnect();

	void updateSend(Hand *inputHand);

	void updateRecieve(LRA *inputLRAs, Motor *inputMotors);


};

#endif