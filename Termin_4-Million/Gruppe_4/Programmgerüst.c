#include<stdio.h>
#define MAX 97

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

struct fragenKatalogEintrag[MAX]Catalogue;

int nutzerdaten_eingabe(char*vorname,char*nachname);
void read_frage(struct fragenKatalogEintrag * Catalogue, int * nr_entries);
int frage_auswahl(struct fragenKatalogEintrag*Catalogue, int nr_entries);
void frage_ausgabe(struct fragenKatalogEintrag* Catalogue, int index);
int antwort_eingabe();
int antwort_auswertung(int richtig);
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
