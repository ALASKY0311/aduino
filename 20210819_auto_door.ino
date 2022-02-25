//손대면 서보 모니터가 돌아가서 열리는 것
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
#include <Servo.h>
Servo myservo;
void setup() {
  myservo.attach(3);
  myservo.write(0);
  pinMode (5,OUTPUT);
  pinMode (4,INPUT);
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
 if( distance >= 0 and distance <= 10){
  lcd.setCursor(0,0);
  lcd.print ("open");
  myservo.write(180);
  delay(2000);
  myservo.write(0);
  lcd.clear();
 }
  else{
     lcd.setCursor(0,0);
    lcd.print("closed");
    delay(100);
    lcd.clear();
    }
  }
