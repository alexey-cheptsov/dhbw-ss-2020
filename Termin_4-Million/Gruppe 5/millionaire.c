
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <dirent.h>

#define L 7
void get_filenames(char array[][100]);
void random_questions(char array[][100]);
void add_path(char array[][100]);
void open_files(char array[][100]);
void cut_files(FILE*datei, int structdata);
void insert_in_struct(char string[][150], int structdata);
void bestenliste(int runde);


struct Fragen_Catalogue{
	char Frage[150];
	char Antworten[4][150];
	int nr_correct;

} first, second, third, fourth, fifth, sixth, seventh;


int main ()
{
	char namestr[100][100];
	
	get_filenames(namestr);
	random_questions(namestr);
	add_path(namestr);
	open_files(namestr);
	
	printf("%s\n",first.Frage);
	printf("%s\n",first.Antworten[0]);
	printf("%s\n",first.Antworten[1]);
	printf("%s\n",first.Antworten[2]);
	printf("%s\n",first.Antworten[3]);
	
	printf("%s\n",seventh.Frage);
	printf("%s\n",seventh.Antworten[0]);
	printf("%s\n",seventh.Antworten[1]);
	printf("%s\n",seventh.Antworten[2]);
	printf("%s\n",seventh.Antworten[3]);
	
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
//Hinzufügen des Dateipfads an die Dateinamen zum späteren erfolgreichen öffnen
void add_path(char array[][100]){
	
	char buffer[L][100];
	
	for(int m=0;m<L;m++){
		strcpy(buffer[m], "/home/knoppix/Fragen-DB/");
		strcat(buffer[m], array[m]);
	}
	//Zurückspeichern in "array", um weiterhin in Main zu bleiben 
	for(int i=0; i<L;i++){
		strcpy(array[i], buffer[i]);
		
	}
}

void open_files(char array[][100]){	
	FILE*datei;
	int structdata[]={1,2,3,4,5,6,7};
	
	
	
	for(int i=0;i<L;i++){
		
		datei=fopen(array[i],"r");
		
		cut_files(datei,structdata[i]);
		
		
		/*while(!feof(datei)){
			printf("%c",fgetc(datei));
			
		}
		printf("\n\n\n");*/
		fclose(datei);
	}
}
void cut_files(FILE*datei, int structdata){
	
	int  m=0;
	char string[6][150];
	while(!feof(datei))
	{	
		fgets(string[m],149,datei);
		m++;	
	}
	insert_in_struct(string, structdata);
	
	/*for(int j=0;j<6;j++)
		printf("%s\n",string[j]);*/

	//printf("%s\n", string[2]);
}

void insert_in_struct(char string[][150], int structdata){
	
	switch(structdata){
		case 1: 
					  strcpy(first.Frage, string[0]);
					  strcpy(first.Antworten[0], string[2]);	
					  strcpy(first.Antworten[1], string[3]);
					  strcpy(first.Antworten[2], string[4]);
					  strcpy(first.Antworten[3], string[5]);
		break;
		case 2: strcpy(second.Frage, string[0]);
					  strcpy(second.Antworten[0], string[2]);	
					  strcpy(second.Antworten[1], string[3]);
					  strcpy(second.Antworten[2], string[4]);
					  strcpy(second.Antworten[3], string[5]);
		break;			
		case 3: strcpy(third.Frage, string[0]);
					  strcpy(third.Antworten[0], string[2]);	
					  strcpy(third.Antworten[1], string[3]);
					  strcpy(third.Antworten[2], string[4]);
					  strcpy(third.Antworten[3], string[5]);
		break;
		case 4: strcpy(fourth.Frage, string[0]);
					  strcpy(fourth.Antworten[0], string[2]);	
					  strcpy(fourth.Antworten[1], string[3]);
					  strcpy(fourth.Antworten[2], string[4]);
					  strcpy(fourth.Antworten[3], string[5]);
		break;
		case 5: strcpy(fifth.Frage, string[0]);
					  strcpy(fifth.Antworten[0], string[2]);	
					  strcpy(fifth.Antworten[1], string[3]);
					  strcpy(fifth.Antworten[2], string[4]);
					  strcpy(fifth.Antworten[3], string[5]);
		break;
		case 6: strcpy(sixth.Frage, string[0]);
					  strcpy(sixth.Antworten[0], string[2]);	
					  strcpy(sixth.Antworten[1], string[3]);
					  strcpy(sixth.Antworten[2], string[4]);
					  strcpy(sixth.Antworten[3], string[5]);
		break;
		case 7: strcpy(seventh.Frage, string[0]);
					  strcpy(seventh.Antworten[0], string[2]);	
					  strcpy(seventh.Antworten[1], string[3]);
					  strcpy(seventh.Antworten[2], string[4]);
					  strcpy(seventh.Antworten[3], string[5]);
		break;
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


