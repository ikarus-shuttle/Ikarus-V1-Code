#include "linearmotor.h"


// Vorderer Linearmotor 14mm/s

void turnleft_vorne() {
  digitalWrite(linearmotor_back_open, HIGH); //Weil der Motor an der Linken Seite befestigt wird.
  digitalWrite(linearmotor_back_close, LOW); 
  Serial.println("turning left.");
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

// Cargobay 10mm/s

void open_cargo_bay() {
  digitalWrite(linearmotor_cargo_open, HIGH); //Weil der Motor an der Linken Seite befestigt wird.
  digitalWrite(linearmotor_cargo_close, LOW); 
  Serial.println("open cargo.");
}

void close_cargo_bay(){
  digitalWrite(linearmotor_cargo_open, LOW); //Weil der Motor an der Linken Seite befestigt wird.
  digitalWrite(linearmotor_cargo_close, HIGH);
  Serial.println("close cargo.");
}

void block_cargo(){
  digitalWrite(linearmotor_cargo_open, LOW); //Weil der Motor an der Linken Seite befestigt wird.
  digitalWrite(linearmotor_cargo_close, LOW);
  Serial.println("cargo standby");
}

void set_cargo_bay() { 
  if (arrayChannel[4] == -100) { 
    open_cargo_bay();
  }
  else if (arrayChannel[4] == 100) {
    close_cargo_bay();
  }
  else{
    block_cargo();
  }
  
}

// Hinterer Linearmotor 10mm/s

void turnleft_hinten() {
  digitalWrite(linearmotor_front_open, HIGH); //Weil der Motor an der Linken Seite befestigt wird.
  digitalWrite(linearmotor_front_close, LOW); 
  Serial.println("turning left.");
}

void turnright_hinten(){
  digitalWrite(linearmotor_front_open, LOW); //Weil der Motor an der Linken Seite befestigt wird.
  digitalWrite(linearmotor_front_close, HIGH);
  Serial.println("turning right hinten.");
}

void block_hinten(){
  digitalWrite(linearmotor_front_open, LOW); //Weil der Motor an der Linken Seite befestigt wird.
  digitalWrite(linearmotor_front_close, LOW);
  Serial.println("linearmotor standby");
}

void set_steering_back() {
  if (arrayChannel[0] > 10) {
    turnleft_hinten();
  }
  else if (arrayChannel[0] <-10) {
    turnright_hinten();
  }
  else{
    block_hinten();
  }
}
