#include <Servo.h>
Servo shanuservo;
Servo saikatservo;
int pos =0;
int pos1=0;
void setup(){
  char value;
  Serial.begin(9600);
  Serial1.begin(9600);
  shanuservo.attach(12);
  saikatservo.attach(24);
}
void loop(){
  servoRotationLift();
  //servoRotatioKhola();
  servoRotationDhora();
  
}
void servoRotationLift(){
    pos=40;                
    saikatservo.write(pos);
           
}
void servoRotationDhora(){
    pos1=180;  
    shanuservo.write(pos1);   
}
void servoRotatioKhola(){
    pos1=60;  
    shanuservo.write(pos1);    
}
