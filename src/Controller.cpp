#include "Controller.h"
#include <Arduino.h>

void ReadJoysticks(int &xValueJ1, int &yValueJ1, int &xValueJ2, int &yValueJ2){
  // Define Joysctick pins
  const int xAxisPin1     =   32;
  const int yAxisPin1     =   33;
  const int xAxisPin2     =   34;
  const int yAxisPin2     =   35;
  
  // Lees de analoge waarden van X en Y
  xValueJ1 = analogRead(xAxisPin1);
  yValueJ1 = analogRead(yAxisPin1);

  xValueJ2 = analogRead(xAxisPin2);
  yValueJ2 = analogRead(yAxisPin2);
}

bool ReadButton(const int buttonPin){
  bool ButtonState;
  ButtonState = digitalRead(buttonPin);   // Read button state. If pressed (0) if not pressed (1)
  if (ButtonState == 0){
    return 1;     // Set GripperButton 1 if button is pressed
  }else{
    return 0;     // Set GripperButton 1 if button is not pressed
  }
}

void ReadController(int &xValueJ1, int &yValueJ1, int &xValueJ2, int &yValueJ2, int &GripperButton, const int buttonPin){
  ReadJoysticks(xValueJ1, yValueJ1, xValueJ2, yValueJ2);
  GripperButton = ReadButton(buttonPin);
}