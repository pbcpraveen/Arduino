int b1= 2;
int b2= 4;
int b3= 8;
int sr= 5;
int sl= 3;
int dir = 1;
int period=500;
// I assume 1 to represent r->l and -1 to represent l->r
long int t = 0;
int long ct=0;

void setup() {
  // put your setup code here, to run once:
  pinMode(b1,OUTPUT);
  pinMode(b2,OUTPUT);
  pinMode(b3,OUTPUT);
  pinMode(sl,INPUT);
  pinMode(sr,INPUT);
}/*
int glow_left_right()
{
  int t3= period/3;
  int t2= 2*period/3;
  int t1 = period-t3-t2;
  if(t<t3)
  {
    digitalWrite(b1,LOW);
    digitalWrite(b2,LOW);
    digitalWrite(b3,HIGH);
    }
    else if(t<t2)
  {
    digitalWrite(b1,LOW);
    digitalWrite(b2,HIGH);
    digitalWrite(b3,LOW);
    }
    
    else 
  {
    digitalWrite(b1,HIGH);
    digitalWrite(b2,LOW);
    digitalWrite(b3,LOW);
    }
  }
int glow_right_left()
{
  int t1= period/3;
  int t2= 2*period/3;
  int t3 = period-t1-t2;
  if(t<t1)
  {
    digitalWrite(b1,HIGH);
    digitalWrite(b2,LOW);
    digitalWrite(b3,LOW);
    }
    else if(t<t2)
  {
    digitalWrite(b1,LOW);
    digitalWrite(b2,HIGH);
    digitalWrite(b3,LOW);
    }
    
    else 
  {
    digitalWrite(b1,LOW);
    digitalWrite(b2,LOW);
    digitalWrite(b3,HIGH);
    }
  }
  */
  void glow()
  { int a1=0,a0=1,a2=0;
    if(dir ==0)
    {
      a1=0;a2=0;a0=1;
      }
      else if(dir ==1)
      {a1=1;a2=0;a0=0;}
      else
      {a1=0,a2=1;a0=0;}
      digitalWrite(b1,a0);
      digitalWrite(b3,a2);
      digitalWrite(b2,a1);
    }
void loop() {
  // put your main code here, to run repeatedly:
 //ct=millis();
 //t=ct%period;
 int k1=digitalRead(sr);
 int k2= digitalRead(sl);
 if(k1==1)
 {
  while(k1==1) k1=digitalRead(sr);
 
  dir = (dir+1)%3;
  }
 if(k2==1)
 {
  while(k2==1) k2=digitalRead(sl);
  dir --;
  Serial.println(k2);
  if(dir ==-1)
  dir =2;
  
  }
  /*
  if(dir==-1)
 glow_left_right();
 else 
 glow_right_left();
 */
 glow();
}
