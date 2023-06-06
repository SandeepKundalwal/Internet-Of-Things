/**
 * Global Variables declared here
 */
static unsigned int _ITERATION = 0;

// the setup function runs once when you press reset or power the board
void setup() {
  //BAUD RATE -> 9600
  Serial.begin(9600);
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  if(_ITERATION < 3){
    _HomeAutomation();
    _ITERATION++;
  }
}

void _HomeAutomation(){
  Serial.println("Enter the temperature: ");
  while(Serial.available() == 0) {}
  
  int _temparature = Serial.parseInt();
  Serial.println(_temparature);
  
  if(_temparature <= 26){
    Serial.println("Winter is here. Starks will rule the NORTH.\nTurn OFF the AC says Sansa Stark. ");
    _ManualBlinker(3);
  } else {
    Serial.println("Summer is here. Lannisters will rule the NORTH.\nTurn ON the AC says Tyrion Lannister.");
    _ManualBlinker(6);
  }
}

/**
 * it will manually blink the LED based on the userinput
 * @userInput -> the number of times the LED should blink
 */
void _ManualBlinker(int _userInput){
  for(int i = 0; i < _userInput; i++){
    digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
    delay(500);                       // wait for a second
    digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
    delay(500); 
  }
}
