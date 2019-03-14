int left2,left1,middle,right1,right2,leftbottom,rightbottom;
boolean r2=false;
boolean l2=false;
void setup() {
  // put your setup code here, to run once:
pinMode(7,OUTPUT);
pinMode(6,OUTPUT);
pinMode(5,OUTPUT);
pinMode(4,OUTPUT);
Serial.begin(9600);
}

void loop() {

  Read();
if( rightbottom>600 ||leftbottom>600 ||(rightbottom>600 && leftbottom>600) )
{
Sensor_Reading();  
if(r2==true && l2==false && middle<600 && left1<600 && right1<600 )
{
  while(middle<600)
  {
    middle=analogRead(A2);                                      //right turn
  right_turn();
  Serial.println("Right Turn");
  }
  r2=false;
}
if(l2==true && r2==false && middle<600 && left1<600 && right1<600)
{
  while(middle<600)
  {
    middle=analogRead(A2);                                           //left turn
    left_turn();
  }
  l2=false;
  
}
if(l2==true && r2==true && (middle>600 || right1>600 ||left1>600))
{ 
  right_turn();
  delay(200);
  middle=analogRead(A2);                                              //plus
 while(middle<600)
{
  middle=analogRead(A2); 
  right_turn();
}
l2=false;
r2=false;
}
if(r2==true && l2==false && (middle>600 || right1>600 ||left1>600))
{
  right_turn();
  delay(200);
  
   middle=analogRead(A2);                                    //RT
 while(middle<600)
{
  middle=analogRead(A2); 
  right_turn();
}
l2=false;
r2=false;
}
if(l2=true && r2==true && middle<600 && left1<600 &&right1<600)
{
 while(middle<600)
{
  middle=analogRead(A2);                                              //t
 right_turn();
}
l2=false;
r2=false;
}
if(r2==false && l2==true && (middle>600 || right1>600 ||left1>600))
{
forward();
l2=false;                                                         //lt
r2=false;
}    
}


if(middle>600 && right1<600 && left1<600)
{
forward();
}
if(right1>600 && middle<600 && left1<600)
{
  right_zig();
}
if(left1>600 && middle<600 && right1<600)
{
 left_zig();
}
if(middle<600 && left1<600 && right1<600 && rightbottom<600 && leftbottom<600 && r2==false && l2==false)

{
  while(middle<600)
  {
    middle=analogRead(A2);                                                           
    right_turn();
  }

}

}
//Sub function
void Read()
{
Sensor_Reading();
if(right2>600 && left2<600)
{
r2=true;
Serial.println("r2");
Serial.println(l2);
}
if(right2<600 && left2>600)
{
l2=true;
}
if(right2>600 && left2>600)
{
r2=true;
l2=true;
}

}

void Sensor_Reading()
{

right2=analogRead(A0);// put your main code here, to run repeatedly:
Serial.print(leftbottom);
Serial.print("    ");
right1=analogRead(A1);// put your main code here, to run repeatedly:
Serial.print(left2);
Serial.print("    ");
middle=analogRead(A2);// put your main code here, to run repeatedly:
Serial.print(left1);
Serial.print("    ");
left1=analogRead(A3);// put your main code here, to run repeatedly:
Serial.print(middle);
Serial.print("    ");
left2=analogRead(A4);// put your main code here, to run repeatedly:
Serial.print(right1);
Serial.print("    ");
rightbottom=analogRead(A5);// put your main code here, to run repeatedly:
Serial.print(right2);
Serial.print("    ");
leftbottom=analogRead(A6);// put your main code here, to run repeatedly:
Serial.println(rightbottom);
Serial.print("    ");
}


void forward()
{
digitalWrite(7,HIGH);
  analogWrite(6,200);
  
  digitalWrite(4,HIGH);
  analogWrite(5,200);
}

void backward()
{
 digitalWrite(7,LOW);
  analogWrite(6,200);
  
  digitalWrite(4,LOW);
  analogWrite(5,200);
}
void left_turn()
{
digitalWrite(7,HIGH);
  analogWrite(6,200);
  
  digitalWrite(4,LOW);
  analogWrite(5,200);
}
void right_turn()
{
 digitalWrite(7,LOW);
  analogWrite(6,200);
  
  digitalWrite(4,HIGH);
  analogWrite(5,200);
}
void left_zig()
{
  digitalWrite(7,HIGH);
  analogWrite(6,120);
  
  digitalWrite(4,HIGH);
  analogWrite(5,50);
}
void right_zig()
{
 digitalWrite(7,HIGH);
  analogWrite(6,50);
  
  digitalWrite(4,HIGH);
  analogWrite(5,120);

}
