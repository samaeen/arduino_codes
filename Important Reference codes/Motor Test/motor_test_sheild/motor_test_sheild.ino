void setup()
{
pinMode(4,OUTPUT);  // put your setup code here, to run once:
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
pinMode(7,OUTPUT);
}

void loop()
{
//digitalWrite(4,HIGH);
//analogWrite(5,255);
//digitalWrite(7,HIGH);
//analogWrite(6,255);  
//delay(3000);
digitalWrite(4,LOW);
analogWrite(5,255);
digitalWrite(7,LOW);
analogWrite(6,255);  
delay(3000);
}
