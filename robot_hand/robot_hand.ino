
int sensePin1 = 0, sensePin2 = 1;
int motorPin1 = 8, motorPin2 = 9;
int ledPin = 10;


void setup()
{
  pinMode(ledPin, OUTPUT);
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  Serial.begin(9600);
}


void loop()
{
  int rightVal = analogRead(sensePin1);
  int leftVal = analogRead(sensePin2);
  Serial.println( leftVal);
  
  if(rightVal > 120 && leftVal < 1020)
  {
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, LOW);
    analogWrite(ledPin, 255);
  }
  else if(rightVal < 120 && leftVal < 1020)  //rightrotate
  {
    if(rightVal > 90)  analogWrite(ledPin, rightVal+100);
    else if(rightVal > 40)  analogWrite(ledPin, rightVal+50);
    else if(rightVal > 10)  analogWrite(ledPin, rightVal+20);
    else analogWrite(ledPin, 0);
    
   digitalWrite(motorPin1, HIGH);
   digitalWrite(motorPin2, LOW);
    
    delay(300);
  }
  else if(rightVal > 120 && leftVal > 1020)  //leftrotate
  {
   digitalWrite(motorPin1, LOW);
   digitalWrite(motorPin2, HIGH);
   delay(300);     
  }
  else
  {
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, LOW);
  }
  
  
}
