
int sensePin = 0;
int ledPin = 10;
void setup()
{
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  int val = analogRead(sensePin);
  Serial.println(val);
  if(val > 120)
      analogWrite(ledPin, 255);
  else
  {
    if(val > 90)  analogWrite(ledPin, val+100);
    else if(val > 40)  analogWrite(ledPin, val+50);
    else if(val > 10)  analogWrite(ledPin, val+20);
    else analogWrite(ledPin, 0);
    
    delay(20);
  }
}
