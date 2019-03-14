
#include <Servo.h> 

Servo shoummoservo;

Servo ratulservo;

int pos = 90;    // variable to store the servo position 
int pos1=90;
void setup() {

  char value;
  Serial.begin(38400);
  Serial1.begin(38400);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  shoummoservo.attach(9);  // attaches the servo on pin 9 to the servo object
  ratulservo.attach(10);

}

void loop() {
  char value;
  if (Serial1.available()) {
    value = Serial1.read();
    //Serial.write(value);
    Serial.println(value);
  }
  if (value=='8')
  {//forward
    //right motor
    analogWrite(2,120);
    digitalWrite(3,LOW);
    digitalWrite(4,HIGH);
    //left motor
    analogWrite(5,120);
    digitalWrite(6,LOW);
    digitalWrite(7,HIGH);
  }
  if (value=='4')
  {//RIGHT
    //right motor
    analogWrite(2,120);
    digitalWrite(3,HIGH);
    digitalWrite(4,LOW);
    //left motor
    analogWrite(5,120);
    digitalWrite(6,LOW);
    digitalWrite(7,HIGH); 
  }     

  if (value=='7')
  {//NORMAL RIGHT
    //right motor
    analogWrite(2,70);
    digitalWrite(3,LOW);
    digitalWrite(4,HIGH);
    //left motor
    analogWrite(5,120);
    digitalWrite(6,LOW);
    digitalWrite(7,HIGH);
  }

  if (value=='1')
  {//LEFT BACK
    //right motor
    analogWrite(2,70);
    digitalWrite(3,HIGH);
    digitalWrite(4,LOW);
    //left motor
    analogWrite(5,120);
    digitalWrite(6,HIGH);
    digitalWrite(7,LOW);
  }

  if (value=='6')
  {//LEFT
    //right motor
    analogWrite(2,120);
    digitalWrite(3,LOW);
    digitalWrite(4,HIGH);
    //left motor
    analogWrite(5,120);
    digitalWrite(6,HIGH);
    digitalWrite(7,LOW); 
  }

  if (value=='9')
  {//NORMAL LEFT
    //right motor
    analogWrite(2,120);
    digitalWrite(3,LOW);
    digitalWrite(4,HIGH);
    //left motor
    analogWrite(5,70);
    digitalWrite(6,LOW);
    digitalWrite(7,HIGH);
  }

  if (value=='3')
  {//RIGHT BACK
    //right motor
    analogWrite(2,120);
    digitalWrite(3,HIGH);
    digitalWrite(4,LOW);
    //left motor
    analogWrite(5,70);
    digitalWrite(6,HIGH);
    digitalWrite(7,LOW);
  }


  if (value=='2')
  {//BACKWARD
    //right motor
    analogWrite(2,120);
    digitalWrite(3,HIGH);
    digitalWrite(4,LOW);
    //left motor
    analogWrite(5,120);
    digitalWrite(6,HIGH);
    digitalWrite(7,LOW);
  }

  if (value=='0')
  {//STOP
    //right motor
    analogWrite(2,0);
    digitalWrite(3,LOW);
    digitalWrite(4,HIGH);
    //left motor
    analogWrite(5,0);
    digitalWrite(6,LOW);
    digitalWrite(7,HIGH);
  }

  if(value=='l')
  {

    pos=pos-5; 
    if(pos<10)
      pos=10;
    shoummoservo.write(pos);

    Serial.println(pos);
  }
  if(value=='x')
  {

    pos=pos+5;
    if(pos>120)
      pos=120;
    shoummoservo.write(pos);

    Serial.println(pos);
  }
  if(value=='m')
  {

    pos1=pos1+5;
    if(pos1>120)
      pos1=120;
    ratulservo.write(pos1);

    Serial.println(pos1);
  }
  if(value=='y')
  {

    pos1=pos1-5;
    if(pos1<10)
      pos1=10;
    ratulservo.write(pos1);

    Serial.println(pos1);
  }

}

