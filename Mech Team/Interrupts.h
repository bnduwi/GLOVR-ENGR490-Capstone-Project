#ifndef INTERVALTIMERS
#define INTERVALTIMERS

IntervalTimer test1;

int value = 0;

void printyprint(){

	//motor1.speed();

}

void startInterrupts(){

	test1.begin(printyprint, 100000);


}



#endif