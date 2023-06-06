#include<Wire.h>

#define SLAVE_ADDR 9

#define ANSWERSIZE 14

#define BAUDRATE 9600

String answer = "Hello Master.!";

void setup(){
  Wire.begin(SLAVE_ADDR);

  Wire.onRequest(requestEvent);

  Wire.onReceive(receiveEvent);

  Serial.begin(BAUDRATE);
  Serial.println("I2C Slave Demonstration");
  Serial.println("----------------------------------------------------------------------------------------");
}

void receiveEvent(){
    String recievedMessage = "";
    while(Wire.available()){
      char ch = Wire.read();
      recievedMessage += ch;
    }
    Serial.println("Recieved data from master: " + recievedMessage);
}

void requestEvent(){
  byte response[ANSWERSIZE];

  for(byte i = 0; i < ANSWERSIZE; i++){
    response[i] = (byte)answer.charAt(i);
  }


  Wire.write(response, sizeof(response));

  Serial.println("Sending to Master: " + answer);
  Serial.println();
}

void loop(){
  delay(500);
}
