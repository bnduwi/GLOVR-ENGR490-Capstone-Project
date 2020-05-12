#include "Motor_Control.h"
#include "Hand.h"
#include "Serial_Communication.h"
#include "LRA_Control.h"

#define MOTOR_IN1 6 
#define MOTOR_IN2 7

Motor Motors[1] = {Motor(6,7,6.5,50,11,12,28.0,0x40)};
int potPinss[16] = {A9,A8,A7,A6,A3,A2,A1,A0,A22,A21,A20,A19,A18,A17,A16,A15}; 
Hand Hand1 (potPinss);
BeeriConnect Beeri;
LRA LRAs[8] = {0,1,2,3,4,5,6,7};
IntervalTimer speedInterrupt, serialSendInterrupt, serialRecieveInterrupt, motorModeInterrupt, currentReadingInterrupt;
int counter;

void startInterrupt();

void motorSpeedReferesh();

void serialRefereshSend();

void serialRefereshRecieve();

void motorModeUpdate();

void potUpdate();

void currentReadingUpdate();


void setup() {

  startInterrupt();

}

void loop(){
}


void startInterrupt(){

  speedInterrupt.begin(motorSpeedReferesh, 3500); //originally 1000 before testing the current stuff
  speedInterrupt.priority(120); //was 140 before testing
  serialSendInterrupt.begin(serialRefereshSend, 600); ///update still gets paused on recieve, it we recieve too many lra
  serialSendInterrupt.priority(125);
  serialRecieveInterrupt.begin(serialRefereshRecieve, 100); 
  serialRecieveInterrupt.priority(125); // recieving needs to be lower priority then the sending or else the sending pauses when a value is recieved
  motorModeInterrupt.begin(motorModeUpdate, 190000);
  motorModeInterrupt.priority(255);

  // currentReadingInterrupt.begin(currentReadingUpdate, 5000);
  // currentReadingInterrupt.priority(120);

}

void motorSpeedReferesh(){

  Motors[0].speed(Motors, 0); // 10 microseconds

  int currentHolder = Motors[0].readCurrent(); //one takes 2200 micros

}

void serialRefereshRecieve(){ //0-1 micro when not revieving and 5400 when decoding a command

  Beeri.updateRecieve(LRAs, Motors);

}

void serialRefereshSend(){ 

  Hand1.update(Motors); // 164 - 184 micros

  if(counter == 100){

    Beeri.updateSend(&Hand1);//takes around 50-80 microseconds 
    counter = 0;

  }

  counter++;


}

void motorModeUpdate(){

  Motors[0].modeControl(); //very long time 183352 microseconds, probably due to current sensor 

}


