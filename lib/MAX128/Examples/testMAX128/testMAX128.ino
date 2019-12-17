/* Board I2C / TWI pins 
   Heltec WiFi Kit 32 (ESP32 with OLED): 21 (SAD), 22 (SCL)
   Uno, Ethernet:                        A4 (SDA), A5 (SCL) 
   Mega2560:                             20 (SDA), 21 (SCL) 
   Leonardo:                              2 (SDA), 3 (SCL) 
   Due:                                  20 (SDA), 21 (SCL), SDA1, SCL1 
 */
#include "Arduino.h"
#include "MAX128.h"
#include "Wire.h"
/* Address: 0x28
   A2,A1,A0: tied to GND */
   
byte address = 0x28;
int data = 0;
int channel = 2;
float volt;

MAX128 adc(address);

void setup(){ 
 Serial.begin(115200);
}
void loop(){
 data = adc.readADC(channel);
 volt = (5.096/4096)*data; //External ref conected on 5V out ESP32 (measured with DMM)
 Serial.println("Volt: " + String(volt));
 //Serial.println(volt);
 delay(1000);
}
