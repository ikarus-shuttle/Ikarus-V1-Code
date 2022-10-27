/*
#include <lights.h>

extern int arrayChannel[10];
extern int schwein
void set_lights(){
  if (arrayChannel[5]==100){  //Down-state
    digitalWrite(schweinwerfer_vorne, LOW);
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
    for(int i=0; i<led_front_num; i++) { 
    //do blinkers or sthg.
    //digitalWrite();
    strip_front.clear(); //switch all the Lights off.
    strip_back_left.clear(); //
    strip_back_right.clear();
    //strip_front.setPixelColor(i, strip_front.Color(0, 0, 0));
    //strip_back_left.setPixelColor(i, strip_back_left.Color(0, 0, 0));
    //strip_back_right.setPixelColor(i, strip_back_right.Color(0, 0, 0));
    strip_front.show(); //switch all the Lights on.
    strip_back_left.show(); 
    strip_back_right.show(); 
    Serial.println("lights blinking");
    }
  }
  
  else { //Upstate
  digitalWrite(schweinwerfer_vorne, HIGH);
  Serial.println("lights on");
  //engage all strips (front part is white, while the back part is red.)
  for(int i=0; i<led_front_num; i++) { // For each pixel...

    // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
    // Here we're using a moderately bright green color:
    strip_front.setPixelColor(i, strip_front.Color(255, 160, 255));
    strip_back_left.setPixelColor(i, strip_back_left.Color(255, 0, 0));
    strip_back_right.setPixelColor(i, strip_back_right.Color(255, 0, 0));

    strip_front.show(); //switch all the Lights on.
    strip_back_left.show(); 
    strip_back_right.show();   // Send the updated pixel colors to the hardware.
  }
  } 
}
*/
