IntervalTimer test1;

int value = 0;

void printyprint(){

	value++;

}

void startInterrupts(){

	test1.begin(printyprint, 100000);


}



