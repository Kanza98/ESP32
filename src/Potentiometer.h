#include <Arduino.h>
#include "Connector.h"
 
 
 
class Potentiometer{
    public:
        int pinNumber;
        int lastRead;
        int currentRead; //current value of the potentiometer 
        int sensitivity;
        Connector connect;
        String color = "";
   
 
        Potentiometer(int pinNumber) // Constructor for the Potentiometer class
        {
            this->pinNumber = pinNumber;
            pinMode(pinNumber, INPUT);
            this->lastRead = this->readPotentiometer();
       
        }
 
        int readPotentiometer()
        {
            return analogRead(pinNumber); //returns the reading received via the pin 
        }
 
        void setSensitivity(int sensitivity)
        {
            this->sensitivity = sensitivity;
        }
        bool hasChanged()
        {
            return abs(lastRead-analogRead(pinNumber)) > sensitivity;
        }
       
        void changePixelColor() //this is the method checks the currentRead and initiates commands representing different rgb colors 
        {
            if (this->hasChanged())
            {
                currentRead = readPotentiometer();
                Serial.print(analogRead(pinNumber)); //tells the program to print the value gotten via the pin 
 
                if (currentRead <=1356 )
                {  
                    connect.broadcast("color 255 0 0"); //if the value is less than or equal to 1356 then change the color to red
                }
                else if(currentRead > 1356 && currentRead <= 2712)
                {
                    connect.broadcast("color 0 255 0"); //if the value is less than or equal to 2712 then change the color to green
               
                }
                 else
                {
                    connect.broadcast("color 0 0 255"); //if the above two are not the cases then change the color to blue 
                    
                }
            }
        }
};