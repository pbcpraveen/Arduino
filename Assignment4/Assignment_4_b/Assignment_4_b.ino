#include<string.h>

void setup() 
{
  // put your setup code here, to run once:
  pinMode(2,OUTPUT);
  Serial.begin(9600);
}
int d = 30;
long int t0=0;
long int t1=0;
long int p=0;
void loop() 
{
  // put your main code here, to run repeatedly:
  String a =Serial.readStringUntil("\n");
  if(a!=NULL)
  {
    char n[20];
    for(int i=0;i<a.length();i++)
    n[i]=a[i];
    d=(atoi(n))*1000;
    t0=t1;
  }
  if((t1-t0)%(2*d)<d)
    digitalWrite(2,HIGH);
  else if((t1-t0)%(2*d)>d)
    digitalWrite(2,LOW);
  t1=millis();
  
  if((t1-p)>10000)
  {
    Serial.println(d);
    t0=t1;
    p=millis();
  }
  
}
