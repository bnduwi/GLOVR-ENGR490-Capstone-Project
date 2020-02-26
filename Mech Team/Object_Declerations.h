#include "Motor_Control.h"
//#include <Wire.h>
#include "Hand.h"
#include "interrupts.h"
#include "Serial_Communication.h"


Motor Motora(6,7,6.5,50,11,12,28.0,0x40);
LRA LRAa(0), LRAb(1), LRAc(2), LRAd(3), LRAe(4), LRAf(5), LRAg(6), LRA7g(7);
int potPinss[16] = {A9,A8,A7,A6,A3,A2,A1,A0,A22,A21,A20,A19,A18,A17,A16,A15}; 
Hand Hand1 (potPinss);