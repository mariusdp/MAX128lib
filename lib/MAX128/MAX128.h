/* MAX128.h library for Microchip DAC
   by Marius P.
   inspired from many sources: Thank to everyone
   Version: 1.0*/
   

#if defined(ARDUINO) && ARDUINO >= 100
  #include "Arduino.h"
#endif

#include <Wire.h>

class MAX128
{
   public:
     MAX128(uint8_t address);
     int readADC(byte channel);
   private:
     byte MSB;
     byte LSB;     
     int MSByte;
     int LSByte;
     uint8_t _address;
     uint8_t numBytes;
     byte controlByte;
     int data;
};

