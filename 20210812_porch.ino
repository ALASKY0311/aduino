//초음파센서로 일정한 거리까지 닿으면 불빛이남
void setup() {
 pinMode (5,OUTPUT);
 pinMode (4,INPUT);
 pinMode (11,OUTPUT);
 pinMode (10,OUTPUT);
 pinMode (9,OUTPUT);
 Serial.begin(9600);
 
}

void loop() {
 float duration =0;
 float distance =0;

 digitalWrite(5,HIGH);
 delay(10);
 digitalWrite(5,LOW);
 duration = pulseIn (4,HIGH);
 distance = ((float)(340*duration)/10000)/2; 
 
 Serial.print (distance);
 Serial.println ("cm"); 
 if (distance <= 10){
  digitalWrite(9,HIGH);
  digitalWrite(10,HIGH);
  digitalWrite(11,HIGH);
  delay(5000);
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
  }



}
