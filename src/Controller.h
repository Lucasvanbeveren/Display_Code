/***************************************************************************
*                             PREPROCESSOR GUARDS
***************************************************************************/
#ifndef CONTROLLER_H
#define CONTROLLER_H

/***************************************************************************
*                                DEPENDENCIES
***************************************************************************/
#include <Arduino.h>



/***************************************************************************
*                             FUNCTION PROTOTYPES
***************************************************************************/

/**
 * @brief This function reads the joysticks on the controller and writes them to the delivered values.
 * 
 * @param xValueJ1      This is the x value output of the first joystick.
 * @param yValueJ1      This is the y value output of the first joystick.
 * @param xValueJ2      This is the x value output of the second joystick.
 * @param yValueJ2      This is the y value output of the second joystick.
 */ 
void ReadJoysticks(int &xValueJ1, int &yValueJ1, int &xValueJ2, int &yValueJ2);

/**
 * @brief This function reads the state of the button. If the button is pressed, the function will return true. If not, it will return false.
 * 
 * @param buttonPin     This is the connection pin of the button.
 * 
 * @retval              true if button is pressed.
 * @retval              false if button is not pressed.
 */
bool ReadButton(const int buttonPin);

/**
 * @brief This is the main function. this will call the other functions of the controller
 * 
 * @param xValueJ1      This is the x value output of the first joystick.
 * @param yValueJ1      This is the y value output of the first joystick.
 * @param xValueJ2      This is the x value output of the second joystick.
 * @param yValueJ2      This is the y value output of the second joystick.
 * @param GripperButton This is the state of the gripper button.
 * @param buttonPin     This is the connection pin of the button.
 */
void ReadController(int &xValueJ1, int &yValueJ1, int &xValueJ2, int &yValueJ2, int &GripperButton, const int buttonPin);

#endif // CONTROLLER_H