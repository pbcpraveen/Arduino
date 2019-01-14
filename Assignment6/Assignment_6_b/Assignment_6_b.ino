void setup() {
  // put your setup code here, to run once:
  pinMode(10,OUTPUT);
  pinMode(A0,INPUT);
  Serial.begin(9600);
}
int duty_cycle=10;
int s1=1,s2=0,s3=0,s4=0,s5=0;
int level=1;
//int blinkled()
//{
  
//}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(10,200);
  Serial.println(analogRead(A0));
  Serial.println("\n");
  Serial.println(millis());
  
  
}
