int ledPin = 8;
int switchPin = 9;
boolean lastButton = LOW;
boolean currentButton = LOW;
int ledOn = false;

//used input pull down where it is short ckt when it is not pressed(LOW or 0V) else pressed(HIGH or 5v) 

void setup()
{
pinMode(ledPin, OUTPUT);
pinMode(switchPin, INPUT);

}

boolean check(boolean last)
{
   boolean current = digitalRead(switchPin);
  if(last != current)
 {
  delay(5);
   current = digitalRead(switchPin);
 }
return current; 
  
}

void loop()
{
  
  
  
    currentButton = check(lastButton);
    if(lastButton == LOW && currentButton == HIGH)
    {
      ledOn = !ledOn;
    }
    lastButton = currentButton;
    digitalWrite(ledPin, ledOn);

} 
