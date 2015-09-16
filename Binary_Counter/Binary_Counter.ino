
/*

to make for all 0000 to 1111
   for(i from 0 to 1, i++)
      for(j from 0 to 1)
        for (k from 0 to 1)
          for(l from 0 to 1)
           {   each loop will get one nos(i,j,k,l) from 0000, 0001 to 1111 }
       we can perform same for n bits.
    
    
  to find individual bits:
     i=0;
     while(i<16) for 4 bits... 5bit is 32/.. etc
     {
        bit0 = ((i&1) == 1); bit1 = ((i&2)==2);
        bit2 = ((i&4) == 4); bit3 = ((i&8)==8);.. etc 
     }
 */




int  ledPin1 = 8;
int  ledPin2 = 9;
int  ledPin3 = 10;

void setup()
{
 pinMode(ledPin1, OUTPUT); 
 pinMode(ledPin2, OUTPUT);
 pinMode(ledPin3, OUTPUT); 
}


void loop()
{
  for(int i=0; i<=1; i++)
      for(int j=0; j<=1; j++)
        for (int k=0; k<=1; k++)
          {
           digitalWrite(ledPin1, i);
           digitalWrite(ledPin2, j);
           digitalWrite(ledPin3, k);
           delay(1000);
           
          }
  
}
