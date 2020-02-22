
struct finger {

	int potPin[4];

	int potOpen[4];

	int potClosed[4];

	int potCurrent[4];

};


class hand {

public:

	finger fingers[5];

	hand(int pins_Input[]); //Takes input pins in same order as the documentation except for the extra thumb pin 
							//which is placed at the end of the array;
	void calibrate();

	void update();


};


