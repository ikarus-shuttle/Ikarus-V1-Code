
#include <Arduino.h>
#include <SPI.h>
#include <IBusBM.h>
int csPin = 23;
//int csPin2 = 23;
int arrayChannel[10];
int direction = 27;
int linearmotor_back_open = 34;
int linearmotor_back_close = 35;
int current_motor_speed;
int current_motor_speed2;
IBusBM ibusRc;

HardwareSerial& ibusRcSerial = Serial2;
HardwareSerial& debugSerial = Serial;

void setup() {
    pinMode(csPin, OUTPUT);
    //pinMode(csPin2, OUTPUT);
    pinMode(direction, OUTPUT);
    pinMode(linearmotor_back_open, OUTPUT);
    pinMode(linearmotor_back_close, OUTPUT);
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

void turnleft_hinten() {
  digitalWrite(linearmotor_back_open, HIGH); //Weil der Motor an der Linken Seite befestigt wird.
  digitalWrite(linearmotor_back_close, LOW); 
  Serial.println("turning left.");
}
void turnright_hinten(){
  digitalWrite(linearmotor_back_open, LOW); //Weil der Motor an der Linken Seite befestigt wird.
  digitalWrite(linearmotor_back_close, HIGH);
  Serial.println("turning right hinten.");
}
void block_hinten(){
  digitalWrite(linearmotor_back_open, LOW); //Weil der Motor an der Linken Seite befestigt wird.
  digitalWrite(linearmotor_back_close, LOW);
  Serial.println("linearmotor standby");
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

void loop() 
{
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
    //allMotors
    current_motor_speed = map(arrayChannel[2],100,-80,0,128); //Auslesen der Daten an Channel 3.
    digitalWrite(csPin, LOW);
    
    //SPI.transfer(0x00);
    SPI.transfer(0);
    SPI.transfer(current_motor_speed);
    //delay(10);
    digitalWrite(csPin, HIGH); 
     
    Serial.println(current_motor_speed);
    
    set_steering_back();
    if (arrayChannel[8]==100){ //Bremsen und Richtungswechsel (it's not a bug it's a feature.) funktioniert mit allen Motorcontrollern
    digitalWrite(direction, HIGH);
    delay(1010); //angenährte Zeit, welche der Controller braucht um die Richtung zu wechseln. Dabei sollte so wenig Zeit benötigt werden, damit der Controller nicht eine Geschwindigkeit von 50% erreicht.
    digitalWrite(direction, LOW);
    Serial.println("on");
    }
    else {
    digitalWrite(direction, LOW);
    Serial.println("off");
    }
   

}

