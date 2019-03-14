int middle, right, left, right_most, left_most, right_flag, left_flag, ref;
void setup()
{
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);
  pinMode(A6, INPUT);

  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);

}
void loop()
{
  if(right_flag>ref && left_flag>ref && right_most>ref && left_most>ref)
  {
    BlackOnWhite();
  }
  if(right_flag<ref && left_flag<ref && right_most<ref && left_most<ref)
  {
    WhiteOnBlack();
  }
}
void BlackOnWhite()
{
  if(right_flag>ref && left_flag>ref && right>ref && middle<ref && left>ref && right_most>ref && left_most>ref)
  {
    forward();
  }
  
}
void WhiteOnBlack()
{
    if(right_flag<ref && left_flag<ref && right<ref && middle>ref && left<ref && right_most<ref && left_most<ref)
  {
    forward();
  }
}
void forward()
{
  digitalWrite(7, LOW);
  analogWrite(6, 255);

  digitalWrite(4, LOW);
  analogWrite(5, 255);
}

void reverse()
{
  digitalWrite(7, HIGH);
  analogWrite(6, 200);

  digitalWrite(4, HIGH);
  analogWrite(5, 200);
}


void Stop()
{
  digitalWrite(7, HIGH);
  analogWrite(6, 0);

  digitalWrite(4, HIGH);
  analogWrite(5, 0);
}

void hardright_turn()
{
  digitalWrite(7, LOW);
  analogWrite(6, 210);

  digitalWrite(4, HIGH);
  analogWrite(5, 210);
}

void hardleft_turn()
{
  digitalWrite(7, HIGH);
  analogWrite(6, 210);

  digitalWrite(4, LOW);
  analogWrite(5, 210);
}


void left_turn() {
  digitalWrite(7, LOW);
  analogWrite(6, 0);

  digitalWrite(4, LOW);
  analogWrite(5, 230);
}

void left_zig() {
  digitalWrite(7, LOW);
  analogWrite(6, 95);

  digitalWrite(4, LOW);
  analogWrite(5, 195);
}

void right_turn() {
  digitalWrite(7, LOW);
  analogWrite(6, 230);

  digitalWrite(4, LOW);
  analogWrite(5, 0);
}

void right_zig() {
  digitalWrite(7, LOW);
  analogWrite(6, 195);

  digitalWrite(4, LOW);
  analogWrite(5, 95);
}
void Read()
{
  middle = analogRead(A3);
  right = analogRead(A4);
  left = analogRead(A2);
  right_most = analogRead(A5);
  left_most = analogRead(A1);
  right_flag = analogRead(A6);
  left_flag = analogRead(A0);
 }
