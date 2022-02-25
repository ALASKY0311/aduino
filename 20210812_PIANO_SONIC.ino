//귀갱피아노
void setup() {
  
 pinMode (5,OUTPUT);
 pinMode (4,INPUT);
 Serial.begin(9600);
 pinMode (6,OUTPUT);
}

void loop() {
  
 float duration =0;
 float distance =0;

 digitalWrite(5,HIGH);
 delay(10);
 digitalWrite(5,LOW);
 duration = pulseIn (4,HIGH);
 distance = ((float)(340*duration)/10000)/2; 
 if ( distance >= 0 and distance <= 7){
 tone(6,523);
 }
 else if( distance >= 8 and distance <= 15){
 tone(6,587);
 }
else if( distance >= 16 and distance <= 20){
 tone(6,659);
}
else{
  noTone(6);
  }
}
