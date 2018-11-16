//From Arduino to Processing to Txt or cvs etc.
//import
import processing.serial.*;
//declare
PrintWriter output;
Serial udSerial;

void setup() {
  udSerial = new Serial(this, "COM5", 9600); //Définit l'entrée d'informations
  output = createWriter ("Battements.csv"); //Créé/modifie le fichier CSV créé
}

  void draw() {
    if (udSerial.available() > 0) {
      String SenVal = udSerial.readString();//s'assure que la valeur enregistrée est différente
      if (SenVal != null) {
        output.print(SenVal);//Imprime la valeur dans le fichier Battements.csv
     
      }
    }
    
}

  void keyPressed(){ 
    output.flush();
    output.close();
    exit(); //Stoppe l'impression de données dans le fichier lorsqu'une touche est pressée
  }
