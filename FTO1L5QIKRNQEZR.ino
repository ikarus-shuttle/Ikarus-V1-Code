/* X9C103P Basic Operation - Synchronize code with hardware*/
/*    Move wiper down the minimum tap terminal.            */
/*    Move wiper up the maximum tap terminal.              */
/*
 *  Created  Feb 2016
 *  By user  TrewRoad
 *
 *  X9C103P  pin out
 *    Pin 1 INC
 *    Pin 2 U_D
 *    Pin 3 VH
 *    Pin 4 Gnd
 *    Pin 5 VW
 *    Pin 6 VL
 *    Pin 7 CS
 *    Pin 8 Vcc
 */
// Define some values for the POT and ADC
 /*
#include <Arduino.h>
#define ANALOG_REFERENCE 5.0    // Alter for 3.3V Arduino
#define POT_VALUE 100000L        // Nominal POT value
#define STEP_OHMS POT_VALUE/99  // Number of ohms per tap point
#define PULSE_TIMED 10          // millisecond delay 

const int pinUD = 8;            // --> X9C103P pin 2
const int pinINC = 9;           // --> X9C103P pin 1
const int CS = 10;              // --> X9C103P pin 7
const int pinWiper = A1;        // --> X9C103P pin 5

const int tapPoints = 100;     // X9C103P specs
int sampleADC = 0;
float voltage = 0;
boolean countDirection  = true;
 
void setup() {
  // Set up digital pins
  pinMode (CS, OUTPUT);
  //Deselect before any misc. bit bashing?
  digitalWrite(CS,HIGH);        //deselect the POT
  pinMode (pinUD, OUTPUT); 
  pinMode (pinINC, OUTPUT);
  // Set analog pin to known state just to be thorough
  pinMode(pinWiper, INPUT);
  digitalWrite(pinWiper, LOW);  // re-set pullup on analog pin
                                // this seems to happen on pinMode()
                                // but the explanantion is a bit 'foggy' to me.
  // Invoke the serial communicatiom
  Serial.begin(9600);
  //Deselect before any misc. bit bashing?
  digitalWrite(CS,HIGH);     //deselect the POT
  // Provide some terminal output then wait for interaction
  Serial.println("\n* X9C103P Basic Operation *\n");
  Serial.print("Nominal Resistive Element ");
  Serial.print(STEP_OHMS);
  Serial.println(" Ohms");
  Serial.print("Initial sample");
  voltage = g_PrintADC(pinWiper);
  Serial.println("\nSend any character to begin.\n");

}
 
void loop() {
  // Wait for any byte to start
  while (Serial.available() <= 0);

  // Use simple loop to move wiper it's full scope.
  // First pass will ensure the wiper position is
  // a fixed terminal. The second iteration will provide
  // an ADC sampling for the increment/decrement away from
  // this fixed terminal.
  for (int locTap=0; locTap<2; locTap++)
  {
    countDirection  = ! countDirection;
    digitalWrite(pinUD,countDirection);
    Serial.print("Wiper Direction ");
    if (countDirection) {
      Serial.println("UP");
    }else{
      Serial.println("DOWN");
    }
    tapDance(tapPoints);
    Serial.println("");   //separate the listing and pause 2sec.
    delay(2000);
  }
  Serial.println("Wiper Tap Synchronized.");
  Serial.print("Re-sample");
  voltage = g_PrintADC(pinWiper);
  while(true); //while away the cycles.
}
// Simple routine to perform a wiper movement.
void X9C103P_INC(int enable, int pulse){

  digitalWrite(pulse, HIGH);   // HIGH before falling edge
                               // Not recommended for puksed key to be low 
                               // when chip select (enable) pulled low.
  delay(PULSE_TIMED);          // wait for IC/stray capacitance ?
  digitalWrite(enable,LOW);    // select the POT
  digitalWrite(pulse, LOW);    // LOW for effective falling edge
  delay(PULSE_TIMED);          // wait for IC/stray capacitance ?
                               // tap point copied into non-volatile memory
                               // if CS returns HIGH while INC is HIGH
  digitalWrite(enable,HIGH);   //deselect the POT 

}
// Routine to sample ADC. Calculate and display a voltage on wiper pin.
// Display the nominal wiper point resistance and that calculated with ADC
// Tap number may not be the Wiper Tap Point until one u/d cycle completed.
void tapDance(int taplimits)
{
    for (int tap = 0; tap < taplimits; tap++) 
    {
      String stringOne ="0";
      String stringTwo ="";
      if (countDirection) {
        stringOne += String(tap);
        stringTwo = String(tap*STEP_OHMS);
      } else {
        stringOne += String(taplimits-tap-1);
        stringTwo = String((taplimits-tap-1)*STEP_OHMS,DEC);
      }
      //Display the quantities
      Serial.print("Tap = " );
      Serial.print(stringOne.substring(stringOne.length()-2));
      voltage = g_PrintADC(pinWiper);
      Serial.print("   Tap Ohm = ");
      stringTwo +="     ";    //Pad to 1M-1
      Serial.print(stringTwo.substring(0,6));
      Serial.print("  Law = ");
      Serial.println(float (POT_VALUE )*(voltage/ANALOG_REFERENCE),0);
   
      // Move the tap point one count 
      X9C103P_INC(CS,pinINC);
      delay(200);     // delay a bit for viewing
    } 
}
float g_PrintADC(byte anaPin)
{
  int sampleADC = analogRead(anaPin);
  float volts = (sampleADC * ANALOG_REFERENCE)/ 1023.0;
  Serial.print("   ADC = ");
  Serial.print(sampleADC);     
  Serial.print("\tVoltage = ");
  Serial.print(volts,3);
  return volts;
}

*/