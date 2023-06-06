int iteration = 5;
bool breakLoop = false;

void setup()
{
  Serial.begin(9600);
}

void loop(){
  if(breakLoop == false){
    for(int i =0; i < iteration; i++){
    int randomNumber = random(2,25);
    Serial.println(randomNumber);
    if(i == 4){
      while(Serial.available() == 0){}
      String ack = Serial.readStringUntil('\n');
      if(ack == "Arduino: Acknowledgement recieved!"){
        Serial.println(ack);
        continue;
      } else {
        breakLoop = true;
        break;
      }
    }
  }
  }
}
