/***************************************************************************
*                             PREPROCESSOR GUARDS
***************************************************************************/
#ifndef WIFI_DATA_H
#define WIFI_DATA_H

/***************************************************************************
*                                DEPENDENCIES
***************************************************************************/
#include <Arduino.h>

/***************************************************************************
*                              DEFINES IN GROUPS
***************************************************************************/

/**
 * @addtogroup RaspberryPi
 * @{
 */
#define RaspConnected       1   /**< Indicates that the Raspberry Pi is connected. */
#define RaspDisconnected    0   /**< Indicates that the Raspberry Pi is disconnected. */
/** @} */ // end of RaspberryPi group




/***************************************************************************
*                             FUNCTION PROTOTYPES
***************************************************************************/

/**
 * @brief This function checks if there is a WiFi connection between the Controller and the Raspberry Pi.
 * 
 * @param host This is the ip adress of the Raspberry pi.
 * @param port This is the port on which the Raspberry Pi is listening.
 * @retval TRUE if there is a WIFI connection
 * @retval FALSE if there isn't a WIFI connection 
 */
bool WifiCheck(const char* host, const uint16_t port);

/**
 * @brief This function makes connection to the WIFI network
 * 
 * @param ssid This is the name of the WIFI network
 * @param password This is the password of the WIFI network
 */
void WifiSetup(const char* &ssid, const char* &password);

/**
 * @brief This function sends data to the Raspberry
 * 
 * @param dataToSend This is the data it needs to send
 */
void WifiSend(String dataToSend);

/**
 * @brief This funtion reads data from the raspberry
 * 
 * @param ReadRasp This is the data recieved from the Raspberry
 */
void WifiRead(String &ReadRasp);

#endif // WIFI_DATA_H