int middle, right, left, right_most, left_most, right_flag, left_flag, value,ref;
unsigned int whiteValue[] = {0, 0, 0, 0, 0, 0, 0};
unsigned int blackValue[] = {0, 0, 0, 0, 0, 0, 0};
unsigned int reff[] = {0, 0, 0, 0, 0, 0, 0};

unsigned int count, i, Length, Length1, a, b, c;
//unsigned int j=1;
boolean LM;
boolean RM;
boolean solved;
char path[300];
char solve[300];

void setup()
{
  Serial.begin(38400);
  Serial1.begin(38400);
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
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  
    for (int d = 0; d <= 6; d++)
  {
    whiteValue[d] = 800;
    blackValue[d] = 300;
  }
  Calibration();
   LM=false;
   RM=false;
  
}


void loop()
{
  //Serial1.println("Start");
  if (Serial1.available()) {
    value = Serial.read();
    Serial1.println(value);
  }
  Read();
  Flag_test();

  if (solved) {
    //Serial1.println("Solved");

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
      Serial1.println("Ghuri gese :D");
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
        Serial1.println(" Normal Left 1");
        hardleft_turn();
        Read();
      }
      while (left <= ref)
      {
        Serial1.println(" Normal Left 2");
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
        Serial1.println("Right");
        hardright_turn();
        Read();
      }
      while (right <= ref)
      {
        Serial1.println("Right 2");
        hardright_turn();
        Read();
      }
      LM = false;
      RM = false;
    }

    // T

    else if ((right >= ref) && (left >= ref) && ((left_flag <= ref) || (right_flag <= ref)) && (middle >= ref) && (LM) && (RM))
    {
      Serial1.println("T");
      Stop();
      delay(50);
      Serial1.println(solve[a]);
      if (solve[a] == 'R') {
        while (middle >= ref)
        {
          Serial1.println("T");
          hardleft_turn();
          Read();
        }
        while (left <= ref)
        {
          Serial1.println(" T 2");
          hardleft_turn();
          Read();
        }
        LM = false;
        RM = false;
      }

      else {
        while (middle >= ref)
        {
          Serial1.println("T");
          hardright_turn();
          Read();
        }
        while (right <= ref)
        {
          Serial1.println("T 2");
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
      Serial1.println("left T");
      Stop();
      delay(50);

      if (solve[a] == 'R') {
        while (right <= ref)
        {
          Serial1.println("left T step 1");
          hardleft_turn();
          Read();
        }
        while (left <= ref)

        {
          Serial1.println("left T step 2");
          hardleft_turn();
          Read();
        }
        while (middle <= ref)
        {
          Serial1.println("left T step 3");
          hardleft_turn();
          Read();
        }
        while (middle >= ref)
        {
          Serial1.println("Left T step 4");
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
      Serial1.println("Complete");

      Stop();      
      delay(1000);
      digitalWrite(13, HIGH);
      delay(100);
      digitalWrite(13, LOW);
      delay(100);
      digitalWrite(12, HIGH);
      delay(100);
      digitalWrite(12, LOW);
      delay(100);
      digitalWrite(13, HIGH);
      delay(100);
      digitalWrite(13, LOW);
      delay(100);
       digitalWrite(12, HIGH);
      delay(100);
      digitalWrite(12, LOW);
      delay(100);
      digitalWrite(13, HIGH);
      delay(100);
        digitalWrite(12, HIGH);
      delay(1000);
     


    }


    //+
    else if (((right <= ref) || (left <= ref) || (middle <= ref)) && ((left_flag <= ref) || (right_flag <= ref)) && (LM) && (RM))
    {

      Serial1.println("+ paise yayyy :D");
      Serial1.println(solve[a]);

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
        Serial1.println("LM=True");
      }
      if (!LM) {
        Serial1.println("LM=False");
      }
      if (RM) {
        Serial1.println("RM=True");
      }
      if (!RM) {
        Serial1.println("LM=False");
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
    }


    else if ((right <= ref) && (left <= ref) && (left_flag >= ref) && (right_flag >= ref) && (middle <= ref))
    {
      forward();
    }

    //U turn
    else if ((left >= ref) && (right >= ref) && (left_flag >= ref) && (right_flag >= ref) && (middle >= ref) && (!LM) && (!RM))
    {
      Serial1.println("Ghuri gese :D");
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


    //   Left
    else if ((right >= ref) && (left >= ref) && (left_flag <= ref) && (right_flag >= ref) && (middle >= ref) && (LM) && (!RM))
    {
      Stop();
      delay(50);
      while (middle >= ref)
      {
        Serial1.println(" Normal Left");
        hardleft_turn();
        Read();
      }
      while (left >= ref)
      {
        Serial1.println(" Normal Left 2");
        hardleft_turn();
        Read();
      }
      RM = false;
      LM = false;
    }

    //T Right
    else if (((right <= ref) || (left <= ref) || (middle <= ref)) && (left_flag >= ref) && (right_flag <= ref) && (!LM) && (RM))
    {
      Serial1.println("Right T");
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
      while (middle >= ref)
      {
        Serial1.println("Right");
        hardright_turn();
        Read();
      }

      while (right <= ref)
      {
        Serial1.println("Right 2");
        hardright_turn();
        Read();
      }
      LM = false;
      RM = false;
    }


    // T

    else if ((right >= ref) && (left >= ref) && ((left_flag <= ref) || (right_flag <= ref)) && (middle >= ref) && (LM) && (RM))
    {
      Serial1.println("T");
      Stop();
      delay(50);
      while (middle >= ref)
      {
        Serial1.println("T");
        hardleft_turn();
        Read();
      }
      while (left >= ref)
      {
        Serial1.println("T 2");
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
      Serial1.println("left T");
      Stop();
      delay(50);
      while (right <= ref)
      {
        Serial1.println("left T step 1");
        hardleft_turn();
        Read();
      }
      while (left <= ref)

      {
        Serial1.println("left T step 2");
        hardleft_turn();
        Read();
      }
      while (middle <= ref)
      {
        Serial1.println("left T step 3");
        hardleft_turn();
        Read();
      }
      while (middle >= ref)
      {
        Serial1.println("Left T step 4");
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
      Serial1.println("Rest Koruk :p");
      count = 0;

      Stop();

      delay(1000);
      solved = true;
      Serial1.println("True korse yayyyy :p");
      Solveline();
      digitalWrite(13, HIGH);
      delay(100);
      digitalWrite(13, LOW);
      delay(100);
      digitalWrite(12, HIGH);
      delay(100);
      digitalWrite(12, LOW);
      delay(100);
      digitalWrite(13, HIGH);
      delay(100);
      digitalWrite(13, LOW);
      delay(100);
      digitalWrite(12, HIGH);
      delay(100);
      digitalWrite(12, LOW);
      delay(100);
      digitalWrite(13, HIGH);
      count = 0;
      while (count <= 50) {
        reverse();
        count++;
        Serial1.println("Reverse");
      }
      count = 0;
      while (left_most <= ref) {
        Read();
        hardleft_turn();
        Serial1.println("Right most");
      }
      while (left_most >= ref) {
        Read();
        hardleft_turn();
        Serial1.println("Right most 2");
      }
      while (middle >= ref) {
        Read();
        hardleft_turn();
        Serial1.println("Middle");
      }

      //    while(middle<=ref){
      //        Read();
      //        hardleft_turn();
      //        Serial1.println("Middle 2");
      //    }

      LM = false;
      RM = false;
    }

    //+
    else if (((right <= ref) || (left <= ref) || (middle <= ref)) && ((left_flag <= ref) || (right_flag <= ref)) && (LM) && (RM))
    {

      Serial1.println("+ paise yayyy :D");

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
        Serial1.println("LM=True");
      }
      if (!LM) {
        Serial1.println("LM=False");
      }
      if (RM) {
        Serial1.println("RM=True");
      }
      if (!RM) {
        Serial1.println("LM=False");
      }
      forward();
    }

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
  analogWrite(6, 255);

  digitalWrite(4, HIGH);
  analogWrite(5, 255);
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
  analogWrite(6, 230);

  digitalWrite(4, HIGH);
  analogWrite(5, 230);
}

void hardleft_turn()
{
  digitalWrite(7, HIGH);
  analogWrite(6, 230);

  digitalWrite(4, LOW);
  analogWrite(5, 230);
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
  middle = 1023- analogRead(A3);
  right = 1023- analogRead(A4);
  left = 1023- analogRead(A2);
  right_most = 1023- analogRead(A5);
  left_most = 1023- analogRead(A1);
  right_flag = 1023- analogRead(A6);
  left_flag = 1023- analogRead(A0);

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
  Serial1.println("Solve koira felse :p");

  for (i = 0; path[i] != 0; i++)
  {
    Length++;
    // Serial1.println(Length);
    //Serial1.println("Length");
    //Serial1.println(path[i]);
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
      Serial1.println("Path same :p");
    }
    Serial1.println("Done :p");
    // Serial1.println(a);

  }

  for (i = 0; path[i] != 0; i++)
  {
    Length1++;
    //Serial1.println(Length1);
    //Serial1.println("Length1");
    // Serial1.println(path[i]);
  }

  for (a = 0; a<Length1; a++) {
    //    Serial1.println(path[a]);
  }

  for (a = 0; a<Length1; a++)
  {

    solve[a] = path[Length1 - a - 1];
    //  Serial1.println(solve[b]);
    //Serial1.println("Solve koira felse pray :p");
  }


  for (a = 1; a<Length1; a++) {
    Serial1.println(solve[a]);
  }


  a = 1;


}

void Calibration()
{

  count = 0;
  while (count <= 8000)
  {
    Read();
    whiteValue[2] = min(whiteValue[2], left);
    whiteValue[4] = min(whiteValue[4], right);
    whiteValue[0] = min(whiteValue[0], left_flag);
    whiteValue[6] = min(whiteValue[6], right_flag);
    whiteValue[3] = min(whiteValue[3], middle);
    whiteValue[1] = min(whiteValue[1], left_most);
    whiteValue[5] = min(whiteValue[5], right_most);
    hardright_turn();
    count++;
  }

  count = 0;
  while (count <= 8000)
  {
    Read();
    blackValue[0] = max(blackValue[0], left);
    blackValue[1] = max(blackValue[1], right);
    blackValue[0] = max(blackValue[0], left_flag);
    blackValue[6] = max(blackValue[6], right_flag);
    blackValue[3] = max(blackValue[3], middle);
    blackValue[1] = max(blackValue[1], left_most);
    blackValue[5] = max(blackValue[5], right_most);
    hardleft_turn();
    count++;
  }
  LM = false;
  RM = false;
  Stop();
  delay(6000);
  LM = false;
  RM = false;

  for (i = 0; i < 7; i++)
  {
    reff[i] = (whiteValue[i] + blackValue[i]) / 2;
    delay(5);
  }
  ref=(reff[0]+reff[1]+reff[2]+reff[3]+reff[4]+reff[5]+reff[6])/7;
  
}
