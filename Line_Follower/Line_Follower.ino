/*
 *  Project: Line Follower
 *  Name: V. Sathish (munna)
 *  Website: http://www.sathishmun.comule.com/
 */


/*
0 0 - straight

1 1 - opp to straight

0 1 = one wheel off , another on

1 0 = opp to above
*/


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



void straight()
{
 digitalWrite(rightMotor1, HIGH);
  digitalWrite(rightMotor2, LOW);

  digitalWrite(leftMotor1, LOW);
  digitalWrite(leftMotor2, HIGH);  
   
}

void  backward()
{
  
   digitalWrite(rightMotor1, LOW);
  digitalWrite(rightMotor2, HIGH);


  digitalWrite(leftMotor1, HIGH);
  digitalWrite(leftMotor2, LOW);
}

void left()
{
    
    
  digitalWrite(rightMotor1, HIGH);
  digitalWrite(rightMotor2, LOW);


  digitalWrite(leftMotor1, LOW);
  digitalWrite(leftMotor2, LOW);
  
  
  
  /*
  while(digitalRead(rightCenterSensor)== HIGH||digitalRead(leftCenterSensor)== HIGH){
     digitalWrite(leftMotor1, LOW);
    digitalWrite(leftMotor2, HIGH);
    digitalWrite(rightMotor1, HIGH);
    digitalWrite(rightMotor2, LOW);
    delay(2);
     digitalWrite(leftMotor1, LOW);
    digitalWrite(leftMotor2, LOW);
    digitalWrite(rightMotor1, LOW);
    digitalWrite(rightMotor2, LOW);
    delay(1);
  }
    
  while(digitalRead(rightCenterSensor)== LOW){
    digitalWrite(leftMotor1, LOW);
    digitalWrite(leftMotor2, HIGH);
    digitalWrite(rightMotor1, HIGH);
    digitalWrite(rightMotor2, LOW);
    delay(2);
    digitalWrite(leftMotor1, LOW);
    digitalWrite(leftMotor2, LOW);
    digitalWrite(rightMotor1, LOW);
    digitalWrite(rightMotor2, LOW);
    delay(1);
  }
  
  */
}



void right()
{
   
  digitalWrite(rightMotor1, LOW);
  digitalWrite(rightMotor2, LOW);


  digitalWrite(leftMotor1, LOW);
  digitalWrite(leftMotor2, HIGH);
  
  
  
  
/*  
  
    while(digitalRead(rightCenterSensor)== HIGH){
     digitalWrite(leftMotor1, HIGH);
    digitalWrite(leftMotor2, LOW);
    digitalWrite(rightMotor1, LOW);
    digitalWrite(rightMotor2, HIGH);
    delay(2);
     digitalWrite(leftMotor1, LOW);
    digitalWrite(leftMotor2, LOW);
    digitalWrite(rightMotor1, LOW);
    digitalWrite(rightMotor2, LOW);
    delay(1);
  }
   while(digitalRead(rightCenterSensor)==LOW){
     digitalWrite(leftMotor1, HIGH);
    digitalWrite(leftMotor2, LOW);
    digitalWrite(rightMotor1, LOW);
    digitalWrite(rightMotor2, HIGH);
    delay(2);
     digitalWrite(leftMotor1, LOW);
    digitalWrite(leftMotor2, LOW);
    digitalWrite(rightMotor1, LOW);
    digitalWrite(rightMotor2, LOW);
    delay(1);
  }
   while((leftCenterSensor)== LOW){
     digitalWrite(leftMotor1, HIGH);
    digitalWrite(leftMotor2, LOW);
    digitalWrite(rightMotor1, LOW);
    digitalWrite(rightMotor2, HIGH);
    delay(2);
    digitalWrite(leftMotor1, LOW);
    digitalWrite(leftMotor2, LOW);
    digitalWrite(rightMotor1, LOW);
    digitalWrite(rightMotor2, LOW);
    delay(1);
  }
 */
}
  
void loop()
{
  
  if(digitalRead(leftCenterSensor) ==  HIGH && digitalRead(rightCenterSensor) ==  HIGH)
  { 
  
    backward();

  }
  else if(digitalRead(leftCenterSensor) ==  LOW && digitalRead(rightCenterSensor) ==  LOW)
  {
     straight(); 
  }
  
  
  else if(digitalRead(leftCenterSensor) ==  LOW && digitalRead(rightCenterSensor) ==  HIGH)
  {
  left();
 
  }
  
  
  else if(digitalRead(leftCenterSensor) ==  HIGH && digitalRead(rightCenterSensor) ==  LOW)
  {
       right();
  }
  
  else if(digitalRead(leftFarSensor) == LOW  ||  digitalRead(rightFarSensor) == LOW)
  {
    
    while(digitalRead(leftFarSensor) == LOW || digitalRead(rightFarSensor) == LOW || 
                        digitalRead(leftCenterSensor) == HIGH &&  digitalRead(rightCenterSensor) == HIGH)
                        {
                          right();  
                        }
                        
     
  }
}
