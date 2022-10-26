/* This code works with JSN SR04 T ultrasound module
 * It measures the distance and shows it on the Serial monitor
 */
#ifndef distance_sensor_h
#define distance_sensor_h
#include <Arduino.h>
#include <string.h>

class Distancesensor
{
    // Access specifier
    public:
  
    // Data Members
    int triggerPin;
    int echoPin;
    String name; //for debugging purposes.
    // Member Functions()
    void checkdistance()
    {
        digitalWrite(triggerPin, LOW); // Set the trigger pin to low for 2uS 
        delayMicroseconds(2); 

        digitalWrite(triggerPin, HIGH); // Send a 10uS high to trigger ranging 
        delayMicroseconds(20); 

        digitalWrite(triggerPin, LOW); // Send pin low again 
        int distance = pulseIn(echoPin, HIGH,26000); // Read in times pulse 

        distance= distance/58; //Convert the pulse duration to distance
                                //You can add other math functions to calibrate it well
                                
        Serial.print("Distance ");
        Serial.print(name);
        Serial.print(distance);
        Serial.println("cm");

        delay(50); //change to timer.
    }
};

#endif




