// -------- Includes the necessary classes and libraries ------------
#include <Arduino.h> 
#include "Button.h"
#include "Potentiometer.h"
#include "Joystick.h"
 
const char * ssid = "ZAQK"; //Insert your wifi name
const char * password = "199zia66"; //Insert your wifi password
 
 
int PIN_BUTTON = 23; // pin number for the button sensor
Button button (PIN_BUTTON); 
Joystick joystick(36, 35); //pin numbers for the x and y coordinates of the joystick
Potentiometer potentiometer (34); //pin number for the potentiometer 

 
void setup() { //this is what the program will start with 
      Serial.begin(9600); //this tells the arduino to exchange messages at the rate of 9600 bits per second
      WiFi.mode(WIFI_STA);
      WiFi.begin(ssid, password);
      potentiometer.setSensitivity(50); //this sets the sensitivity of the potentiometer 
    
}

/*
* The loop function constineuosly looks for updates and calls the button, joystick and potentiometer functions if there are any.
*/
void loop() { //this functions runs in a loop lol. It basically runs repeatedly looking for updates and calling the declared functions 
  delay (2000); //causes a delay of 2 seconds 
  button.buttonPressed(); //runs the method buttonPressed from the Button class
  delay (2000); //causes a delay of 2 seconds 
  joystick.movement();  // runs the method movement from the Joystick class 
  potentiometer.changePixelColor(); //runs the method changePixelColor from the potentiometer class
    
 
}