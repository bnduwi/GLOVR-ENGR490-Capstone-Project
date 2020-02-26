#ifndef LRACON
#define LRACON

#include <Adafruit_DRV2605.h>


class LRA {

public:

Adafruit_DRV2605 *lraDriver;
int multiplexerPort;

//static Adafruit_DRV2605 lraDriver;

LRA(int multiplexerPort_Input);

void tcaSelect(int port);

void playWaveForm(int effect);

};

#endif