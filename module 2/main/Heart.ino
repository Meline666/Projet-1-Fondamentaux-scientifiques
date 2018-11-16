//Jonah

#include "LEDOptionFunc.h" // to get all the functions for the different lighting modes from LEDOptionFunc.ino
#include "Heart.h"

int lightEmUp(int option, int option2, float bpm, int pulseLength){ // function to light up the LEDs of the heart module according to the options chosen in menu.c and paramHGenerator.c, the BPM detected by cardio.c (and pulseLength to say how long the LEDs should remain on for)
    float heartRateFrequency = bpm / 60;               // These four lines are used to calculate and store the heartrate ms intervals from BPM
    float heartRatePeriod = 1 / heartRateFrequency;    // They are spread out like this for ease of understanding (this isn't optimal but it's easier to read)
    float heartRateMs = heartRatePeriod*1000;          // -
    float heartRateDisp = heartRateMs - pulseLength;   // -

    switch (option){
        case 1 : // when option from param.h is 1, do this
            BPMall(heartRateDisp,pulseLength); // flash all LEDs according to BPM (delay of heartRateDisp)
            break;
        case 2 :
            BPMoutOfX(heartRateDisp,pulseLength,option2); // flash a user choice fraction of the LEDs according to BPM (delay of heartRateDisp)
            break;
        case 3 :
            BPMchoice(heartRateDisp, pulseLength, option2); // flash a user choice single LED according to BPM (elay of heartRateDisp)
            break;
    }
    return 0;
}
