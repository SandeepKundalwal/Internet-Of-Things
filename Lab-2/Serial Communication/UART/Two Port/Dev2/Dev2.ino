#include <SoftwareSerial.h>
SoftwareSerial ArduinoMaster(10,11);
SoftwareSerial ArduinoSlave(10,11);
char cmd="";
char old_cmd;
char answer="";
char old_answer;
void setup(){
  Serial.begin(9600);
  //Serial.println("ENTER Commands:");
  ArduinoMaster.begin(9600);
  ArduinoSlave.begin(9600);
}
void loop(){
  if(Serial.available()){
    String data = Serial.readStringUntil('\n');
    Serial.print("Data sent: ");
    Serial.println(data);
    writeString(data);
  }

  ArduinoSlave.listen();
  if(ArduinoSlave.available()){
    String slaveData = ArduinoSlave.readStringUntil('\n');
    Serial.print("Data recieved: ");
    Serial.println(slaveData);
  }
}

void writeString(String data){
  for(int i = 0; i < data.length(); i++){
    ArduinoSlave.write(data[i]);
  }
}
//void loop(){
//  old_cmd=cmd;
//  old_answer=answer;
//  //Read command from monitor
//  if (Serial.available()){
//    cmd=Serial.read();
//  }
//  //Read answer from slave
//  if (ArduinoSlave.available()){
//    answer=ArduinoSlave.read();
//  }
//  //Send data to slave
//  if(cmd!=old_cmd){
//    Serial.print("Data sent : ");
//    Serial.println(cmd);
//    ArduinoSlave.write(cmd);
//  }
//  //Send answer to monitor
//  if(answer!=old_answer){
//    Serial.print("Data received : ");
//    Serial.println(answer);
//  }
//}
