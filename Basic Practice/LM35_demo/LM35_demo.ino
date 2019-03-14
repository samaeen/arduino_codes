float temp;
float tempa;
void setup(){
  Serial.begin(9600);
  pinMode(A1,INPUT);
  pinMode(12,OUTPUT);
}
void loop(){
  tempa=analogRead(A1);
  temp= tempa*0.48828125;
  Serial.println(temp);
  delay(1000);
  if(temp >= 25){
  digitalWrite(12,HIGH);
  }
  else{
    digitalWrite(12,LOW);
  }

  
}


