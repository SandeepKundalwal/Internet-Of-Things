#include<Wire.h>

#define SLAVE_ADDR 9

#define ANSWERSIZE 14

#define BAUDRATE 9600

int x = 0;

void setup(){
  Wire.begin();

  Serial.begin(BAUDRATE);
  Serial.println("I2C Master Demonstration");
  Serial.println("----------------------------------------------------------------------------------------");
}

void loop(){
   while(Serial.available() == 0){
   }
   
   String transmittedMessage = Serial.readString();

   Wire.beginTransmission(SLAVE_ADDR);
   Wire.write(transmittedMessage.c_str());
   Wire.endTransmission();

   Wire.requestFrom(SLAVE_ADDR, ANSWERSIZE);

   String response = "";
   while(Wire.available()){
      char b = Wire.read();
      response += b;
   }

   Serial.println("Recieved data: " + response);
   delay(500);
}
