
#include <Servo.h> 
 
Servo shoummoservo;  // create servo object to control a servo 
                // twelve servo objects can be created on most boards
Servo ratulservo;

int pos = 0;    // variable to store the servo position 

void setup() {
   
      int value;
      Serial.begin(38400);
      Serial1.begin(38400);
      pinMode(12,OUTPUT);
      pinMode(13,OUTPUT);
      pinMode(10,OUTPUT);
      pinMode(11,OUTPUT);
      shoummoservo.attach(9);  // attaches the servo on pin 9 to the servo object
      ratulservo.attach(10);  // attaches the servo on pin 10 to the servo object
}

void loop() {
  int value;
   
  if (Serial1.available()) {
   value = Serial1.read();
    Serial.write(value);
  }
  if (value=='8')
          {
                 digitalWrite(12,HIGH);  // left motor  (Forward)
                 analogWrite(10,250);
                 digitalWrite(13,HIGH); // right motor
                 analogWrite(11,246);
          }
  if (value=='6')
         {
                 digitalWrite(12,HIGH);  // left motor  (hard right TURN)
                 analogWrite(10,250);
                 digitalWrite(13,LOW); // right motor
                 analogWrite(11,200);
         }     
  
   if (value=='9')
         {
                 digitalWrite(12,HIGH);  // left motor  (right TURN)
                 analogWrite(10,250);
                 digitalWrite(130,LOW); // right motor
                 analogWrite(11,50);
         }
    if (value=='3')
         {
                 digitalWrite(12,LOW);  // left motor  (backward Right TURN)
                 analogWrite(10,250);
                 digitalWrite(13,HIGH); // right motor
                 analogWrite(11,50);
         }
         
    
   if (value=='7')
    {
                 digitalWrite(12,HIGH);  // left motor  (left TURN)
                 analogWrite(10,50);
                 digitalWrite(13,HIGH); // right motor
                 analogWrite(11,250);
    }
    if (value=='4')
    {
                 digitalWrite(12,LOW);  // left motor  (hardleft TURN)
                 analogWrite(10,150);
                 digitalWrite(13,HIGH); // right motor
                 analogWrite(11,250);
    }
    
    
    if (value=='2')
    {
                 digitalWrite(12,LOW);  // left motor  (back)
                 analogWrite(10,250);
                 digitalWrite(13,LOW); // right motor
                 analogWrite(11,250);

    }
    if (value=='1')
         {
                 digitalWrite(12,HIGH);  // left motor  (backward left TURN)
                 analogWrite(10,50);
                 digitalWrite(13,LOW); // right motor
                 analogWrite(11,250);
         }
    if (value=='0')
    {
                 digitalWrite(12,LOW);  // left motor  (stop)
                 analogWrite(10,0);
                 digitalWrite(13,LOW); // right motor
                 analogWrite(11,0);

    }
  if(value='11') //servo up
  {
  for(pos = 0; pos <= 10; pos += 5)  
  {                                 
    shoummoservo.write(pos);              
    delay(10);                      
  }
  }
 if (value='10')  //servo down
  {
  for(pos = 180; pos>=0; pos-=1)     
  {                                
    shoummoservo.write(pos);             
    delay(10);                      
  }
  }
    if(value='12') //servo up
  {
  for(pos = 0; pos <=180; pos += 5)  
  {                                 
    ratulservo.write(pos);              
    delay(10);                      
  }
  }
 if (value='13')  //servo down
  {
  for(pos = 180; pos>=0; pos-=1)     
  {                                
    ratulservo.write(pos);             
    delay(10);                      
  }
  }


  // read from port 0, send to port 1:
    if (Serial.available()) {
    int value = Serial.read();
    Serial1.write(value);
  }
}
