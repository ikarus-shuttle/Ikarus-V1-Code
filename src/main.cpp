#include <Arduino.h>
#include <SPI.h>
#include <IBusBM.h>
#include <pinout.h> //in this File, all the used Pins and used Variables are declared to make the code more clear.
#include <string.h> // Includes the library for editing Strings.
#include <distance_sensor.h> // Includes the Distance Sensor Class.
#include <linearmotor.h> // Includes the linearmotor files.
#include <hubmotor.h> // Includes the files for controlling the motors.
#include <remote.h> // Includes the files for working with the Remote.

IBusBM ibusRc;

/* //Removed due to incomplete class files.
Distancesensor LV;
LV.triggerPin = distance_LV_trig;
LV.echoPin = distance_LV_echo;
LV.name ="linksvorne";

Distancesensor MV;
MV.triggerPin = distance_MV_trig;
MV.echoPin = distance_MV_echo;
MV.name ="mittevorne";

Distancesensor RV;
RV.triggerPin = distance_RV_trig;
RV.echoPin = distance_RV_echo;
RV.name ="rechtsvorne";

Distancesensor LS;
LS.triggerPin = distance_LS_trig;
LS.echoPin = distance_LS_echo;
LS.name ="linksseite";

Distancesensor RS;
RS.triggerPin = distance_RS_trig;
RS.echoPin = distance_RS_echo;
RS.name ="rechtsseite";

Distancesensor H;
H.triggerPin = distance_H_trig;
H.echoPin = distance_H_echo;
H.name ="hinten";
*/

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

    pinMode(distance_LV_trig, OUTPUT);
    pinMode(distance_LV_echo, OUTPUT);
    pinMode(distance_MV_trig, OUTPUT);
    pinMode(distance_MV_echo, OUTPUT);
    pinMode(distance_RV_trig, OUTPUT);
    pinMode(distance_RV_echo, OUTPUT);
    pinMode(distance_LS_trig, OUTPUT);
    pinMode(distance_LS_echo, OUTPUT);
    pinMode(distance_RS_trig, OUTPUT);
    pinMode(distance_RS_echo, OUTPUT);
    pinMode(distance_H_trig, OUTPUT);
    pinMode(distance_H_echo, OUTPUT);

    ibusRc.begin(ibusRcSerial);
    Serial.begin(9600);
    SPI.begin();
    //SPI.transfer(0x00);
    SPI.transfer(0); // Den Motor abschalten
}




void set_lights(){
  if (arrayChannel[5]==100){ 
    digitalWrite(schweinwerfer_vorne, LOW);
    Serial.println("Lights off");
  }
  else if (arrayChannel[5]==0)
  {
    //do blinkers or sthg.
    //digitalWrite();
    Serial.println("lights blinking");
  }
  
  else {
  digitalWrite(schweinwerfer_vorne, HIGH);
  Serial.println("lights on");
  } 
}


void set_alarm() {
  if (arrayChannel[7]==100){ 
    digitalWrite(alarm, HIGH);
    digitalWrite(schweinwerfer_vorne, LOW);
    Serial.println("Alarm on");
    }
    else {
    digitalWrite(alarm, LOW);
    Serial.println("Alarm off");
    } 
}


void loop() {

  get_tgy_data();
  set_lights();
  set_motor_speed();

  set_steering_front();

  set_brakes();
  set_alarm();

}

