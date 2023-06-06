#include <SoftwareSerial.h>

const int _P1Rx = 10;
const int _P1Tx = 11;
const int _P2Rx = 8;
const int _P2Tx = 9;
const int _BaudRate = 9600;

SoftwareSerial portOne(_P1Rx, _P1Tx);
SoftwareSerial portTwo(_P2Rx, _P2Tx);

void setup()  
{
  Serial.begin(_BaudRate);
  portOne.begin(_BaudRate);
  portTwo.begin(_BaudRate);
} 
void loop()  
{ 
  Serial.println("Enter character to be transmitted: ");
  while(Serial.available() == 0){
  }

  char ch = Serial.read();
  softSerial.write(ch);
  delay (1000);
}
