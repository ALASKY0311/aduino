//초음파 센서로 벽에 일정거리 가까워지면 경고음을 내면서 빨간색 불이 깜빡깜빡하는 대충 주차 도와주는 기계
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
void setup() {
 pinMode (5,OUTPUT);
 pinMode (4,INPUT);
 Serial.begin(9600);
 pinMode (6,OUTPUT);
 pinMode (9,OUTPUT);
 pinMode(10,OUTPUT);
 pinMode(11,OUTPUT);
 lcd.init();
 lcd.backlight();

}

void loop() {
 float duration =0;
 float distance =0;

 digitalWrite(5,HIGH);
 delay(10);
 digitalWrite(5,LOW);
 duration = pulseIn (4,HIGH);
 distance = ((float)(340*duration)/10000)/2;
 if( distance >= 0 and distance <= 7){

lcd.setCursor (1,1);
 lcd.print ("self destruct");
 digitalWrite(9,HIGH);
 digitalWrite(10,LOW);
 tone(6,659);
 delay(300);
 noTone(6);
 lcd.setCursor (1,1);
 lcd.print ("self destruct");
 delay(100);
  lcd.clear();
 
 
 }
else if( distance >= 8 and distance <= 15){

 lcd.setCursor (8,1);
 lcd.print ("danger");
 digitalWrite(10,HIGH);
 digitalWrite(9,HIGH);
 tone(6,659);
 delay(700);
 noTone(6);
  lcd.clear();
 delay(100);
 
}
else if( distance >= 16){
 lcd.setCursor (8,1);
 lcd.print ("safe");
 digitalWrite(10,HIGH);
 digitalWrite(9,LOW);
 noTone(6);
 delay(100);
 lcd.clear();

}
  }
