void setup() {
  // put your setup code here, to run once:
 pinMode(A0,INPUT);
 pinMode(2,OUTPUT);
 pinMode(4,OUTPUT);
 pinMode(8,OUTPUT);
 Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
 long int k= analogRead(A0);
 float m= k/1023.0;
 int mapped = m*255;
 //mapped=251;
 Serial.print(mapped);
 Serial.print("\n");
 if(mapped == 0)
 {
  digitalWrite(8,HIGH);
  digitalWrite(2,LOW);
  digitalWrite(4,LOW);
  }
  else if(mapped > 245)
  {
    digitalWrite(2,HIGH);
  digitalWrite(4,LOW);
  digitalWrite(8,LOW);
    }
    else
    {
      digitalWrite(4,HIGH);
      digitalWrite(2,LOW);
      digitalWrite(8,LOW);
      }
}
