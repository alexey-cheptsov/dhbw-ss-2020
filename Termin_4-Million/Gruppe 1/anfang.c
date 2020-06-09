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



int anmeldung(int a, int b, int op)
{
    int c = 0;

    c = a + b;

    return c;
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

int main()
{

    char[]Spielername = anmeldung(int nummer);
    int geld = guthabensumme(int plus)

}
