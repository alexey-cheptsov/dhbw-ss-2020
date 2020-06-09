//Tolles c program
#define pi = 1.5
//auswahl -> Diego
//ausgabe -> Nico
//50-50 -> Jenny
//read_fragen -> Stefan

typedef struct Frage {
    char* frage;
    char* antworten[4];
    int richtigeantwort;
} Frage;




void anmeldung(char* Spielername)
{

    // printf()
    // scanf(Spielername)
    //

}

void guthabensumme(int a)
{

  int guthaben += a;
}

int fragenkatalog()
{
    Datenbank = fopen( "Fragen-DB", "r");

    /* Der Erfolg oder Misserfolg von fopen() wird geprüft*/

    if(Datenbank == NULL){
        printf("Fehler beim Öffnen von Fragen-DB");
        exit(EXIT_FAILURE);
    }
    else
        printf("Fragen-DB erfolgreich geöffnet!");


    return 0;
}

}


void fragen_einlesen(Frage* Fragen_Katalog, char* pfad) {
    // fopen(pfad, ...)...
    // fscanf...
    // Fragen_Katalog[i].frage = ....
}

int main()
{

    // Eigenschaften
    char[100] Spielername; // Name des Spielers
    
    int Guthaben = 0;
    int 50_50_flag = 0; // 0 - nicht genommen, 1 - genommen
    
    Frage *Fragen_Katalog;
    

    // Programmablauf
    
    // 1. Eingabe des Spielernahmen
    anmeldung(Spielername); // Eingabe vom Nutzer 
    
    // 2. Fragen von der DB laden
    fragen_einlesen(Fragen_Katalog, "C://Document/Fragen");
    
    // 3. Hauptspielfunktion
        
    
    int geld = guthabensumme(int plus)

}
