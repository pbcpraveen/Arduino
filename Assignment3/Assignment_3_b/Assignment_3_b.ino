void setup() {
  // put your setup code here, to run once:
pinMode(7,OUTPUT);
pinMode(8,OUTPUT);
pinMode(4,OUTPUT);

}
int time=0;
void glow()
{
  int a0=time%10==0?1:0;
  int a1=time%100==0?1:0;
  int a2=time%1000==0?1:0;
  digitalWrite(7,a0);
  digitalWrite(8,a1);
  digitalWrite(4,a2);
  delay(50);
  
  }
void loop() {
  // put your main code here, to run repeatedly:
glow();
if(time==1000)
time=1;
time++;
}
