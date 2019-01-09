void setup() {
  // put your setup code here, to run once:
  pinMode(A0,INPUT);
  pinMode(A3,OUTPUT);
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  int c= analogRead(A0);
  //Serial.print(c);
  Serial.print("\n");
  int k= map(c,0,1023,0,255);
  Serial.print(k);
  analogWrite(A3,k);

}
