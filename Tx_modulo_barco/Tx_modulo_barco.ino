#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
 
const int pinCE = 9;
const int pinCSN = 10;

// SCK pin 13, MISO pin 12, MOSI pin 11,SS pin 10 
RF24 radio(pinCE, pinCSN);
// Single radio pipe address for the 2 nodes to communicate.
const uint64_t pipe = 0xE8E8F0F0E1LL;
short data[2];

const int pinJoyX = A0 ;
const int pinJoyY = A1 ;

void setup()
{
   radio.begin();
   radio.setPALevel(RF24_PA_MAX);
   radio.setDataRate(RF24_2MBPS);
   radio.setChannel(100);
   radio.openWritingPipe(pipe);
}
 
void loop()
{ 

  data[0]=analogRead(pinJoyX);
  delay(100);    
  data[1]=analogRead(pinJoyY);
  
  radio.write(&data, sizeof data);

}
