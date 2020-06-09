#include<stdio.h>
#define MAX 97
#define JOKER 5
#define FEHLERMELDUNG 6

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

struct fragenKatalogEintrag Catalouge[MAX];

int nutzerdaten_eingabe(char*vorname,char*nachname);// Patrik
void read_frage(struct fragenKatalogEintrag * Catalogue, int * nr_entries);//Tobias
int frage_auswahl(struct fragenKatalogEintrag*Catalogue, int nr_entries);// Joscha
void frage_ausgabe(struct fragenKatalogEintrag* Catalogue, int index);// Anja
int antwort_eingabe();// Harald
int antwort_auswertung(int richtig);//Harald
int spielstand_speichern();
void frage_ausgabe_50_50 (struct fragenKatalogEintrag* Eintrag, int index);


int nutzerdaten_eingabe(char*vorname,char*nachname)
{
    return 0;
}
void read_frage(struct fragenKatalogEintrag * Catalogue, int * nr_entries)
{

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
    char antwort = 0;
    int antwortNummer = 0;
    do
    {
        printf("Geben Sie die Nummer der Richtigen Antwort ein!\n"
               "Wenn Sie den 50/50 Joker wünschen drücken Sie die 5!\n"
               "Bei Eingabe einer Falschen Antwort wird das Programm abgebrochen"
               "und Ihr aktueller Spielstand gespeichert.");
        antwort = getchar();
        antwortNummer = (int)antwort;

    }while(antwortNummer == 0 || antwortNummer >5);
    printf("Vielen Dank! Ihre Antwort wird ausgewertet!");
    return antwort;
}
int antwort_auswertung(int richtig, int antwort)
{
    if(antwort == JOKER)
    {
        return JOKER;
    }
    else if(antwort == richtig)
    {

    }
    else
    {

    }
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
