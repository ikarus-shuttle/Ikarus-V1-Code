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
int alarm = 3;

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


#endif