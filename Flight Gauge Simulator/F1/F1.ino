#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

/**
 * WiFi parameters to be configured
 */
const char* ssid = "vivo 1803"; // Wifi's SSID
const char* password = "446228123"; // Wifi's Password

/**
 * Socket Details
 */
const uint16_t port = 1880;  //Port Number Node-Red
//const uint16_t port = 8484;  //Port Number RPI
const char *nodered_server = "192.168.43.113";   //IP Address of the Server Sandeep
//const char *nodered_server = "192.168.43.39";   //IP Address of the Server Mahima

WiFiUDP UDPClient;  //Creating instance of WiFiClient

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  /**
   * Connect to the WiFi
   */
  connect_WiFi();
  generateFuelPointsAndSend();
}

void sendUDP(String fuelData){
  UDPClient.beginPacket(nodered_server, port);
  UDPClient.print(fuelData);
  UDPClient.endPacket();
}

void generateFuelPointsAndSend(){
  float t = 0.00;
  for(int i = 0; i < 501; i++){
    String fuelData = String(((-0.29) * t) + 100);
    sendUDP(fuelData);
    t += 0.75;
    delay(250);
  }
}



void loop() {
//   put your main code here, to run repeatedly:
}

void connect_WiFi(){
  // WIFI_STA -> ESP32 connects to an access point
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  
  /*
   * 1.WiFi.status() can return ---> WL_CONNECTED: assigned when connected to a WIFI Network
   *                                 WL_NO_SHEILD: assigned when no WIFI shield is present
   *                                 etc.
   */
  delay(3000);
  String connection_string = "Connecting to WiFi...";
  Serial.print(connection_string);
  while(WiFi.status() != WL_CONNECTED){
     delay(500);
     Serial.print(".");
  }
  Serial.println();
  Serial.print("NodeMCU connected to WiFi with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();
}
