// 24CXXX EEPROM driver header file
#ifndef AT24CXXX_h
#define AT24CXXX_h

#include "Arduino.h"
#include "Wire.h"

class AT24CXXX
{
public: 
		AT24CXXX(uint8_t address);
		void write(uint16_t writeAddress, uint8_t* data, uint8_t len);
		void read(uint16_t readAddress, uint8_t* data, uint8_t len);

private:
		uint8_t _address;
		void sendRWAddress(uint16_t rw_address);
};

#endif
