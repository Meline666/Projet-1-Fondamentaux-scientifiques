//Jonah

#include "LEDOptionFunc.h"

void BPMall(float heartRatePeriod, int pulseLength){ // flash all LEDs at speed BPM for pulseLength amount of time
    for(int i = 2; i <= 12; i++){ //turn all LEDs on
        digitalWrite(i, HIGH);
    }
    delay(pulseLength); //wait pulseLength
    for(int i = 2; i <= 12; i++){ //turn all LEDs off
        digitalWrite(i, LOW);
    }
    delay(heartRatePeriod); //wait heartRatePeriod (corresponds to heartRateDisp in Heart.ino)
}

void BPMoutOfX(int heartRatePeriod, int pulseLength, int option2){ // Flash user choice fraction of LEDs at speed BPM for pulseLength amount of time
    for(int i = 2; i <= 12; i = i + option2){ // turn one in option2 number of LEDs on
        digitalWrite(i, HIGH);
    }
    delay(pulseLength); //wait pulseLength
    for(int i = 2; i <= 12; i = i + option2){ // turn one in option2 number of LEDs off
        digitalWrite(i, LOW);
    }
    delay(heartRatePeriod); //wait heartRatePeriod (corresponds to heartRateDisp in heart.ino)
}

void BPMchoice(int heartRatePeriod, int pulseLength, int option2){ // Flash user choice single LED at speed BPM for pulseLength amount of time
    option2++; // since our digital output pins start at 2, this makes it so that when the user enters 1, it'll turn on the 1st LED which is on pin 2
    digitalWrite(option2, HIGH); // turn LED of choice on
    delay(pulseLength); //wait pulse length
    digitalWrite(option2, LOW); // turn LED of choice off
    delay(heartRatePeriod); //wait heartRatePeriod (corresponds to heartRateDisp in heart.ino)
}
