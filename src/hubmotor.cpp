#include "hubmotor.h"

void set_motor_speed()
{
   //allMotors
  current_motor_speed = map(arrayChannel[2],100,-40,0,128); //Auslesen der Daten an Channel 3.
  digitalWrite(csPin, LOW);
  
  //SPI.transfer(0x00);
  SPI.transfer(0);
  SPI.transfer(current_motor_speed);
  //delay(10);
  digitalWrite(csPin, HIGH); 
    
  Serial.println(current_motor_speed);
}

void set_direction(){
  if (arrayChannel[9]==100){ //Umpolungsschalter an oder aus. 
    digitalWrite(direction_motor, HIGH);
    Serial.println("Backward");
    }
    else {
    digitalWrite(direction_motor, LOW);
    Serial.println("Forward");
    } 
}

void set_brakes(){
  if (arrayChannel[8]==100){ //Bremsen 
    digitalWrite(brakes_motor, HIGH);
    Serial.println("Breaks Engaged");
    }
    else {
    digitalWrite(direction_motor, LOW);
    Serial.println("Breaks Disengaged");
    } 
}