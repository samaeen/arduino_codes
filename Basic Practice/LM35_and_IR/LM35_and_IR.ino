int ref,val;
float temp;
float tempa;
void setup(){
  Serial.begin(9600);
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(12,OUTPUT);
}
void loop(){
  ref=80;
  val=analogRead(A0);
  tempa=analogRead(A1);
  temp= tempa*0.48828125;
  Serial.println(temp);
  delay(1000);
if(val>ref){
  if(temp>25){
  digitalWrite(12,HIGH);
  }
  else{
  digitalWrite(12,LOW);
  }
}
else{
  digitalWrite(12,LOW);
}

}


