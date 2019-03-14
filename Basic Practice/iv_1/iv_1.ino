int left2,left1,middle,right1,right2,leftbottom,rightbottom;
boolean r2=false;
boolean l2=false;
void setup() {
  // put your setup code here, to run once:
pinMode(22,OUTPUT);
pinMode(23,OUTPUT);
pinMode(38,OUTPUT);
pinMode(39,OUTPUT);
Serial.begin(9600);
}

void loop() {

  Read();
if( rightbottom>800 ||leftbottom>800 ||(rightbottom>800 && leftbottom>800) )
{
Sensor_Reading();  
if(r2==true && l2==false && middle<800 && left1<800 && right1<800 )
{
  while(middle<800)
  {
    middle=analogRead(A2);                                      //right turn
  right_turn();
  Serial.println("Right Turn");
  }
  r2=false;
}
if(l2==true && r2==false && middle<800 && left1<800 && right1<800)
{
  while(middle<800)
  {
    middle=analogRead(A2);                                           //left turn
    left_turn();
  }
  l2=false;
  
}
if(l2==true && r2==true && (middle>800 || right1>800 ||left1>800))
{ 
  right_turn();
  delay(200);
  middle=analogRead(A2);                                              //plus
 while(middle<800)
{
  middle=analogRead(A2); 
  right_turn();
}
l2=false;
r2=false;
}
if(r2==true && l2==false && (middle>800 || right1>800 ||left1>800))
{
  right_turn();
  delay(200);
  
   middle=analogRead(A2);                                    //RT
 while(middle<800)
{
  middle=analogRead(A2); 
  right_turn();
}
l2=false;
r2=false;
}
if(l2=true && r2==true && middle<800 && left1<800 &&right1<800)
{
 while(middle<800)
{
  middle=analogRead(A2);                                              //t
 right_turn();
}
l2=false;
r2=false;
}
if(r2==false && l2==true && (middle>800 || right1>800 ||left1>800))
{
forward();
l2=false;                                                         //lt
r2=false;
}    
}


if(middle>800 && right1<800 && left1<800)
{
forward();
}
if(right1>800 && middle<800 && left1<800)
{
  right_zig();
}
if(left1>800 && middle<800 && right1<800)
{
 left_zig();
}
if(middle<800 && left1<800 && right1<800 && rightbottom<800 && leftbottom<800 && r2==false && l2==false)

{
  while(middle<800)
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
if(right2>800 && left2<800)
{
r2=true;
Serial.println("r2");
Serial.println(l2);
}
if(right2<800 && left2>800)
{
l2=true;
}
if(right2>800 && left2>800)
{
r2=true;
l2=true;
}

}

void Sensor_Reading()
{

right2=analogRead(A0);// put your main code here, to run repeatedly:
Serial.print(right2);
Serial.print("    ");
right1=analogRead(A1);// put your main code here, to run repeatedly:
Serial.print(right1);
Serial.print("    ");
middle=analogRead(A2);// put your main code here, to run repeatedly:
Serial.print(middle);
Serial.print("    ");
left1=analogRead(A3);// put your main code here, to run repeatedly:
Serial.print(left1);
Serial.print("    ");
left2=analogRead(A4);// put your main code here, to run repeatedly:
Serial.print(left2);
Serial.print("    ");
rightbottom=analogRead(A5);// put your main code here, to run repeatedly:
Serial.print(rightbottom);
Serial.print("    ");
leftbottom=analogRead(A6);// put your main code here, to run repeatedly:
Serial.println(leftbottom);
Serial.print("    ");
}


void forward()
{
digitalWrite(23,HIGH);
digitalWrite(22,LOW);
analogWrite(9,100);
digitalWrite(39,HIGH);
digitalWrite(38,LOW);
analogWrite(10,100);
}

void backward()
{
digitalWrite(23,LOW);
digitalWrite(22,HIGH);
analogWrite(9,100);
digitalWrite(39,LOW);
digitalWrite(38,HIGH);
analogWrite(10,100);
}
void left_turn()
{
digitalWrite(23,HIGH);
digitalWrite(22,LOW);
analogWrite(9,100);
digitalWrite(39,LOW);
digitalWrite(38,HIGH);
analogWrite(10,100);
}
void right_turn()
{
digitalWrite(23,LOW);
digitalWrite(22,HIGH);
analogWrite(9,100);
digitalWrite(39,HIGH);
digitalWrite(38,LOW);
analogWrite(10,100);
}
void left_zig()
{
digitalWrite(23,HIGH);
digitalWrite(22,LOW);
analogWrite(9,100);
digitalWrite(39,HIGH);
digitalWrite(38,LOW);
analogWrite(10,55);
}
void right_zig()
{
digitalWrite(23,HIGH);
digitalWrite(22,LOW);
analogWrite(9,55);
digitalWrite(39,HIGH);
digitalWrite(38,LOW);
analogWrite(10,100);

}
