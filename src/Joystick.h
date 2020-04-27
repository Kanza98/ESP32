#include <Arduino.h>
#include "Connector.h"

class Joystick {

public:
  int pinX; //initalizes variable for X pin
  int pinY; //initializes variable for pin Y
  int currentX; // the current X value
  int currentY; // the current Y value
  Connector connect; //Calls the Connector class 

  Joystick (int pinX, int pinY) {  //creates a constructor for the jouystick class that takes input from pinX and pinY
    this-> pinX = pinX;
    this-> pinY = pinY;
    pinMode (pinX, INPUT);
    pinMode (pinY, INPUT);
  }


  void movement(){ //this method checks the X and Y values and sends commands using the braodcast method from the java class
    currentX = analogRead(pinX); //sets the current X value to the value being read from the x pin 
    currentY = analogRead(pinY);//sets the current X value to the value being read from the y pin 

    Serial.print("X: ");
    Serial.println(analogRead(pinX)); //Prints out X value to the terminal 
    Serial.print("Y: ");
    Serial.println(analogRead(pinY)); //prints out Y value to the terminal

    // When using 3,5 volts center is between 1700-1850
    if(currentX > 1500 && currentX < 1900 && currentY > 1500 && currentY < 1900){

    }else if (currentX > 1900){
      connect.broadcast("moveright"); // move the pixel to the right
    }else if(currentX < 1500){
      connect.broadcast("moveleft"); //move the pixel to the left 
    }
    if(currentY > 1900){
      connect.broadcast("moveup"); //move the pixel up 
    } else if(currentY < 1500){
      connect.broadcast("movedown"); //move the pixel down 
    }
  }
    
};