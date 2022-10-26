#ifndef LINEARMOTOR_H
#define LINEARMOTOR_H
#include <Arduino.h>


// Tell the program, that this class/int/variable exists somewhere.
extern int linearmotor_back_open;
extern int linearmotor_back_close;
extern int arrayChannel[10];

void turnleft_vorne();
void turnright_vorne();
void block_vorne();
void set_steering_front();

#endif