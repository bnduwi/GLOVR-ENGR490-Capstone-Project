#include <Servo.h>
Servo servo0;

double val = 0;
double ang = 0;
double val_to_angle = 3 .001/50;

double angle = 0;
int servoangle = 0;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
Serial.println(val_to_angle);
servo0.attach(9);
servo0.write(90);
}

void loop() {
delay(1); 
  
  // put your main code here, to run repeatedly:

double sumang = 0;
Serial.print("Time in milliseconds: ");
Serial.println(millis());
for (int x = 0; x < 10; x = x + 1){
val = analogRead(A2) + analogRead(A1) + analogRead(A0);  // read the input pin
  Serial.println(val);
ang = ((val*val_to_angle)-60);
//Serial.println(ang);
  
  sumang = sumang + ang;
  }
  Serial.print("Time in milliseconds: ");
  Serial.println(millis());
angle = sumang/10;
servoangle = angle;
Serial.println(servoangle);
servo0.write(servoangle);  
}
