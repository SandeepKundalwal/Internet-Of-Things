#include <ESP8266WiFi.h>
#include <WiFiClient.h>

/**
 * WiFi parameters to be configured
 */
const char* ssid = ""; // Wifi's SSID
const char* password = ""; // Wifi's Password

/**
 * Socket Details
 */
const uint16_t port = 8585;  //Port Number
const char *rpi_server = "XXX.XXX.XXX.XXX";   //IP Address of the Server

WiFiClient client;  //Creating instance of WiFiClient

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  /**
   * Connect to the WiFi
   */
  connect_WiFi();

  /**
   * Connecting to Server
   */
  Serial.println("Connecting to server...");
  //In case the connection to server fails
  if(!client.connect(rpi_server, port)){
    Serial.println("Connection to Server Failed.");
    Serial.println();
    delay(1000);
    return;
  }
  Serial.println("Connection Established Successfully.");
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Press T or t to get the time");
  while(Serial.available() == 0){}
  String serial_read = Serial.readStringUntil('\n');
  client.println(serial_read);
  while(client.available() == 0){}
  String response = client.readString();
  Serial.println(response);
  Serial.println();
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
