
int sensePin = 0;
//int ledPin = 9;

int ledPinA = 8;
int ledPinB = 9;
int ledPinC = 10;

void setup()
{
 // analogReference(DEFAULT);
 // pinMode(ledPin, OUTPUT);
 pinMode(ledPinA, OUTPUT);
 pinMode(ledPinB, OUTPUT);
 pinMode(ledPinC, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  int val = analogRead(sensePin);
  
  val = constrain(val, 750, 900);
  int ledLevel = map(val, 750, 900, 255, 0);
  Serial.println( ledLevel );
  //delay(1000);
  //analogWrite(ledPin, ledLevel);
  
  if(ledLevel < 100){
      digitalWrite(ledPinA, HIGH);
digitalWrite(ledPinB, LOW);
digitalWrite(ledPinC, LOW);
}
   if(ledLevel < 200 && ledLevel > 100){
      digitalWrite(ledPinB, HIGH);
      digitalWrite(ledPinA, LOW);
digitalWrite(ledPinC, LOW);
}

    
   if(ledLevel > 200){
      digitalWrite(ledPinC, HIGH);
      digitalWrite(ledPinB, LOW);
digitalWrite(ledPinA, LOW);
}

      
     
}
