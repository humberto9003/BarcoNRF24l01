#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Servo.h>          // Incluir la librería Servo
Servo servo1;   
 
const int pinCE = D4;
const int pinCSN = D8;
// SCLK pin D5, MISO pin D6, MOSI pin D7, CS pin D8.
RF24 radio(pinCE, pinCSN);
// Single radio pipe address for the 2 nodes to communicate.
const uint64_t pipe = 0xE8E8F0F0E1LL;
short data[2];


void setup()
{
   radio.begin();
   Serial.begin(9600); 
   radio.setPALevel(RF24_PA_MAX);
   radio.setDataRate(RF24_2MBPS);
   radio.setChannel(100);
   radio.openReadingPipe(1, pipe);
   radio.startListening();
   servo1.attach(D1) ;  // Conectar servo1 al pin 6
}
 
void loop()
{
  
  
   if (radio.available())
   {    
      radio.read(&data, sizeof data);
        //mostrar valores por serial
      int angulo  = map( data[0], 0, 1024, 0, 180);
      int motorPWM = map( data[1], 512, 1024, 0,255);
      servo1.write(angulo);
      Serial.print("X:" );
      Serial.print(angulo);
      Serial.print(" | Y: ");
      Serial.println(motorPWM);
    
        
    }
    else{
      Serial.println("No radio available");
    }
      
   delay(100);
}

