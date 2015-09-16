int sensePin = 7;


void setup() {
  // put your setup code here, to run once:

 pinMode(sensePin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  boolean val =  digitalRead(sensePin);

Serial.println(val);
delay(1000);
  
}
