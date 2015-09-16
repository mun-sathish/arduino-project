

int led = 10;
int times = 72;
void setup() {                
  pinMode(led, OUTPUT);     
}

void loop() {
  
  
  
  int count = 2;
  while(count)
  {
  digitalWrite(led, HIGH);   
  delay(100);               
  digitalWrite(led, LOW);    
  delay(100);
  count = count -1;  
  }
  delay(400);
  
  

}
