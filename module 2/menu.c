//Jonah

#include <stdio.h>
#include "menu.h"



int menu(){
    int option;
    // ask what option user wants:
    printf("Welcome to Hexart! Please choose your preferred lighting option:\n 1. BPM match, All LEDs\n 2. BPM match, 1/x LEDs\n 3. BPM match, LED choice\nOption: ");
    scanf("%d", &option);

    //handle user error (non-existent option)
    if(option < 0 || option > 3){
        printf("ERROR, that's not an option!\n");
        menu(); // just reiterate, unless the user  repeats the error on purpose this won't cause problems
    }
    return option; // return user's choice
}

