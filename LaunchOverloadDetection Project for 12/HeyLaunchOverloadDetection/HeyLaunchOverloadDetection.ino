#include <SoftwareSerial.h>      //GSM
SoftwareSerial mySerial(9, 10);  //Rx/Tx
void setup()
{
  pinMode(5,INPUT);
  pinMode(6,INPUT);
  pinMode(7,INPUT);
  mySerial.begin(19200);   
  Serial.begin(19200);    
  delay(500);
}
void loop()
{
  int a=digitalRead(5);
  int b=digitalRead(6);
  int c=digitalRead(7);
  
if(a==1 && b==1 && c==0){
  Serial.println("Danger!!!");
  delay(1000);
}
if(a==1 && b==1 && c==1){
  SendTextMessage();
  }  
}
void SendTextMessage()    //send a message(3)
{
  Serial.println("Message");
  mySerial.println("AT+CMGF=1");   
  delay(2000);
  mySerial.println("AT+CMGS=\"+8801738833277\"\r"); // change to the phone number you using 
  delay(2000);
  mySerial.println("Launch overload limit !");//the content of the message
  delay(200);
  mySerial.println((char)26);
  delay(2000);
  mySerial.println("AT+CMGD=1,4");
  delay(2000);
  Serial.println("Message");
}
