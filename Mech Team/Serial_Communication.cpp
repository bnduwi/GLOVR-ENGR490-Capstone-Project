#include"Serial_Communication.h"
#include <arduino.h>
#include <string.h>
#include <stdlib.h> 


///Formatting l,a,123$

BeeriConnect::BeeriConnect(){

	Serial.begin(19200);

}

void BeeriConnect::update(LRA &LRAa){

	Serial.print("\nupdating");

	bytesRead = Serial.readBytesUntil('$', buffer, 256);

				//Serial.print(bytesRead);

	buffer[bytesRead + 1] = NULL;

	int miniBuffer;

	char *strParse;

	char test;

	strParse = strtok (buffer, ",");

	Serial.printf(strParse);

	strParse = strtok (NULL, ",");

	Serial.printf(strParse);

	strParse = strtok (NULL, ",");

	miniBuffer = atoi(strParse);

	Serial.print(2*miniBuffer);

	// switch(miniBuffer[0]){


	// 	case 'l':

	// 		switch(miniBuffer[1]){

	// 			case 'a':

	// 				LRAa.playWaveForm(miniBuffer[2]);

	// 			// case 'b':

	// 			// case 'c':

	// 			// case 'd':

	// 			// case 'e':

	// 			// case 'h':

	// 			// case 'f':

	// 			// case 'g':



	// 		}

		//case 'f':


	//}





	// while (miniBuffer != NULL){


	// 	switch(miniBuffer){

	// 		case l:



	// 		case f:

	// 		default:





	// 	}


	// 	miniBuffer = strtok (NULL, ",")
	// }









	// while ( i < bytesRead ){

	// 	switch(buffer[i]) {

	// 		case 'a':


	// 			if ( buffer[i+1] == ",") { //if the second char is a comma we know its the LRA value

	// 				int waveFormValue = createInt( buffer[i+2], buffer[i+3], buffer[i+4] );

	// 				i += 5;

	// 				Serial.print(waveFormValue);

	// 			}

	// 			else if ( buffer[i+1] == forceMarker ){ //if its t we know its a force value

	// 				int forceValue = createInt( buffer[i+2], buffer[i+3], buffer[i+4] );

	// 				i += 6;

	// 				Serial.print(forceValue);
	// 			}

	// 			else {

	// 				break;

	// 			}


			

	// 		// case 'b':

	// 		// case 'c':

	// 		// case 'd':

	// 		// case 'e':

	// 		// case 'h':

	// 		// case 'f':

	// 		// case 'g':

	// 		default:

	// 			break;



	// 	}


	// }

}


// int BeeriConnect::createInt(int number1, int number2, int number3){

// 	return (number1*100) + (number2*10) + (number3*1); //assume that we are always recieving three ints
// 													   // 1*100 + 3*10 + 5*1= 135


// }