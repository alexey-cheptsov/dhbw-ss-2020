
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <dirent.h>

#define L 7

void get_filenames(char array[][100]);

void random_questions(char array[][100]);
void open_files(char array[][100]);
void bestenliste(int runde);


struct Fragen_Catalogue_Eintrag{
	char *Frage;
	char *Antworten[4];
	int nr_correct;
	
}Catalogue;


int main ()
{
	char namestr[100][100];
	
	get_filenames(namestr);
	random_questions(namestr);
	open_files(namestr);
	
	return 0;	
}

//Auslesen der aktuellen Dateinamen aus der Datenbank.
void get_filenames(char array[][100]){
	int i=0;
    DIR * Ordner;
    struct dirent * entry;
  

    Ordner = opendir ("Fragen-DB");
    if (Ordner == NULL)
    {
        perror ("Verzeichnis kann nicht gelesen werden");
       
    }

    while ((entry = readdir (Ordner)))
    {
        
       strcpy(array[i], entry->d_name);
        i++;
    }

    closedir (Ordner);
}


		
void random_questions(char array[][100]){
	char buffer[L][100];
	int m=0;
	srand(time(NULL));
	
	for(int i=0; i<L;i++){
		// Zufällig ausgewählte Dateinamen zwischenspeichern
		strcpy(buffer[i], array[rand()%94]);
	}
	
	//Ursprünglichen Inhalt von Array löschen 
		while(m<=100){
		array[m][0] = '\0';
		m++;
	}
	//Array neu beschreiben mit zufällig Ausgew
	for(int i=0; i<L;i++){
		strcpy(array[i], buffer[i]);
		
	}
}
void open_files(char array[][100]){
	FILE*datei;
	char buffer[L][100];
	
	for(int m=0;m<L;m++){
		strcpy(buffer[m], "/home/knoppix/Fragen-DB/");
		strcat(buffer[m], array[m]);
	}
		
/*	for(int i=0; i<L;i++){

		printf("%s\n", buffer[i]);
	}*/
	
	
	for(int i=0;i<L;i++){
		datei=fopen(buffer[i],"r");
		
		while(!feof(datei)){
			printf("%c",fgetc(datei));
			
		}
		printf("\n\n\n");
		fclose(datei);
	}
	

}

//Fragt den Namen ab und schreibt dann den Namen und die Runde in die Bestenliste Datei
void bestenliste(int runde){
	char vorname[50];
	char nachname[50];
	FILE *fp;
	printf("Bitte geben Sie ihren Vorname und Nachname fuer die Bestenliste ein:\n");
	scanf("%s %s",vorname,nachname);
	
	fp=fopen("Bestenliste.txt", "a");
	if(fp==NULL) printf("Fehler Datei konnte nicht geöfnet werden");
	else{
		fprintf(fp, "Name:%s %s Runde: %d\n",vorname ,nachname, runde);
		}
	}


