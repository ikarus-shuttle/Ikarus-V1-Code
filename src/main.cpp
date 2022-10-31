#include <Arduino.h>
#include <SPI.h>
#include <IBusBM.h>
#include <pinout.h> //in this File, all the used Pins and used Variables are declared to make the code more clear.
#include <string.h> // Includes the library for editing Strings.
#include <distance_sensor.h> // Includes the Distance Sensor Class.
#include <linearmotor.h> // Includes the linearmotor files.
#include <hubmotor.h> // Includes the files for controlling the motors.
#include <remote.h> // Includes the files for working with the Remote.
#include <Adafruit_NeoPixel.h>

#ifdef __AVR__  // Adafruit Neopixel needs this code (i guess).
#include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

//call the diffrent classes.
IBusBM ibusRc;
Adafruit_NeoPixel strip_front(led_front_num, led_front, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip_back_left(led_back_left_num, led_back_left, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip_back_right(led_back_right_num, led_back_right, NEO_GRB + NEO_KHZ800);


/* //Removed due to incomplete class files.
Distancesensor LV;
LV.triggerPin = distance_LV_trig;
LV.echoPin = distance_LV_echo;
LV.name ="linksvorne";

Distancesensor MV;
MV.triggerPin = distance_MV_trig;
MV.echoPin = distance_MV_echo;
MV.name ="mittevorne";

Distancesensor RV;
RV.triggerPin = distance_RV_trig;
RV.echoPin = distance_RV_echo;
RV.name ="rechtsvorne";

Distancesensor LS;
LS.triggerPin = distance_LS_trig;
LS.echoPin = distance_LS_echo;
LS.name ="linksseite";

Distancesensor RS;
RS.triggerPin = distance_RS_trig;
RS.echoPin = distance_RS_echo;
RS.name ="rechtsseite";

Distancesensor H;
H.triggerPin = distance_H_trig;
H.echoPin = distance_H_echo;
H.name ="hinten";
*/

void setup() {
    pinMode(csPin, OUTPUT);
    //pinMode(csPin2, OUTPUT);
    pinMode(direction_motor, OUTPUT);
    pinMode(linearmotor_back_open, OUTPUT);
    pinMode(linearmotor_back_close, OUTPUT);
    
    pinMode(linearmotor_front_open, OUTPUT);

    pinMode(linearmotor_front_close, OUTPUT);
    pinMode(linearmotor_cargo_open, OUTPUT);
    pinMode(linearmotor_cargo_close, OUTPUT);
    pinMode(linearmotor_cargosmall_open, OUTPUT);
    pinMode(linearmotor_cargosmall_close, OUTPUT);
    pinMode(poti_steering_front, INPUT);
    pinMode(poti_steering_back, INPUT);
    pinMode(scheinwerfer_vorne, OUTPUT);

    pinMode(led_back_right, OUTPUT);
    pinMode(led_back_left, OUTPUT);
    pinMode(led_front, OUTPUT);
    pinMode(led_cargo, OUTPUT);
    pinMode(voltage_battery, INPUT);
    pinMode(ampere_battery, INPUT);

    pinMode(solenoid_lock, OUTPUT);
    pinMode(alarm, OUTPUT);
    pinMode(MPU6050_int, OUTPUT);
    pinMode(MPU6050_sda, OUTPUT);
    pinMode(MPU6050_scl, OUTPUT);

    pinMode(distance_LV_trig, OUTPUT);
    pinMode(distance_LV_echo, OUTPUT);
    pinMode(distance_MV_trig, OUTPUT);
    pinMode(distance_MV_echo, OUTPUT);
    pinMode(distance_RV_trig, OUTPUT);
    pinMode(distance_RV_echo, OUTPUT);
    pinMode(distance_LS_trig, OUTPUT);
    pinMode(distance_LS_echo, OUTPUT);
    pinMode(distance_RS_trig, OUTPUT);
    pinMode(distance_RS_echo, OUTPUT);
    pinMode(distance_H_trig, OUTPUT);
    pinMode(distance_H_echo, OUTPUT);

    ibusRc.begin(ibusRcSerial);
    Serial.begin(9600);
    SPI.begin();
    //SPI.transfer(0x00);
    SPI.transfer(0); // Den Motor abschalten

    //initialize Led strips.
    strip_front.begin();
    strip_back_left.begin();
    strip_back_right.begin();
}




void set_lights(){
  if (arrayChannel[5]==100){  //Down-state
    digitalWrite(scheinwerfer_vorne, LOW);
    Serial.println("Lights off");
    for(int i=0; i<led_front_num; i++) { 
    //do blinkers or sthg.
    //digitalWrite();
    strip_front.clear(); //switch all the Lights off.
    strip_back_left.clear(); //
    strip_back_right.clear();
    strip_front.show(); //switch all the Lights on.
    strip_back_left.show(); 
    strip_back_right.show(); 
    Serial.println("lights blinking");
    }

  }
  else if (arrayChannel[5]==0) //Mid-state
  {
    for(int i=0; i<80; i++) { 
    //do blinkers or sthg.
    //digitalWrite();
    //strip_front.clear(); //switch all the Lights off.
    //strip_back_left.clear(); //
    //strip_back_right.clear();
    strip_front.setPixelColor(i, strip_front.Color(220, 150, 0));
    strip_back_left.setPixelColor(i, strip_back_left.Color(220, 150, 0));
    strip_back_right.setPixelColor(i, strip_back_right.Color(220, 150, 0));
    strip_front.show(); //switch all the Lights on.
    strip_back_left.show(); 
    strip_back_right.show(); 
    //Serial.println("lights blinking");
    }
    strip_front.clear(); //switch all the Lights off.
    strip_back_left.clear(); //
    strip_back_right.clear();
  }
  
  else { //Upstate
  digitalWrite(scheinwerfer_vorne, HIGH);
  Serial.println("lights on");
  //engage all strips (front part is white, while the back part is red.)
  for(int i=0; i<led_front_num; i++) { // For each pixel...

    // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
    // Here we're using a moderately bright green color:
    
    strip_back_left.setPixelColor(i, strip_back_left.Color(255, 0, 0));
    strip_back_right.setPixelColor(i, strip_back_right.Color(255, 0, 0));
    strip_front.setPixelColor(i, strip_front.Color(255, 160, 255));

    strip_front.show(); //switch all the Lights on.
    strip_back_left.show(); 
    strip_back_right.show();   // Send the updated pixel colors to the hardware.
  }
  } 
}


void set_alarm() {
  if (arrayChannel[7]==100){ 
    digitalWrite(alarm, HIGH);
    digitalWrite(scheinwerfer_vorne, LOW);
    Serial.println("Alarm on");
    }
    else {
    digitalWrite(alarm, LOW);
    Serial.println("Alarm off");
    } 
}


void loop() {

  get_tgy_data();
  //set_lights();
  set_motor_speed();

  set_steering_front();
  set_cargo_bay();
  //set_brakes();
  set_alarm();

}

