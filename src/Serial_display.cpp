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
    ID1          = "page31.t9.txt=\""  + strings[0] + "\"";   // Print ID to display
    Voltage1     = "page31.t10.txt=\"" + strings[1] + "\"";
    Speed1       = "page31.t11.txt=\"" + strings[2] + "\"";
    Temprature1  = "page31.t12.txt=\"" + strings[3] + "\"";
    Posistion1   = "page31.t13.txt=\"" + strings[4] + "\"";
    Error1       = "page31.t14.txt=\"" + strings[5] + "\"";
    PrintToDisplay(ID1);          // Print ID to display
    PrintToDisplay(Voltage1);     // Print voltage to display
    PrintToDisplay(Speed1);       // Print speed to display
    PrintToDisplay(Temprature1);  // Print temprature to display
    PrintToDisplay(Posistion1);   // Print posistion to display
    PrintToDisplay(Error1);       // Print error to display
    ReadServo = 0;}
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
    ReadServo = 0;}
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
    PrintToDisplay(Error3);
    ReadServo = 0;}
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
    ReadServo = 0;}
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
    ReadServo = 0;}
}

int SetServoSpeed(String data_from_display) {
  // Difine variables
  const char* DataSendSlo    = "page1.t4.txt=\"Slow\"";     
  const char* DataSendMed    = "page1.t4.txt=\"Medium\"";   
  const char* DataSendFas    = "page1.t4.txt=\"Fast\"";     

  if (data_from_display == "SpSerSlo") {
    PrintToDisplay(DataSendSlo);
    return SpeedServoSlow;

  } else if (data_from_display == "SpSerMed") {
    PrintToDisplay(DataSendMed);
    return SpeedServoMedium;

  } else if (data_from_display == "SpSerFas") {
    PrintToDisplay(DataSendFas);
    return SpeedServoFast;
  } else{
    return 0;
  }
}

int SetTranslationSpeed(String data_from_display) {
  // Difine variables
  const char* DataSendSlo    = "page1.t5.txt=\"Slow\"";
  const char* DataSendMed    = "page1.t5.txt=\"Medium\"";
  const char* DataSendFas    = "page1.t5.txt=\"Fast\"";
  
  if (data_from_display == "SpTraSlo") {
    PrintToDisplay(DataSendSlo);
    return SpeedTranslationSlow;

  } else if (data_from_display == "SpTraMed") {
    PrintToDisplay(DataSendMed);
    return SpeedTranslationMedium;
  } else if (data_from_display == "SpTraFas") {
    PrintToDisplay(DataSendFas);
    return SpeedTranslationFast;
  } else{
    return 0;
  }
}


int SetGripperForce(String data_from_display) {
  // Difine variables
  const char* DataSendLow1    = "page1.t6.txt=\"Low\"";
  const char* DataSendMed1    = "page1.t6.txt=\"Medium\"";
  const char* DataSendPow1    = "page1.t6.txt=\"Power\"";
  const char* DataSendLow2    = "page2.t6.txt=\"Low\"";
  const char* DataSendMed2    = "page2.t6.txt=\"Medium\"";
  const char* DataSendPow2    = "page2.t6.txt=\"Power\"";

  if (data_from_display == "FoGrLow") {
    PrintToDisplay(DataSendLow1);
    PrintToDisplay(DataSendLow2);
    return ForceGripperLow;
    
  } else if (data_from_display == "FoGrMed") {
    PrintToDisplay(DataSendMed1);
    PrintToDisplay(DataSendMed2);
    return ForceGripperMedium;

  } else if (data_from_display == "FoGrPow") {
    PrintToDisplay(DataSendPow1);
    PrintToDisplay(DataSendPow2);
    return ForceGripperPower;
  } else{
    return 0;
  }
}


int SetAutonome(String data_from_display){
  // Difine variables
  const char* DataSendOn    = "page2.t2.txt=\"ON\"";
  const char* DataSendOff   = "page2.t2.txt=\"OFF\"";

  if (data_from_display == "AutOn") {
    PrintToDisplay(DataSendOn);
    return AutonomeOn;
  } else if (data_from_display == "AutOff") {
    PrintToDisplay(DataSendOff);
    return AutonomeOff;
  } else{
    return 0;
  }
  
}

int SetCameraLight(String data_from_display){
  // Difine variables
  const char* DataSendOn    = "page2.t5.txt=\"ON\"";
  const char* DataSendOff   = "page2.t5.txt=\"OFF\"";

  if (data_from_display == "LigOn") {
    PrintToDisplay(DataSendOn);
    return CameraLightOn;
    
  } else if (data_from_display == "LigOff") {
    PrintToDisplay(DataSendOff);
    return CameraLightOff;
  } else{
    return 0;
  }
}

int SetRaspberryOff(String data_from_display){
  if (data_from_display == "RaspOff") {
    return Raspberryoff;
  } else{
    return 0;
  }
}

int SetReadServo(String data_from_display){
  if (data_from_display == "ReadS1") {
    return ReadServo1;
  }else if (data_from_display == "ReadS2"){
    return ReadServo2;
  }else if (data_from_display == "ReadS3"){
    return ReadServo3;
  }else if (data_from_display == "ReadS4"){
    return ReadServo4;
  }else if (data_from_display == "ReadS5"){
    return ReadServo5;
  }else{
    return 0;
  }
}

int SetGripperHead(String data_from_display){
  // Difine variables
  const char* DataSendCil     = "page43.t10.txt=\"Cilinder\"";
  const char* DataSendPen     = "page43.t10.txt=\"Pen\"";
  const char* DataSendTools   = "page43.t10.txt=\"Tools\"";

  if (data_from_display == "HeadCil") {
    PrintToDisplay(DataSendCil);
    return HeadCilinder;
  }else if (data_from_display == "HeadPen"){
    PrintToDisplay(DataSendPen);
    return HeadPen;
  }else if (data_from_display == "HeadTool"){
    PrintToDisplay(DataSendTools);
    return HeadTools;
  }else{
    return 0;
  }
}




void ReadSerialData(int &SpeedServo, int &SpeedTranslation, int &ForceGripper, int &Autonome, int &CameraLight, int &RaspberryOff, int &CurrentPage, int &ReadServo, int &GripperHead) {
  if (Serial.available()) {
    String data_from_display = "";    // Clear data buffer
    delay(30);                        // Wait for data to be collected

    while (Serial.available()) {
      data_from_display += char(Serial.read());     // Put the data in the buffer
    }

    // Print the received data to the serial monitor
    Serial.println(data_from_display);
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
  }
}