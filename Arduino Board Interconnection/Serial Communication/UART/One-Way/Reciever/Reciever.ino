#include <SoftwareSerial.h>

const int _Rx = 10;
const int _Tx = 11;
const int _BaudRate = 9600;

SoftwareSerial softSerial(_Rx, _Tx);

char ch;

void setup()  
{
  Serial.begin(_BaudRate);
  softSerial.begin(_BaudRate);
} 
void loop()  
{ 
  if (softSerial.available())
  {
    ch=softSerial.read();
    delay(1000);
    softSerial.print(ch);
    Serial.println(ch);
  }
}
