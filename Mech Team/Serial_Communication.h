#include "LRA_Control.h"

class BeeriConnect{

private:

	char buffer[256];

	int bytesRead;

public:

	BeeriConnect();


	void update(LRA &LRAa);

	//static int createInt(int number1, int number2, int number3);

};