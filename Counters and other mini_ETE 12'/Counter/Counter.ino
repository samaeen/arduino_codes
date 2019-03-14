int ref,count=0,a1,b1;
void setup(){
Serial.begin(9600);
pinMode(A0,INPUT);
pinMode(A1,INPUT);
}
void loop(){
ref=100;
a1=analogRead(A0);
b1=analogRead(A1);
if(a1>ref && b1>ref){
  count=count;
}
if(a1<ref && b1>ref){
  while(a1<ref){
  a1=analogRead(A0);
  }
  while(b1>ref){
  b1=analogRead(A1);
  }
  while(b1<ref){
  b1=analogRead(A1);
  }
  count=count+1;
  Serial.print("present");
  Serial.print("  ");
  Serial.println(count);
  delay(100);
}
if(a1>ref && b1<ref){
  while(b1<ref){
  b1=analogRead(A1);
  }
  while(b1>ref){
  b1=analogRead(A1);
  }
  while(a1<ref){
  a1=analogRead(A0);
  }
  count=count-1;
  Serial.print("present");
  Serial.print("  ");
  Serial.println(count);
  delay(100);
}
}
