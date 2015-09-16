
int ledPin = 10;


void setup()
{
  pinMode(ledPin, OUTPUT);
  
}

void loop()
{
     for(int i=0; i<= 255; i+= 1)
  {
//      int ledLevel = map(i, 750, 900, 255, 0);

    analogWrite(ledPin, i);
    delay(10);
  }
  
    for(int i=255; i>= 0; i-= 1)
  {
//      int ledLevel = map(i, 750, 900, 255, 0);

    analogWrite(ledPin, i);
    delay(10);
  }
}
