#include <remote.h>

int readChannel(byte channelInput, int minLimit, int maxLimit, int defaultValue){
  uint16_t ch = ibusRc.readChannel(channelInput);
  if (ch < 100) return defaultValue;
  
  return map(ch, 1000, 2000, minLimit, maxLimit);
}

void get_tgy_data()
{
  for (byte i = 0; i<10; i++){ //Alle Channels auslesen.
    //int value = readChannel(i, -100, 100, 0);
    arrayChannel[i] = readChannel(i, -100, 100, 0); //Hier werden die Daten der Fernbedienung gespeichert.
    debugSerial.print("Ch");
    debugSerial.print(i + 1);
    debugSerial.print(": ");
    debugSerial.print(arrayChannel[i]);
    //debugSerial.print(value);
    debugSerial.print(" "); 
}
}