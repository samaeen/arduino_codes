void setup() {
  char value;
  pinMode(13,OUTPUT);
  Serial.begin(38400);
  Serial1.begin(38400);
}
void loop(){
  char value;
  if (Serial1.available()>0) {
   value = Serial1.read();
    //Serial.write(value);
    Serial.println(value);
  }
    if (value=='F')
  {
    digitalWrite(13,HIGH);
  }  
}
