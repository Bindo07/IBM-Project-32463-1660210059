int t =3;
int e =2;
void setup()
{
  Serial.begin(9600);
  pinMode(t,OUTPUT);
  pinMode(e,INPUT);
  pinMode(13,OUTPUT);
  pinMode(4,INPUT);
  pinMode(12,OUTPUT); 
}

void loop()
{
  // OBJECT DETECTION :
  digitalWrite(t,LOW);
  digitalWrite(t,HIGH);
  delayMicroseconds(10);
  digitalWrite(t,LOW);
  float dur=pulseIn(e,HIGH);
  float dis=(dur*0.0343)/2;
  Serial.print("Distance :");
  Serial.println(dis);
 
  // TEMPERATURE SENSING :
  
  double a = analogRead(A0);
  double c = (((a/1024)*5)-0.5)*100;
  Serial.print("Temp :");
  Serial.println(c);
  delay(2000);
  
  // MOTION DETECTOR
  
  int p = digitalRead(4);
  Serial.println(p);
  if(p)
    Serial.println("Motion Detected");
  delay(1000);
  
  // BUZZER 
  
  for(int i=0;i<=30000;i=i+10)
  {
    tone(12,i);
    delay(1000);
    noTone(12);
    delay(1000);
  }
  
  
}