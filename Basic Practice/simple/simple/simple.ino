int middle,right,left,right_most,left_most,right_flag,left_flag;
boolean RM=false;
boolean LM=false;
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
  Serial.println("Start");
  Sensor_test();
  if(right_flag>600 || left_flag>600 || (right_flag>600 && left_flag>600))
  {
    Read(); 
      if(middle<600 && right<600 && left<600  && LM==true && RM==false ){
     while(middle<600){
       left_turn();
       middle=analogRead(A3);
       
       }
 RM==false;
      LM=false;
       Serial.println("Left");
      }
  
  
  if(middle<600 && right<600 && left<600 && RM==true && LM==false){
      while(middle<600){
      right_turn();
      middle=analogRead(A3);
   
     }
 LM==false;
      RM=false;
          Serial.println("90 DEGREE RIGHT");
    }   
   
      if((middle>600 || right>600 || left>600) && RM==true && LM==false ){
     
   
       right_turn();

       delay(200);
         middle=analogRead(A3);     
       while(middle<600){
      right_turn();
      middle=analogRead(A3);

         }
        LM==false;  
      RM=false;
             Serial.println("RIGHT with Line 1");
    }
     
     
    if(middle<600 && right<600 && left<600 && RM==true && LM==true ){
     
      while(middle<600){
      right_turn();
      middle=analogRead(A3);
      
         }
          
      RM=false;
      LM=false;
      Serial.println("T sign");
    }
    


  if((middle>600 || right>600 || left>600) && RM==true && LM==true ){
    forward();
    //delay(60);
      left_most=analogRead(A1);
         while(left_most<600){
           left_most=analogRead(A1);
        right_turn();
         }
     
       middle=analogRead(A3);
     while(middle<600){
      right_turn();
      middle=analogRead(A3);

         }

      RM=false;
      LM=false;
       Serial.println("plus 1");
    }
  

    if(middle>600 && right<600 && left<600 && RM==false && LM==true){
      forward();
      Serial.println("Left with line");
      LM=false;
    }
    
  }




  if(middle>600 && right<600 && left<600 && right_flag<600 && left_flag<600 ){
    forward();
    Serial.println("Forward");
  } 
    
  if(middle<600 && left>600 && right<600 && right_flag<600 && left_flag<600 ){
     left_zig();
     Serial.print("left zig");
   }
   
   if(middle<600 && right>600 && left<600 && right_flag<600 && left_flag<600){
     right_zig();
     
    Serial.println("RIGHT zig");
   }

   if(middle<600 && right<600 && left<600 && right_flag<600 && left_flag<600 && RM==false && LM==false){
     
      while(middle<600){
      right_turn();
      middle=analogRead(A3);
     
         }
  Serial.println("out of line");
    }
   
}


void forward()
{
  digitalWrite(7,HIGH);
  analogWrite(6,250);
  
  digitalWrite(4,HIGH);
  analogWrite(5,250);
}

void reverse()
{
  digitalWrite(7,LOW);
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

void left_turn()
{
  digitalWrite(7,HIGH);
  analogWrite(6,200);
  
  digitalWrite(4,LOW);
  analogWrite(5,200);
}


void right_zig(){
  digitalWrite(7,HIGH);
  analogWrite(6,0);
  
  digitalWrite(4,HIGH);
  analogWrite(5,200);
}

void left_zig(){
    digitalWrite(7,HIGH);
  analogWrite(6,200);
  
  digitalWrite(4,HIGH);
  analogWrite(5,0);
}
void Read()
{
  middle=analogRead(A3);
  right=analogRead(A4);
  left=analogRead(A2);
  right_most=analogRead(A5);
  left_most=analogRead(A1);
  right_flag=analogRead(A6);
  left_flag=analogRead(A0);

}
void Sensor_test()
{

  Read();
  if(right_most>500 &&  left_most<500){ 
  RM=true;
 //Serial.println("rM");  
  }
  
  if(right_most<500 &&  left_most>500){ 
  //RM=false;
  LM=true;  
   //Serial.println("LM"); 
  }
  
  if(right_most>500 &&  left_most>500){ 
  RM=true;
  LM=true; 
 //Serial.println("rMLM"); 
  }
  
  
}
