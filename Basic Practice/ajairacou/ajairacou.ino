int value;
int i;
void setup()
{
  pinMode(13,OUTPUT);
  Serial.begin(9600);
}
void loop
{
  while(Serial.avialble()){
  value=Serial.read();
  Serial.write(value);
  }
  if(value==1){
    Serial.pritnln
  }
}

