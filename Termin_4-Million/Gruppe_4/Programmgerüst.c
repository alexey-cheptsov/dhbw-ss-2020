#include<stdio.h>
#include<dirent.h>
#include<string.h> 
#define MAX 97
#define PATH "test123"
#define ZEILENLAENGE 80

struct fragenKatalogEintrag
{
    char* frage;
    char* antworten[4];
    int nr_correct;
};
struct spieler {
	char* name;
	int gewinn;
};

struct fragenKatalogEintrag Catalogue[MAX];

int nutzerdaten_eingabe(char*vorname,char*nachname);// Patrik
int read_frage(struct fragenKatalogEintrag * Catalogue, int * nr_entries);//Tobias
int frage_auswahl(struct fragenKatalogEintrag*Catalogue, int nr_entries);// Joscha
void frage_ausgabe(struct fragenKatalogEintrag* Catalogue, int index);// Anja
int antwort_eingabe();// Harald
int antwort_auswertung(int richtig);
int spielstand_speichern();
void frage_ausgabe_50_50 (struct fragenKatalogEintrag* Eintrag, int index);


int nutzerdaten_eingabe(char*vorname,char*nachname)
{
    return 0;
}
int read_frage(struct fragenKatalogEintrag * Catalogue, int * nr_entries)
{ 	
	DIR *dir;
	FILE *dateiFrage;
	struct dirent *dirzeiger;
	int i = 0;
	/* öffne Verzeichnis @ PATH */
	if((dir=opendir(PATH)) == NULL){
		printf("\nVerzeichnis konnte nicht gefunden werden\n");
		return 0;}
	/* komplettes Verzeichnis Eintrag für Eintrag auslesen */
	while((dirzeiger=readdir(dir)) != NULL){
		char* dateipfad;
		strcpy(dateipfad, PATH);
		strcat(dateipfad, (*dirzeiger).d_name);
		dateiFrage = fopen(dateipfad, "r");
		fgets(Catalogue[i].frage, ZEILENLAENGE, dateiFrage);
		//test
}
int frage_auswahl(struct fragenKatalogEintrag*Catalogue, int nr_entries)
{
    return 0;
}
void frage_ausgabe(struct fragenKatalogEintrag* Catalogue, int index)
{

}
int antwort_eingabe()
{
    return 0;
}
int antwort_auswertung(int richtig)
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
    return 0;
}
