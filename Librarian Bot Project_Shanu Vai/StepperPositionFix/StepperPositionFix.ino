#include <Stepper.h>

const int stepsPerRevolution = 170;
Stepper myStepper(stepsPerRevolution, 8,9,10,11);            

void setup() {

  myStepper.setSpeed(60);
  char value;
  Serial.begin(9600);
  Serial1.begin(9600);
}

void loop() {
    char value;
  if (Serial1.available()) {
    value = Serial1.read();
    //Serial.write(value);
    Serial.println(value);
  }
if(value=='1'){
  Serial.println("counterclockwise");
  myStepper.step(-stepsPerRevolution);
  delay(500);
  myStepper.setSpeed(60);
}
if(value=='2'){
  Serial.println("counterclockwise");
  myStepper.step(-stepsPerRevolution);
  delay(800);
  myStepper.setSpeed(0);
  
}
if(value=='3'){
  Serial.println("counterclockwise");
  myStepper.step(-stepsPerRevolution);
  delay(500); 
}
if(value=='4'){
  Serial.println("counterclockwise");
  myStepper.step(-stepsPerRevolution);
  delay(500); 
}
}

