
#include <Arduino.h>
#include <IBusBM.h>
#include <SPI.h>

//Linearmotor vorne
int linearmotor_front_open = 32;
int linearmotor_front_close = 33;
//Linearmotor hinten
int linearmotor_back_open = 34;
int linearmotor_back_close = 35;
int hupe = 2;
int arrayChannel[10]; //Hier werden die Daten der Fernbedienung gespeichert.

//Motorpins
//int motorLV_speed_pin  = 27;
int cs_PIN = 22;
int motorRV_speed_pin = 23;
int motorLH_speed_pin = 24;
int motorRH_speed_pin = 26;
int motor_brakes = 26; //Ein Pin schalter alle Bremsen an.
int motor_direction = 27; // Ein Pin bestimmt alle Richtungsänderungen. (Mehrere Transistoren in Reihe geschaltet.)
int current_motor_speed;
IBusBM ibusRc;


HardwareSerial& ibusRcSerial = Serial2;
HardwareSerial& debugSerial = Serial;

void setup() {
  pinMode(linearmotor_front_open, OUTPUT);
  pinMode(linearmotor_front_close, OUTPUT);
  pinMode(linearmotor_back_open, OUTPUT);
  pinMode(linearmotor_back_close, OUTPUT);
  pinMode(motor_direction, OUTPUT);
  pinMode(cs_PIN, OUTPUT);
  pinMode(hupe, OUTPUT);
  debugSerial.begin(9600);
  ibusRc.begin(ibusRcSerial);
  SPI.begin();

}

// Read the number of a given channel and convert to the range provided.
// If the channel is off, return the default value
int readChannel(byte channelInput, int minLimit, int maxLimit, int defaultValue){
  uint16_t ch = ibusRc.readChannel(channelInput);
  if (ch < 100) return defaultValue;
  
  return map(ch, 1000, 2000, minLimit, maxLimit);
}
  

//Funktionen für Linearmotoren
void turnleft_vorne() {
  digitalWrite(linearmotor_front_open, HIGH); //Weil der Motor an der Linken Seite befestigt wird.
  digitalWrite(linearmotor_front_close, LOW); 
  Serial.println("turning left.");
}
void turnright_vorne(){
  digitalWrite(linearmotor_front_open, LOW); //Weil der Motor an der Linken Seite befestigt wird.
  digitalWrite(linearmotor_front_close, HIGH);
  Serial.println("turning right.");
}

void block_vorne(){
  digitalWrite(linearmotor_front_open, LOW); //Weil der Motor an der Linken Seite befestigt wird.
  digitalWrite(linearmotor_front_close, LOW);
  Serial.println("linearmotor standby");
}

void turnleft_hinten() {
  digitalWrite(linearmotor_back_open, HIGH); //Weil der Motor an der Linken Seite befestigt wird.
  digitalWrite(linearmotor_back_close, LOW); 
  Serial.println("turning left.");
}
void turnright_hinten(){
  digitalWrite(linearmotor_back_open, LOW); //Weil der Motor an der Linken Seite befestigt wird.
  digitalWrite(linearmotor_back_close, HIGH);
  Serial.println("turning right.");
}

void block_hinten(){
  digitalWrite(linearmotor_back_open, LOW); //Weil der Motor an der Linken Seite befestigt wird.
  digitalWrite(linearmotor_back_close, LOW);
  Serial.println("linearmotor standby");
}

void set_steering_front() {
  if (arrayChannel[0] > 10) {
    turnleft_vorne();
  }
  else if (arrayChannel[0] <-10) {
    turnright_vorne();
  }
  else{
    block_vorne();
  }
}
void set_steering_back() {
  if (arrayChannel[3] > 10) {
    turnleft_hinten();
  }
  else if (arrayChannel[3] <-10) {
    turnright_hinten();
  }
  else{
    block_hinten();
  }
}

void check_lights() {
  if (arrayChannel[5]==-100){
    digitalWrite(hupe, HIGH);
  }
  else {
    digitalWrite(hupe, LOW);
  }
}

//Funktionen der Motoren
void check_driving_status() {
  current_motor_speed = map(arrayChannel[2],100,-100,0,128); //Auslesen der Daten an Channel 3.
  digitalWrite(cs_PIN, LOW);
  SPI.transfer(0);
  SPI.transfer(current_motor_speed);
  Serial.println(current_motor_speed);
  delay(10);
  digitalWrite(cs_PIN, HIGH); 
  Serial.println(current_motor_speed);
}
void test_function() {
  for(int i=0; i <=128; i++ ) {
        digitalWrite(cs_PIN, LOW);
        SPI.transfer(0);
        SPI.transfer(i);
        //value = analogRead(readPin);
        //Serial.println(value);
        Serial.println(i);
        //delay(10);
        //Serial.println("no");
        digitalWrite(cs_PIN, HIGH);
    }
    for(int i=128; i >=0; i-- ) {
        digitalWrite(cs_PIN, LOW);
        SPI.transfer(0);
        SPI.transfer(i);
        //value = analogRead(readPin);
        //Serial.println(value);
        Serial.println(i);
        delay(10);
        //Serial.println("no");
        digitalWrite(cs_PIN, HIGH);
    }
}

void loop() {
  for (byte i = 0; i<10; i++){ //Alle Channels auslesen.
    //int value = readChannel(i, -100, 100, 0);
    arrayChannel[i] = readChannel(i, -100, 100, 0);
    debugSerial.print("Ch");
    debugSerial.print(i + 1);
    debugSerial.print(": ");
    debugSerial.print(arrayChannel[i]);
    //debugSerial.print(value);
    debugSerial.print(" "); 
    
    
  }
  debugSerial.println();
  //set_steering_back();
  //set_steering_front();
  //check_lights();
  check_driving_status();
  delay(500);
  test_function();
  delay(500);
  //debugSerial.println();
  //check_driving_status();
  
}