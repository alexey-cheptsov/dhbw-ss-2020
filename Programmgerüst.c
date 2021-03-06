#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define MAX 97
#define PATH "test123"					//Eintragen des Pfades in dem sich das Verzeichnis mit den Fragen befindet
#define ZEILENLAENGE 80

struct fragenKatalogEintrag
{
    char* frage;
    char* antworten[4];
    int nr_correct;
};
struct spieler {
	char* vorname;
	char* nachname;
	int gewinn;
};

struct fragenKatalogEintrag Catalogue[MAX];

int nutzerdaten_eingabe(char*vorname,char*nachname);// Patrik
int read_frage(struct fragenKatalogEintrag * Catalogue, int * nr_entries);//Tobias
int frage_auswahl(struct fragenKatalogEintrag*Catalogue, int nr_entries);// Joscha
void frage_ausgabe(struct fragenKatalogEintrag* Catalogue, int index);// Anja
int antwort_eingabe();// Harald
int antwort_auswertung(int richtig, int antwort);// Harald
int spielstand_speichern();
void frage_ausgabe_50_50 (struct fragenKatalogEintrag* Eintrag, int index);


int nutzerdaten_eingabe(char*vorname,char*nachname)
{
    vorname[50];
	nachname[50];
	printf("Bitte Vornamen und Nachnamen eingeben:\n");
	scanf("%s %s",vorname,nachname);
    return 0;
}
int read_frage(struct fragenKatalogEintrag * Catalogue, int * nr_entries)
{
	DIR *dir;
	FILE *dateiFrage;
	struct dirent *dirzeiger;
	int i = 0;
	int k = 2;
	char *temp;
	char* antwortAOld;
	char* antwortBOld;
	char* antwortCOld;
	char* antwortDOld;
	
	/*	öffne Verzeichnis @ PATH */
	if((dir=opendir(PATH)) == NULL){
		printf("\nVerzeichnis konnte nicht gefunden werden\n");
		return 0;}
	/*	komplettes Verzeichnis Eintrag für Eintrag auslesen 
		Jede Fragedatei wird geöffnet*/
	while((dirzeiger=readdir(dir)) != NULL){
		char* dateipfad = NULL;
		strcpy(dateipfad, PATH);
		strcat(dateipfad, (*dirzeiger).d_name);
		dateiFrage = fopen(dateipfad, "r");
		if (NULL == dateiFrage){
			printf("\n Datei konnte nicht geoeffnet werden\n\n\n");
			return 0;}
		/*	Aus der ersten Zeile wird die Frage ausgelesen, die zweite wird übersprungen und die folgenden Zeilen
		werden als Fragen zwischengespeichert. */
		fgets(Catalogue[i].frage, ZEILENLAENGE, dateiFrage);
		fgets(temp, ZEILENLAENGE, dateiFrage);
		fgets(antwortAOld, ZEILENLAENGE, dateiFrage);
		fgets(antwortBOld, ZEILENLAENGE, dateiFrage);
		fgets(antwortCOld, ZEILENLAENGE, dateiFrage);
		fgets(antwortDOld, ZEILENLAENGE, dateiFrage);
		/*	Richtige Antwort wird gesucht und die Nummer der Antwort wird gespeichert (a =  1, b = 2, usw)
		Richtige Antwort ist am ersten Zeichen zu erkennnen */
		if(antwortAOld[0] == '+'){
			Catalogue[i].nr_correct = 1;}
		else if(antwortBOld[0] == '+'){
			Catalogue[i].nr_correct = 2;}
		else if(antwortCOld[0] == '+'){
			Catalogue[i].nr_correct = 3;}
		else if(antwortDOld[0] == '+'){
			Catalogue[i].nr_correct = 4;}
		/*	Die Zwischenspeicher werden in die Structure geschrieben, aber die ersten 2 Zeichen werden uebergangen, da
			sie nur der Formatierung und ERkennung dienen */
		for(int j=0; j<=strlen(antwortAOld); j++){
			Catalogue[i].antworten[0][j] = antwortAOld[k];
			}
		for(int j=0; j<=strlen(antwortBOld); j++){
			Catalogue[i].antworten[1][j] = antwortBOld[k];
			}
		for(int j=0; j<=strlen(antwortCOld); j++){
			Catalogue[i].antworten[2][j] = antwortCOld[k];
			}
		for(int j=0; j<=strlen(antwortDOld); j++){
			Catalogue[i].antworten[3][j] = antwortDOld[k];
			}
		i++;
	}
	/*	Directory wird wieder geschlossen */
	closedir(dir);
	return 0;
}
int frage_auswahl(struct fragenKatalogEintrag*Catalogue, int nr_entries)
{
    char Zwischenspeicher[7][100];
	int j=0;
	//Zufallszahl mittels Zeitstempel auf Startwert gesetzt
	srand(time(NULL));

	for(int i=0; i<7;i++){
		// Zufällig ausgewählte Dateinamen zwischenspeichern
		strcpy(Zwischenspeicher[i], fragenKatalogEintrag.frage[rand()%nr_entries+1]);
	}

	//Ursprünglichen Inhalt von dem fragenKatalogEintrag löschen
		while(j<=100){
		fragenKatalogEintrag.frage[j][0] = '\0';
		j++;
	}

	//fragenKatalogEintrag mit neuen zufällig ausgewählten Fragen füllen
	for(int i=0; i<7;i++){
		strcpy(fragenKatalogEintrag.frage[i], Zwischenspeicher[i]);}
    return 0;
}
void frage_ausgabe(struct fragenKatalogEintrag* Catalogue, int index)
{
	//Ausgabe der aktuellen Frage
	printf("Frage: %s \n", Catalogue[index].frage);
	//Ausgabe der vier Antwortmöglichkeiten
	for(int n = 0; n <= 3; n++)
		printf("%d) %s \n", n+1, Catalogue[index].antworten[n]);
}
int antwort_eingabe()
{
    char antwort = 0;
    int antwortNummer = 0;
    do
    {
        printf("Bitte geben Sie die Nummer der richtigen Antwort ein!"
               "Wenn Sie einen Joker wuenschen waehlen Sie die 5!"
               "Bei eingabe der Falschen Antwort wird das Programm abgebrochen"
               "und Ihr aktueller Highscore gespeichert!\n");
        antwort = getchar();
        antwortNummer = (int)antwort;
    }while(antwortNummer ==0||antwortNummer >5);
    printf("Ihre antwort wird ausgewertet\n");
    return antwortNummer;
}
int antwort_auswertung(int richtig, int antwort)
{
    return 0;
}
int spielstand_speichern()
{
    return 0;
}
void frage_ausgabe_50_50 (struct fragenKatalogEintrag* Eintrag, int index)
{

}
int main()
{
    int frageAktuell = 0, antwort = 0, richtigeAntwort = 0, jokerflag = 0;

    struct spieler neuerSpieler;
    read_frage(&Catalogue);
    nutzerdaten_eingabe(&neuerSpieler.vorname,&neuerSpieler.nachname);
    while(1)
    {
        frageAktuell = frage_auswahl(&Catalogue, MAX);
        frage_ausgabe(Catalogue, frageAktuell);
        antwort = antwort_eingabe();
        if(antwort == 5)
        {
            if(jokerflag == 1)
            {
                printf("Sie haben leider keinen Joker mehr!\n");
                antwort = antwort_eingabe();
            }
            else
            {
                jokerflag = 1;
                frage_ausgabe_50_50(&Catalogue, frageAktuell);
                antwort_eingabe();
            }
        }
        antwort_auswertung(richtigeAntwort, antwort);
    }
    return 0;
}
