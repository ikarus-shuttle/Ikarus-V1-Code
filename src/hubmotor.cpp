#include "hubmotor.h"

void set_motor_speed()
{
   //allMotors
  current_motor_speed = map(arrayChannel[2],100,-80,0,128); //Auslesen der Daten an Channel 3.
  digitalWrite(csPin, LOW);
  
  //SPI.transfer(0x00);
  SPI.transfer(0);
  SPI.transfer(current_motor_speed);
  //delay(10);
  digitalWrite(csPin, HIGH); 
    
  Serial.println(current_motor_speed);
}

void set_brakes(){
  if (arrayChannel[8]==100){ //Bremsen und Richtungswechsel (it's not a bug it's a feature.) funktioniert mit allen Motorcontrollern
    digitalWrite(direction_motor, HIGH);
    delay(1010); //angenährte Zeit, welche der Controller braucht um die Richtung zu wechseln. Dabei sollte so wenig Zeit benötigt werden, damit der Controller nicht eine Geschwindigkeit von 50% erreicht.
    digitalWrite(direction_motor, LOW);
    Serial.println("on");
    }
    else {
    digitalWrite(direction_motor, LOW);
    Serial.println("off");
    } 
}