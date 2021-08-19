# Enlace con NRF24L01
Este repositorio contiene el programa para comunicar dos modulos NRF24L01, enviando las señales analogicas de un joystick por radiocomunicacion (2.4GHZ) para controlar un servomotor SG90 y un motor Brushless.


### Requisitos
Para que el código de este repositorio funcione, es necesario contar con lo siguiente:

- Arduino Uno
- IDE de Arduino 1.8 o superior
- Biblioteca RF24
- Servomotor SG90
- Motor Brushless A2212 Kv1400 / Kv2200
- NRF24L01
- Regulador de Voltaje para el NR24L01
- Modulo Joystick de dos ejes.

### Guías

Puedes obtener la biblioteca RF24 desde el siguiente enlace.

https://github.com/nRF24/RF24

Para conocer mas acerca del modulo NRF24L01 puede consultarlo en el siguiente enlace.

http://robots-argentina.com.ar/didactica/arduino-comunicacion-inalambrica-con-nrf24l01/


### Funcionamiento

Para observar el funcionamiento de este proyecto deberás realizar lo siguiente.

1. Configuarar los pines para el motor,servomotor y joystick de tu preferencia en el codigo de RX y Tx.
2. Si no cunetas con un NodeMCU se puede sustituir con otro arduino, solo tendrias que configuarar los pines de igual manera que el codigo de TX.
3. Alimentar el modulo NRF24L01 unicamete y exclusivamente con el regulador de  3.3V
4. En caso de usar el motor alimentarlo de una bateria externa y no del arduino ya que este no proporciona la corriente suficiente.

![](https://github.com/humberto9003/BarcoNRF24l01/blob/master/Tx_Barco.jpg)

![](https://github.com/humberto9003/BarcoNRF24l01/blob/master/Rx_Barco.jpg)


Podras comunicar dos arduinos por radiocomunicación, para este caso en particular poder manipular un servomor y motor con un Joystick. 

Por: [Humberto Pastor](https://https://github.com/humberto9003)
