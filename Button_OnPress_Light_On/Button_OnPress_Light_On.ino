
int switchPin = 10;
int ledPin = 8;




void setup()
{

pinMode(switchPin, INPUT_PULLUP);
pinMode(ledPin, OUTPUT);
  
  
}



void loop()
{
  
  if(digitalRead(switchPin) == HIGH) //button not pressed
  {
    digitalWrite(ledPin, LOW);
  }
  
  else if(digitalRead(switchPin) == LOW) //button pressed
  {
    digitalWrite(ledPin, HIGH);
  }
  
}
