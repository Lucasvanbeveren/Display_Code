@mainpage S.J.O.N.N.I.E. Robot

Welcome to the documentation of our project. This project focuses on developing a robot capable of recognizing and sorting medical instruments. Below is an image giving an overview of the project.

![S.J.O.N.N.I.E.](Sjonnie.jpg)

The image above shows an overview of our robot project.

For detailed code documentation, see the following sections:
- @subpage main_code "Main Code"












<!-- This is the Main code -->
@page main_code Main Code

This page provides details about the main code used in the project.

![Main Code Flowchart](Main_ccp.png)

The image above shows a flowchart of the main code.

**Code Overview**
The main code initializes the robot and handles the primary control loop.

**Functions**

- [Wifi_Setup function](wifi_setup_function.html)
- [Connection_Print function](connection_print_function.html)
- [Wifi_Check funtion](wifi_check_function.html)
- [Read_Serial_Data funtion](read_serial_data_function.html)
- [Read_Controller funtion](read_controller_function.html)
- [Wifi_Send funtion](wifi_send_function.html)
- [Wifi_Read funtion](wifi_read_function.html)
- [Send_Servo_Data](send_servo_data_function.html)
- [Print_To_Display](print_to_display_function.html)


**Source Files**
- [main.ccp](main_8cpp.html)

**Library Files**
- @subpage controller "Controller"
- @subpage serial_display "Serial Display"
- @subpage wifi_data "WiFi Data"





<!-- This is the Controller Lib -->
@page controller Controller

This page provides details about the controller code used in the project.

**Code Overview**

The controller code is responsible for processing commands and handling wireless communication.

**Source Files**
- [Controller.h](_controller_8h.html)
- [Controller.cpp](_controller_8cpp.html)

**Functions**
- @subpage read_joysticks_function "Read Joysticks Function"
- @subpage read_button_function "Read Button Function"
- @subpage read_controller_function "Read Controller Function"


<!-- This is the read_joysticks Function -->
@page read_joysticks_function Read Joysticks Function

This page provides details about the function to read joystick values.

![Read Joysticks Function Flowchart](read_joysticks_function_flowchart.png)

The image above shows a flowchart of the Read Joysticks function.

**Function Overview**

This function reads the joysticks on the controller and writes them to the delivered values.

**Parameters**
- `xValueJ1`: The x value output of the first joystick.
- `yValueJ1`: The y value output of the first joystick.
- `xValueJ2`: The x value output of the second joystick.
- `yValueJ2`: The y value output of the second joystick.

**Source Files**

For detailed implementation and usage information, please refer to the source files:
- [Controller.h](_controller_8h.html)
- [Controller.cpp](_controller_8cpp.html)


<!-- This is the read_button Function -->
@page read_button_function Read Button Function

This page provides details about the function to read the state of a button.

![Read Button Function Flowchart](read_button_function_flowchart.png)

The image above shows a flowchart of the Read Button function.

**Function Overview**

This function reads the state of the button. If the button is pressed, the function will return true; otherwise, it will return false.

**Parameters**
- `buttonPin`: The connection pin of the button.

**Return Value**
- `true`: If the button is pressed.
- `false`: If the button is not pressed.

**Source Files**

For detailed implementation and usage information, please refer to the source files:
- [Controller.h](_controller_8h.html)
- [Controller.cpp](_controller_8cpp.html)


<!-- This is the read_controller Function -->
@page read_controller_function Read Controller Function

This page provides details about the main controller function.

![Read Controller Function Flowchart](read_controller_function_flowchart.png)

The image above shows a flowchart of the Read Controller function.

**Function Overview**

This function is the main function of the controller. It orchestrates the overall functionality by calling other controller functions.

**Parameters**
- `xValueJ1`: The x value output of the first joystick.
- `yValueJ1`: The y value output of the first joystick.
- `xValueJ2`: The x value output of the second joystick.
- `yValueJ2`: The y value output of the second joystick.
- `GripperButton`: The state of the gripper button.
- `buttonPin`: The connection pin of the button.

**Functions**
- [Read joysticks function](read_joysticks_function.html)
- [Read button function](read_button_function.html)

**Source Files**

For detailed implementation and usage information, please refer to the source files:
- [Controller.h](_controller_8h.html)
- [Controller.cpp](_controller_8cpp.html)















































<!-- This is the Serial_Display Lib -->
@page serial_display Serial Display

This page provides details about the serial display code used in the project.

**Code Overview**

The serial display code handles the initialization and updating of the serial display.

**Source Files**
- [Serial_display.h](_serial__display_8h.html)
- [Serial_display.cpp](_serial__display_8cpp.html)

**Functions**
- @subpage print_to_display_function "Print To Display Function"
- @subpage next_pages_function "Next Pages Function"
- @subpage connection_print_function "Connection Print Function"
- @subpage split_string_function "Split String Function"
- @subpage send_servo_data_function "Send Servo Data Function"
- @subpage set_servo_speed_function "Set Servo Speed Function"
- @subpage set_translation_speed_function "Set Translation Speed Function"
- @subpage set_gripper_force_function "Set Gripper Force Function"
- @subpage set_autonome_function "Set Autonome Function"
- @subpage set_camera_light_function "Set Camera Light Function"
- @subpage set_raspberry_off_function "Set Raspberry Off Function"
- @subpage set_read_servo_function "Set Read Servo Function"
- @subpage set_gripper_head_function "Set Gripper Head Function"
- @subpage set_color_function "Set Color Function"
- @subpage read_serial_data_function "Read Serial Data Function"


<!-- This is the print_to_display Function -->
@page print_to_display_function Print To Display Function

This page provides details about the function to print information to the display.

![Print To Display Function Flowchart](print_to_display_function_flowchart.png)

The image above shows a flowchart of the Print To Display function.

**Function Overview**

This function prints information to the display.

**Parameters**
- `print`: The text to be sent to the display.

**Source Files**

For detailed implementation and usage information, please refer to the source files:
- [Serial_display.h](_serial_display_8h.html)
- [Serial_display.cpp](_serial_display_8cpp.html)


<!-- This is the next_pages Function -->
@page next_pages_function Next Pages Function

This page provides details about the function to print the right information to the new page and set "CurrentPage" to the new page.

![Next Pages Function Flowchart](next_pages_function_flowchart.png)

The image above shows a flowchart of the Next Pages function.

**Function Overview**

This function prints the right information to the new page and sets "CurrentPage" to the new page.

**Parameter** 
- `data_from_display`: The data of the display.
- `SetServoSpeed`: The current servo speed.
- `SetTranslationSpeed`: The current translation speed.
- `SetGripperForce`: The current gripper force.
- `SetAutonome`: The current state of autonome.
- `SetCameraLight`: The current state of the camera light.
- `CurrentPage`: The current page the display is on.
- `GripperHead`: The current gripper head.

**Source Files**

For detailed implementation and usage information, please refer to the source files:
- [Serial_display.h](_serial_display_8h.html)
- [Serial_display.cpp](_serial_display_8cpp.html)


<!-- This is the connection_print Function -->
@page connection_print_function Connection Print Function

This page provides details about the function to print the current connection with the Raspberry to the display.

![Connection Print Function Flowchart](connection_print_function_flowchart.png)

The image above shows a flowchart of the Connection Print function.

**Function Overview**

This function prints the current connection with the Raspberry to the display.

**Parameter** 
- `CurrentPage`: The current page the display is on.
- `RaspConnection`: The current connection to the Raspberry (Connected(1), Not connected(0)).

**Source Files**

For detailed implementation and usage information, please refer to the source files:
- [Serial_display.h](_serial_display_8h.html)
- [Serial_display.cpp](_serial_display_8cpp.html)


<!-- This is the split_string Function -->
@page split_string_function Split String Function

This page provides details about the function to split a string at the position of the separator.

![Split String Function Flowchart](split_string_function_flowchart.png)

The image above shows a flowchart of the Split String function.

**Function Overview**

This function splits a string at the position of the separator.

**Parameter** 
- `str`: The string to split.
- `separator`: The separator.

**Source Files**

For detailed implementation and usage information, please refer to the source files:
- [Serial_display.h](_serial_display_8h.html)
- [Serial_display.cpp](_serial_display_8cpp.html)


<!-- This is the send_servo_data Function -->
@page send_servo_data_function Send Servo Data Function

This page provides details about the function to send the servo information received from the Raspberry to the display.

![Send Servo Data Function Flowchart](send_servo_data_function_flowchart.png)

The image above shows a flowchart of the Send Servo Data function.

**Function Overview**

This function sends the servo information received from the Raspberry to the display.

**Parameter** 
- `DataRasp`: The data received from the Raspberry.
- `ReadServo`: The servo for which the information is meant.

**Source Files**

For detailed implementation and usage information, please refer to the source files:
- [Serial_display.h](_serial_display_8h.html)
- [Serial_display.cpp](_serial_display_8cpp.html)


<!-- This is the set_servo_speed Function -->
@page set_servo_speed_function Set Servo Speed Function

This page provides details about the function to return the servo speed and send it to the display.

![Set Servo Speed Function Flowchart](set_servo_speed_function_flowchart.png)

The image above shows a flowchart of the Set Servo Speed function.

**Function Overview**

This function returns the servo speed and sends it to the display.

**Parameter** 
- `data_from_display`: The data of the display.

**Return Value**
- @ref SpeedServoSlow
- @ref SpeedServoMedium
- @ref SpeedServoFast

**Source Files**

For detailed implementation and usage information, please refer to the source files:
- [Serial_display.h](_serial_display_8h.html)
- [Serial_display.cpp](_serial_display_8cpp.html)


<!-- This is the set_translation_speed Function -->
@page set_translation_speed_function Set Translation Speed Function

This page provides details about the function to return the translation speed and send it to the display.

![Set Translation Speed Function Flowchart](set_translation_speed_function_flowchart.png)

The image above shows a flowchart of the Set Translation Speed function.

**Function Overview**

This function returns the translation speed and sends it to the display.

**Parameter** 
- `data_from_display`: The data of the display.

**Return Value**
- @ref SpeedTranslationSlow
- @ref SpeedTranslationMedium
- @ref SpeedTranslationFast

**Source Files**

For detailed implementation and usage information, please refer to the source files:
- [Serial_display.h](_serial_display_8h.html)
- [Serial_display.cpp](_serial_display_8cpp.html)


<!-- This is the set_gripper_force Function -->
@page set_gripper_force_function Set Gripper Force Function

This page provides details about the function to return the gripper force and send it to the display.

![Set Gripper Force Function Flowchart](set_gripper_force_function_flowchart.png)

The image above shows a flowchart of the Set Gripper Force function.

**Function Overview**

This function returns the gripper force and sends it to the display.

**Parameter** 
- `data_from_display`: The data of the display.

**Return Value**
- @ref ForceGripperLow
- @ref ForceGripperMedium
- @ref ForceGripperPower

**Source Files**

For detailed implementation and usage information, please refer to the source files:
- [Serial_display.h](_serial_display_8h.html)
- [Serial_display.cpp](_serial_display_8cpp.html)


<!-- This is the set_autonome Function -->
@page set_autonome_function Set Autonome Function

This page provides details about the function to return the status of autonome and send it to the display.

![Set Autonome Function Flowchart](set_autonome_function_flowchart.png)

The image above shows a flowchart of the Set Autonome function.

**Function Overview**

This function returns the status of autonome and sends it to the display.

**Parameter** 
- `data_from_display`: The data of the display.

**Return Value**
- @ref AutonomeOn
- @ref AutonomeOff

**Source Files**

For detailed implementation and usage information, please refer to the source files:
- [Serial_display.h](_serial_display_8h.html)
- [Serial_display.cpp](_serial_display_8cpp.html)


<!-- This is the set_camera_light Function -->
@page set_camera_light_function Set Camera Light Function

This page provides details about the function to return the status of the camera light and send it to the display.

![Set Camera Light Function Flowchart](set_camera_light_function_flowchart.png)

The image above shows a flowchart of the Set Camera Light function.

**Function Overview**

This function returns the status of the camera light and sends it to the display.

**Parameter** 
- `data_from_display`: The data of the display.

**Return Value**
- @ref CameraLightOn
- @ref CameraLightOff

**Source Files**

For detailed implementation and usage information, please refer to the source files:
- [Serial_display.h](_serial_display_8h.html)
- [Serial_display.cpp](_serial_display_8cpp.html)


<!-- This is the set_raspberry_off Function -->
@page set_raspberry_off_function Set Raspberry Off Function

This page provides details about the function to return the status if the Raspberry needs to be shut down.

![Set Raspberry Off Function Flowchart](set_raspberry_off_function_flowchart.png)

The image above shows a flowchart of the Set Raspberry Off function.

**Function Overview**

This function returns the status if the Raspberry needs to be shut down.

**Parameter** 
- `data_from_display`: The data of the display.

**Return Value**
- @ref Raspberryoff

**Source Files**

For detailed implementation and usage information, please refer to the source files:
- [Serial_display.h](_serial_display_8h.html)
- [Serial_display.cpp](_serial_display_8cpp.html)


<!-- This is the set_read_servo Function -->
@page set_read_servo_function Set Read Servo Function

This page provides details about the function to return which servo needs to be read by the Raspberry Pi.

![Set Read Servo Function Flowchart](set_read_servo_function_flowchart.png)

The image above shows a flowchart of the Set Read Servo function.

**Function Overview**

This function returns which servo needs to be read by the Raspberry Pi.

**Parameter** 
- `data_from_display`: The data of the display.

**Return Value**
- @ref ReadServo1
- @ref ReadServo2
- @ref ReadServo3
- @ref ReadServo4
- @ref ReadServo5

**Source Files**

For detailed implementation and usage information, please refer to the source files:
- [Serial_display.h](_serial_display_8h.html)
- [Serial_display.cpp](_serial_display_8cpp.html)


<!-- This is the set_gripper_head Function -->
@page set_gripper_head_function Set Gripper Head Function

This page provides details about the function to return the gripper head and send it to the display.

![Set Gripper Head Function Flowchart](set_gripper_head_function_flowchart.png)

The image above shows a flowchart of the Set Gripper Head function.

**Function Overview**

This function returns the gripper head and sends it to the display.

**Parameter** 
- `data_from_display`: The data of the display.

**Return Value**
- @ref HeadCilinder
- @ref HeadPen
- @ref HeadTools

**Source Files**

For detailed implementation and usage information, please refer to the source files:
- [Serial_display.h](_serial_display_8h.html)
- [Serial_display.cpp](_serial_display_8cpp.html)


<!-- This is the set_color Function -->
@page set_color_function Set Color Function

This page provides details about the function to return the gripper head and send it to the display.

![Set Color Function Flowchart](set_color_function_flowchart.png)

The image above shows a flowchart of the Set Color function.

**Function Overview**

This function returns the gripper head and sends it to the display.

**Parameter** 
- `data_from_display`: The data of the display.

**Return Value**
- @ref All
- @ref Silver
- @ref Red
- @ref Green
- @ref Blue
- @ref Pink

**Source Files**

For detailed implementation and usage information, please refer to the source files:
- [Serial_display.h](_serial_display_8h.html)
- [Serial_display.cpp](_serial_display_8cpp.html)



<!-- This is the read_serial_data Function -->
@page read_serial_data_function Read Serial Data Function

This page provides details about the function to read the data from the display and ensure that the correct functions are called.

![Read Serial Data Function Flowchart](read_serial_data_function_flowchart.png)

The image above shows a flowchart of the Read Serial Data function.

**Function Overview**

This function reads the data from the display and ensures that the correct functions are called.

**Parameter** 
- `SpeedServo`: The current servo speed.
- `SpeedTranslation`: The current translation speed.
- `ForceGripper`: The current gripper force.
- `Autonome`: The current state of autonome.
- `CameraLight`: The current state of the camera light.
- `RaspberryOff`: The current state of which the Raspberry needs to be shut down.
- `CurrentPage`: The current page the display is on.
- `ReadServo`: The current servo who needs to be read.
- `GripperHead`: The current gripper head.

**Source Files**

For detailed implementation and usage information, please refer to the source files:
- [Serial_display.h](_serial_display_8h.html)
- [Serial_display.cpp](_serial_display_8cpp.html)

























<!-- This is the Wifi Lib -->
@page wifi_data WiFi Data

This page provides details about the WiFi data handling code used in the project.

**Code Overview**

The WiFi data handling code manages the communication over WiFi, including sending and receiving data.

**Source Files**
- [Wifi_Data.h](_wifi___data_8h.html)
- [Wifi_Data.cpp](_wifi___data_8cpp.html)

**Functions**
- @subpage wifi_check_function "WiFi_Check"
- @subpage wifi_setup_function "WiFi_Setup"
- @subpage wifi_send_function "WiFi_Send"
- @subpage wifi_read_function "WiFi_Read"



<!-- This is the Wifi_Check Function -->
@page wifi_check_function WiFi Check Function

This page provides details about the WiFi check function used in the project.

![WiFi Check Function Flowchart](Wifi_Check_Function_flowchart.png)

The image above shows a flowchart of the WiFi check function.

**Function Overview**

The WiFi check function verifies if there is a WiFi connection between the controller and the Raspberry Pi.

**Parameters**
- `host`: The IP address of the Raspberry Pi.
- `port`: The port on which the Raspberry Pi is listening.

**Return Values**
- [RaspConnected](group___raspberry_pi.html): If there is a WiFi connection.
- [RaspDisconnected](group___raspberry_pi.html): If there isn't a WiFi connection.

**Source Files**

For detailed implementation and usage information, please refer to the source files:
- [Wifi_Data.h](_wifi___data_8h.html)
- [Wifi_Data.cpp](_wifi___data_8cpp.html)


<!-- This is the Wifi_setup Function -->
@page wifi_setup_function WiFi Setup Function

This page provides details about the WiFi setup function used in the project.

![WiFi Setup Function Flowchart](Wifi_Setup_Function_flowchart.png)

The image above shows a flowchart of the WiFi setup function.

**Function Overview**

The WiFi setup function establishes a connection to the WiFi network.

**Parameters**
- `ssid`: The name of the WiFi network.
- `password`: The password of the WiFi network.

**Source Files**

For detailed implementation and usage information, please refer to the source files:
- [Wifi_Data.h](_wifi___data_8h.html)
- [Wifi_Data.cpp](_wifi___data_8cpp.html)


<!-- This is the Wifi_Send Function -->
@page wifi_send_function WiFi Send Function

This page provides details about the WiFi send function used in the project.

![WiFi Send Function Flowchart](Wifi_Send_Function_flowchart.png)

The image above shows a flowchart of the WiFi send function.

**Function Overview**

The WiFi send function transmits data to the Raspberry Pi over the WiFi connection.

**Parameters**
- `dataToSend`: The data to be sent.

**Source Files**

For detailed implementation and usage information, please refer to the source files:
- [Wifi_Data.h](_wifi___data_8h.html)
- [Wifi_Data.cpp](_wifi___data_8cpp.html)


<!-- This is the Wifi_Read Function -->
@page wifi_read_function WiFi Read Function

This page provides details about the WiFi read function used in the project.

![WiFi Read Function Flowchart](Wifi_Read_Function_flowchart.png)

The image above shows a flowchart of the WiFi read function.

**Function Overview**

The WiFi read function retrieves data from the Raspberry Pi over the WiFi connection.

**Parameters**
- `ReadRasp`: The data received from the Raspberry Pi.

**Source Files**

For detailed implementation and usage information, please refer to the source files:
- [Wifi_Data.h](_wifi___data_8h.html)
- [Wifi_Data.cpp](_wifi___data_8cpp.html)