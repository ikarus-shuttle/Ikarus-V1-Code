#ifndef REMOTE_H
#define REMOTE_H
#include <Arduino.h>
#include <IBusBM.h>

// Tell the program, that this class/int/variable exists somewhere.
extern IBusBM ibusRc;
extern int arrayChannel[10];
extern HardwareSerial& debugSerial; 
int readChannel(byte channelInput, int minLimit, int maxLimit, int defaultValue);
void get_tgy_data();

#endif