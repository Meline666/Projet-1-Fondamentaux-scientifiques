//Donovan (et Jonah)

#include <Arduino.h>
#include "cardio.h"
#include "Heart.h"
#include "param.h"

int valeurPrecedente = 0;
long tempsPrecedent = 0;

void pouls(){

    int valeurActuelle; // var pour stocker la valeur actuelle de A0 (valeur émise par le capteur)
    float BPM; // var pour contenir le BPM calculé pour le renvoyer à lightEmUp
    long tempsDetection; // le temps auquel le pic de circulation de sang a été detécté

    valeurActuelle = analogRead(A0); // prends la valeur émise par le capteur

    if (valeurActuelle > VALEUR_SEUIL) { // si la valeur actuelle est superieure à la valeur minimale definie dans cardio.h, faire
        if (valeurPrecedente <= VALEUR_SEUIL) { // si la valeur précédente est inferieure (ou égale) à la valeur minimum définie, faire
            tempsDetection = millis(); // mets le nombre de millisecondes passé depuis l'éxécution du programme arduino dans la var tempsDetection
            if (tempsDetection > (tempsPrecedent + 200)){ // si le temps auquel le pouls à été detécté est venu plus de 200ms après le temps précédent, faire
                double tempsEcoule = millis()/1000.0; // le temps écoulé depuis le début du programme en secondes
                BPM = (1000.0 * 60.0) / (tempsDetection - tempsPrecedent); // mettre le puls dans BPM
                Serial.print(BPM,0); // envoyer la valeur du pouls au port serie
                Serial.print(";"); // séparer le BPM du temps écoulé avec ;
                Serial.println(tempsEcoule); //envoyer la valeur du temps écoulé
                lightEmUp(option, option2, BPM, 100); //appel la fonction lightEmUp de Heart.ino pour faire clignoter le module coeur en fonction du BPM calculé et des options choisies dans param.h
                tempsPrecedent = tempsDetection; //mets tempsDetection dans tempsPrecedent pour la comparaison des deux dans le loop
            }
        }
    }
    valeurPrecedente = valeurActuelle; //mets valeurActuelle dans valeurPrecedente pour la comparaison des deux dans le loop
}
