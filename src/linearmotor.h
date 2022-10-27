#ifndef LINEARMOTOR_H
#define LINEARMOTOR_H
#include <Arduino.h>


// Tell the program, that this class/int/variable exists somewhere.
//Lenkung
extern int linearmotor_back_open;
extern int linearmotor_back_close;

//Fernsteuerung
extern int arrayChannel[10];

//cargo hinten
extern int linearmotor_cargo_open;
extern int linearmotor_cargo_close;

void open_cargo_bay();
void close_cargo_bay();
void block_cargo();
void set_cargo_bay();

void turnleft_vorne();
void turnright_vorne();
void block_vorne();
void set_steering_front();

#endif