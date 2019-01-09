#include<Servo.h>
Servo s;
void setup() {
  // put your setup code here, to run once:
pinMode(A0,INPUT);
s.attach(3);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
int c= analogRead(A0);
// 600-1023
float k= (c-600)/(1023.0-600.0);
int g= k*180;
if(g<0)
g=0;
else if(g>180)
g=180;
s.write(g);
Serial.print(g);
Serial.print("\n");
}
