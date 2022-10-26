#include "linearmotor.h"



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