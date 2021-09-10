#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Servo.h>          // Incluir la librería Servo
Servo servo1;   

#define LED 7
#define motor 5

/*volatile unsigned int cuenta = 0;
bool ESTADO = false;*/


unsigned long timeNow, timeLast; // Variables de control de tiempo no bloqueante
int wait = 500;

 
/*const int pinCE = D4;
const int pinCSN = D8;
// SCLK pin D5, MISO pin D6, MOSI pin D7, CS pin D8.
RF24 radio(pinCE, pinCSN);
// Single radio pipe address for the 2 nodes to communicate.
const uint64_t pipe = 0xE8E8F0F0E1LL;*/

const int pinCE = 9;
const int pinCSN = 10;

// SCK pin 13, MISO pin 12, MOSI pin 11,SS pin 10 
RF24 radio(pinCE, pinCSN);
// Single radio pipe address for the 2 nodes to communicate.
const uint64_t pipe = 0xE8E8F0F0E1LL;
short data[2];



void setup()
{
   radio.begin();
   /*Serial.begin(9600); */
   radio.setPALevel(RF24_PA_MAX);
   radio.setDataRate(RF24_2MBPS);
   radio.setChannel(100);
   radio.openReadingPipe(1, pipe);
   radio.startListening();
   servo1.attach(6) ;  // Conectar servo1 al pin 5
   
  /*SREG = (SREG & 0b01111111); //Desabilitar interrupciones
   TIMSK2 = TIMSK2|0b00000001; //Habilita la interrupcion por desbordamiento
   TCCR2B = 0b00000111; //Configura preescala para que FT2 sea de 7812.5Hz
   SREG = (SREG & 0b01111111) | 0b10000000; //Habilitar interrupciones //Desabilitar interrupciones
*/
   pinMode(LED, OUTPUT);
   timeLast = millis (); // Inicia el control de tiempo*/
}
 
void loop()
{
  
  
   if (radio.available())
   {    
      radio.read(&data, sizeof data);
        //mostrar valores por serial
      int angulo  = map( data[0], 0, 1024, 0, 180);
      int motorPWM = map( data[1], 0, 1024, 0,255);
      servo1.write(angulo);
      analogWrite(motor, motorPWM);
      /*Serial.print("X:" );
      Serial.print(angulo);
      Serial.print(" | Y: ");
      Serial.println(motorPWM);

      /*digitalWrite(LED, HIGH);   // turn the LED on (HIGH is the voltage level)*/
      
      timeNow = millis(); // Control de tiempo para esperas no bloqueantes
      if (timeNow - timeLast > wait) { // Manda un mensaje por MQTT cada cinco segundos
           timeLast = timeNow; // Actualización de seguimiento de tiempo
           digitalWrite(LED, HIGH); 
      }
      else {
           digitalWrite(LED, LOW);   
      }  
    }
    else{
      /*Serial.println("No radio available");*/
      digitalWrite(LED, LOW);   // turn the LED on (HIGH is the voltage level)*/
    }
      
}

/**ISR(TIMER2_OVF_vect){
    cuenta++;
  if (radio.available()) {
    if(cuenta > 7) {
      digitalWrite(LED,ESTADO);
      ESTADO = !ESTADO;
      cuenta=0;
    }
  }
  else{
      digitalWrite(LED, LOW);   // turn the LED on (HIGH is the voltage level)*/
  /*}
}*/
