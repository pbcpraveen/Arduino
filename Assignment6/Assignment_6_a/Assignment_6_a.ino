int bulb = 2;
int play = 4;
int record = 6;
long int a[100];
long int n=0;
long int start=0,stop_time=0;
void setup() {
  // put your setup code here, to run once:
  pinMode(bulb,OUTPUT);
  pinMode(play,INPUT);
  pinMode(record,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int k= digitalRead(play);
   //Serial.println(k);
  if(k==1)
  {
    while(k==1) k = digitalRead(play);
    Serial.println("Recording started");
    start=millis();
    stop_time=millis();
    int change = 0;
    int b = digitalRead(record);
    int pre=b;
    while(k!=1)
    {
       digitalWrite(bulb,b);
       if(pre!=b)
       {
        change=1;
       }   
       else change =0;
       if(change==1)
       {
        stop_time=millis();
        a[n]=  stop_time-start;
        start=stop_time;
        n++;
        
       }
       pre=b;
       b=digitalRead(record);
       k=digitalRead(play); 
    }  
    Serial.println("Recording Stopped");
    stop_time=millis();
    a[n]=stop_time-start;
    n++;
    int state=0;
    start=millis();
    stop_time=millis();

    while(k==1) k = digitalRead(play);
   
    for(int i =0; i<n;i++)
    {
      while((stop_time-start)!=a[i])
        {
          digitalWrite(bulb,state);
          stop_time=millis();
        }
       state = (state == 1 ? 0 : 1);
      stop_time = millis();
      start = millis();
      
    }
    n=0;
  }
  
  

}
