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
const uint16_t port = 8585;  //Port Number Node-Red
//const uint16_t port = 8686;  //Port Number RPI
const char *nodered_server = "192.168.43.113";   //IP Address of the Server Sandeep
//const char *nodered_server = "192.168.43.39";   //IP Address of the Server Mahima


WiFiUDP UDPClient;  //Creating instance of WiFiClient

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  
  /**
   * Connect to the WiFi
   */
  connect_WiFi();
  UDPClient.begin(port);
  Serial.print("Listening on UDP port ");
  Serial.println(port);
}

char packet[255];
void loop() {
//   put your main code here, to run repeatedly:
  int packetSize = UDPClient.parsePacket();
  if(packetSize) {
    UDPClient.read(packet, 255);
    float fuel = atof(packet);     
    if(fuel < 20){
      digitalWrite(LED_BUILTIN, LOW);
      delay(125);
      digitalWrite(LED_BUILTIN, HIGH);
      delay(125);
    } else {
      digitalWrite(LED_BUILTIN, LOW);
      delay(250);
    }
  }
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
