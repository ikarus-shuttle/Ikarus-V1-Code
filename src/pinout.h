#ifndef PINOUT_H
#define PINOUT_H
#include <Arduino.h>

//all Pins
int csPin = 23;
int arrayChannel[10];

//Serial Port Declaration
HardwareSerial& ibusRcSerial = Serial2; //Pin 17
HardwareSerial& debugSerial = Serial; //Pin 0, Pin 1

//HUB-Motor Steering
int direction_motor = 27;
//all Variables
int current_motor_speed;
int current_motor_speed2; 

//Linearmotors
int linearmotor_back_open = 34;
int linearmotor_back_close = 35;
int linearmotor_front_open = 32;
int linearmotor_front_close = 33;
int linearmotor_cargo_open = 36;
int linearmotor_cargo_close = 37;
int linearmotor_cargosmall_open = 38;
int linearmotor_cargosmall_close = 39;

//Steering 
int poti_steering_front = A2;
int poti_steering_back = A3;

//Beleuchtung
int schweinwerfer_vorne = 3;
int led_back_right = 28;
int led_back_left = 29;
int led_front = 30;
int led_cargo = 31;

//Battery Compartiment
int voltage_battery = A0;
int ampere_battery = A1;

//internal Systems
int solenoid_lock = 2;
int alarm = 5;

//Gyroscope Declaration
int MPU6050_int = 4;
int MPU6050_sda = 20;
int MPU6050_scl = 21;

//Temperature Sensor
int temp_inside = 6;

//Loudspeakers
int Dfplayer_rx = 7;
int Dfplayer_tx = 8;

//4G and LTE Communication
int SIM7600E_sleep = 9;
int SIM7600E_rx = 10;
int SIM7600E_tx = 11;
int SIM7600E_sim = 12;

//Distance Sensor Declaration
int distance_LV_trig = 40; //links vorne
int distance_LV_echo = 41;
int distance_MV_trig = 42; //mitte vorne
int distance_MV_echo = 43;
int distance_RV_trig = 44; //rechts vorne
int distance_RV_echo = 45;
int distance_LS_trig = 46; //links seite
int distance_LS_echo = 47;
int distance_RS_trig = 48; //rechts seite
int distance_RS_echo = 49;
int distance_H_trig = 13; //hinten
int distance_H_echo = 53;

#endif