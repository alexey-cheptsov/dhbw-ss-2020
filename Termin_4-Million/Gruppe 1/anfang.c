//Tolles c program
#define pi = 1.5
//auswahl der Fragen-> Diego/Simmi
//ausgabe -> Nico
//50-50 -> Jenny
//read_fragen -> Stefan

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

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


/*Die Funktion "zufallszahl" berechnet 7 Zufallszahlen und sortiert diese dann in 
 aufsteigender Reihenfolge. Danach prüft sie, ob aufeinanderfolgende Zahlen gleich sind.
 Die Schleife läuft solange durch, bis alle Zufallszahlen einen unterschiedlichen Wert haben 
 und wird dann verlassen. Im Anschluss werden die Zufallszahlen ausgegeben.*/	

int zufallszahl(int Zahl[8])
{
	int flag=1;
	do
	{
		srand(time(NULL));
		
		for(int i=0;i<7;i++)
		{
			Zahl[i]= (rand()%93)+1;		
		}
	
		qsort(Zahl, 7, sizeof(int), cmpfunc);

		for(int i=1;i<=7;i++)
		{
			if(Zahl[i]==Zahl[i-1])		
			{
				flag=0;	
				break;
			}
			
			else
			{
		   flag=1;
			}
		}
	}while(flag==0);	 
	 
		printf("Folgende Fragen wurden ausgewählt: \n");
		for(int n = 0 ; n < 7; n++ ) 
		{   
			printf("%d ", Zahl[n]);
		}
	return *Zahl;
}




void fragen_einlesen(Frage* Fragen_Katalog, char* PFAD){

int Frage[8];
zufallszahl(Frage); //7 Zufallszahlen werden in das Array "Frage" geschrieben
    
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
    abfrage50_50();
    Antwort_einlesen();
    richtig_o_falsch();
    gewinnberechnen();
    endscreen();
    
    
    

}
