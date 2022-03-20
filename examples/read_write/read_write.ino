#include <AT24Cxxx.h>

AT24CXXX eeprom(0x50);

void setup() {
  char mextowrite[] = "Hello World";
  char message[25];
    
  Serial.begin(9600);
  Serial.println("Reading eeprom");
  eeprom.read(0, (uint8_t*) message, sizeof(message));
  Serial.println(message);

  eeprom.write(0, (uint8_t*)mextowrite, sizeof(message));
  Serial.println("eeprom written");
  
  Serial.println("Reading eeprom");
  eeprom.read(0, (uint8_t*) message, sizeof(message));
  Serial.println(message);
}

void loop() {
  // put your main code here, to run repeatedly:

}
