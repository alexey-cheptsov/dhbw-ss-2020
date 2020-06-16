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
#define NAME_SIZE 20
#define ROUNDS 7

#define min(X, Y) ((X < Y) ? (X) : (Y))
#define max(X, Y) ((X > Y) ? (X) : (Y))

typedef struct Player {
	char *name;
	int score;
	int chanceUsed;
	int lost;
} Player;

typedef struct Question {
	char *question;
	char *answers[4];
	int correctAnswer;
} Question;

Player *players;
Question *questions;

const int prices[] = {10,100,1000,10000,100000,500000,1000000};

void printTitle();
void getSettings(Player *players, int *count);

void readQuestiones(Question *questions, int size);
void printQuestion(Question question);
void getAnswer(Player player, char *answer);
int checkAnswer(Question question, int playerindex, char answer, int level);

void printChance(Question question, int playerindex);
int printScore(FILE *file, Player *players);

int random(int min, int max);

void shuffle (int*); //Fabian
void swap_int (int*,int,int);

int main(int argc, char **argv) {
	srand(time(NULL));
	printTitle();
	
	int count = 0;
	getSettings(players, &count);
	readQuestiones(questions, ROUNDS);
	int lost = 0;
	for(int i = 0; i < ROUNDS; i++) {
		Question question = questions[i];
		
		printQuestion(question);
		
		
		
		for(int j = 0; j < count; j++) {
			Player player = players[j];
			
			if (player.lost) {
				continue;
			}
			else {
					char answer;
					getAnswer(player, &answer);
				if(checkAnswer(question, j, answer, i)) {
					printChance(question, j);
					getAnswer(player, &answer);
					checkAnswer(question, j, answer, i);
					
				}
				if (players[j].lost) {
					lost ++;
				}
			}
		}
		printf("\n -> Richtige Antwort: %c.) %s\n", 'a' + question.correctAnswer, question.answers[question.correctAnswer]);
		if (lost == count){
			break;
		}
		
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
	printf("Viel ERFOLG! :)\n\n\n");
}

void getSettings(Player *players1, int *count) {
	// Abfrage Anzahl der Spieler
	printf("Bitte Geben Sie die Anzahl der Spieler ein: ");
	scanf("%d", count);

    //Anlegen eine dynamischen Arrays zum Zwischenspeichern des Namens
    players = (Player*) malloc(*count * sizeof(Player));


    //Einlesen des Spielernamens
    for(int i = 0; i < *count; i++){
		char *name = (char*) malloc(20 * sizeof(char));
		
		//Überprüfen ob der Speicherbereich voll ist
		if(name == NULL)
			return;
        
		// Eingabe der Spielernamen
		printf("Bitte Geben sie Ihren Namen ein (%d): ", i);
        scanf("%20s", name);
		while (getchar()!= '\n');

        Player player = {name, 0, 0, 0};
        players[i] = player;
    }
}


void readQuestiones(Question *questions1, int size) {
	// Speichern der Fragen
	// Fabian Himmelsbach
	char filename [] = "ET19xxx_x.txt";  
	FILE *path;
	int filenumber;   
	int tempnumber;  
	int numbers [] = {0,1,2,3};       	
	int x;
	int used  [7]; 
	questions = (Question*)  malloc (size * sizeof(Question));
		
	chdir(FILE_PATH); // wechselt in das Verzeichnis indem die Fragen sind
		//n muss noch geshuffelt werden
	for (int i = 0; i < size;){
		
		filenumber = rand() % 141; //die nummern reichen bis 140
		
		for(int k = i-1; k >= 0; k--) { //schaut ob eine Frage dieses Autors bereits vorkam
			if  (k >= 0 && used[k] == filenumber){
				continue;
			}
		}
		used[i] = filenumber; //speichert verwenden
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
				
			questions[i].question = (char*) malloc (500 * sizeof(char));
			fscanf(path,"%[^\n]",questions[i].question);
			
			while (fgetc(path)!= '\n');
			shuffle(numbers);
			for (int n = 0; n < 4; n++) {
				questions[i].answers[n] =(char*) malloc (500*sizeof(char)); //Speicherreservierung für die Antworten 
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
			i++; //erfolgreiches öffnen der Datei.
		}
		
	}
}
void swap_int (int array[4],int random_number,int index){
	int temp = array [index];
	array[index] = array[random_number];
	array[random_number] = temp;
}

void shuffle (int array[4]){
	for (int i = 3;i > 0; i--){
		swap_int(array,rand()%i,i);	
	}
}

void printQuestion(Question question) {
	printf("\nFrage: %s\n", question.question);
	for(int i = 0; i < 4; i++) {
		printf("%c.) %s\n", 'a' + i, question.answers[i]);
	}
}

void getAnswer(Player player, char *answer) {
	// Eingabe der Antwort des Spielers
	printf("\nBitte geben Sie Ihre Antwort ein %s: ", player.name);
	scanf("%c", answer);
	while (getchar()!= '\n');
	// Deniz Akdeniz
}

int checkAnswer(Question question, int playerindex, char answer, int level) {
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
		case '%': return 1;
	}
	if(question.correctAnswer == input)
	{
		//printf("Antwort %c ist korrekt!\n", answer);
		players[playerindex].score = prices[level];	// Setzen der Punkte
		
	}
	else
	{
		//printf("Antwort %c ist falsch, Antwot %c waere richtig gewesen!\n", answer, question.correctAnswer + 65);
		//player.score = 0;
		players[playerindex].lost = 1;
	}
	return 0;
	// Nick Hof
}
// Ausgabe der 50-50 Chance
void printChance(Question question, int playerindex) {
	if(players[playerindex].chanceUsed) {
		printf("\nDu hast deine 50-50 Chance bereits verwendet!\n");
		return;
	}
	int answer = random(0, 4);

	while(answer == question.correctAnswer) {
		answer = random(0, 4);
	}
	int index1 = min(answer, question.correctAnswer);
	int index2 = max(answer, question.correctAnswer);
	
	printf("%c.) %s\n", 'a' + index1, question.answers[index1]);
	printf("%c.) %s\n", 'a' + index2, question.answers[index2]);
	players[playerindex].chanceUsed = 1;
}

int printScore(FILE *file, Player *players) {
	// Ausgabe des Spielstands / der Ergebnisse
	// Speichern der Ergebnisse in Datei

	// Fabian
	return 1;
}

int random(int min, int max) {
	return (rand() % (max - min + 1)) + min;
}
