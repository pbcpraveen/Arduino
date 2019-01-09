void setup() {
  // put your setup code here, to run once:
  pinMode(5,OUTPUT);
  Serial.begin(9600);

}
int val=0;
void loop() {
  // put your main code here, to run repeatedly:
   
   int k=Serial.read();
   while(k==-1) k=Serial.read();;
   if(k>=48&&k<=58)
   {
    val= val*10+(k-48);
    }
   if(k==10)
   {   
   Serial.print(val);
   Serial.print("\n");
   analogWrite(5,val);
   val=0;
   }
}
