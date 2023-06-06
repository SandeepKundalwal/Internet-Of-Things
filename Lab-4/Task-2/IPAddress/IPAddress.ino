#include "ESP8266WiFi.h"
#define BAUDRATE 9600

// WiFi parameters to be configured
const char* ssid = "XXXXXX"; // Wifi's SSID
const char* password = "XXXXXX"; // Wifi's Password

void setup(void)
{ 
  Serial.begin(BAUDRATE);
  pinMode(LED_BUILTIN, OUTPUT);  // Initialize the LED_BUILTIN pin as an output
  // Connect to WiFi
  setupWiFi();
}

void loop() {
  // Nothing
}

void setupWiFi(){
  WiFi.begin(ssid, password);
  /**
   * 1.while wifi not connected yet, print '.', then after it connected, get out of the loop
   * 2.WiFi.status() can return ---> WL_CONNECTED: assigned when connected to a WIFI Network
   *                                 WL_NO_SHEILD: assigned when no WIFI shield is present
   *                                 etc.
   */
   while(WiFi.status() != WL_CONNECTED){
      delay(500);
      Serial.print(".");
   }
   Serial.println();
   Serial.println("WiFi connected");
   digitalWrite(LED_BUILTIN, LOW);
   Serial.println(WiFi.localIP());
}
