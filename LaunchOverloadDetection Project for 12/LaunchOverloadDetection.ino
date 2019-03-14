#include <SoftwareSerial.h>      //GSM
SoftwareSerial mySerial(9, 10);  //Rx/Tx
void setup()
{
  pinMode(A8,INPUT);
  mySerial.begin(19200);   
  Serial.begin(19200);    
  delay(500);
}
void loop()
{
  int a=analogRead(A8);
if(a<=90){
  Serial.println(a);
  delay(1000);
}
if(a>=90){  
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
