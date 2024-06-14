#include <Arduino.h>
#include "Wifi_Data.h"
#include <WiFi.h>

WiFiClient client;                        // Set WifiClient

void WifiSetup(const char* &ssid, const char* &password){
  WiFi.begin(ssid, password);             // Begin Wifi connection
  Serial.println("");                     // Print a emty line
  Serial.print("Connecting to ");         // Print "connecting to"
  Serial.print(ssid);                     // Print the name of the Wifi network
  while (WiFi.status() != WL_CONNECTED) { // While not connected
    Serial.print(".");                    // Print a "." 
    delay(500);                           // 500ms delay
  }

  Serial.println("WiFi connected.");      // Print WIfi connected
  Serial.println("IP address: ");         // Print "IP address: "
  Serial.println(WiFi.localIP());         // Print the IP address
  Serial.println("Mac address: ");        // Print "Mac adderss:"
  Serial.println(WiFi.macAddress());      // Print macAdderss
}

bool WifiCheck(const char* host, const uint16_t port){
  if (client.connect(host, port)) {       // Wifi connection check 
    return RaspConnected;                 // Return connected (1) 
  } else {
  return RaspDisconnected;                // Return disconnected (0)
  }
}

void WifiSend(String dataToSend){
  //Send Data
  Serial.println(dataToSend);            // Print DataToSend
  client.print(dataToSend);              // Send DataToSend to the Raspberry
  delay(10);                             // Delay 10ms
}

void WifiRead(String &DataRasp){
    while (client.connected()) {                  // While conneted to raspberry
    if (client.available()) {                     // If Data avalable 
      DataRasp = client.readStringUntil('\n');    // DataRasp is the data recieved untill \n
      Serial.println("Received: " + DataRasp);    // Print "Recieved" and DataRasp
      break;                                      // Go out of the if and while loop
    }
  }
}

