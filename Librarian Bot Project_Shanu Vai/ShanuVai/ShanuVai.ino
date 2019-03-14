int middle, right, left, right_most, left_most, value;
int ref = 700;
void setup(){
    Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
}
void loop(){
    Read();
    if (left >= ref && right >= ref && left_most >= ref && right_most >= ref && middle <= ref)
    {
      forward();
      Serial.println("forward");
    }
    if ((right <= ref) && (left <= ref) && (left_most >= ref) && (right_most >= ref) && (middle <= ref))
    {
      forward();
      Serial.println("forward");
    }
    if(left <= ref && right >= ref && left_most <= ref && right_most >= ref && (middle <= ref))
    {
      leftTurn();
      Serial.println("left");
    }
    if(left >= ref && right <= ref && left_most >= ref && right_most <= ref && (middle <= ref))
    {
      rightTurn();
      Serial.println("right");
    }
    if (left <= ref && right >= ref && left_most >= ref && right_most >= ref && (middle <= ref))
    {
      leftZig();
      Serial.println("left zig");
    }
    if ((right <= ref) && (left >= ref) && (left_most >= ref) && (right_most >= ref) && (middle <= ref))
    {
      rightZig();
      Serial.println("right zig");
    }
    if(left >= ref && right >= ref && left_most >= ref && right_most >= ref && (middle >= ref))
    {
      stopp();
      Serial.println("stop");
    }
}
void forward()
{
//right motor
  analogWrite(2,120);
  digitalWrite(3,LOW);
  digitalWrite(4,HIGH);
//left motor
  analogWrite(5,120);
  digitalWrite(6,HIGH);
  digitalWrite(7,LOW);
}
void rightTurn()
{
//right motor
  analogWrite(2,120);
  digitalWrite(3,HIGH);
  digitalWrite(4,LOW);
//left motor
  analogWrite(5,120);
  digitalWrite(6,HIGH);
  digitalWrite(7,LOW);
}
void rightZig()
{
//right motor
  analogWrite(2,0);
  digitalWrite(3,LOW);
  digitalWrite(4,HIGH);
//left motor
  analogWrite(5,120);
  digitalWrite(6,HIGH);
  digitalWrite(7,LOW);
}
void leftTurn()
{
//right motor
  analogWrite(2,120);
  digitalWrite(3,LOW);
  digitalWrite(4,HIGH);
//left motor
  analogWrite(5,120);
  digitalWrite(6,LOW);
  digitalWrite(7,HIGH);
}
void leftZig()
{
//right motor
  analogWrite(2,120);
  digitalWrite(3,LOW);
  digitalWrite(4,HIGH);
//left motor
  analogWrite(5,0);
  digitalWrite(6,HIGH);
  digitalWrite(7,LOW);
}
void backward()
{
//right motor
  analogWrite(2,120);
  digitalWrite(3,HIGH);
  digitalWrite(4,LOW);
//left motor
  analogWrite(5,120);
  digitalWrite(6,LOW);
  digitalWrite(7,HIGH);
}
void stopp()
{
//right motor
  analogWrite(2,0);
  digitalWrite(3,LOW);
  digitalWrite(4,HIGH);
//left motor
  analogWrite(5,0);
  digitalWrite(6,HIGH);
  digitalWrite(7,LOW);
}
void Read()
{
  middle = analogRead(A2);
  right = analogRead(A3);
  left = analogRead(A1);
  right_most = analogRead(A4);
  left_most = analogRead(A0);
}

