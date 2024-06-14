#include <Arduino.h>
#include "Serial_display.h"
#include "Wifi_Data.h"
#include "Controller.h"

/**
 * @brief Main file for Arduino setup and loop functions.
 */

/***************************************************************************
*                               GLOBAL VARIABLES
***************************************************************************/

/**
 * @defgroup WiFi WiFi Settings
 * @brief Group of variables related to WiFi settings.
 * @{
 */
const char* ssid = "IDP-Robotica";  /**< SSID of the WiFi network. */
const char* password = "fbtownrbes"; /**< Password for the WiFi network. */
const char* host = "141.252.29.70"; /**< IP address of the Raspberry Pi. */
const uint16_t port = 65432; /**< Port number for the connection to the Raspberry Pi. */
bool RaspConnection = 0; /**< Indicates if the Raspberry Pi is connected (1) or not (0). */
String dataToSend = ""; /**< Data to send to the Raspberry Pi. */
String DataRasp = ""; /**< Data received from the Raspberry Pi. */
/** @} */ // end of WiFi group

/**
 * @defgroup Display Display Settings
 * @brief Group of variables related to display settings.
 * @{
 */
int CurrentPage = 0; /**< Current page on the display. */
int SpeedServo = 10; /**< Servo speed (Slow 10, Medium 25, Fast 50). */
int SpeedTranslation = 100; /**< Translation speed (Slow 100, Medium 200, Fast 300). */
int ForceGripper = 50; /**< Gripper force (Low 50, Medium 100, Power 150). */
int Autonome = 0; /**< Autonome mode status (On 1, Off 0). */
int CameraLight = 0; /**< Camera light status (On 1, Off 0). */
int RaspberryOff = 0; /**< Indicates if the Raspberry Pi should be turned off (1). */
int ReadServo = 0; /**< Specifies which servo to read (Servo1 1, Servo2 2, Servo3 3, Servo4 4, Servo5 5). */
int GripperHead = 1; /**< Gripper head type (Cilinder 1, Pen 2, Tools 3). */
/** @} */ // end of Display group

/**
 * @defgroup Controller Controller Settings
 * @brief Group of variables related to the controller settings.
 * @{
 */
int xValueJ1 = 0; /**< Joystick 1 X value. */
int yValueJ1 = 0; /**< Joystick 1 Y value. */
int xValueJ2 = 0; /**< Joystick 2 X value. */
int yValueJ2 = 0; /**< Joystick 2 Y value. */
const int buttonPin = 26; /**< Button pin on ESP32. */
int GripperButton = 0; /**< Button state for the gripper. */
/** @} */ // end of Controller group

/**
 * @brief Setup function for Arduino.
 * Initializes the button pin, serial communication, and WiFi connection.
 */
void setup() {
  pinMode(buttonPin, INPUT_PULLUP); /**< Set button pin to input with pull-up resistor. */
  Serial.begin(9600); /**< Initialize serial communication with baud rate 9600. */
  WifiSetup(ssid, password); /**< Connect to the WiFi network. */
}

/**
 * @brief Main loop function for Arduino.
 * Handles serial communication, controller input, and WiFi data transmission.
 */
void loop() {
  ConnectionPrint(CurrentPage, RaspConnection); /**< Update connection status on the display. */
  RaspConnection = WifiCheck(host, port); /**< Check connection to the Raspberry Pi. */
  ReadSerialData(SpeedServo, SpeedTranslation, ForceGripper, Autonome, CameraLight, RaspberryOff, CurrentPage, ReadServo, GripperHead); /**< Read data from the display. */
  ReadController(xValueJ1, yValueJ1, xValueJ2, yValueJ2, GripperButton, buttonPin); /**< Read joystick values and button state from the controller. */
 
  if (RaspConnection == 1) { /**< If Raspberry Pi is connected. */
    // Combine values into a single string to send to the Raspberry Pi
    dataToSend = String(SpeedServo) + "," + String(SpeedTranslation) + "," + String(ForceGripper) + "," + String(Autonome) + "," + String(CameraLight) + "," + String(xValueJ1) + "," + String(yValueJ1) + "," + String(xValueJ2) + "," + String(yValueJ2) + "," + String(RaspberryOff) + "," + String(ReadServo) + "," + String(GripperButton) + "," + String(GripperHead);
    WifiSend(dataToSend); /**< Send data to the Raspberry Pi. */

    if ((ReadServo == 1) || (ReadServo == 2) || (ReadServo == 3) || (ReadServo == 4) || (ReadServo == 5)) { /**< If a servo needs to be read. */
      WifiRead(DataRasp); /**< Read data from the Raspberry Pi. */
      SendServoData(DataRasp, ReadServo); /**< Send servo data to the display. */
    }  
    if (RaspberryOff == 1) { /**< If the Raspberry Pi needs to shut down. */
      WifiRead(DataRasp); /**< Read data from the Raspberry Pi. */
      if (DataRasp == "Raspberry uit") { /**< If the received data indicates the Raspberry Pi is off. */
        PrintToDisplay("page421.t12.txt=\"OFF\""); /**< Display "OFF" on the screen. */
        RaspberryOff = 0; /**< Reset the RaspberryOff flag. */
      }
    }
  }
  printf("helo");
}