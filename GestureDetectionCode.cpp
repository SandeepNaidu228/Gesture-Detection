// Code for interfacing cloud with ESP8266 and Arduino
#include "thingProperties.h"

void setup() {
  // Initialize serial and wait for port to open:
  Serial.begin(9600);
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500);

  // Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  
  /*
     The following function allows you to obtain more information
     related to the state of network and IoT Cloud connection and errors
     the higher number the more granular information you’ll get.
     The default is 0 (only errors).
     Maximum is 4
  */
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop() {
  ArduinoCloud.update();
  char buffer[40]="";
  if (Serial.available()>0){
    Serial.readBytesUntil('\n',buffer,40);
    Serial.println(buffer);
    message = buffer;
  }
  delay(1000);
}

/*
  Since Message is READ_WRITE variable, onMessageChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onMessageChange()  {
  // Add your code here to act upon Message change
}

// Code for flex sensor
const int flexPin = A0; 

void setup() 
{ 
  Serial.begin(9600);
} 

void loop() 
{ 
  int flexValue;
  flexValue = analogRead(flexPin);
  if (flexValue>150 && flexValue<250){
    Serial.print("Info: ");
    Serial.println("HI I NEED HELP");
  }

  delay(5000);
} 
