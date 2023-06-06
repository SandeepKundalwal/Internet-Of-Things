#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

/**
 * WiFi parameters to be configured
 */
const char* ssid = "XXXXXXX"; // Wifi's SSID
const char* password = "XXXXXXX"; // Wifi's Password

/**
 * Socket Details
 */
const uint16_t port = 1880;  //Node-Red default port Number
const char *nodered_server = "XXX.XXX.XXX.XXX";   //IP Address of the Server

WiFiUDP UDPClient;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  /**
   * Connect to the WiFi
   */
  connect_WiFi();
}

void loop() {
  // put your main code here, to run repeatedly:
  int randomNumber = random(100);
  UDPClient.beginPacket(nodered_server, port);
  UDPClient.write(byte(randomNumber));
  UDPClient.endPacket();
  delay(1000);
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
