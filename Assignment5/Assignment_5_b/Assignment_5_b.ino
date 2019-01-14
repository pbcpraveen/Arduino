#include<stdio.h>
#include<string.h>
int b1=50;
int b2=50;
int b3=50;
long int t1=0,t2=0,t3=0,tp1=0,tp2=0,tp3=0;
long int t=0, p1=100,p2=100,p3=100;
void setup() {
  // put your setup code here, to run once:
pinMode(3,OUTPUT);
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
Serial.begin(9600);
}
void read_update()
{
  if(Serial.available()>0)
  {
  String s= Serial.readStringUntil("\n");  
  char c[s.length()+1];
  strcpy(c,s.c_str());
  char *t= strtok(c, " ");
  while(t!=NULL)
  {
   Serial.println(t);
    if(strcmp(t,"L1")==0)
    {
      t=strtok(NULL," ");
      b1=atoi(t);
    }
    else if(strcmp(t,"L2")==0)
    {
      t=strtok(NULL," ");
      b2=atoi(t);
    }
    else if(strcmp(t,"L3")==0)
    {
      t=strtok(NULL," ");
      b3=atoi(t);
    }
    Serial.println(t);
      t= strtok(NULL, " "); 
  }
  refresh();
  
}
  }
void refresh()
{
  tp1=t1;
  tp2=t2;
  tp3=t3;
  t1=millis();
  t2=millis();
  t3=millis();
  p1=2*b1;
  p2=2*b2;
  p3=2*b3;
  digitalWrite(2,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
   
}
void blinkledb1()
{
  if((t1-tp1)%(p1)<b1)
    digitalWrite(2,HIGH);
  else if((t1-tp1)%(p1)>b1)
    digitalWrite(2,LOW);
  }
  void blinkledb3()
{
  if((t3-tp3)%(p3)<b3)
    digitalWrite(8,HIGH);
  else if((t3-tp3)%(p3)>b3)
    digitalWrite(8,LOW);
  }
  void blinkledb2()
{
  if((t2-tp2)%(p2)<b2)
    digitalWrite(4,HIGH);
  else if((t2-tp2)%(p2)>b2)
    digitalWrite(4,LOW);
  }
  
void glow()
{
 // analogWrite(3,b1);
 // analogWrite(5,b2);
  //analogWrite(6,b3);
  blinkledb1();
  blinkledb2();
  blinkledb3();  
}
void loop() {
  // put your main code here, to run repeatedly:
read_update();
 t1=millis();
  t2=millis();
  t3=millis();
glow();

}
