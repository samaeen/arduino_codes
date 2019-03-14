int middle, right, left, right_most, left_most, right_flag, left_flag, value;
int ref = 400;

unsigned int count, i, Length, Length1, a, b, c;
//unsigned int j=1;
boolean LM;
boolean RM;
boolean solved;
char path[300];
char solve[300];

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

  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  
  
}


void loop()
{

  Read();
  Flag_test();

  if (solved) {
    //Serial.println("Solved");

    if (left >= ref && right >= ref && left_flag >= ref && right_flag >= ref && middle <= ref)
    {
      forward();
    }


    else if ((right <= ref) && (left <= ref) && (left_flag >= ref) && (right_flag >= ref) && (middle <= ref))
    {
      forward();
    }
    else if (left <= ref && right >= ref && left_flag >= ref && right_flag >= ref && (middle <= ref))
    {
      left_zig();
    }


    else if ((right <= ref) && (left >= ref) && (left_flag >= ref) && (right_flag >= ref) && (middle <= ref))
    {
      right_zig();
    }



    else if (left <= ref && right >= ref && left_flag >= ref && right_flag >= ref && (middle >= ref))
    {
      left_turn();
    }


    else if ((right <= ref) && (left >= ref) && (left_flag >= ref) && (right_flag >= ref) && (middle >= ref))
    {
      right_turn();
    }

    else if ((left >= ref) && (right >= ref) && (left_flag >= ref) && (right_flag >= ref) && (middle >= ref) && (!LM) && (!RM))
    {
      Serial.println("Ghuri gese :D");
      forward();
      delay(70);

      Stop();
      delay(50);
      Read();
      while (middle >= ref)
      {
        Read();
        hardleft_turn();

      }


      LM = false;
      RM = false;
      Stop();
      delay(50);
    }

    //   Left
    else if ((right >= ref) && (left >= ref) && (left_flag <= ref) && (right_flag >= ref) && (middle >= ref) && (LM) && (!RM))
    {
      Stop();
      delay(50);
      while (middle >= ref)
      {
        Serial.println(" Normal Left 1");
        hardleft_turn();
        Read();
      }
      while (left <= ref)
      {
        Serial.println(" Normal Left 2");
        hardleft_turn();
        Read();
      }

      LM = false;
      RM = false;
    }

    //  Right
    else if ((right >= ref) && (left >= ref) && (left_flag >= ref) && (right_flag <= ref) && (middle >= ref) && (!LM) && (RM))
    {
      Stop();
      delay(50);
      while (middle >= ref)
      {
        Serial.println("Right");
        hardright_turn();
        Read();
      }
      while (right <= ref)
      {
        Serial.println("Right 2");
        hardright_turn();
        Read();
      }
      LM = false;
      RM = false;
    }

    // T

    else if ((right >= ref) && (left >= ref) && ((left_flag <= ref) || (right_flag <= ref)) && (middle >= ref) && (LM) && (RM))
    {
      Serial.println("T");
      Stop();
      delay(50);
      Serial.println(solve[a]);
      if (solve[a] == 'R') {
        while (middle >= ref)
        {
          Serial.println("T");
          hardleft_turn();
          Read();
        }
        while (left <= ref)
        {
          Serial.println(" T 2");
          hardleft_turn();
          Read();
        }
        LM = false;
        RM = false;
      }

      else {
        while (middle >= ref)
        {
          Serial.println("T");
          hardright_turn();
          Read();
        }
        while (right <= ref)
        {
          Serial.println("T 2");
          hardright_turn();
          Read();
        }
        LM = false;
        RM = false;
      }
//      forward();
//      delay(50);
      LM = false;
      RM = false;
      a++;
    }

    //T Left
    else if (((right <= ref) || (left <= ref) || (middle <= ref)) && (left_flag <= ref) && (right_flag >= ref) && (LM) && (!RM))
    {
      Serial.println("left T");
      Stop();
      delay(50);

      if (solve[a] == 'R') {
        while (right <= ref)
        {
          Serial.println("left T step 1");
          hardleft_turn();
          Read();
        }
        while (left <= ref)

        {
          Serial.println("left T step 2");
          hardleft_turn();
          Read();
        }
        while (middle <= ref)
        {
          Serial.println("left T step 3");
          hardleft_turn();
          Read();
        }
        while (middle >= ref)
        {
          Serial.println("Left T step 4");
          hardleft_turn();
          Read();
        }
      }

      else {
        while (left_flag <= ref)
        {
          forward();
          Read();
        }
        count = 0;
        while (count <= 80)
        {
          forward();
          count++;
        }
        count = 0;
      }
//      forward();
//      delay(50);
      RM = false;
      LM = false;
      a++;
    }

    //End point
    else if ((right <= ref) && (left <= ref) && (middle <= ref) && (left_flag <= ref) && (right_flag <= ref) && (LM) && (RM)) {
      Serial.println("Complete");

      Stop();      
      delay(1000);
      digitalWrite(13, LOW);
      delay(100);
      digitalWrite(13, HIGH);
      delay(100);
      digitalWrite(12, LOW);
      delay(100);
      digitalWrite(12, HIGH);
      delay(100);
      digitalWrite(13, LOW);
      delay(100);
      digitalWrite(13, HIGH);
      delay(100);
       digitalWrite(12, LOW);
      delay(100);
      digitalWrite(12, HIGH);
      delay(100);
      digitalWrite(13, LOW);
      delay(100);
        digitalWrite(12, LOW);
      delay(1000);
     


    }


    //+
    else if (((right <= ref) || (left <= ref) || (middle <= ref)) && ((left_flag <= ref) || (right_flag <= ref)) && (LM) && (RM))
    {

      Serial.println("+ paise yayyy :D");
      Serial.println(solve[a]);

      if (solve[a] == 'R') {
        while ((left_flag <= ref) && (right_flag >= ref))
        {
          left_turn();
          Read();

        }
        while ((left_flag >= ref) && (right_flag <= ref))
        {
          right_turn();
          Read();

        }
        while ((left_flag <= ref) && (right_flag >= ref))
        {
          left_turn();
          Read();

        }
        while ((left_flag >= ref) && (right_flag <= ref))
        {
          right_turn();
          Read();
        }

        if (left <= ref && right <= ref && left_flag <= ref && right_flag <= ref && middle <= ref && LM && RM)
        {
          //returnBackCal();

        }
        else
        {
          Stop();
          delay(50);

          while (left <= ref)
          {
            hardleft_turn();
            Read();
          }
          while (right <= ref)
          {
            hardleft_turn();
            Read();
          }
          while (middle <= ref)
          {

            hardleft_turn();
            Read();
          }

          while (middle >= ref)
          {

            hardleft_turn();
            Read();
          }

//          forward();
//          delay(50);
          LM = false;
          RM = false;
        }
      }

      else if (solve[a] == 'S') {
        {
          while (left_flag <= ref)
          {
            forward();
            Read();
          }
          count = 0;
          while (count <= 80)
          {
            forward();
            count++;
          }
          count = 0;
        }
      }

      else {
        while ((left_flag <= ref) && (right_flag >= ref))
        {
          left_turn();
          Read();

        }
        while ((left_flag >= ref) && (right_flag <= ref))
        {
          right_turn();
          Read();

        }
        while ((left_flag <= ref) && (right_flag >= ref))
        {
          left_turn();
          Read();

        }
        while ((left_flag >= ref) && (right_flag <= ref))
        {
          right_turn();
          Read();

        }

        if (left <= ref && right <= ref && left_flag <= ref && right_flag <= ref && middle <= ref && LM && RM)
        {
          //returnBackCal();
        }
        else
        {
          Stop();
          delay(50);
          while ((right <= ref))
          {
            hardright_turn();
            Read();
          }
          while ((left <= ref))
          {
            hardright_turn();
            Read();
          }
          while (middle <= ref)
          {
            hardright_turn();
            Read();
          }

          while (middle >= ref)
          {
            hardright_turn();
            Read();
          }
//          forward();
//          delay(50);
          LM = false;
          RM = false;
        }
      }
      LM = false;
      RM = false;
      a++;
    }

    //T Right
    else if (((right <= ref) || (left <= ref) || (middle <= ref)) && (left_flag >= ref) && (right_flag <= ref) && (!LM) && (RM))
    {

      if (solve[a] == 'L') {

        while ((left <= ref))
        {
          hardright_turn();
          Read();
        }
        while ((right <= ref))
        {
          hardright_turn();
          Read();
        }

        while (middle <= ref)
        {
          hardright_turn();
          Read();
        }
        while (middle >= ref)
        {
          hardright_turn();
          Read();
        }
      }

      else
      {
        Stop();
        delay(50);
        while (right_flag <= ref)
        {
          forward();
          Read();
        }
        count = 0;
        while (count <= 80)
        {
          forward();
          count++;
        }
        count = 0;
      }
//      forward();
//      delay(50);
      LM = false;
      RM = false;
      a++;
    }

    else
    {
      count = 0;
      if (LM) {
        Serial.println("LM=True");
      }
      if (!LM) {
        Serial.println("LM=False");
      }
      if (RM) {
        Serial.println("RM=True");
      }
      if (!RM) {
        Serial.println("LM=False");
      }
      forward();
    }

  }



  //Normal Run

  //
  //

  else {
    if (left >= ref && right >= ref && left_flag >= ref && right_flag >= ref && middle <= ref)
    {
      forward();
      Serial.println("Forward");
    }


    else if ((right <= ref) && (left <= ref) && (left_flag >= ref) && (right_flag >= ref) && (middle <= ref))
    {
      forward();
    }

    //U turn
    else if ((left >= ref) && (right >= ref) && (left_flag >= ref) && (right_flag >= ref) && (middle >= ref) && (!LM) && (!RM))
    {
      Serial.println("Ghuri gese :D");
      forward();
      delay(120);

      Stop();
      delay(50);
      Read();
      while (middle >= ref)
      {
        Read();
        hardleft_turn();

      }
      while (middle <= ref)
      {
        Read();
        hardleft_turn();

      }

      path[i] = 'U';
      i++;
      LM = false;
      RM = false;
      Stop();
      delay(50);
    }


    else if (left <= ref && right >= ref && left_flag >= ref && right_flag >= ref && (middle <= ref))
    {
      left_zig();
      Serial.println("zig er jhamela left");
    }


    else if ((right <= ref) && (left >= ref) && (left_flag >= ref) && (right_flag >= ref) && (middle <= ref))
    {
      right_zig();
      Serial.println("zig er jhamela right");
    }



    else if (left <= ref && right >= ref && left_flag >= ref && right_flag >= ref && (middle >= ref))
    {
      left_turn();
    }



    else if ((right <= ref) && (left >= ref) && (left_flag >= ref) && (right_flag >= ref) && (middle >= ref))
    {
      right_turn();
    }


    //   Left
    else if ((right >= ref) && (left >= ref) && (left_flag <= ref) && (right_flag >= ref) && (middle >= ref) && (LM) && (!RM))
    {
      Stop();
      delay(50);
      while (left >= ref)
      {
        Serial.println(" Normal Left");
        hardleft_turn();
        Read();
      }
       while (middle >= ref)
      {
        Serial.println(" Normal Left");
        hardleft_turn();
        Read();
      }


      RM = false;
      LM = false;
    }

    //T Right
    else if (((right <= ref) || (left <= ref) || (middle <= ref)) && (left_flag >= ref) && (right_flag <= ref) && (!LM) && (RM))
    {
      Serial.println("Right T");
      while (right_flag <= ref)
      {
        forward();
        Read();
      }
      count = 0;
      while (count <= 80)
      {
        forward();
        count++;
      }
      count = 0;
      //forward();
      //delay(50);
      path[i] = 'S';
      i++;
      LM = false;
      RM = false;
    }





    //  Right
    else if ((right >= ref) && (left >= ref) && (left_flag >= ref) && (right_flag <= ref) && (middle >= ref) && (!LM) && (RM))
    {
      Stop();
      delay(50);
      while (right >= ref)
      {
        Serial.println("Right");
        hardright_turn();
        Read();
      }
            while (middle >= ref)
      {
        Serial.println("Right");
        hardright_turn();
        Read();
      }


      LM = false;
      RM = false;
    }


    // T

    else if ((right >= ref) && (left >= ref) && ((left_flag <= ref) || (right_flag <= ref)) && (middle >= ref) && (LM) && (RM))
    {
      Serial.println("T");
      Stop();
      delay(50);
      while (middle >= ref)
      {
        Serial.println("T");
        hardleft_turn();
        Read();
      }
      while (left <= ref)
      {
        Serial.println("T 2");
        hardleft_turn();
        Read();
      }
      path[i] = 'L';
      i++;
//      forward();
//      delay(50);
      LM = false;
      RM = false;
    }


    //T Left
    else if (((right <= ref) || (left <= ref) || (middle <= ref)) && (left_flag <= ref) && (right_flag >= ref) && (LM) && (!RM))
    {
      Serial.println("left T");
      Stop();
      delay(50);
      while (right <= ref)
      {
        Serial.println("left T step 1");
        hardleft_turn();
        Read();
      }
      while (left <= ref)

      {
        Serial.println("left T step 2");
        hardleft_turn();
        Read();
      }
      while (middle <= ref)
      {
        Serial.println("left T step 3");
        hardleft_turn();
        Read();
      }
      while (middle >= ref)
      {
        Serial.println("Left T step 4");
        hardleft_turn();
        Read();
      }
//      forward();
//      delay(50);
      path[i] = 'L';
      i++;
      LM = false;
    }

    //End point
    else if ((right <= ref) && (left <= ref) && (middle <= ref) && (left_flag <= ref) && (right_flag <= ref) && (left_most <= ref) && (right_most <= ref)) {
      Serial.println("Rest Koruk :p");
      count = 0;

      Stop();

      delay(1000);
      solved = true;
      Serial.println("True korse yayyyy :p");
      Solveline();
      digitalWrite(13, LOW);
      delay(100);
      digitalWrite(13, HIGH);
      delay(100);
      digitalWrite(12, LOW);
      delay(100);
      digitalWrite(12, HIGH);
      delay(100);
      digitalWrite(13, LOW);
      delay(100);
      digitalWrite(13, HIGH);
      delay(100);
      digitalWrite(12, LOW);
      delay(100);
      digitalWrite(12, HIGH);
      delay(100);
      digitalWrite(13, LOW);
      count = 0;
      while (right_flag<=ref || left_flag<=ref) {
        reverse();
        Serial.println("Reverse");
      }
      count = 0;
      while (left_most <= ref) {
        Read();
        hardleft_turn();
        Serial.println("Right most");
      }
      while (left_most >= ref) {
        Read();
        hardleft_turn();
        Serial.println("Right most 2");
      }
      while (middle >= ref) {
        Read();
        hardleft_turn();
        Serial.println("Middle");
      }
            while (left <= ref) {
        Read();
        hardleft_turn();
        Serial.println("Middle");
      }
      

      //    while(middle<=ref){
      //        Read();
      //        hardleft_turn();
      //        Serial.println("Middle 2");
      //    }

      LM = false;
      RM = false;
    }

    //+
    else if (((right <= ref) || (left <= ref) || (middle <= ref)) && ((left_flag <= ref) || (right_flag <= ref)) && (LM) && (RM))
    {

      Serial.println("+ paise yayyy :D");

      path[i] = 'L';
      i++;

      while ((left_flag <= ref) && (right_flag >= ref))
      {
        left_turn();
        Read();
      }

      while ((left_flag >= ref) && (right_flag <= ref))
      {
        right_turn();
        Read();
      }

      while ((left_flag <= ref) && (right_flag >= ref))
      {
        left_turn();
        Read();
      }

      while ((left_flag >= ref) && (right_flag <= ref))
      {
        right_turn();
        Read();
      }

      if (left <= ref && right <= ref && left_flag <= ref && right_flag <= ref && middle <= ref && LM && RM)
      {
        //returnBackCal();

      }
      else
      {
        Stop();
        delay(50);
        while (left <= ref)
        {
          hardleft_turn();
          Read();
        }
        while (right <= ref)
        {
          hardleft_turn();
          Read();
        }
        while (middle <= ref)
        {

          hardleft_turn();
          Read();
        }

        while (middle >= ref)
        {

          hardleft_turn();
          Read();
        }

//        forward();
//        delay(50);
        LM = false;
        RM = false;
      }
    }


        else
    {
      count = 0;
      if (LM) {
        Serial.println("LM=True");
      }
      if (!LM) {
        Serial.println("LM=False");
      }
      if (RM) {
        Serial.println("RM=True");
      }
      if (!RM) {
        Serial.println("LM=False");
      }
      forward();
    }

}
}



void forward()
{
//right motor
  analogWrite(5,110);
  digitalWrite(6,LOW);
  digitalWrite(7,HIGH);
//left motor
  analogWrite(2,110);
  digitalWrite(3,LOW);
  digitalWrite(4,HIGH);
}
void reverse()
{
//right motor
  analogWrite(5,80);
  digitalWrite(6,HIGH);
  digitalWrite(7,LOW);
//left motor
  analogWrite(2,80);
  digitalWrite(3,HIGH);
  digitalWrite(4,LOW);
}

void Stop()
{
//right motor
  analogWrite(2,0);
  digitalWrite(4,LOW);
  digitalWrite(3,HIGH);
//left motor
  analogWrite(5,0);
  digitalWrite(7,LOW);
  digitalWrite(6,HIGH);
}

void hardright_turn()
{
//right motor
  analogWrite(5,100);
  digitalWrite(6,HIGH);
  digitalWrite(7,LOW);
//left motoR
  analogWrite(2,100);
  digitalWrite(3,LOW);
  digitalWrite(4,HIGH);
}

void hardleft_turn()
{
//right motor
  analogWrite(5,100);
  digitalWrite(6,LOW);
  digitalWrite(7,HIGH);
//left motor
  analogWrite(2,100);
  digitalWrite(3,HIGH);
  digitalWrite(4,LOW);
}


void left_turn() {
//right motor
  analogWrite(5,100);
  digitalWrite(6,LOW);
  digitalWrite(7,HIGH);
//left motor
  analogWrite(2,0);
  digitalWrite(3,HIGH);
  digitalWrite(4,LOW);
}

void left_zig() {
//right motor
  analogWrite(5,110);
  digitalWrite(6,LOW);
  digitalWrite(7,HIGH);
//left motor
  analogWrite(2,60);
  digitalWrite(3,LOW);
  digitalWrite(4,HIGH);
}

void right_turn() {
//right motor
  analogWrite(5,0);
  digitalWrite(6,HIGH);
  digitalWrite(7,LOW);
//left motoR
  analogWrite(2,100);
  digitalWrite(3,LOW);
  digitalWrite(4,HIGH);
}

void right_zig()  {
//right motor
  analogWrite(5,60);
  digitalWrite(6,LOW);
  digitalWrite(7,HIGH);
//left motor
  analogWrite(2,110);
  digitalWrite(3,LOW);
  digitalWrite(4,HIGH);
}

void Read()
{
  middle = 1023-analogRead(A3);
  right =  1023-analogRead(A4);
  left = 1023-analogRead(A2);
  right_most = 1023-analogRead(A5);
  left_most = 1023-analogRead(A1);
  right_flag = 1023-analogRead(A6);
  left_flag = 1023-analogRead(A0);

}


void Flag_test()
{

  if (right_most >= ref && left_most <= ref)
  {
    LM = true;
  }
  if (left_most <= ref && right_most <= ref)
  {
    LM = true;
    RM = true;
  }
  if (right_most <= ref && left_most >= ref) {
    RM = true;
  }

}

void Solveline()
{
  Serial.println("Solve koira felse :p");

  for (i = 0; path[i] != 0; i++)
  {
    Length++;
    // Serial.println(Length);
    //Serial.println("Length");
    //Serial.println(path[i]);
  }

  for (a = Length; a >= 1; a--) {


    if (path[a - 1] == 'L' && path[a] == 'U' && path[a + 1] == 'S') {
      a = a - 1;
      path[a] = 'R';
      for (a = a + 1; path[a] != '\0'; a++)
      {
        path[a] = path[a + 2];
      }

    }

    else if (path[a - 1] == 'L' && path[a] == 'U' && path[a + 1] == 'R') {
      a = a - 1;
      path[a] = 'U';
      for (a = a + 1; path[a] != '\0'; a++)
      {
        path[a] = path[a + 2];
      }

    }

    else if (path[a - 1] == 'R' && path[a] == 'U' &&path[a + 1] == 'L') {
      a = a - 1;
      path[a] = 'U';
      for (a = a + 1; path[a] != '\0'; a++)
      {
        path[a] = path[a + 2];
      }
    }


    else if (path[a - 1] == 'S' && path[a] == 'U' && path[a + 1] == 'L') {
      a = a - 1;
      path[a] = 'R';
      for (a = a + 1; path[a] != '\0'; a++)
      {
        path[a] = path[a + 2];
      }
    }

    else if (path[a - 1] == 'S' && path[a] == 'U' && path[a + 1] == 'S') {
      a = a - 1;
      path[a] = 'U';
      for (a = a + 1; path[a] != '\0'; a++)
      {
        path[a] = path[a + 2];
      }
    }

    else if (path[a - 1] == 'L' && path[a] == 'U' && path[a + 1] == 'L') {
      a = a - 1;
      path[a] = 'S';
      for (a = a + 1; path[a] != '\0'; a++)
      {
        path[a] = path[a + 2];
      }
    }

    else
    {
      path[a] = path[a];
      Serial.println("Path same :p");
    }
    Serial.println("Done :p");
    // Serial.println(a);

  }

  for (i = 0; path[i] != 0; i++)
  {
    Length1++;
    //Serial.println(Length1);
    //Serial.println("Length1");
    // Serial.println(path[i]);
  }

  for (a = 0; a<Length1; a++) {
    //    Serial.println(path[a]);
  }

  for (a = 0; a<Length1; a++)
  {

    solve[a] = path[Length1 - a - 1];
    //  Serial.println(solve[b]);
    //Serial.println("Solve koira felse pray :p");
  }


  for (a = 1; a<Length1; a++) {
    Serial.println(solve[a]);
  }


  a = 1;


}

