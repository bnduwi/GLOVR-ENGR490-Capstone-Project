
struct Finger {

	int potPin[4];

	int potOpen[4];

	int potClosed[4];

	int potCurrent[4];

};


class Hand {

public:

	Finger fingers[5];

	Hand(int pins_Input[]); //Takes input pins in same order as the documentation except for the extra thumb pin 
							//which is placed at the end of the array;
	void calibrate();

	void update();


};


