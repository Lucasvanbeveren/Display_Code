/***************************************************************************
*                             PREPROCESSOR GUARDS
***************************************************************************/
#ifndef SERIAL_DISPLAY_H
#define SERIAL_DISPLAY_H

/***************************************************************************
*                                DEPENDENCIES
***************************************************************************/
#include <Arduino.h>

/***************************************************************************
*                              DEFINE MACRO GROUPS
***************************************************************************/
/**
 * @defgroup ServoSpeeds Servo Speeds
 * @brief Macros to represent different speed levels for servos.
 */
/**
 * @defgroup TranslationSpeeds Translation Speeds
 * @brief Macros to represent different translation speed levels.
 */
/**
 * @defgroup GripperForces Gripper Forces
 * @brief Macros to represent different force levels for the gripper.
 */
/**
 * @defgroup Autonome Autonome
 * @brief Macros to represent the autonome state.
 */
/**
 * @defgroup CameraLight Camera Light
 * @brief Macros to represent the state of the camera light.
 */
/**
 * @defgroup RaspberryPi Raspberry Pi Connection
 * @brief Macros to represent the state of the Raspberry Pi connection.
 */
/**
 * @defgroup ServoReadings Servo Readings
 * @brief Macros to represent different servo readings.
 */
/**
 * @defgroup RobotHeads Robot Heads
 * @brief Macros to represent different robot heads.
 */


/***************************************************************************
*                              DEFINES IN GROUPS
***************************************************************************/
/**
 * @addtogroup ServoSpeeds
 * @{
 */
#define SpeedServoSlow      10          /**< Slow speed for servos. */
#define SpeedServoMedium    25          /**< Medium speed for servos. */
#define SpeedServoFast      50          /**< Fast speed for servos. */
/** @} */ // end of ServoSpeeds group

/**
 * @addtogroup TranslationSpeeds
 * @{
 */
#define SpeedTranslationSlow    100     /**< Slow translation speed. */
#define SpeedTranslationMedium  200     /**< Medium translation speed. */
#define SpeedTranslationFast    300     /**< Fast translation speed. */
/** @} */ // end of TranslationSpeeds group

/**
 * @addtogroup GripperForces
 * @{
 */
#define ForceGripperLow     50          /**< Low force for the gripper. */
#define ForceGripperMedium  100         /**< Medium force for the gripper. */
#define ForceGripperPower   150         /**< High force for the gripper. */
/** @} */ // end of GripperForces group

/**
 * @addtogroup Autonome
 * @{
 */
#define AutonomeOn          1           /**< Autonome mode on. */
#define AutonomeOff         0           /**< Autonome mode off. */
/** @} */ // end of Autonome group

/**
 * @addtogroup CameraLight
 * @{
 */
#define CameraLightOn       1           /**< Camera light on. */
#define CameraLightOff      0           /**< Camera light off. */
/** @} */ // end of CameraLight group

/**
 * @addtogroup RaspberryPi
 * @{
 */
#define RaspberryConnected      1       /**< Raspberry Pi connected. */
#define RaspberryDisconnected   0       /**< Raspberry Pi disconnected. */
#define Raspberryoff            1       /**< Raspberry Pi shutdown. */
/** @} */ // end of RaspberryPi group

/**
 * @addtogroup ServoReadings
 * @{
 */
#define ReadServo1              1       /**< Reading from servo 1. */
#define ReadServo2              2       /**< Reading from servo 2. */
#define ReadServo3              3       /**< Reading from servo 3. */
#define ReadServo4              4       /**< Reading from servo 4. */
#define ReadServo5              5       /**< Reading from servo 5. */
/** @} */ // end of ServoReadings group

/**
 * @addtogroup RobotHeads
 * @{
 */
#define HeadCilinder            1       /**< Cilinder head. */
#define HeadPen                 2       /**< Pen head. */
#define HeadTools               3       /**< Tools head. */
/** @} */ // end of RobotHeads group

/**
 * @addtogroup Color
 * @{
 */
#define All                 0           /**< all colors. */
#define Silver              1           /**< Cilinder head. */
#define Red                 2           /**< Pen head. */
#define Green               3           /**< Tools head. */
#define Blue                4           /**< Pen head. */
#define Pink                5           /**< Tools head. */
/** @} */ // end of RobotHeads group



/***************************************************************************
*                             FUNCTION PROTOTYPES
***************************************************************************/

/**
 * @brief This function prints information to the display
 * 
 * @param print This is the text it needs to send to the display
 */
void PrintToDisplay(String print);

/**
 * @brief This function prints the right information to the new page and sets "CurrentPage" to the new page
 * 
 * @param data_from_display     This is the data of the display
 * @param SetServoSpeed         This is the current servo speed
 * @param SetTranslationSpeed   This is the current translation speed
 * @param SetGripperForce       This is the current gripper force
 * @param SetAutonome           This is the current state of autonome
 * @param SetCameraLight        This is the current state of camera light
 * @param CurrentPage           This is the current page the display is on
 * @param GripperHead           This is the current gripper head
 */
void NextPages(String data_from_display, int SetServoSpeed, int SetTranslationSpeed, int SetGripperForce, int SetAutonome, int SetCameraLight, int &CurrentPage, int &GripperHead);

/**
 * @brief This function prints the current connection with the raspberry to the display
 * 
 * @param CurrentPage           This is the current page the display is on
 * @param RaspConnection        This is the current connection to the raspberry [Connected(1), Not connected(0)]
 */
void ConnectionPrint(int CurrentPage, bool RaspConnection); 

/**
 * @brief This function splits a string at the position of the separator
 * 
 * @param str                   This is the string to split
 * @param separator             This is the separator 
 */
void SplitString (String str, char separator);

/**
 * @brief This function sends the servo information it received from the Raspberry to the display.
 * 
 * @param DataRasp              This is the data recieved from the Raspberry
 * @param ReadServo             This is the servo of which the information is meant
 */
void SendServoData(String DataRasp, int &ReadServo);

/**
 * @brief This function returns the servo speed and sends it to the display
 * 
 * @param data_from_display     This is the data of the display
 * 
 * @return
 *      - @ref SpeedServoSlow
 *      - @ref SpeedServoMedium
 *      - @ref SpeedServoFast
 */
int SetServoSpeed(String data_from_display);

/**
 * @brief This function returns the translation speed and sends it to the display
 * 
 * @param data_from_display     This is the data of the display
 * @return 
 *      - @ref SpeedTranslationSlow
 *      - @ref SpeedTranslationMedium
 *      - @ref SpeedTranslationFast
 */
int SetTranslationSpeed(String data_from_display);

/**
 * @brief This function returns the gripper force and sends it to the display
 * 
 * @param data_from_display     This is the data of the display
 * @return 
 *      - @ref ForceGripperLow
 *      - @ref ForceGripperMedium
 *      - @ref ForceGripperPower
 */
int SetGripperForce(String data_from_display);

/**
 * @brief This function returns the status of autonome and sends it to the display
 * 
 * @param data_from_display    This is the data of the display
 * @return 
 *      - @ref AutonomeOn
 *      - @ref AutonomeOff
 */
int SetAutonome(String data_from_display);

/**
 * @brief This function returns the status of the camera light and sends it to the display
 * 
 * @param data_from_display     This is the data of the display
 * @return 
 *      - @ref CameraLightOn
 *      - @ref CameraLightOff
 */
int SetCameraLight(String data_from_display);

/**
 * @brief This function returns the status if the Raspberry needs to be shut down
 * 
 * @param data_from_display     This is the data of the display
 * @return 
 * *      - @ref Raspberryoff
 */
int SetRaspberryOff(String data_from_display);

/**
 * @brief This function returns which servo needs to be read by the Raspberry Pi.
 * 
 * @param data_from_display     This is the data of the display
 * @return 
 *      - @ref ReadServo1
 *      - @ref ReadServo2
 *      - @ref ReadServo3
 *      - @ref ReadServo4
 *      - @ref ReadServo5
 */
int SetReadServo(String data_from_display);

/**
 * @brief This function returns the gripper head and sends it to the display
 * 
 * @param data_from_display     This is the data of the display
 * @return 
 *      - @ref HeadCilinder
 *      - @ref HeadPen
 *      - @ref HeadTools
 */
int SetGripperHead(String data_from_display);

/**
 * @brief This funtion returns the Color and sends it to the display
 * 
 * @param data_from_display 
 * @return 
 *      - @ref All
 *      - @ref Silver
 *      - @ref Red
 *      - @ref Green
 *      - @ref Blue
 *      - @ref Pink
 */
int SetColor(String data_from_display);


/**
 * @brief This function reads the data from the display and ensures that the correct functions are called.
 * 
 * @param SpeedServo            This is the current servo speed
 * @param SpeedTranslation      This is the current translation speed
 * @param ForceGripper          This is the current gripper force 
 * @param Autonome              This is the current state of autonome
 * @param CameraLight           This is the current state of the camera light
 * @param RaspberryOff          This is the current state of which the raspberry needs to be shut down
 * @param CurrentPage           This is the current page the display is on
 * @param ReadServo             This is the current servo who needs to be read
 * @param GipperHead            This is the current gripper head  
 * @param Color                 This is the current Color   
 */
void ReadSerialData(int &SpeedServo, int &SpeedTranslation, int &ForceGripper, int &Autonome, int &CameraLight, int &RaspberryOff, int &CurrentPage, int &ReadServo, int &GipperHead, int &Color);

#endif // SERIAL_DISPLAY_H