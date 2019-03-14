int middle,right,left,right_most,left_most,right_flag,left_flag;

void setup()
{
  Serial.begin(9600);
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);
  pinMode(A3,INPUT);
  pinMode(A4,INPUT);
  pinMode(A5,INPUT);
  pinMode(A6,INPUT);

  pinMode(7,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(4,OUTPUT);

}

void loop()
{
  digitalWrite(7,HIGH);
  analogWrite(6,255);
  
  digitalWrite(4,HIGH);
  analogWrite(5,255);
}

void Sensor_test()
{
  middle=analogRead(A3);
  right=analogRead(A4);
  left=analogRead(A2);
  right_most=analogRead(A5);
  left_most=analogRead(A1);
  right_flag=analogRead(A6);
  left_flag=analogRead(A0);
}
