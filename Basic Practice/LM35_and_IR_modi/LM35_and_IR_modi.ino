int ref,a1,b1;
float temp;
float tempa;
void setup(){
Serial.begin(9600);
pinMode(A0,INPUT);
pinMode(A1,INPUT);
pinMode(A2,INPUT);
pinMode(12,OUTPUT);
}
void loop(){
  ref=500;
  a1=analogRead(A0);
  b1=analogRead(A2);
  tempa=analogRead(A1);
  temp= tempa*0.48828125;
 // Serial.println(temp);
//if(a1>ref && b1>ref){
//  digitalWrite(12,LOW);
//  Serial.println("as usual");
//}
if(a1<ref && b1>ref){
  while(a1<ref){
  a1=analogRead(A0);
  Serial.println("1");
  }
  while(b1>ref){
  b1=analogRead(A2);
  Serial.println("2");
  }
  while(b1<ref){
  b1=analogRead(A2);
  Serial.println("3");
  }
  if(temp>25){
   Serial.println("passed 1");
  digitalWrite(12,HIGH);
  delay(1000);
  }
//  else{
//  digitalWrite(12,LOW);
//  }
}
if(a1>ref && b1<ref){
  while(b1<ref){
  b1=analogRead(A2);
  Serial.println("4");
  }
  while(a1>ref){
  a1=analogRead(A0);
  Serial.println("5");
  }
  while(a1<ref){
  a1=analogRead(A0);
  Serial.println("6");
  }
  Serial.println("back again");
  digitalWrite(12,LOW);
//  if(temp>25){
//  digitalWrite(12,HIGH);
//  }
//  else{
//  digitalWrite(12,LOW);
//  }
//  delay(100);
}
delay(100);
}
