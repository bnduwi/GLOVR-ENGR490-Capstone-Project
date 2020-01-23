// Analog read with Serial Monitor
const int butPin1 = 6;
const int butPin2 = 7;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); //initialize serial communication at 9600 bits per second

  pinMode(butPin1, INPUT);
  pinMode(butPin2, INPUT);

  digitalWrite(butPin1, HIGH);
  digitalWrite(butPin2, HIGH);  
}

void loop() {
  // put your main code here, to run repeatedly:
  /*int sensorValue = analogRead(A0); // read the input on the analog pin
  Serial.println(sensorValue); // print out the value you read
  delay(10); //delay in between reads for stability*/

  if(digitalRead(butPin1) == LOW){
    //Serial.println("LEFT");
    Serial.write(1);
    Serial.flush();
    delay(20);
  }

  if(digitalRead(butPin2) == LOW){
    //Serial.println("RIGHT");
    Serial.write(2);
    Serial.flush();
    delay(20);
  }
  
}
