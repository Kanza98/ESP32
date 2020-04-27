#include <Arduino.h>
#include "Connector.h"


class Button {

int buttonPin;
        Connector connect; // Calls the Connector class 
    public: 

    Button (int buttonPin) { // Creates a constructor for the Button class
        this->buttonPin = buttonPin;
        pinMode(buttonPin, INPUT_PULLUP);
    }

    void buttonPressed (){ //this is the method for checking whether the button is pressed or not 
        if(digitalRead(buttonPin)){
                Serial.println("Not pressed x"); //incase the button is not pressed 
        }else{
            Serial.println("Pressed x"); //incase the button is pressed 
            connect.broadcast("init 200 200"); //and if the button is pressed then intialize the pixel at the x and y value of 200 200 respectively
        }
    }
};