unsigned short altitude[500];
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  generatePlot();
}

// Runtime = 1:40 mins
int plotter = 0;
void loop() {
  // put your main code here, to run repeatedly:
  if(plotter < 500){
    Serial.println(altitude[plotter++]);
  }
  delay(50);
}

void generatePlot(){
  int i = 0;
  for(; i < 100; i++){
    altitude[i] = i;
  }
  
  for(; i < 400; i++){
    altitude[i] = 100;
  }

  int decreasingAltitude = 99;
  for(; i < 500; i++){
    altitude[i] = decreasingAltitude--;
  }  
}
