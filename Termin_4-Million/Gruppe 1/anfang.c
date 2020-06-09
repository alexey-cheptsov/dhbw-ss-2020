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
Frage *fragen;



int anmeldung(char* Spielername)
{
    printf("Wie ist dein Name...");
    scanf()
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

void fragen_einlesen(Frage* Fragen_Katalog, char* PFAD){

    //fopen(...)
    //fscanf(...)
    //Fragen_Katalog[i].Frage = ...
}

int main()
{

  //Eigenschaften
    char[20] Spielername;
    
    int Guthaben = 0;
    int 50_50_flag = 0;  // 0 - nicht genommen, 1 - genommen
    
    Frage *Fragen_Katalog;
    
//Programmablauf
    
    //1. Eingabe Player-Creds
    anmeldung(Spielername);
    
    //2. Fragen aus der DB laden
    fragen_einlesen(Fragen_Katalog, char* PFAD);
    
    //3.  Hauptspiel
    
    Frage_fragen();
    50_50abfrage();
    Antwort_einlesen();
    richtig_o_falsch();
    gewinnberechnen();
    endscreen();
    
    
    

}
