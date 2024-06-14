#include "Serial_display.h"
#include <Arduino.h>

void PrintToDisplay(String print){
  Serial.write(0xff);         // Write 0xff to display (11111111)
  Serial.write(0xff);         // Write 0xff to display (11111111)
  Serial.write(0xff);         // Write 0xff to display (11111111)
  Serial.print(print);        // Print print to the display
  Serial.write(0xff);         // Write 0xff to display (11111111)
  Serial.write(0xff);         // Write 0xff to display (11111111)
  Serial.write(0xff);         // Write 0xff to display (11111111)
}


void NextPages(String data_from_display, int ServoSpeed, int TranslationSpeed, int GripperForce, int Autonome, int CameraLight, int &CurrentPage, int &GripperHead){
  if (data_from_display == "GoPage0"){        // If display prints GoPage 0 
    CurrentPage = 0;                          // Current page = 0
  } 
  else if (data_from_display == "GoPage1"){
    CurrentPage = 1;                          // Current page = 1              
    if      (ServoSpeed         == SpeedServoSlow){               PrintToDisplay("page1.t4.txt=\"Slow\"");}     // Print the right text the to right page
    else if (ServoSpeed         == SpeedServoMedium){             PrintToDisplay("page1.t4.txt=\"Medium\"");}   // Print the right text the to right page
    else if (ServoSpeed         == SpeedServoFast){               PrintToDisplay("page1.t4.txt=\"Fast\"");}     // Print the right text the to right page
    if      (TranslationSpeed   == SpeedTranslationSlow){         PrintToDisplay("page1.t5.txt=\"Slow\"");}     // Print the right text the to right page
    else if (TranslationSpeed   == SpeedTranslationMedium){       PrintToDisplay("page1.t5.txt=\"Medium\"");}   // Print the right text the to right page
    else if (TranslationSpeed   == SpeedTranslationFast){         PrintToDisplay("page1.t5.txt=\"Fast\"");}     // Print the right text the to right page
    if      (GripperForce       == ForceGripperLow){              PrintToDisplay("page1.t6.txt=\"Low\"");}      // Print the right text the to right page
    else if (GripperForce       == ForceGripperMedium){           PrintToDisplay("page1.t6.txt=\"Medium\"");}   // Print the right text the to right page
    else if (GripperForce       == ForceGripperPower){            PrintToDisplay("page1.t6.txt=\"Power\"");}    // Print the right text the to right page
  }
  else if (data_from_display == "GoPage2"){
    CurrentPage = 2;                          // Current page = 2
    if        (Autonome           == AutonomeOn){                 PrintToDisplay("page2.t2.txt=\"ON\"");}       // Print the right text the to right page
    else if   (Autonome           == AutonomeOff){                PrintToDisplay("page2.t2.txt=\"OFF\"");}      // Print the right text the to right page
    if        (CameraLight        == CameraLightOn){              PrintToDisplay("page2.t5.txt=\"ON\"");}       // Print the right text the to right page
    else if   (CameraLight        == CameraLightOff){             PrintToDisplay("page2.t5.txt=\"OFF\"");}      // Print the right text the to right page
    if        (GripperForce       == ForceGripperLow){            PrintToDisplay("page2.t6.txt=\"Low\"");}      // Print the right text the to right page
    else if   (GripperForce       == ForceGripperMedium){         PrintToDisplay("page2.t6.txt=\"Medium\"");}   // Print the right text the to right page
    else if   (GripperForce       == ForceGripperPower){          PrintToDisplay("page2.t6.txt=\"Power\"");}    // Print the right text the to right page
  } 
  else if (data_from_display == "GoPage3"){   CurrentPage = 3;}   // Current page = 3
  else if (data_from_display == "GoPage31"){  CurrentPage = 31;}  // Current page = 31
  else if (data_from_display == "GoPage32"){  CurrentPage = 32;}  // Current page = 32
  else if (data_from_display == "GoPage33"){  CurrentPage = 33;}  // Current page = 33
  else if (data_from_display == "GoPage34"){  CurrentPage = 34;}  // Current page = 34
  else if (data_from_display == "GoPage35"){  CurrentPage = 35;}  // Current page = 35
  else if (data_from_display == "GoPage4"){   CurrentPage = 4;}   // Current page = 4
  else if (data_from_display == "GoPage41"){  CurrentPage = 41;}  // Current page = 41
  else if (data_from_display == "GoPage42"){  CurrentPage = 42;}  // Current page = 42
  else if (data_from_display == "GoPage421"){ CurrentPage = 421;} // Current page = 421
  else if (data_from_display == "GoPage43"){  
    CurrentPage = 43;                          // Current page = 43                       
    if        (GripperHead       == HeadCilinder){              PrintToDisplay("page43.t10.txt=\"Cilinder\"");} // Print the right text the to right page
    else if   (GripperHead       == HeadPen){                   PrintToDisplay("page43.t10.txt=\"Pen\"");}      // Print the right text the to right page
    else if   (GripperHead       == HeadTools){                 PrintToDisplay("page43.t10.txt=\"Tools\"");}    // Print the right text the to right page
  } 
}

void ConnectionPrint(int CurrentPage, bool RaspConnection){
  if (RaspConnection == RaspberryDisconnected){               // If Raspberry not connected
    PrintToDisplay("page0.t5.txt=\"No\"");                    // Print Raspberry not connected to display
    PrintToDisplay("page1.t8.txt=\"No\"");                    // Print Raspberry not connected to display
    PrintToDisplay("page2.t8.txt=\"No\"");                    // Print Raspberry not connected to display
    PrintToDisplay("page3.t5.txt=\"No\"");                    // Print Raspberry not connected to display
    PrintToDisplay("page31.t5.txt=\"No\"");                   // Print Raspberry not connected to display
    PrintToDisplay("page32.t5.txt=\"No\"");                   // Print Raspberry not connected to display
    PrintToDisplay("page33.t5.txt=\"No\"");                   // Print Raspberry not connected to display
    PrintToDisplay("page34.t5.txt=\"No\"");                   // Print Raspberry not connected to display
    PrintToDisplay("page35.t5.txt=\"No\"");                   // Print Raspberry not connected to display
    PrintToDisplay("page4.t5.txt=\"No\"");                    // Print Raspberry not connected to display 
    PrintToDisplay("page41.t5.txt=\"No\"");                   // Print Raspberry not connected to display
    PrintToDisplay("page42.t5.txt=\"No\"");                   // Print Raspberry not connected to display
    PrintToDisplay("page43.t5.txt=\"No\"");                   // Print Raspberry not connected to display
  }
  if (RaspConnection == RaspberryConnected){                                // If Raspberry connected
    if (CurrentPage == 0){        PrintToDisplay("page0.t5.txt=\"Yes\"");}  // Print Raspberry connected to display page 0 if on page 0 
    else if (CurrentPage == 1){   PrintToDisplay("page1.t8.txt=\"Yes\"");}  // Print Raspberry connected to display page 1 if on page 1 
    else if (CurrentPage == 2){   PrintToDisplay("page2.t8.txt=\"Yes\"");}  // Print Raspberry connected to display page 2 if on page 2 
    else if (CurrentPage == 3){   PrintToDisplay("page3.t5.txt=\"Yes\"");}  // Print Raspberry connected to display page 3 if on page 3 
    else if (CurrentPage == 31){  PrintToDisplay("page31.t5.txt=\"Yes\"");} // Print Raspberry connected to display page 31 if on page 31 
    else if (CurrentPage == 32){  PrintToDisplay("page32.t5.txt=\"Yes\"");} // Print Raspberry connected to display page 32 if on page 32 
    else if (CurrentPage == 33){  PrintToDisplay("page33.t5.txt=\"Yes\"");} // Print Raspberry connected to display page 33 if on page 33
    else if (CurrentPage == 34){  PrintToDisplay("page34.t5.txt=\"Yes\"");} // Print Raspberry connected to display page 34 if on page 34
    else if (CurrentPage == 35){  PrintToDisplay("page35.t5.txt=\"Yes\"");} // Print Raspberry connected to display page 35 if on page 35
    else if (CurrentPage == 4){   PrintToDisplay("page4.t5.txt=\"Yes\"");}  // Print Raspberry connected to display page 4 if on page 4
    else if (CurrentPage == 41){  PrintToDisplay("page41.t5.txt=\"Yes\"");} // Print Raspberry connected to display page 41 if on page 41 
    else if (CurrentPage == 42){  PrintToDisplay("page42.t5.txt=\"Yes\"");} // Print Raspberry connected to display page 42 if on page 42
    else if (CurrentPage == 43){  PrintToDisplay("page43.t5.txt=\"Yes\"");} // Print Raspberry connected to display page 43 if on page 43
  }
}

String strings[6]; // define max string

void SplitString(String str, char separator) {
  //Define variables 
  int currIndex = 0, i = 0;             // Initialize current index and iterator
  int startIndex = 0, endIndex = 0;     // Initialize start and end indices for substrings

  while (i <= str.length()) {           // While i is not equal to the string length
    if (i == str.length() || str.charAt(i) == separator) {  // If end of string or separator is found
      endIndex = i;                                         // Set end index to current position
      String subStr = str.substring(startIndex, endIndex);  // Extract substring
      strings[currIndex] = subStr;                          // Store substring in the array
      currIndex += 1;                                       // Move to the next position in the array
      startIndex = endIndex + 1;                            // Set start index to the next character after the separator
    }
    i++;  // Move to the next character in the string
  }
}

void SendServoData(String DataRasp, int &ReadServo){
  //Devine Values Servos
  String ID1, ID2, ID3, ID4, ID5;                                           // ID strings to send to display
  String Voltage1, Voltage2, Voltage3, Voltage4, Voltage5;                  // Voltage strings to send to display
  String Speed1, Speed2, Speed3, Speed4, Speed5;                            // Speed strings to send to display
  String Temprature1, Temprature2, Temprature3, Temprature4, Temprature5;   // Temprature strings to send to display
  String Posistion1, Posistion2, Posistion3, Posistion4, Posistion5;        // Possistion strings to send to display
  String Error1, Error2, Error3, Error4, Error5;                            // Error strings to send to display

  char seperator = ',';               // The comma + space is the separater
  SplitString(DataRasp, seperator);   // Function to split the string after the seperator

  if (ReadServo == ReadServo1){                               // If servo 1 reading
    ID1          = "page31.t9.txt=\""  + strings[0] + "\"";   // Set text to the right value
    Voltage1     = "page31.t10.txt=\"" + strings[1] + "\"";   // Set text to the right value
    Speed1       = "page31.t11.txt=\"" + strings[2] + "\"";   // Set text to the right value
    Temprature1  = "page31.t12.txt=\"" + strings[3] + "\"";   // Set text to the right value
    Posistion1   = "page31.t13.txt=\"" + strings[4] + "\"";   // Set text to the right value
    Error1       = "page31.t14.txt=\"" + strings[5] + "\"";   // Set text to the right value
    PrintToDisplay(ID1);          // Print ID to display
    PrintToDisplay(Voltage1);     // Print voltage to display
    PrintToDisplay(Speed1);       // Print speed to display
    PrintToDisplay(Temprature1);  // Print temprature to display
    PrintToDisplay(Posistion1);   // Print posistion to display
    PrintToDisplay(Error1);       // Print error to display
    ReadServo = 0;}               // ReadServo to 0
  else if (ReadServo == ReadServo2){                          // If servo 2 reading
    ID2          = "page32.t10.txt=\"" + strings[0] + "\"";   // Set text to the right value
    Voltage2     = "page32.t11.txt=\"" + strings[1] + "\"";   // Set text to the right value
    Speed2       = "page32.t12.txt=\"" + strings[2] + "\"";   // Set text to the right value
    Temprature2  = "page32.t13.txt=\"" + strings[3] + "\"";   // Set text to the right value
    Posistion2   = "page32.t14.txt=\"" + strings[4] + "\"";   // Set text to the right value
    Error2       = "page32.t15.txt=\"" + strings[5] + "\"";   // Set text to the right value
    PrintToDisplay(ID2);          // Print ID to display
    PrintToDisplay(Voltage2);     // Print voltage to display
    PrintToDisplay(Speed2);       // Print Speed to display
    PrintToDisplay(Temprature2);  // Print temprature to display
    PrintToDisplay(Posistion2);   // Print posistion to display
    PrintToDisplay(Error2);       // Print error to display
    ReadServo = 0;}               // ReadServo to 0
  else if (ReadServo == ReadServo3){                          // If servo 3 reading
    ID3          = "page33.t10.txt=\"" + strings[0] + "\"";   // Set text to the right value
    Voltage3     = "page33.t11.txt=\"" + strings[1] + "\"";   // Set text to the right value
    Speed3       = "page33.t12.txt=\"" + strings[2] + "\"";   // Set text to the right value
    Temprature3  = "page33.t13.txt=\"" + strings[3] + "\"";   // Set text to the right value
    Posistion3   = "page33.t14.txt=\"" + strings[4] + "\"";   // Set text to the right value
    Error3       = "page33.t15.txt=\"" + strings[5] + "\"";   // Set text to the right value
    PrintToDisplay(ID3);          // Print ID to display
    PrintToDisplay(Voltage3);     // Print voltage to display
    PrintToDisplay(Speed3);       // Print Speed to display
    PrintToDisplay(Temprature3);  // Print temprature to display
    PrintToDisplay(Posistion3);   // Print posistion to display
    PrintToDisplay(Error3);       // Print error to display
    ReadServo = 0;}               // ReadServo to 0
  else if (ReadServo == ReadServo4){                          // If servo 4 reading
    ID4          = "page34.t10.txt=\"" + strings[0] + "\"";   // Set text to the right value
    Voltage4     = "page34.t11.txt=\"" + strings[1] + "\"";   // Set text to the right value
    Speed4       = "page34.t12.txt=\"" + strings[2] + "\"";   // Set text to the right value
    Temprature4  = "page34.t13.txt=\"" + strings[3] + "\"";   // Set text to the right value
    Posistion4   = "page34.t14.txt=\"" + strings[4] + "\"";   // Set text to the right value
    Error4       = "page34.t15.txt=\"" + strings[5] + "\"";   // Set text to the right value
    PrintToDisplay(ID4);          // Print ID to display
    PrintToDisplay(Voltage4);     // Print voltage to display
    PrintToDisplay(Speed4);       // Print Speed to display
    PrintToDisplay(Temprature4);  // Print temprature to display
    PrintToDisplay(Posistion4);   // Print posistion to display
    PrintToDisplay(Error4);       // Print error to display
    ReadServo = 0;}               // ReadServo to 0
  else if (ReadServo == ReadServo5){                          // If servo 5 reading
    ID5          = "page35.t10.txt=\"" + strings[0] + "\"";   // Set text to the right value
    Voltage5     = "page35.t11.txt=\"" + strings[1] + "\"";   // Set text to the right value
    Speed5       = "page35.t12.txt=\"" + strings[2] + "\"";   // Set text to the right value
    Temprature5  = "page35.t13.txt=\"" + strings[3] + "\"";   // Set text to the right value
    Posistion5   = "page35.t14.txt=\"" + strings[4] + "\"";   // Set text to the right value
    Error5       = "page35.t15.txt=\"" + strings[5] + "\"";   // Set text to the right value
    PrintToDisplay(ID5);          // Print ID to display
    PrintToDisplay(Voltage5);     // Print voltage to display
    PrintToDisplay(Speed5);       // Print Speed to display
    PrintToDisplay(Temprature5);  // Print temprature to display
    PrintToDisplay(Posistion5);   // Print posistion to display
    PrintToDisplay(Error5);       // Print error to display
    ReadServo = 0;}               // ReadServo to 0
}

int SetServoSpeed(String data_from_display) {
  // Difine variables
  const char* DataSendSlo    = "page1.t4.txt=\"Slow\"";     // Set text to the right value
  const char* DataSendMed    = "page1.t4.txt=\"Medium\"";   // Set text to the right value
  const char* DataSendFas    = "page1.t4.txt=\"Fast\"";     // Set text to the right value

  if (data_from_display == "SpSerSlo") {                    // If display prints SpSerSlo 
    PrintToDisplay(DataSendSlo);                            // Print Slow To display
    return SpeedServoSlow;                                  // Returns Servo Speed Slow

  } else if (data_from_display == "SpSerMed") {             // If display prints SpSerMed 
    PrintToDisplay(DataSendMed);                            // Print Medium To display
    return SpeedServoMedium;                                // Returns Servo Speed Medium

  } else if (data_from_display == "SpSerFas") {             // If display prints SpSerFas
    PrintToDisplay(DataSendFas);                            // Print Fast To display
    return SpeedServoFast;                                  // Returns Servo Speed Fast

  } else{                                                   // If nothing in this funtion is set
    return 0;                                               // Return 0        
  }
}

int SetTranslationSpeed(String data_from_display) {
  // Difine variables
  const char* DataSendSlo    = "page1.t5.txt=\"Slow\"";     // Set text to the right value
  const char* DataSendMed    = "page1.t5.txt=\"Medium\"";   // Set text to the right value
  const char* DataSendFas    = "page1.t5.txt=\"Fast\"";     // Set text to the right value
  
  if (data_from_display == "SpTraSlo") {                    // If display prints SpTraSlo 
    PrintToDisplay(DataSendSlo);                            // Print Slow To display
    return SpeedTranslationSlow;                            // Returns Translation Speed Slow

  } else if (data_from_display == "SpTraMed") {             // If display prints SpTraMed 
    PrintToDisplay(DataSendMed);                            // Print Medium To display
    return SpeedTranslationMedium;                          // Returns Translation Speed Medium

  } else if (data_from_display == "SpTraFas") {             // If display prints SpTraFas 
    PrintToDisplay(DataSendFas);                            // Print Fast To display
    return SpeedTranslationFast;                            // Returns Translation Speed Fast

  } else{                                                   // If nothing in this funtion is set
    return 0;                                               // Return 0
  }
}


int SetGripperForce(String data_from_display) {
  // Difine variables
  const char* DataSendLow1    = "page1.t6.txt=\"Low\"";   // Set text to the right value
  const char* DataSendMed1    = "page1.t6.txt=\"Medium\"";// Set text to the right value
  const char* DataSendPow1    = "page1.t6.txt=\"Power\""; // Set text to the right value
  const char* DataSendLow2    = "page2.t6.txt=\"Low\"";   // Set text to the right value  
  const char* DataSendMed2    = "page2.t6.txt=\"Medium\"";// Set text to the right value
  const char* DataSendPow2    = "page2.t6.txt=\"Power\""; // Set text to the right value

  if (data_from_display == "FoGrLow") {                   // If display prints FoGrLow 
    PrintToDisplay(DataSendLow1);                         // Print low To display
    PrintToDisplay(DataSendLow2);                         // Print low To display
    return ForceGripperLow;                               // Returns Gripper force low
    
  } else if (data_from_display == "FoGrMed") {            // If display prints FoGrMed
    PrintToDisplay(DataSendMed1);                         // Print Medium To display
    PrintToDisplay(DataSendMed2);                         // Print Medium To display
    return ForceGripperMedium;                            // Returns Gripper force Medium

  } else if (data_from_display == "FoGrPow") {            // If display prints FoGrFas
    PrintToDisplay(DataSendPow1);                         // Print Power To display
    PrintToDisplay(DataSendPow2);                         // Print Power To display
    return ForceGripperPower;                             // Returns Gripper force Power

  } else{                                                 // If nothing in this funtion is set
    return 0;                                             // Return 0
  } 
}


int SetAutonome(String data_from_display){
  // Difine variables
  const char* DataSendOn    = "page2.t2.txt=\"ON\"";  // Set text to the right value
  const char* DataSendOff   = "page2.t2.txt=\"OFF\""; // Set text to the right value

  if (data_from_display == "AutOn") {                 // If display prints AutOn
    PrintToDisplay(DataSendOn);                       // Print On To display
    return AutonomeOn;                                // Returns Autonome on

  } else if (data_from_display == "AutOff") {         // If display prints AutOff
    PrintToDisplay(DataSendOff);                      // Print Off To display
    return AutonomeOff;                               // Returns Autonome off

  } else{                                             // If nothing in this funtion is set  
    return 0;                                         // Return 0
  }
  
}


int SetCameraLight(String data_from_display){
  // Difine variables
  const char* DataSendOn    = "page2.t5.txt=\"ON\"";  // Set text to the right value
  const char* DataSendOff   = "page2.t5.txt=\"OFF\""; // Set text to the right value

  if (data_from_display == "LigOn") {                 // If display prints LigOn
    PrintToDisplay(DataSendOn);                       // Print On To display
    return CameraLightOn;                             // Returns Camera light on
    
  } else if (data_from_display == "LigOff") {         // If display prints LifOff
    PrintToDisplay(DataSendOff);                      // Print Off To display
    return CameraLightOff;                            // Returns Camera Light off

  } else{                                             // If nothing in this funtion is set
    return 0;                                         // Return 0
  }
}


int SetRaspberryOff(String data_from_display){
  if (data_from_display == "RaspOff") {             // If display prints RaspOff
    return Raspberryoff;                            // Returns Raspberry off

  } else{                                           // If nothing in this funtion is set
    return 0;                                       // Return 0
  }
}


int SetReadServo(String data_from_display){
  if (data_from_display == "ReadS1") {            // If display prints ReadS1 
    return ReadServo1;                            // Returns Read Servo 1

  }else if (data_from_display == "ReadS2"){       // If display prints ReadS2
    return ReadServo2;                            // Returns Read Servo 2

  }else if (data_from_display == "ReadS3"){       // If display prints ReadS3
    return ReadServo3;                            // Returns Read Servo 3

  }else if (data_from_display == "ReadS4"){       // If display prints ReadS4
    return ReadServo4;                            // Returns Read Servo 4

  }else if (data_from_display == "ReadS5"){       // If display prints ReadS5
    return ReadServo5;                            // Returns Read Servo 5

  }else{                                          // If nothing in this funtion is set
    return 0;                                     // Return 0
  }
}


int SetGripperHead(String data_from_display){
  // Difine variables
  const char* DataSendCil     = "page43.t10.txt=\"Cilinder\"";  // Set text to the right value
  const char* DataSendPen     = "page43.t10.txt=\"Pen\"";       // Set text to the right value
  const char* DataSendTools   = "page43.t10.txt=\"Tools\"";     // Set text to the right value

  if (data_from_display == "HeadCil") {           // If display prints HeadCil
    PrintToDisplay(DataSendCil);                  // Print Cilinder To display
    return HeadCilinder;                          // Returns Gripper Head Cilinder

  }else if (data_from_display == "HeadPen"){      // If display prints HeadPen
    PrintToDisplay(DataSendPen);                  // Print Pen To display
    return HeadPen;                               // Returns Gripper Head Pen

  }else if (data_from_display == "HeadTool"){     // If display prints HeadTool
    PrintToDisplay(DataSendTools);                // Print Tools To display
    return HeadTools;                             // Returns Gripper Head Tools

  }else{                                          // If nothing in this funtion is set
    return 0;                                     // Return 0
  }
}

int SetColor(String data_from_display){
  // Difine variables
  const char* DataSendAll       = "page43.t15.txt=\"All\"";     // Set text to the right value
  const char* DataSendSilver    = "page43.t15.txt=\"Silver\"";  // Set text to the right value
  const char* DataSendRed       = "page43.t15.txt=\"Red\"";     // Set text to the right value
  const char* DataSendGreen     = "page43.t15.txt=\"Green\"";   // Set text to the right value
  const char* DataSendBlue      = "page43.t15.txt=\"Blue\"";    // Set text to the right value
  const char* DataSendPink      = "page43.t15.txt=\"Pink\"";    // Set text to the right value

  if (data_from_display == "ColAll") {            // If display prints ColAll
    PrintToDisplay(DataSendAll);                  // Print All To display
    return All;                                   // Return All

  }else if (data_from_display == "ColSil") {      // If display prints ColSil
    PrintToDisplay(DataSendSilver);               // Print Silver To display
    return Silver;                                // Return Silver

  }else if (data_from_display == "ColRed"){       // If display prints ColRed
    PrintToDisplay(DataSendRed);                  // Print Red To display
    return Red;                                   // Return Red

  }else if (data_from_display == "ColGre"){       // If display prints ColGre
    PrintToDisplay(DataSendGreen);                // Print Green To display
    return Green;                                 // Return Green

  }else if (data_from_display == "ColBlu"){       // If display prints ColBlu
    PrintToDisplay(DataSendBlue);                 // Print Blue To display
    return Blue;                                  // Return BLue

  }else if (data_from_display == "ColPin"){       // If display prints ColPin
    PrintToDisplay(DataSendPink);                 // Print Pink To display
    return Pink;                                  // Return Pink

  }else{                                          // If nothing in this funtion is set
    return 0;                                     // Return 0
  }
}


void ReadSerialData(int &SpeedServo, int &SpeedTranslation, int &ForceGripper, int &Autonome, int &CameraLight, int &RaspberryOff, int &CurrentPage, int &ReadServo, int &GripperHead, int &Color) {
  if (Serial.available()) {
    String data_from_display = "";    // Clear data buffer
    delay(30);                        // Wait for data to be collected

    while (Serial.available()) {
      data_from_display += char(Serial.read());     // Put the from display in the data_from_dispay
    }

    // Print the received data to the serial monitor
    Serial.println(data_from_display);

    // Call funtions Made for display
    if (data_from_display == "GoPage0" ||data_from_display == "GoPage1" || data_from_display == "GoPage2" || data_from_display == "GoPage3" || data_from_display == "GoPage31" || data_from_display == "GoPage32" || data_from_display == "GoPage33" || data_from_display == "GoPage34" || data_from_display == "GoPage35" || data_from_display == "GoPage4" || data_from_display == "GoPage41" || data_from_display == "GoPage42" || data_from_display == "GoPage421" || data_from_display == "GoPage43") {
      NextPages(data_from_display, SpeedServo, SpeedTranslation, ForceGripper, Autonome, CameraLight, CurrentPage, GripperHead);
    }
    if (data_from_display == "SpSerSlo" || data_from_display == "SpSerMed" || data_from_display == "SpSerFas") {
      SpeedServo = SetServoSpeed(data_from_display);
    }
    if (data_from_display == "SpTraSlo" || data_from_display == "SpTraMed" || data_from_display == "SpTraFas") {
      SpeedTranslation = SetTranslationSpeed(data_from_display);
    }
    if (data_from_display == "FoGrLow" || data_from_display == "FoGrMed" || data_from_display == "FoGrPow") {
      ForceGripper = SetGripperForce(data_from_display);
    }
    if (data_from_display == "AutOn" || data_from_display == "AutOff") {
      Autonome = SetAutonome(data_from_display);
    }
    if (data_from_display == "LigOn" || data_from_display == "LigOff") {
      CameraLight = SetCameraLight(data_from_display);
    }
    if (data_from_display == "RaspOff"){
      RaspberryOff = SetRaspberryOff(data_from_display);
    }
    if (data_from_display == "ReadS1" || data_from_display == "ReadS2" || data_from_display == "ReadS3" || data_from_display == "ReadS4" || data_from_display == "ReadS5"){
      ReadServo = SetReadServo(data_from_display);
    }
    if (data_from_display == "HeadCil" || data_from_display == "HeadPen" || data_from_display == "HeadTool") {
      GripperHead = SetGripperHead(data_from_display);
    }
    if (data_from_display == "ColSil" || data_from_display == "ColRed" || data_from_display == "ColGre" || data_from_display == "ColBlu" || data_from_display == "ColPin" || data_from_display == "ColAll") {
      Color = SetColor(data_from_display);
    }
  }
}