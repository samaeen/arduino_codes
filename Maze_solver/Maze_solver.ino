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
  Sensor_test();
  
  if(middle>600 && right<600 && left<600 && right_most<600 && left_most<600 && right_flag<600 && left_flag<600){
    forward();
  }
  
  if(middle<600 && right<600 && left<600 && right_most<600 && left_most<600 && right_flag>600 && left_flag<600){
    right_turn();
  }
  
  if(middle<600 && right<600 && left<600 && right_most<600 && left_most<600 && right_flag<600 && left_flag>600){
    left_turn();
  }
  
  if(middle>600 && right<600 && left<600 && right_most<600 && left_most<600 && right_flag>600 && left_flag<600){
    while(middle<600){
      right_turn();
      middle=analogRead(A3);
    }
  }
  
  if(middle<600 && right<600 && left<600 && right_most<600 && left_most<600 && right_flag<600 && left_flag>600){
    while(middle<600){
      left_turn();
      middle=analogRead(A3);
    }
  }
  
//  if((middle>600 || right>600 || left>600) && right_most<600 && left_most<600 && right_flag>600 && left_flag<600){
//    while(left_flag<600){
//      right_turn();
//      left_flag=analogRead(A0);
//    }
//    while(middle<600){
//      right_turn();
//      middle=analogRead(A3);
//    }    
//    }
  
  
}

void forward(){
  digitalWrite(7,HIGH);
  analogWrite(6,255);
  
  digitalWrite(4,HIGH);
  analogWrite(5,255);
}

void reverse()
{
  digitalWrite(7,LOW);
  analogWrite(6,255);
  
  digitalWrite(4,LOW);
  analogWrite(5,255);
}

void right_turn()
{
  digitalWrite(7,HIGH);
  analogWrite(6,255);
  
  digitalWrite(4,LOW);
  analogWrite(5,255);
}

void left_turn()
{
  digitalWrite(7,LOW);
  analogWrite(6,255);
  
  digitalWrite(4,HIGH);
  analogWrite(5,255);
}


void right_zig(){
  digitalWrite(7,HIGH);
  analogWrite(6,0);
  
  digitalWrite(4,HIGH);
  analogWrite(5,255);
}

void left_zig(){
    digitalWrite(7,HIGH);
  analogWrite(6,255);
  
  digitalWrite(4,HIGH);
  analogWrite(5,0);
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
