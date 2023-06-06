#define BAUDRATE 9600

void setup() {
  Serial.begin(BAUDRATE);
  pinMode(LED_BUILTIN, OUTPUT);  // Initialize the LED_BUILTIN pin as an output
}

// the loop function runs over and over again forever
void loop() {
  int randNumber = random(1,8);
  String serialPrint = "Blinking the LED ";
  serialPrint += randNumber;
  serialPrint += " time(s)";
  Serial.println(serialPrint);
  for(int i = 0; i < randNumber; i++){
    /**
     * Turn the LED on (Note that LOW is the voltage level but actually the LED is on; this is because
     * it is active low on the ESP-01)
     */
    digitalWrite(LED_BUILTIN, LOW); 
    delay(1000);
    digitalWrite(LED_BUILTIN, HIGH);  // Turn the LED off by making the voltage HIGH
    delay(500);
  }
  delay(4500); 
}
