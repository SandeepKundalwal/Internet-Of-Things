/* Receiver Arduino code */
void setup() {
  // put your setup code here, to run once:
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  pinMode(10, INPUT);
  pinMode(11, INPUT);
  
  Serial.begin(9600);
}

int iteration = 0;
void loop() {
  // put your main code here, to run repeatedly:
  // read the message
  if(iteration++ < 10){
    int bit3 = digitalRead(8);
    int bit2 = digitalRead(9);
    int bit1 = digitalRead(10);
    int bit0 = digitalRead(11);

    String decimal = "Received: ";
    decimal += BCDtoDecimalConversion(bit3, bit2, bit1, bit0);
    Serial.println(decimal);
    delay(1000);
  }
  
} // end loop

int BCDtoDecimalConversion(int bit3, int bit2, int bit1, int bit0){
  String BCDString = "";
  BCDString += bit3;
  BCDString += bit2;
  BCDString += bit1;
  BCDString += bit0;

  int sum = 0, mul = 1;
  for(int i = BCDString.length() - 1; i >= 0; i--){
    sum += (BCDString.charAt(i) - '0') * mul;
    mul *= 2;
  }
  return sum;
}
