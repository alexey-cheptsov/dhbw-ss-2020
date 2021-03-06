
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
void insert_in_struct(char string[][150], int structdata);
void Fragenausgabe();
void richtigeantwort();
void Antworteingabe(int zahl1,int zahl2,int zahl3,int zahl4);
void Umwandlung(char zahl1[4],int *zahl);
struct Fragen_Catalogue{
	char Frage[150];
	char Antworten[5][150];
	int nr_correct;

} first, second, third, fourth, fifth, sixth, seventh;




int main ()
{
	char namestr[100][100];
	
	get_filenames(namestr);
	random_questions(namestr);
	add_path(namestr);
	open_files(namestr);
	richtigeantwort();
	Fragenausgabe(namestr);
	
	
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
void Fragenausgabe()
{
	
	printf("%s\n",first.Frage);
	int zahl1;
	int zahl2;
	int zahl3;
	int zahl4;
	srand(time(NULL));
	zahl1=rand() % 4;
	zahl4=zahl3=zahl2=zahl1;
	while(zahl2==zahl1)
	{
		zahl2=rand() % 4;
	}
	while(zahl3==zahl1||zahl3==zahl2)
	{
		zahl3=rand() % 4;
	}
	while(zahl4==zahl1||zahl4==zahl2||zahl4==zahl3)
	{
		zahl4=rand() % 4;
	}
	printf(" a)%10s",first.Antworten[zahl1]);
	printf(" b)%10s\n",first.Antworten[zahl2]);
	printf(" c)%10s",first.Antworten[zahl3]);
	printf(" d)%10s\n",first.Antworten[zahl4]);
	Antworteingabe(zahl1,zahl2,zahl3,zahl4);
}
void richtigeantwort()
{	
	if(*first.Antworten[0]=='+')
	{
	strcpy(first.Antworten[4],"0");
	}
	if(*first.Antworten[1]=='+')
	{
	strcpy(first.Antworten[4],"1");
	}
	if(*first.Antworten[2]=='+')
	{
	strcpy(first.Antworten[4],"2");
	}
	if(*first.Antworten[3]=='+')
	{
	strcpy(first.Antworten[4],"3");
	}
	printf("%s",first.Antworten[4]);
	first.Antworten[0][0]=' ';
	first.Antworten[1][0]=' ';
	first.Antworten[2][0]=' ';
	first.Antworten[3][0]=' ';
}
void Umwandlung(char zahl1[4],int *zahl)
{
	if(*zahl==0)
	*zahl1='0';
	if(*zahl==1)
	*zahl1='1';
	if(*zahl==2)
	*zahl1='2';
	if(*zahl==3)
	*zahl1='3';
}
void Antworteingabe(int zahl1,int zahl2,int zahl3,int zahl4)
{
	char zahl[4][4];
	Umwandlung(zahl[0],&zahl1);
	Umwandlung(zahl[1],&zahl2);
	Umwandlung(zahl[2],&zahl3);
	Umwandlung(zahl[3],&zahl4);
	
	char eingabe[10];
	scanf("%s",eingabe);
	if(*eingabe=='a')
	{
		printf("a");
		if(*zahl[0]==*first.Antworten[4])
		{
			printf("Richtig");
		}
	}
	if(*eingabe=='b')
	{
		printf("b");
		if(*zahl[1]==*first.Antworten[4])
		{
			printf("Richtig");
		}
	}
	if(*eingabe=='c')
	{
		printf("c");
		if(*zahl[2]==*first.Antworten[4])
		{
			printf("Richtig");
		}
	}
	if(*eingabe=='d')
	{
		printf("d");
		if(*zahl[3]==*first.Antworten[4])
		{
			printf("Richtig");
		}
	}
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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


	//Auswählen zufälliger Dateinamen aus allen	
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

