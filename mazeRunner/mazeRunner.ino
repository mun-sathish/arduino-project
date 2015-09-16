
//each intersection = one turning...
//no of intersection = no of directions to the end


String s = "LBR";
char left = 'l';
char right = 'r';
char straight = 's';
char back = 'b';

char path = [
  'l','r','s','b'];
int pathLength = 4;



int rightMotor1 = 8;  //rightMotor1
int rightMotor2 = 9;  //rightMotor2
int leftMotor1 = 10;  //leftMotor1
int leftMotor2 = 11;  //leftMotor2

int leftCenterSensor = 3;   //leftCenterSensor
int rightCenterSensor = 4;   //rightCenterSensor
int leftFarSensor  =  5;
int rightFarSensor = 6;



void setup() 
{
  pinMode(rightMotor1, OUTPUT);
  pinMode(rightMotor2, OUTPUT);

  pinMode(leftCenterSensor, INPUT);
  pinMode(rightCenterSensor, INPUT);

  pinMode(leftMotor1, OUTPUT);
  pinMode(leftMotor2, OUTPUT);

}

void straightPath()
{
  while(1)
  {
  if(digitalRead(leftFarSensor) == LOW || digitalRead(rightFarSensor) == LOW)
  {
    if( (digitalRead(leftCenterSensor) == HIGH && digitalRead(rightCenterSensor) == HIGH) ||
      (digitalRead(leftCenterSensor) == LOW && digitalRead(rightCenterSensor) == LOW) ) 
      {
        loops();
        break;
      }
  }
      else
      {
        if(digitalRead(leftCenterSensor) ==  LOW && digitalRead(rightCenterSensor) ==  LOW)
        {
          // straight();

          digitalWrite(rightMotor1, HIGH); 
          digitalWrite(rightMotor2, LOW);  

          digitalWrite(leftMotor1, LOW); 
          digitalWrite(leftMotor2, HIGH); 
          delay(5); 
        }

        else if(digitalRead(leftCenterSensor) ==  LOW && digitalRead(rightCenterSensor) ==  HIGH)
        {
          //left        
          digitalWrite(rightMotor1, HIGH);
          digitalWrite(rightMotor2, LOW);


          digitalWrite(leftMotor1, LOW);    
          digitalWrite(leftMotor2, LOW);

        }


        else if(digitalRead(leftCenterSensor) ==  HIGH && digitalRead(rightCenterSensor) ==  LOW)
        {
          //  right();
          digitalWrite(rightMotor1, LOW);
          digitalWrite(rightMotor2, LOW);


          digitalWrite(leftMotor1, LOW);
          digitalWrite(leftMotor2, HIGH);
        }
      }

  }

}


void  backward()
{

  digitalWrite(rightMotor1, LOW);
  digitalWrite(rightMotor2, HIGH);


  digitalWrite(leftMotor1, HIGH);
  digitalWrite(leftMotor2, LOW);
}




void leftTurn()
{




  while(1)
  {
    if(digitalRead(leftCenterSensor) == LOW && digitalRead(rightCenterSensor) == LOW)
    {   
      if(digitalRead(leftFarSensor) == HIGH || digitalRead(rightFarSensor) == HIGH)
      {
        straightPath();
        break;
      }  
    }
    else
    {
      digitalWrite(rightMotor1, HIGH);
      digitalWrite(rightMotor2, LOW);


      digitalWrite(leftMotor1, LOW);
      digitalWrite(leftMotor2, LOW);
      delay(2);
    }

  }


}



void rightTurn()
{

  while(1)
  {
    if(digitalRead(leftCenterSensor) == LOW && digitalRead(rightCenterSensor) == LOW)
    {   
      if(digitalRead(leftFarSensor) == HIGH || digitalRead(rightFarSensor) == HIGH)
      {
        straightPath();
        break;
      }  
    }
    else
    {
      digitalWrite(rightMotor1, LOW);
      digitalWrite(rightMotor2, LOW);


      digitalWrite(leftMotor1, LOW);
      digitalWrite(leftMotor2, HIGH);

      delay(2);
    }

  }


}



int movement_fn(char directions)
{

  if(directions == left)
  {
    leftTurn();  
  }
  else if(directions == right)
  {
    rightTurn();

  } 
  else if(directions == straight)
  {
    straightPath();
  }
  else if(directions == back)
  {
    backward();
  }

return 1;

}


void loops()
{
  for( int i=0; i<pathLength; i++)
    movement_fn(path(i));

}


void loop()
{

  //  if( (senseleftpin == black || senserightpin ==  black))
  // if(   both sense on front == white  || both sense on front == black)
  if(digitalRead(leftFarSensor) == LOW || digitalRead(rightFarSensor) == LOW)
  {
    if( (digitalRead(leftCenterSensor) == HIGH && digitalRead(rightCenterSensor) == HIGH) ||
      (digitalRead(leftCenterSensor) == LOW && digitalRead(rightCenterSensor) == LOW) ) 
    {
      loops();
    }
  }

  else
  {
    movement_fn(straight);

  }



}










//algorithm for solving the array:


















