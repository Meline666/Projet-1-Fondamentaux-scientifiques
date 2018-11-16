#include <Arduino.h>
#include "cardio.h"

  int valeurPrecedente = 0;
  long tempsPrecedent = 0;

void pouls(){

  int valeurActuelle;
  long tempsDetection;

  valeurActuelle = analogRead(A0);

  if (valeurActuelle > VALEUR_SEUIL) {
    if (valeurPrecedente <= VALEUR_SEUIL) {
      tempsDetection = millis();
      if (tempsDetection > (tempsPrecedent + 200)){
        double tempsEcoule = millis()/1000.0;
        Serial.print( (1000.0 * 60.0) / (tempsDetection - tempsPrecedent),0);
        Serial.print(";");
        Serial.println(tempsEcoule); 
        tempsPrecedent = tempsDetection;
      }
    }
  }
  valeurPrecedente = valeurActuelle;
}
