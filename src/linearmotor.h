#ifndef LINEARMOTOR_H
#define LINEARMOTOR_H
#include <Arduino.h>


// Tell the program, that this class/int/variable exists somewhere.
//Lenkung vorne
extern int linearmotor_back_open;
extern int linearmotor_back_close;

//Lenkung hinten
extern int linearmotor_front_open;
extern int linearmotor_front_close;

//Fernsteuerung
extern int arrayChannel[10];

//cargo hinten
extern int linearmotor_cargo_open;
extern int linearmotor_cargo_close;

// Funktionen für den Cargobay
void open_cargo_bay();
void close_cargo_bay();
void block_cargo();
void set_cargo_bay();

// Funktionen für die vordere Lenkung
void turnleft_vorne();
void turnright_vorne();
void block_vorne();
void set_steering_front();

// Funktionen für die hintere Leknung
void turnleft_hinten();
void turnright_hinten();
void block_hinten();
void set_steering_back();


#endif