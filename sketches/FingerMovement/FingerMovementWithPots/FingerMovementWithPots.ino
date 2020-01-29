void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // Analog pin A0
  int sensorA0 = analogRead(A0);
  
  // Analog pin A1
  int sensorA1 = analogRead(A1);
  
  // Analog pin A2
  int sensorA2 = analogRead(A2);
  
  // Analog pin A3
  int sensorA3 = analogRead(A3);
  
  // Analog pin A4
  int sensorA4 = analogRead(A4);
  
  // Analog pin A5
  int sensorA5 = analogRead(A5);
  
  // Analog pin A6
  int sensorA6 = analogRead(A6);  
  
  // Analog pin A7
  int sensorA7 = analogRead(A7);

  // Map the values read to a number between 0 and 360
  int mapA0 = map(sensorA0,0,1023,0,180);
  int mapA1 = map(sensorA1,0,1023,0,180);
  int mapA2 = map(sensorA2,0,1023,0,180);
  int mapA3 = map(sensorA3,0,1023,0,180);
  int mapA4 = map(sensorA4,0,1023,0,180);
  int mapA5 = map(sensorA5,0,1023,0,180);
  int mapA6 = map(sensorA6,0,1023,0,180);
  int mapA7 = map(sensorA7,0,1023,0,180);

  
  // Create the string line to send to serial
  String line = "a1:" + String(mapA0) + 
               ";b1:" + String(mapA1) + 
               ";c1:" + String(mapA2) + 
               ";d1:" + String(mapA3) + 
               ";a2:" + String(mapA4) + 
               ";b2:" + String(mapA5) + 
               ";c2:" + String(mapA6) + 
               ";d2:" + String(mapA7);

  // Write the data to serial with IDs
  Serial.println(line);
  //delay(10);
}
