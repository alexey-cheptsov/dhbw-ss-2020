/*
 * millionaire.c
 * 
 * Copyright 2020 Gruppe_3
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */
#include <string.h>
#include <dir.h>
#include <time.h>

#include <stdio.h>
#include <stdlib.h>

#define FILE_PATH "../Fragen-DB"

#define min(X, Y) ((X < Y) ? (X) : (Y))
#define max(X, Y) ((X > Y) ? (X) : (Y))

typedef struct Player {
	char *name;
	int score;
	int chanceUsed;
} Player;

typedef struct Question {
	char *question;
	char *answers[4];
	int correctAnswer;
} Question;

Player *players;
Question *questions;

const int[] price = {10,100,1000,10000,100000,500000,1000000};

void printTitle();
void getSettings(Player *players, int *count);

void readQuestiones(Question *questions, int size);
void printQuestion(Question question);
void getAnswer(Player *player, char *answer);
int checkAnswer(Question question, char *answer);

void printChance(Question question, Player player);
int printScore(FILE *file, Player *players);

int random(int min, int max);

void shuffle (int*); //Fabian
void swap_int (int*,int,int);

int main(int argc, char **argv) {
	int count = 0;
	getSettings(players, &count);
	readQuestiones(questions, ROUNDS);
	
	for(int i = 0; i < ROUNDS; i++) {
		Question question = questions[i];
		printQuestion(question);
		
		for(int j = 0; j < count; j++) {
			Player player = players[j];
			char *answer;
			getAnswer(player, answer);
			checkAnswer(question, player, &answer);
		}
		printf("\n -> Richtige Antwort: %i.) %s\n", question.correctAnswer, question.answers[correctAnswer]);
	}
	
	return 0;
}

void printTitle() {	
	printf("Willkommen bei 'Wer Wird Million%cr' !\n",132 );
	printf("Die Sendung in der Sie mit Ihrem Wissen Geld verdienen, ");
	printf("und sogar Million%cr werden k%cnnen!\n\n",132,148);
	printf("Zu den Spielregeln:\n");
	printf("Regel Nummer eins : Nicht schummeln!\n");
	printf("Regel Nummer zwei : nur g%cltige Zeichen eingeben!\n",129);
	printf("Zu den g%cltigen Zeichen geh%cren -> A,B,C,D ODER a,b,c,d .\n\n",129,148);
	printf("Sie erhalten auch EINEN Joker, der 50:50 Joker kann nur einmal\n");
	printf("pro Spiel verwendet werden!\n");
	printf("Diesen benutzen Sie dann, wenn Ihnen die Frage ");
	printf("vorgelesen wurde.\n");
	printf("Sie k%cnnen auch mit Ihren Freunden gegeneinander spielen.\n",148);
	printf("Sie m%cssen lediglich die Anzahl der Spieler eingeben.\n",129);
	printf("Im Anschluss frage ich Sie nach Ihrem Namen.\n");
	printf("Viel ERFOLG! :)");
}

void getSettings(Player *players, int *count) {
	// Abfrage Anzahl der Spieler
	printf("Bitte Geben Sie die Anzahl der Spieler ein: ");
	scanf("%d", count);

	// Eingabe der Spielernamen
    printf("Bitte Geben sie Ihren Namen ein: ");

    //Anlegen eine dynamischen Arrays zum Zwischenspeichern des Namens
    char *Array_name = (char*) malloc(*count*sizeof(*Array_name));

    //Überprüfen ob der Speicherbereich voll ist
    if(Array_name == NULL)
        return;

    //Einlesen des Spielernamens
    for(int i=0; i<=*count;i++){
        scanf("%s", Array_name);

        Player player = {Array_name, 0, 0};
        players[i] = player;
    }
    //Speicherplatz wieder freigeben für den nächsten Spieler
        free(Array_name);

	// Lukas Hauser
}


void readQuestiones(Question *questions, int size) {
	// Speichern der Fragen
	char filename [] = "ET19xxx_x.txt"; 
	FILE *path;
	int filenumber;
	int tempnumber;
	srand(time(NULL));
	int numbers [] = {0,1,2,3};
	int x;
	questions = (Question*) malloc (size * sizeof(Question));
		
	chdir(FILE_PATH); // wechselt in das Verzeichnis indem die Fragen sind
	for (int i = 0; i < size;){
		
		filenumber = rand() % 141; //die nummern reichen bis 140
		
		for (int i = 0; i < 3; i++) { //zufällige Nummer wird in einzelne Ziffern aufgeteilt und in String eingefügt
			tempnumber = filenumber % 10;
			filename[6 - i] = '0' + tempnumber;
			filenumber /= 10;
		}
		filename [8] = '0' + (rand() % 4);
		path = fopen(filename,"r");
		if (path == NULL) {
			continue; // wenn Datei nicht existiert/nicht zu öffnen ist wird nächste Nummer versucht
		}
		else {
			i++; //erfolgreiches öffnen der Datei.
	
			questions[i].question = (char*) malloc (100 * sizeof(char));
			fscanf(path,"%[^\n]",questions[i].question);
			while (fgetc(path)!= '\n'); //Buffer leeren
			
				
			shuffle(numbers);
			
			for (int n = 0; n < 4; n++) {
				questions[i].answers[n] =(char*) malloc (100*sizeof(char)); //Speicherreservierung für die Antworten 
			}
			for (int n = 0; n < 4; n++){ 
				x = numbers[n];	
				while (fgetc(path)!= '\n'); // Buffer leeren
				fscanf(path,"%[^\n]",questions[i].answers[x]);
				if (questions[i].answers[x][0] == '+'){
						 questions[i].correctAnswer = x;
				}
				for (int k = 0;questions[i].answers[x][k+1] != '\0'; k++){
					questions[i].answers[x][k] = questions[i].answers[x][k+2]; //entfernt vorzeichen und erstes Leerzeichen
				}
			}
			
		}
	}
	
}
void swap_int (int array[4],int random_number,int index){
	int temp = array [index];
	array[index] = array[random_number];
	array[random_number] = temp;
} // Fabian Himmelsbach
void shuffle (int array[4]){
	for (int i = 3;i > 0; i--){
		swap_int(array,rand()%i,i);	
	}
}// Fabian Himmelsbach

void printQuestion(Question question) {
	// Ausgabe der Frage (Zufaellige Nummerierung)

	// Fabian Himmelsbach
}

void getAnswer(Player *player, char *answer) {
	// Eingabe der Antwort des Spielers
	printf("Bitte geben Sie Ihre Antwort ein %s", player->name);
	scanf("%c", answer);
	// Deniz Akdeniz
}

int checkAnswer(Question question, Player player, char answer, int level) {
	// Überprüfen der Antwort
	int input; //answer als int
	switch(answer)
	{
		case 65: //A
		case 97: input = 0; break; //a
		case 66: //B
		case 98: input = 1; break; //b
		case 67: //C
		case 99: input = 2;  break; //c
		case 68: //D
		case 100: input = 3; break; //d
	}
	if(question.correctAnswer == input)
	{
		printf("Antwort %c ist korrekt!\n", answer);
		player.score = prices[level];	// Setzen der Punkte
	}
	else
	{
		printf("Antwort %c ist falsch, Antwot %c waere richtig gewesen!\n", answer, question.correctAnswer + 65);
		//player.score = 0;
	}
	// Nick Hof
}
// Ausgabe der 50-50 Chance
void printChance(Question question, Player player) {
	if(player.chanceUsed) {
		printf("\nDu hast dein 50-50 Chance bereits verwendet!\n");
		return;
	}
	int answer = random(0, 4);

	while(answer == question.correctAnswer) {
		answer = random(0, 4);
	}
	int index1 = min(answer, question.correctAnswer);
	int index2 = max(answer, question.correctAnswer);
	
	printf("\n%s\n\n a) %s\n b) %s\n", question.question, question.answers[index1], question.answers[index2]);
	player.chanceUsed = 1;
}

int printScore(FILE *file, Player *players) {
	// Ausgabe des Spielstands / der Ergebnisse
	// Speichern der Ergebnisse in Datei

	// To be continued...
}

int random(int min, int max) {
	return (rand() % (max - min + 1)) + min;
}
