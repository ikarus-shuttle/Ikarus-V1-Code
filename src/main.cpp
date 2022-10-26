#include <Arduino.h>
#include <SPI.h>
#include <IBusBM.h>
#include <pinout.h> //in this File, all the used Pins and used Variables are declared to make the code more clear.
#include <string.h> // Includes the library for editing Strings.
#include <distance_sensor.cpp> // Includes the Distance Sensor Class.
#include <linearmotor.h> // Includes the linearmotor files.
#include <hubmotor.h> // Includes the files for controlling the motors.
#include <remote.h> // Includes the files for working with the Remote.

IBusBM ibusRc;


void setup() {
    pinMode(csPin, OUTPUT);
    //pinMode(csPin2, OUTPUT);
    pinMode(direction_motor, OUTPUT);
    pinMode(linearmotor_back_open, OUTPUT);
    pinMode(linearmotor_back_close, OUTPUT);
    
    pinMode(linearmotor_front_open, OUTPUT);

    pinMode(linearmotor_front_close, OUTPUT);
    pinMode(linearmotor_cargo_open, OUTPUT);
    pinMode(linearmotor_cargo_close, OUTPUT);
    pinMode(linearmotor_cargosmall_open, OUTPUT);
    pinMode(linearmotor_cargosmall_close, OUTPUT);
    pinMode(poti_steering_front, INPUT);
    pinMode(poti_steering_back, INPUT);
    pinMode(schweinwerfer_vorne, OUTPUT);

    pinMode(led_back_right, OUTPUT);
    pinMode(led_back_left, OUTPUT);
    pinMode(led_front, OUTPUT);
    pinMode(led_cargo, OUTPUT);
    pinMode(voltage_battery, INPUT);
    pinMode(ampere_battery, INPUT);

    pinMode(solenoid_lock, OUTPUT);
    pinMode(alarm, OUTPUT);
    pinMode(MPU6050_int, OUTPUT);
    pinMode(MPU6050_sda, OUTPUT);
    pinMode(MPU6050_scl, OUTPUT);
  

    ibusRc.begin(ibusRcSerial);
    Serial.begin(9600);
    SPI.begin();
}





/*
void set_lights(){
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
*/

void set_light(){

}


void loop() {

    
  get_tgy_data();
  //set_lights();
  set_motor_speed();

  set_steering_front();

  set_brakes();
  
    Distancesensor vornelinks;
    Distancesensor vornemitte;
    Distancesensor VorneRechts;
    Distancesensor MitteLinks;
    Distancesensor MitteRechts;
    Distancesensor Hinten;
    vornelinks.echoPin = 41;
    vornelinks.triggerPin = 40;
    vornelinks.name ="vornelinks";
    vornelinks.checkdistance();
    vornemitte.echoPin = 39;
    vornemitte.triggerPin = 38;
    vornemitte.name ="vornerechts";
    vornemitte.checkdistance();

}

