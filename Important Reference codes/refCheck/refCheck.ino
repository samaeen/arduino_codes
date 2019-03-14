int a,b,c;
void setup(){
Serial.begin(9600);
pinMode(A0,INPUT);
pinMode(A1,INPUT);
pinMode(A2,INPUT);
}
void loop(){
a=analogRead(0);
b=analogRead(1);
c=analogRead(2);
Serial.print(a);
Serial.print(" ");
Serial.print(b);
Serial.print(" ");
Serial.println(c);
delay(500);
}
