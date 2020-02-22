#include "LRA_Control.h"
#include <Wire.h>





LRA::LRA(int multiplexerPort_Input){

	multiplexerPort = multiplexerPort_Input;

	lraDriver = new Adafruit_DRV2605();

	lraDriver->begin();

	lraDriver->selectLibrary(1);

	lraDriver->setMode(DRV2605_MODE_INTTRIG);

}


void LRA::tcaSelect(int port){


	Wire.beginTransmission(0x70);
	Wire.write(1 << port);
	Wire.endTransmission();

}

void LRA::playWaveform(int effect){


	LRA::tcaSelect(multiplexerPort);

	LRA::lraDriver->begin();

	LRA::lraDriver->selectLibrary(1);

	LRA::lraDriver->setMode(DRV2605_MODE_INTTRIG);

	LRA::lraDriver->setWaveform(0,effect);

	LRA::lraDriver->go();


}

