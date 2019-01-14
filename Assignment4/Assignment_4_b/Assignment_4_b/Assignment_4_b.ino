void setup() {
  // put your setup code here, to run once:
pinMode(2,OUTPUT);
Serial.begin(9600);

}
long int t1=0,t0=0,tp=0;
int d=100;
int period=2*d;
void blinkled()
{
  if((t1-t0)%(period)<d)
    digitalWrite(2,HIGH);
  else if((t1-t0)%(period)>d)
    digitalWrite(2,LOW);
  
  }


void loop() {
  // put your main code here, to run repeatedly:
t1= millis();
//Serial.println(t1);

  if(Serial.available()>0)
  {
    d=Serial.parseInt();
    if(Serial.read()=='\n'){
    t0=t1;
    period=2*d;
    }
  }
  blinkled();
  if((t1-tp)>=10000)
{
  tp=millis();
  Serial.println(d);
  }
}
