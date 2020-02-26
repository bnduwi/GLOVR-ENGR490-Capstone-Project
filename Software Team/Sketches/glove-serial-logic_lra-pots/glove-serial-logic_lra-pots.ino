#include <Wire.h>
#include "Adafruit_DRV2605.h"

Adafruit_DRV2605 drv;

unsigned long last_time = 0;
int sensorA0;
int sensorA1;
int sensorA2;

void setup() {
  Serial.begin(9600);
  Serial.println("DRV Test With Unity");
  
  drv.begin();  
  drv.selectLibrary(1);
  
  /* I2C trigger by sending 'go' command 
   * default, internal trigger when sending GO command
   */ 
  drv.setMode(DRV2605_MODE_INTTRIG); 

}

void loop() {
  // Setup the pins for the pots
  sensorA0 = analogRead(A0);
  sensorA1 = analogRead(A1);
  sensorA2 = analogRead(A2);

  // Map the values and prepare string to send to simulation
  String unityPotsData = "a1:" + String(map(sensorA0,0,1023,0,180)) + 
               ";b1:" + String(map(sensorA1,0,1023,0,180)) + 
               ";c1:" + String(map(sensorA2,0,1023,0,180));
               
  // Write the data to serial with IDs
  Serial.println(unityPotsData);
  
   // Print a heartbeat (For SerialController in Unity)
    if (millis() > last_time + 2000){
        //Serial.println("Arduino is alive!!");
        last_time = millis();
    }

    // Cases to deal with triggering the correct vibration motor
    // along with the patterns to play
    switch (Serial.read()){
        case 'a':
            //Serial.println("Recieved A");
            drv.setWaveform(0, 1);
            drv.setWaveform(2, 0); 
            break;
        case 'b':
            //Serial.println("Recieved B");
            drv.setWaveform(0, 55);
            drv.setWaveform(1, 0);
            break;
        case 'c':
            //Serial.println("Recieved C");
            drv.setWaveform(0, 119);
            drv.setWaveform(1, 0);
            break;
    }

  // Play the effect!
  drv.go();

}
