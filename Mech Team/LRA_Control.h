#ifndef LRACON
#define LRACON

#include <Adafruit_DRV2605.h>


class LRA {

Adafruit_DRV2605 *lraDriver;
int multiplexerPort;

void tcaSelect(int port);

public:

LRA(int multiplexerPort_Input);

void playWaveForm(int effect);

};

#endif