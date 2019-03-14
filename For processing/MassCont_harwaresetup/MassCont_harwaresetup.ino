
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  pinMode(13,OUTPUT);
  lcd.begin(16,2);
}

void loop() {
  char data; //try int if u fail nigga :P
  if(Serial.available())
  {
   data=Serial.read();
   Serial.println(data);
  }
  if(data == 'a'){          
  digitalWrite(13,HIGH);
  }
  
//    if(data = "a"){
//      lcd.setCursor(0, 1);
//      lcd.print("one people");
//    }
//    if(data = "b"){
//     lcd.setCursor(0, 1);
//     lcd.print("two people"); 
//    }
  
}

