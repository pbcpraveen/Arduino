void setup() {
  // put your setup code here, to run once:
pinMode(7,OUTPUT);
pinMode(4,OUTPUT);
pinMode(8,OUTPUT);
pinMode(2,INPUT);
Serial.begin(9600);
}
int state=0;
void glow()
{
  int a0,a1,a2;
  int k= state;
  a0=k%2;
  k/=2;
  a1=k%2;
  k/=2;
  a2=k%2;
  digitalWrite(7,a2);
  digitalWrite(8,a1);
  digitalWrite(4,a0);
  
  }
void loop() {
  // put your main code here, to run repeatedly:
int c=digitalRead(2);
if(c==1)
{
  while (c==1)
  {
    c=digitalRead(2);
    Serial.print(c);
    Serial.print("\n");
    };
  state=state+1;
  if(state==8)
  state=0;
  }
glow();
}
