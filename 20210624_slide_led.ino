//슬라이드의 값에 따라 바뀌는 LED
void setup() {
 Serial.begin(9600);
pinMode (9,OUTPUT);
pinMode (10,OUTPUT);
pinMode (11,OUTPUT);
}

void loop() {
Serial.println (analogRead (A0));
int slide = analogRead(A0);
if (slide <= 300){
  digitalWrite(9,HIGH);
  digitalWrite(10,LOW);
}
else if(slide <= 600){
  digitalWrite(9,HIGH);
  digitalWrite(10,HIGH);
  digitalWrite(11,LOW);
  }
else if(slide <= 800){
  digitalWrite(9,HIGH);
  digitalWrite(11,HIGH);
  digitalWrite(10,LOW);
    }
else if(slide <= 1000){
  digitalWrite(9,LOW);
  digitalWrite(10,HIGH);
  digitalWrite(11,HIGH);
      }
else if(slide >= 1001){
  digitalWrite(9,HIGH);
      }
}
