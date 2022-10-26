#include "linearmotor.h"



void turnleft_vorne() {
  digitalWrite(linearmotor_back_open, HIGH); //Weil der Motor an der Linken Seite befestigt wird.
  digitalWrite(linearmotor_back_close, LOW); 
  //Serial.println("turning left.");
}