#ifndef HUBMOTOR_H
#define HUBMOTOR_H
#include <Arduino.h>
#include "SPI.h"

// Tell the program, that this class/int/variable exists somewhere.
extern int current_motor_speed;
extern int arrayChannel[10];
extern int csPin;
extern int direction_motor;
extern int brakes_motor;
void set_motor_speed();
void set_brakes();
void set_direction();


#endif