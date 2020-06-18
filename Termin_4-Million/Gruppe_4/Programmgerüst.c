#include<stdio.h>
#include<dirent.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>

#define MAX 85
#define PATH "C:/Users/tobia/Documents/DHBW/2. Semester/Informatik Labor/dhbw-ss-2020/Termin_4-Million/Fragen-DB/"					//Eintragen des Pfades in dem sich das Verzeichnis mit den Fragen befindet
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
int read_frage(struct fragenKatalogEintrag * Catalogue);//Tobias
int frage_auswahl(int nr_entries, int index[7]);// Joscha
void frage_ausgabe(struct fragenKatalogEintrag* Catalogue, int index);// Anja
int antwort_eingabe();// Harald
int antwort_auswertung(struct fragenKatalogEintrag* Catalogue, int antwort);
int spielstand_speichern(struct spieler *neuerSpieler);//Harald
void frage_ausgabe_50_50 (struct fragenKatalogEintrag* Eintrag, int index);
int cmpfunc (const void * a, const void * b);


int nutzerdaten_eingabe(char *vorname,char *nachname)
{
    vorname[50];
	nachname[50];
	printf("Bitte Vornamen und Nachnamen eingeben:\n");
	scanf("%s %s",vorname,nachname);
    return 0;
}
int read_frage(struct fragenKatalogEintrag * Catalogue)
{

	DIR *dir;
	struct dirent *dirzeiger;
	int i = 0;
	int k = 2;
	char array[90][100];
	char *temp;
	char* test = "C:/Users/tobia/Documents/DHBW/2. Semester/Informatik Labor/dhbw-ss-2020/Termin_4-Million/Fragen-DB/Gruppe_4/";
	char* dateipfad;
	char* antwortAOld;
	char* antwortBOld;
	char* antwortCOld;
	char* antwortDOld;

	/*	öffne Verzeichnis @ PATH */
	dir = opendir(PATH);
	if(dir == NULL){
		printf("\nVerzeichnis konnte nicht gefunden werden\n");
		return 0;}
	/*	komplettes Verzeichnis Eintrag für Eintrag auslesen
		Jede Fragedatei wird geöffnet*/
	while(dirzeiger=readdir(dir)){
		strcpy(array[i], dirzeiger->d_name);
		i++;
	}
	
	closedir(dirzeiger);
	
	for(int i=3; i<=MAX; i++){
		FILE *dateiFrage;
		strcpy(dateipfad,test);
		strcat(dateipfad, array[i]);
		dateiFrage = fopen(dateipfad,"r");
		if (dateiFrage == NULL){
			printf("\n Datei konnte nicht geoeffnet werden\n\n\n");
			return 0;
			}
			
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
		fclose(dateiFrage);
		}
	return 0;
}

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int frage_auswahl(int nr_entries, int index[7])
{
	int flag=1;
	do
	{
		srand(time(NULL));

		for(int i=0;i<7;i++)
		{
			index[i]= (rand()%nr_entries)+1;
		}

		qsort(index, 7, sizeof(int), cmpfunc);

		for(int i=1;i<=7;i++)
		{
			if(index[i]==index[i-1])
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

	return *index;
}
void frage_ausgabe(struct fragenKatalogEintrag* Catalogue, int index)
{
	printf("\n%s\n", Catalogue[index].frage);
	for (int i = 0; i<=3;i++){
	printf("\n%d: %s", i+1, Catalogue[index].antworten[i]);
	}

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
int antwort_auswertung(struct fragenKatalogEintrag* Catalogue, int antwort)
{
    if((*Catalogue).nr_correct == antwort){
        return 1;
    }
    else{
        return 0;
    }
}
int spielstand_speichern(struct spieler *neuerSpieler)
{
    FILE *fp = NULL;
    /*Öffnet die spielstand Datei bzw. legt diese an sofern diese noch nicht existiert*/
    if((fp=fopen("spielstaendeWWM.txt", "a")) != NULL)
    {
        fprintf(fp, "\n%s %s\nHighscore: %d", neuerSpieler->vorname, neuerSpieler->nachname, neuerSpieler->gewinn);
        fclose(fp);
    }
    else
    {
        fprintf(stdout, "Dateifehler!\n");//Ausgabe der Fehlermeldung, fals Datei nicht geöffnet wurde
        return 1;//Beenden der Funktion
    }
    return 0;
}
void frage_ausgabe_50_50 (struct fragenKatalogEintrag* Eintrag, int index)
{

	int c;
	/*	Die Frage wird nochmal ausgegeben*/
	printf("\n%s",Catalogue[index].frage);
	/*	Es wird eine Zufallszahl zw. 0 und 3 bestimmt, dabei darf die Zahl nicht die richtige Antwort sein*/
	srand(time(NULL));
	c = rand() % 4;
	if (c == Catalogue[index].nr_correct){
		if (c<3){
			c++;
		}
		else if(c==3){
			c--;
		}
	}
	/*	Die ausgewählte Antwort und die richtige Antwort werden in originaler Reihenfolge ausgegeben*/
	if (c>Catalogue[index].nr_correct){
		printf("\n%d: %s\t%d: %s", Catalogue[index].nr_correct + 1, Catalogue[index].antworten[(Catalogue[index].nr_correct)], c + 1, Catalogue[index].antworten[c]);
	}
	if(c<Catalogue[index].nr_correct){
		printf("\n%d: %s\t%d: %s", c + 1, Catalogue[index].antworten[c], Catalogue[index].nr_correct + 1, Catalogue[index].antworten[(Catalogue[index].nr_correct)]);
	}
}

int main()
{
    int gewinn[7] = {10, 100, 1000, 10000, 100000, 500000, 1000000};
    int index[7] = {};
    int frageAktuell = 0, antwort = 0, jokerflag = 0, fragenzaehler =0;

    struct spieler neuerSpieler;

    read_frage(&Catalogue);

    nutzerdaten_eingabe(neuerSpieler.vorname, neuerSpieler.nachname);
    while(1)
    {
        frageAktuell = frage_auswahl(MAX, index);
        frage_ausgabe(Catalogue, frageAktuell);
        antwort = antwort_eingabe();
        if(antwort == 5)//abfragen ob Joker verlangt
        {
            if(jokerflag == 1)//Abfrage ob Joker bereits verbraucht
            {
                printf("Sie haben leider keinen Joker mehr!\n");
                antwort = antwort_eingabe();
            }
            else//Wenn Joker verfügbar Frage erneut ausgeben mit 2 Antworten
            {
                jokerflag = 1;
                frage_ausgabe_50_50(Catalogue, frageAktuell);
                antwort= antwort_eingabe();
            }
        }
        if(antwort_auswertung(Catalogue, antwort))
        {
            neuerSpieler.gewinn = gewinn[fragenzaehler];
            fragenzaehler++;
        }
        else
        {

            spielstand_speichern(&neuerSpieler);
            return 0;
        }
    }
    return 0;
}
