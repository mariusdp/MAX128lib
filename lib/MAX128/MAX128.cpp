#if defined(ARDUINO) && ARDUINO >= 100
  #include "Arduino.h"
#endif

#include <MAX128.h>
#include <Wire.h>

// 7 bit address

MAX128::MAX128(byte address){
  _address = address;
  Wire.begin();
  //Serial.begin(9600);
}

int MAX128::readADC(byte channel){
numBytes = 2; // number of Bytes to read
switch(channel){
  case 0:
    controlByte = 0x88;
    break;
  case 1:
    controlByte = 0x98;
    break;
  case 2:
    controlByte = 0xA8;
    break;
  case 3:
    controlByte = 0xB8;
    break;
  case 4:
    controlByte = 0xC8;
    break;
  case 5:
    controlByte = 0xD8;
    break;
  case 6:
    controlByte = 0xE8;
    break;
  case 7:
    controlByte = 0xF8;
    break;
    
}

Wire.beginTransmission(_address);
Wire.write(controlByte);
Wire.endTransmission();
Wire.requestFrom(_address,numBytes);
MSB = Wire.read();
LSB = Wire.read();
MSByte = MSB << 4; // Shift to the left 4 bits for MSByte
LSByte = LSB >> 4; // Shift to the right 4 bits for LSByte
data = MSByte | LSByte;
//Serial.print("MSByte: ");
//Serial.println(MSByte,HEX);
//Serial.print("LSByte: ");
//Serial.println(LSByte,HEX);
//Serial.print("Data: ");
//Serial.println(data,HEX);
return data;
}
