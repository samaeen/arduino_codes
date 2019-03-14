
#include <Servo.h> 
 
Servo shoummoservo;  // create servo object to control a servo 
                // twelve servo objects can be created on most boards
Servo ratulservo;

int pos = 90;    // variable to store the servo position 
int pos1=90;
void setup() {
   
      char value;
      Serial.begin(38400);
      Serial1.begin(38400);
   pinMode(4,OUTPUT);  // put your setup code here, to run once:
pinMode(7,OUTPUT);
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
          {
 digitalWrite(4,HIGH);
analogWrite(5,255);
digitalWrite(7,HIGH); //forward
analogWrite(6,255); 
          }
  if (value=='4')
         {
       digitalWrite(4,HIGH);
analogWrite(5,155);                     //Right
digitalWrite(7,LOW);
analogWrite(6,155); 
         }     
         
           if (value=='7')
         {
       digitalWrite(4,HIGH);
analogWrite(5,155);                     //  NORMAL Right
digitalWrite(7,HIGH);
analogWrite(6,50); 
         }
         
           if (value=='1')
         {
       digitalWrite(4,LOW);
analogWrite(5,155);                     //  Left back
digitalWrite(7,LOW);
analogWrite(6,50); 
         }
   
    if (value=='6')
    {
       digitalWrite(4,LOW);
analogWrite(5,155);                     //Left
digitalWrite(7,HIGH);
analogWrite(6,155); 
    }
    
      if (value=='9')
    {
       digitalWrite(4,HIGH);
analogWrite(5,50);                     // NORMAL Left
digitalWrite(7,HIGH);
analogWrite(6,155); 
    }
    
         if (value=='3')
    {
       digitalWrite(4,LOW);
analogWrite(5,50);                     // Right back
digitalWrite(7,LOW);
analogWrite(6,155); 
    }
    
    
    if (value=='2')
    {
     digitalWrite(4,LOW);
analogWrite(5,255);
digitalWrite(7,LOW);
analogWrite(6,255);             //backward

    }

    if (value=='0')
    {
          digitalWrite(4,LOW);
analogWrite(5,0);
digitalWrite(7,LOW);
analogWrite(6,0);             //stop

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
 
 pos=pos+7;
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
