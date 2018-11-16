//Jonah

#include <stdio.h>
#include "paramHGenerator.h"
#include "menu.h"

int generateParamH(int option){ //function that generates param.h based on input from menu.c
    int option2 = 0; // initializes second option as 0 since by default (with option 1) it won't be used
    if(option != 1){ // if the user hasn't selected option 1, do
        switch(option){
            case 2: //ask for value of 2nd option for option 2
                do {
                    printf("Please enter out of how many LEDs you'd like one to be lit up: ");
                    scanf("%d", &option2);
                    if(option2 < 1 || option2 > 10){ // if user enters unavailable number, print this error message
                        printf("ERROR, there are only 10 LEDs, so that's not an option!\n");
                    }
                }while(option2 < 1 || option2 > 10); // if user enters unavailable number, loop back
                break;
            case 3: // ask for value of 2nd option for option 3
                do {
                    printf("Please enter the number of the LED you would like to light up: ");
                    scanf("%d", &option2);
                    if(option2 < 1 || option2 > 10){
                        printf("ERROR, there are only 10 LEDs, so that's not an option!"); // if user enters unavailable number, print this error message
                    }
                }while(option2 >= 1 && option2 <= 10); // if user enters unavailable number, loop back
                break;
        }
    }

    FILE *hFWrite; // inits an object of type FILE to control stream

    hFWrite = fopen("/home/jonah/Documents/Eixadocs/Projets/Projet 1/DEV module coeur/main/main/param.h","w"); //opens param.h into hFWrite

    //Writes contents of H file with variable "option" and "option2" containing input from menu.c so that it can be read by Heart.ino
    fprintf(hFWrite, "#ifndef GENERATIONH_PARAM_H\n#define GENERATIONH_PARAM_H\n\n#endif //GENERATIONH_PARAM_H\n\nconst int option = %d;\nconst int option2 = %d;", option, option2);

    return 0;
}
