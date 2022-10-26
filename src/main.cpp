#include <Arduino.h>
#include <SPI.h>
#include <IBusBM.h>
#include <pinout.h> //in this File, all the used Pins and used Variables are declared to make the code more clear.
#include <string.h> // Includes the library for editing Strings.
#include <distance_sensor.cpp> // Includes the Distance Sensor Class.
#include <linearmotor.h> // Includes the linearmotor files.


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

// Read the number of a given channel and convert to the range provided.
// If the channel is off, return the default value
int readChannel(byte channelInput, int minLimit, int maxLimit, int defaultValue){
  uint16_t ch = ibusRc.readChannel(channelInput);
  if (ch < 100) return defaultValue;
  
  return map(ch, 1000, 2000, minLimit, maxLimit);
}


void turnright_vorne(){
  digitalWrite(linearmotor_back_open, LOW); //Weil der Motor an der Linken Seite befestigt wird.
  digitalWrite(linearmotor_back_close, HIGH);
  Serial.println("turning right hinten.");
}
void block_vorne(){
  digitalWrite(linearmotor_back_open, LOW); //Weil der Motor an der Linken Seite befestigt wird.
  digitalWrite(linearmotor_back_close, LOW);
  Serial.println("linearmotor standby");
}
void set_steering_front() {
  if (arrayChannel[0] > 10) {
    turnright_vorne();
  }
  else if (arrayChannel[0] <-10) {
    turnleft_vorne();
  }
  else{
    block_vorne();
  }
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
void get_tgy_data()
{
  for (byte i = 0; i<10; i++){ //Alle Channels auslesen.
    //int value = readChannel(i, -100, 100, 0);
    arrayChannel[i] = readChannel(i, -100, 100, 0); //Hier werden die Daten der Fernbedienung gespeichert.
    debugSerial.print("Ch");
    debugSerial.print(i + 1);
    debugSerial.print(": ");
    debugSerial.print(arrayChannel[i]);
    //debugSerial.print(value);
    debugSerial.print(" "); 
}
}

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

