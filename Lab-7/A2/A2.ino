void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  while(Serial.available() == 0){}
  int data = Serial.parseInt();
  if(data < 100){
    digitalWrite(LED_BUILTIN, HIGH);
    delay(125);
    digitalWrite(LED_BUILTIN, LOW);
    delay(125);
  } else {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(250);
  }
}
