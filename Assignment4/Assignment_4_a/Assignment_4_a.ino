#include<ctype.h>
void setup() {
  pinMode(2,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  // put your setup code here, to run once:
Serial.begin(9600);
}
String a;
int num=0,s=0,b=0;
void blinkled()
{
  digitalWrite(2,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,HIGH);
  delay(60);
  digitalWrite(8,LOW);  
}
void check()
{
      Serial.println(a);
      int k= a.length();
      num=0;
      s=0;
      b=0;
      for(int i=0;i<k;i++)
      {
        if(isdigit(a[i]))
        {
          num=1;
          break;
        }
        else 
        {
          num=0;
          break;
        }
      }
      if(num!=1)
      {
        if(a.length()>=5)
        s=1;
        else {s=0;
        b=1;
        }
      }
      
        
}
void loop() {
  // put your main code here, to run repeatedly:
while(a==NULL) a = Serial.readStringUntil("\n");
check();
if(num==1)
   {
    digitalWrite(2,HIGH);
    digitalWrite(7,LOW);
    digitalWrite(8,LOW);
    } 
else if(s==1)
    {
      digitalWrite(7,HIGH);
    digitalWrite(2,LOW);
    digitalWrite(8,LOW);
     }
else if (b==1)
{
  
do
  {
    blinkled();
    delay(60);
    a=Serial.readStringUntil("\n");
    delay(60);
  }while(a==NULL);
}     
 if(num==1 || s==1)
  a = Serial.readStringUntil("\n");
  

}
