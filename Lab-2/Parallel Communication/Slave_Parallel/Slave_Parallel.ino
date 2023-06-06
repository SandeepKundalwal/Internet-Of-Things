/* Receiver Arduino code */
void setup() {
  // put your setup code here, to run once:
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  pinMode(10, INPUT);
  
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  // read the message
  int bit2 = digitalRead(8);
  int bit1 = digitalRead(9);
  int bit0 = digitalRead(10);

  if(bit2 == 0 && bit1 == 0 && bit0 == 0){
    return;
  } else {
    BCDtoDecimalConversion(bit2, bit1, bit0);
  }
  delay(1000);
} // end loop

void BCDtoDecimalConversion(int bit2, int bit1, int bit0){
  String BCDString = "";
  BCDString += bit2;
  BCDString += bit1;
  BCDString += bit0;

  if(BCDString == "001"){
    Serial.println("Normal");
  } else if(BCDString == "010"){
    Serial.println("Engine temp low");
  } else if(BCDString == "011"){
    Serial.println("Coolant low");
  } else if(BCDString == "100"){
    Serial.println("Oil low");
  } else if(BCDString == "101"){
    Serial.println("Tyre Pressure Low");
  } else if(BCDString == "110"){
    Serial.println("Servcie Error");
  } else {
    Serial.println("Invalid Choice.");
  }
}
