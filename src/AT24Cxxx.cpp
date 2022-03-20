//AT24Cxxx driver CPP file
#include "Arduino.h"
#include "Wire.h"
#include "AT24Cxxx.h"
#define WRITE_DELAY 1

AT24CXXX::AT24CXXX(uint8_t address){
	Wire.begin();
	_address = address;
}

void AT24CXXX::write(uint16_t writeAddress, uint8_t* data, uint8_t len){

	sendRWAddress(writeAddress);
	
	for(uint8_t i = 0; i < len; i++){
		Wire.write(data[i]);
		delay(WRITE_DELAY);
	}
	Wire.endTransmission();

}

void AT24CXXX::read(uint16_t readAddress, uint8_t* data, uint8_t len){

	sendRWAddress(readAddress);
	Wire.endTransmission();

	Wire.requestFrom(_address, len);
	for(uint8_t i = 0; i < len; i++){
		if( Wire.available() ) 
			data[i] = Wire.read();
	}
}

void AT24CXXX::sendRWAddress(uint16_t rw_address) {
	Wire.beginTransmission(_address);
	Wire.write((byte)(rw_address & 0xFF00) >> 8);
	Wire.write((byte)(rw_address & 0x00FF));
}
