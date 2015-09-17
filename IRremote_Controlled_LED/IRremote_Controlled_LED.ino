
#include <IRremote.h>
int RECV_PIN = 11;
int ledPin = 12;
boolean state = false;
IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
}

void loop() {
  if (irrecv.decode(&results)) {
    if(state)
   {
     state = false;
     digitalWrite(ledPin, LOW); 
   }
   else
   {
     state = true;
     digitalWrite(ledPin, HIGH); 
   }
        
    Serial.println(results.value, HEX);
    irrecv.resume(); // Receive the next value
  }
  delay(100);
}
