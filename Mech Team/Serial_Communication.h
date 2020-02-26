#ifndef SERIALCOM
#define SERIALCOM

#include "LRA_Control.h"
#include "Motor_Control.h"

class BeeriConnect{

private:

	char buffer[256];

	int bytesRead;

public:

	BeeriConnect();


	void update(LRA *inputLRAs, Motor *inputMotors);

	//static int createInt(int number1, int number2, int number3);

};

#endif