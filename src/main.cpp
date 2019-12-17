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
   
//byte address = 0x28;
int address = 0x28;
//int data = 0;
//int channel = 2;
//float volt;

MAX128 adc(address);

void setup(){
 Wire.begin(); 
 Serial.begin(115200);

}
void loop(){
 int data0 = adc.readADC(0);
 int data1 = adc.readADC(1);
 int data2 = adc.readADC(2);
 float volt0 = (5.096/4096)*data0; //External ref conected on 5V out ESP32 (measured with DMM)
 float volt1 = (5.096/4096)*data1; //External ref conected on 5V out ESP32 (measured with DMM)
 float volt2 = (24.500/4096)*data2; //External ref conected on 5V out ESP32 (measured with DMM)
 Serial.println("------------------------------");
 Serial.print("Data 0: ");
 Serial.println(data0);
 Serial.println("Volt 0: " + String(volt0) +" V");
 //Serial.println(volt0);
 Serial.print("Data 1: ");
 Serial.println(data1);
 Serial.println("Volt 1: " + String(volt1) +" V");
 //Serial.println(volt1);
 Serial.print("Data 2: ");
 Serial.println(data2);
 Serial.println("Volt 2: " + String(volt2) +" V");
// Serial.println(volt2);
 Serial.println("------------------------------");
 delay(2000);
}
