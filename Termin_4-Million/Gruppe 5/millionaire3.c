#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <dirent.h>

#define L 7

int get_filenames(char array[][100]);
void random_questions(char array[][100], int file_count);
void check_filenames(char buffer[][100],char array[][100], int file_counter);
void add_path(char array[][100]);
void open_files(char array[][100]);
void cut_files(FILE*datei, int structdata);
void insert_in_struct(char string[][150], int structdata);
void insert_in_struct(char string[][150], int structdata);
void Umwandlung(char zahl1[4],int *zahl);
void Fragenausgabefirst();
void richtigeantwortfirst();
void Antworteingabefirst(int zahl1,int zahl2,int zahl3,int zahl4);

void Fragenausgabesecond();
void richtigeantwortsecond();
void Antworteingabesecond(int zahl1,int zahl2,int zahl3,int zahl4);

void Fragenausgabethird();
void richtigeantwortthird();
void Antworteingabethird(int zahl1,int zahl2,int zahl3,int zahl4);

void Fragenausgabefourth();
void richtigeantwortfourth();
void Antworteingabefourth(int zahl1,int zahl2,int zahl3,int zahl4);

void Fragenausgabefifth();
void richtigeantwortfifth();
void Antworteingabefifth(int zahl1,int zahl2,int zahl3,int zahl4);

void Fragenausgabesixth();
void richtigeantwortsixth();
void Antworteingabesixth(int zahl1,int zahl2,int zahl3,int zahl4);

void Fragenausgabeseventh();
void richtigeantwortseventh();
void Antworteingabeseventh(int zahl1,int zahl2,int zahl3,int zahl4);

struct Fragen_Catalogue{
	char Frage[150];
	char Antworten[5][150];
	int nr_correct;

} first, second, third, fourth, fifth, sixth, seventh;




int main ()
{
	printf("Bitte geben sie ihre antworten mit a, b, c oder d an\n");
	
	char namestr[100][100];
	int file_count=0;
	
	file_count = get_filenames(namestr);
	random_questions(namestr, file_count);
	add_path(namestr);
	open_files(namestr);
	
	
	
	richtigeantwortfirst();
	Fragenausgabefirst();
	richtigeantwortsecond();
	Fragenausgabesecond();
	richtigeantwortthird();
	Fragenausgabethird();
	richtigeantwortfourth();
	Fragenausgabefourth();
	richtigeantwortfifth();
	Fragenausgabefifth();
	richtigeantwortsixth();
	Fragenausgabesixth();
	richtigeantwortseventh();
	Fragenausgabeseventh();
	return 0;	
}
void Fragenausgabefirst()
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
	printf(" a)%s\n",first.Antworten[zahl1]);
	printf(" b)%s\n",first.Antworten[zahl2]);
	printf(" c)%s\n",first.Antworten[zahl3]);
	printf(" d)%s\n",first.Antworten[zahl4]);
	Antworteingabefirst(zahl1,zahl2,zahl3,zahl4);
}
void richtigeantwortfirst()
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
void Antworteingabefirst(int zahl1,int zahl2,int zahl3,int zahl4)
{
	char zahl[4][4];
	Umwandlung(zahl[0],&zahl1);
	Umwandlung(zahl[1],&zahl2);
	Umwandlung(zahl[2],&zahl3);
	Umwandlung(zahl[3],&zahl4);
	int punkte = 0;
	char eingabe[10];
	scanf("%s",eingabe);
	if(*eingabe=='a')
	{
		if(*zahl[0]==*first.Antworten[4])
		{
			printf("Richtig");
			punkte++;
		}
	}
	if(*eingabe=='b')
	{
		if(*zahl[1]==*first.Antworten[4])
		{
			printf("Richtig");
			punkte++;
		}
	}
	if(*eingabe=='c')
	{
		if(*zahl[2]==*first.Antworten[4])
		{
			printf("Richtig");
			punkte++;
		}
	}
	if(*eingabe=='d')
	{
		if(*zahl[3]==*first.Antworten[4])
		{
			printf("Richtig");
			punkte++;
		}
	}
	if(punkte<1)
	printf("Falsch");
	printf("\n");
}
//1111111111111
void Fragenausgabesecond()
{
	
	printf("%s\n",second.Frage);
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
	printf(" a)%s\n",second.Antworten[zahl1]);
	printf(" b)%s\n",second.Antworten[zahl2]);
	printf(" c)%s\n",second.Antworten[zahl3]);
	printf(" d)%s\n",second.Antworten[zahl4]);
	Antworteingabesecond(zahl1,zahl2,zahl3,zahl4);
}
void richtigeantwortsecond()
{	
	if(*second.Antworten[0]=='+')
	{
	strcpy(second.Antworten[4],"0");
	}
	if(*second.Antworten[1]=='+')
	{
	strcpy(second.Antworten[4],"1");
	}
	if(*second.Antworten[2]=='+')
	{
	strcpy(second.Antworten[4],"2");
	}
	if(*second.Antworten[3]=='+')
	{
	strcpy(second.Antworten[4],"3");
	}
	second.Antworten[0][0]=' ';
	second.Antworten[1][0]=' ';
	second.Antworten[2][0]=' ';
	second.Antworten[3][0]=' ';
}

void Antworteingabesecond(int zahl1,int zahl2,int zahl3,int zahl4)
{
	char zahl[4][4];
	Umwandlung(zahl[0],&zahl1);
	Umwandlung(zahl[1],&zahl2);
	Umwandlung(zahl[2],&zahl3);
	Umwandlung(zahl[3],&zahl4);
	int punkte = 0;
	char eingabe[10];
	scanf("%s",eingabe);
	if(*eingabe=='a')
	{
		if(*zahl[0]==*second.Antworten[4])
		{
			printf("Richtig");
			punkte++;
		}
	}
	if(*eingabe=='b')
	{
		if(*zahl[1]==*second.Antworten[4])
		{
			printf("Richtig");
			punkte++;
		}
	}
	if(*eingabe=='c')
	{
		if(*zahl[2]==*second.Antworten[4])
		{
			printf("Richtig");
			punkte++;
		}
	}
	if(*eingabe=='d')
	{
		if(*zahl[3]==*second.Antworten[4])
		{
			printf("Richtig");
			punkte++;
		}
	}
	if(punkte<1)
	printf("Falsch");
	printf("\n");
}
//2222222222222
void Fragenausgabethird()
{
	printf("%s\n",third.Frage);
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
	printf(" a)%s\n",third.Antworten[zahl1]);
	printf(" b)%s\n",third.Antworten[zahl2]);
	printf(" c)%s\n",third.Antworten[zahl3]);
	printf(" d)%s\n",third.Antworten[zahl4]);
	Antworteingabethird(zahl1,zahl2,zahl3,zahl4);
}
void richtigeantwortthird()
{	
	if(*third.Antworten[0]=='+')
	{
	strcpy(third.Antworten[4],"0");
	}
	if(*third.Antworten[1]=='+')
	{
	strcpy(third.Antworten[4],"1");
	}
	if(*third.Antworten[2]=='+')
	{
	strcpy(third.Antworten[4],"2");
	}
	if(*third.Antworten[3]=='+')
	{
	strcpy(third.Antworten[4],"3");
	}
	third.Antworten[0][0]=' ';
	third.Antworten[1][0]=' ';
	third.Antworten[2][0]=' ';
	third.Antworten[3][0]=' ';
}

void Antworteingabethird(int zahl1,int zahl2,int zahl3,int zahl4)
{
	char zahl[4][4];
	Umwandlung(zahl[0],&zahl1);
	Umwandlung(zahl[1],&zahl2);
	Umwandlung(zahl[2],&zahl3);
	Umwandlung(zahl[3],&zahl4);
	int punkte = 0;
	char eingabe[10];
	scanf("%s",eingabe);
	if(*eingabe=='a')
	{
		if(*zahl[0]==*third.Antworten[4])
		{
			printf("Richtig");
			punkte++;
		}
	}
	if(*eingabe=='b')
	{
		if(*zahl[1]==*third.Antworten[4])
		{
			printf("Richtig");
			punkte++;
		}
	}
	if(*eingabe=='c')
	{
		if(*zahl[2]==*third.Antworten[4])
		{
			printf("Richtig");
			punkte++;
		}
	}
	if(*eingabe=='d')
	{
		if(*zahl[3]==*third.Antworten[4])
		{
			printf("Richtig");
			punkte++;
		}
	}
	if(punkte<1)
	printf("Falsch");
	printf("\n");
}
//333333333333
void Fragenausgabefourth()
{
	printf("%s\n",fourth.Frage);
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
	printf(" a)%s\n",fourth.Antworten[zahl1]);
	printf(" b)%s\n",fourth.Antworten[zahl2]);
	printf(" c)%s\n",fourth.Antworten[zahl3]);
	printf(" d)%s\n",fourth.Antworten[zahl4]);
	Antworteingabefourth(zahl1,zahl2,zahl3,zahl4);
}
void richtigeantwortfourth()
{	
	if(*fourth.Antworten[0]=='+')
	{
	strcpy(fourth.Antworten[4],"0");
	}
	if(*fourth.Antworten[1]=='+')
	{
	strcpy(fourth.Antworten[4],"1");
	}
	if(*fourth.Antworten[2]=='+')
	{
	strcpy(fourth.Antworten[4],"2");
	}
	if(*fourth.Antworten[3]=='+')
	{
	strcpy(fourth.Antworten[4],"3");
	}
	fourth.Antworten[0][0]=' ';
	fourth.Antworten[1][0]=' ';
	fourth.Antworten[2][0]=' ';
	fourth.Antworten[3][0]=' ';
}

void Antworteingabefourth(int zahl1,int zahl2,int zahl3,int zahl4)
{
	char zahl[4][4];
	Umwandlung(zahl[0],&zahl1);
	Umwandlung(zahl[1],&zahl2);
	Umwandlung(zahl[2],&zahl3);
	Umwandlung(zahl[3],&zahl4);
	int punkte = 0;
	char eingabe[10];
	scanf("%s",eingabe);
	if(*eingabe=='a')
	{
		if(*zahl[0]==*fourth.Antworten[4])
		{
			printf("Richtig");
			punkte++;
		}
	}
	if(*eingabe=='b')
	{
		if(*zahl[1]==*fourth.Antworten[4])
		{
			printf("Richtig");
			punkte++;
		}
	}
	if(*eingabe=='c')
	{
		if(*zahl[2]==*fourth.Antworten[4])
		{
			printf("Richtig");
			punkte++;
		}
	}
	if(*eingabe=='d')
	{
		if(*zahl[3]==*fourth.Antworten[4])
		{
			printf("Richtig");
			punkte++;
		}
	}
	if(punkte<1)
	printf("Falsch");
	printf("\n");
}
//444444444444
void Fragenausgabefifth()
{
	
	printf("%s\n",fifth.Frage);
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
	printf(" a)%s\n",fifth.Antworten[zahl1]);
	printf(" b)%s\n",fifth.Antworten[zahl2]);
	printf(" c)%s\n",fifth.Antworten[zahl3]);
	printf(" d)%s\n",fifth.Antworten[zahl4]);
	Antworteingabefifth(zahl1,zahl2,zahl3,zahl4);
}
void richtigeantwortfifth()
{	
	if(*fifth.Antworten[0]=='+')
	{
	strcpy(fifth.Antworten[4],"0");
	}
	if(*fifth.Antworten[1]=='+')
	{
	strcpy(fifth.Antworten[4],"1");
	}
	if(*fifth.Antworten[2]=='+')
	{
	strcpy(fifth.Antworten[4],"2");
	}
	if(*fifth.Antworten[3]=='+')
	{
	strcpy(fifth.Antworten[4],"3");
	}
	fifth.Antworten[0][0]=' ';
	fifth.Antworten[1][0]=' ';
	fifth.Antworten[2][0]=' ';
	fifth.Antworten[3][0]=' ';
}

void Antworteingabefifth(int zahl1,int zahl2,int zahl3,int zahl4)
{
	char zahl[4][4];
	Umwandlung(zahl[0],&zahl1);
	Umwandlung(zahl[1],&zahl2);
	Umwandlung(zahl[2],&zahl3);
	Umwandlung(zahl[3],&zahl4);
	int punkte = 0;
	char eingabe[10];
	scanf("%s",eingabe);
	if(*eingabe=='a')
	{
		if(*zahl[0]==*fifth.Antworten[4])
		{
			printf("Richtig");
			punkte++;
		}
	}
	if(*eingabe=='b')
	{
		if(*zahl[1]==*fifth.Antworten[4])
		{
			printf("Richtig");
			punkte++;
		}
	}
	if(*eingabe=='c')
	{
		if(*zahl[2]==*fifth.Antworten[4])
		{
			printf("Richtig");
			punkte++;
		}
	}
	if(*eingabe=='d')
	{
		if(*zahl[3]==*fifth.Antworten[4])
		{
			printf("Richtig");
			punkte++;
		}
	}
	if(punkte<1)
	printf("Falsch");
	printf("\n");
}
//555555555555
void Fragenausgabesixth()
{
	
	printf("%s\n",sixth.Frage);
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
	printf(" a)%s\n",sixth.Antworten[zahl1]);
	printf(" b)%s\n",sixth.Antworten[zahl2]);
	printf(" c)%s\n",sixth.Antworten[zahl3]);
	printf(" d)%s\n",sixth.Antworten[zahl4]);
	Antworteingabesixth(zahl1,zahl2,zahl3,zahl4);
}
void richtigeantwortsixth()
{	
	if(*sixth.Antworten[0]=='+')
	{
	strcpy(sixth.Antworten[4],"0");
	}
	if(*sixth.Antworten[1]=='+')
	{
	strcpy(sixth.Antworten[4],"1");
	}
	if(*sixth.Antworten[2]=='+')
	{
	strcpy(sixth.Antworten[4],"2");
	}
	if(*sixth.Antworten[3]=='+')
	{
	strcpy(sixth.Antworten[4],"3");
	}
	sixth.Antworten[0][0]=' ';
	sixth.Antworten[1][0]=' ';
	sixth.Antworten[2][0]=' ';
	sixth.Antworten[3][0]=' ';
}

void Antworteingabesixth(int zahl1,int zahl2,int zahl3,int zahl4)
{
	char zahl[4][4];
	Umwandlung(zahl[0],&zahl1);
	Umwandlung(zahl[1],&zahl2);
	Umwandlung(zahl[2],&zahl3);
	Umwandlung(zahl[3],&zahl4);
	int punkte = 0;
	char eingabe[10];
	scanf("%s",eingabe);
	if(*eingabe=='a')
	{
		if(*zahl[0]==*sixth.Antworten[4])
		{
			printf("Richtig");
			punkte++;
		}
	}
	if(*eingabe=='b')
	{
		if(*zahl[1]==*sixth.Antworten[4])
		{
			printf("Richtig");
			punkte++;
		}
	}
	if(*eingabe=='c')
	{
		if(*zahl[2]==*sixth.Antworten[4])
		{
			printf("Richtig");
			punkte++;
		}
	}
	if(*eingabe=='d')
	{
		if(*zahl[3]==*sixth.Antworten[4])
		{
			printf("Richtig");
			punkte++;
		}
	}
	if(punkte<1)
	printf("Falsch");
	printf("\n");
}
//666666666666
void Fragenausgabeseventh()
{
	
	printf("%s\n",seventh.Frage);
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
	printf(" a)%s\n",seventh.Antworten[zahl1]);
	printf(" b)%s\n",seventh.Antworten[zahl2]);
	printf(" c)%s\n",seventh.Antworten[zahl3]);
	printf(" d)%s\n",seventh.Antworten[zahl4]);
	Antworteingabeseventh(zahl1,zahl2,zahl3,zahl4);
}
void richtigeantwortseventh()
{	
	if(*seventh.Antworten[0]=='+')
	{
	strcpy(seventh.Antworten[4],"0");
	}
	if(*seventh.Antworten[1]=='+')
	{
	strcpy(seventh.Antworten[4],"1");
	}
	if(*seventh.Antworten[2]=='+')
	{
	strcpy(seventh.Antworten[4],"2");
	}
	if(*seventh.Antworten[3]=='+')
	{
	strcpy(seventh.Antworten[4],"3");
	}
	seventh.Antworten[0][0]=' ';
	seventh.Antworten[1][0]=' ';
	seventh.Antworten[2][0]=' ';
	seventh.Antworten[3][0]=' ';
}

void Antworteingabeseventh(int zahl1,int zahl2,int zahl3,int zahl4)
{
	char zahl[4][4];
	Umwandlung(zahl[0],&zahl1);
	Umwandlung(zahl[1],&zahl2);
	Umwandlung(zahl[2],&zahl3);
	Umwandlung(zahl[3],&zahl4);
	int punkte = 0;
	char eingabe[10];
	scanf("%s",eingabe);
	if(*eingabe=='a')
	{
		if(*zahl[0]==*seventh.Antworten[4])
		{
			printf("Richtig");
			punkte++;
		}
	}
	if(*eingabe=='b')
	{
		if(*zahl[1]==*seventh.Antworten[4])
		{
			printf("Richtig");
			punkte++;
		}
	}
	if(*eingabe=='c')
	{
		if(*zahl[2]==*seventh.Antworten[4])
		{
			printf("Richtig");
			punkte++;
		}
	}
	if(*eingabe=='d')
	{
		if(*zahl[3]==*seventh.Antworten[4])
		{
			printf("Richtig");
			punkte++;
		}
	}
	if(punkte<1)
	printf("Falsch");
	printf("\n");
}
//777777777777

//Auslesen der aktuellen Dateinamen aus der Datenbank.
int get_filenames(char array[][100]){
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
    
    return i;
}


	//Auswählen zufälliger Dateinamen aus allen	
void random_questions(char array[][100], int file_count){
	char buffer[L][100];
	int m=0;
	srand(time(NULL));
	
	for(int i=0; i<L;i++){
		// Zufällig ausgewählte Dateinamen zwischenspeichern
		strcpy(buffer[i], array[rand()%file_count]); //Es wird aus allen existierenden Dateien eine zufällige ausgewählt
	}												 //file_count enthält die Anzahl der vorhandenen Dateien im Verzeichnis
	
	check_filenames(buffer, array, file_count);
	
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
//Sollten Dateinamen doppelt vorkommen, so wird dies hier erkannt und die Dopplungen werden entfernt
void check_filenames(char buffer[][100],char array[][100], int file_count){
	srand(time(NULL));
	int count = 0;
	while(count<3){ //Zur absoluten Sicherheit wird der Check 3 mal durchgeführt. Dopplungen und ungültige Dateinamen sind so gut wie unmöglich.
		for(int i=0; i<L; i++){
			for(int j=(i+1); j<L; j++){
				if(strcmp(buffer[i],buffer[j])==0 || strlen(buffer[j])< 8 )
					strcpy(buffer[j], array[rand()%file_count]);
			}
		}
		count++;
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
		printf("%s\n", array[i]);
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
//Löscht zwei der Falschen antworten und gibt somit nur noch zwei Antworten aus. Der Spieler gibt dann seine Antwort ein und die Funktion gibt 1 für richtig und 0 für falsch zurück
int funzigfunfzig(char antwort1[], char antwort2[], char antwort3[], char antwort4[], int richtig){
	time_t now;
	time(&now);
	srand(now);
	int z,eingabe;
	for(int n=0;2>n;){
		z=rand()%4;
		switch(z){
			case 0:if(richtig!=1&&antwort1[0]!=' '){strcpy(antwort1, " ");n++;}break;
			case 1:if(richtig!=2&&antwort2[0]!=' '){strcpy(antwort2, " ");n++;}break;
			case 2:if(richtig!=3&&antwort3[0]!=' '){strcpy(antwort3, " ");n++;}break;
			case 3:if(richtig!=4&&antwort4[0]!=' '){strcpy(antwort4, " ");n++;}break;
		 }
	}
	printf("1:%s\n2:%s\n3:%s\n4:%s \n %d\n", antwort1, antwort2, antwort3, antwort4, z);
	scanf("%d",&eingabe);
	if (eingabe==richtig) return 1;
	else return 0;
	
	}
