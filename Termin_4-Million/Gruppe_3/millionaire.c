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
 */

// Bibliotheken
#include <string.h>
#include <dir.h>
#include <time.h>

#include <stdio.h>
#include <stdlib.h>

// Konstanten
#define FILE_PATH "../Fragen-DB"
#define SCORE_FILE "../Gruppe_3/millionaire_score.txt"
#define NAME_SIZE 20
#define STRING_SIZE 500

#define ANSWER_COUNT 4
#define ROUNDS 7

// Hilfsfunktionen
#define min(X, Y) ((X < Y) ? (X) : (Y))
#define max(X, Y) ((X > Y) ? (X) : (Y))

/*!
 * @brief Represents a player of the game
 */
typedef struct Player {
	char *name;
	int score;
	int chanceUsed;
	int lost;
} Player;

/*!
 * @brief Represents a quiz question of the game
 */
typedef struct Question {
	char *question;
	char *answers[ANSWER_COUNT];
	int correctAnswer;
} Question;

// Funktionsprototypen
void printTitle();
int getSettings(int *count);
void readQuestiones(int size);

void printQuestion(Question question);
void getAnswer(Player player, char *answer);
int checkAnswer(Question question, int playerindex, char answer, int level);

void printChance(Question question, int playerindex);
int printScore(int playercount);

// Hilfsfunktionen
int random(int min, int max);
void shuffle (int* array, int size);
void swapInt (int* array, int index1, int index2);
void swapPlayer(int index1, int index2);
void sortPlayers(int playercount);

// Liste der Spieler und Quizfragen
Player *players;
Question *questions;

// Preise des Spiels
const int prices[] = {10,100,1000,10000,100000,500000,1000000};

/*!
 * @brief Main program function
 * @param argc - Count of command line arguments
 * @param argv - Array of command line arguments
 * @return The program termination code
 */
int main(int argc, char **argv) {
	srand(time(NULL));
	printTitle();
	
	int count = 0;
	if(!getSettings(&count)) {
		return -1;
	}
	readQuestiones(ROUNDS);
	
	int lost = 0;
	for(int i = 0; i < ROUNDS; i++) {
		Question question = questions[i];
		printQuestion(question);
		
		for(int j = 0; j < count; j++) {
			Player player = players[j];
			
			if (player.lost) {
				continue;
			}
			char answer;
			getAnswer(player, &answer);
			
			while(!checkAnswer(question, j, answer, i)) {
				getAnswer(player, &answer);
			}
			if (players[j].lost) {
				lost++;
			}
		}
		printf("\n -> Richtige Antwort: %c.) %s\n", 'a' + question.correctAnswer, question.answers[question.correctAnswer]);
		if(lost == count){
			break;
		}
	}
	printScore(count);
	free(players);
	free(questions);
	
	return 0;
}

/*!
 * @brief Prints the title of the game
 */
void printTitle() {	
	printf("\n");
	printf("Willkommen bei 'Wer Wird Million%cr' !\n",132 );
	printf("Die Sendung in der Sie mit Ihrem Wissen Geld verdienen, ");
	printf("und sogar Million%cr werden k%cnnen!\n\n",132,148);
	printf("Zu den Spielregeln:\n");
	printf("Regel Nummer eins : Nicht schummeln!\n");
	printf("Regel Nummer zwei : nur g%cltige Zeichen eingeben!\n",129);
	printf("Zu den g%cltigen Zeichen geh%cren -> A,B,C,D ODER a,b,c,d UND %%.\n\n",129,148);
	printf("Sie erhalten auch EINEN Joker, der 50:50 Joker kann nur einmal\n");
	printf("pro Spiel verwendet werden!\n");
	printf("Diesen benutzen Sie dann, wenn Ihnen die Frage ");
	printf("vorgelesen wurde.\n");
	printf("Sie k%cnnen auch mit Ihren Freunden gegeneinander spielen.\n",148);
	printf("Sie m%cssen lediglich die Anzahl der Spieler eingeben.\n",129);
	printf("Im Anschluss frage ich Sie nach Ihrem Namen.\n");
	printf("Viel ERFOLG! :)\n\n\n");
}

/*!
 * @brief Gets the setting for the game
 * @param count - Number of players
 * @return Wether the settings are applied correctly
 */
int getSettings(int *count) {
	// Abfrage Anzahl der Spieler
	printf("Bitte Geben Sie die Anzahl der Spieler ein: ");
	scanf("%d", count);
	while (getchar()!= '\n');

	if(*count < 1) {
		printf("\n[ERROR] Ung%cltige Anzahl von Spielern!\n", 129);
		return 0;
	}
	players = (Player*) malloc(*count * sizeof(Player));

	// Einlesen des Spielernamens
	for(int i = 0; i < *count; i++){
		// Anlegen eine dynamischen Arrays zum Zwischenspeichern des Namens
		char *name = (char*) malloc(NAME_SIZE * sizeof(char));

		// Überprüfen ob der Speicherbereich voll ist
		if(players == NULL || name == NULL) {
			printf("\n[ERROR] Nicht genug Speicherplatz vorhanden!\n");
			return 0;
		}
		// Eingabe der Spielernamen
		printf("Bitte Geben sie Ihren Namen ein (%d): ", i + 1);
		scanf("%19s", name);
		while(getchar()!= '\n');

		Player player = {name, 0, 0, 0};
		players[i] = player;
	}
	return 1;
}

/*!
 * @brief Reads and saves the local quiz questions
 * @param size - Number of questions to read
 */
void readQuestiones(int size) {
	char filename[] = "ET19xxx_x.txt";  
	FILE *path;
	int filenumber;   
	int tempnumber;  
	int numbers[] = {0,1,2,3};       	
	int x;
	int used[7]; 
	int flag;
	questions = (Question*) malloc(size * sizeof(Question));
	
	// Wechseln in das Verzeichnis, in dem die Fragen sind
	chdir(FILE_PATH); 
	for(int i = 0; i < size;){
		filenumber = random(0, 141); // Nummern bis 140
		
		// Überprüfen, ob eine Frage dieses Autors bereits vorkam
		flag = 0;
		for(int k = i - 1; k >= 0; k--) {
			if(used[k] == filenumber) {
				flag = 1;
				break;
			}
		}
		// Speichern der verwendeten Dateien
		if (flag) continue;		
		used[i] = filenumber;
		
		// Einfügen der zufälligen Nummern
		for(int i = 0; i < 3; i++) {
			tempnumber = filenumber % 10;
			filename[6 - i] = '0' + tempnumber;
			filenumber /= 10;
		}
		filename[8] = '0' + random(0, 4);
		path = fopen(filename,"r");
		
		// Überprüfen, ob die Datei existiert
		if(path == NULL) {
			continue;
		}
		else {
			questions[i].question = (char*) malloc(STRING_SIZE * sizeof(char));
			fscanf(path,"%[^\n]",questions[i].question);
			while(fgetc(path)!= '\n');
			shuffle(numbers, ANSWER_COUNT);
			
			// Speicherreservierung für die Antworten 
			for(int n = 0; n < ANSWER_COUNT; n++) {
				questions[i].answers[n] = (char*) malloc(STRING_SIZE * sizeof(char));
			}
			for(int n = 0; n < ANSWER_COUNT; n++){ 
				x = numbers[n];	
				// Leeren des Buffers
				while(fgetc(path)!= '\n');
				fscanf(path,"%[^\n]",questions[i].answers[x]);
				
				if(questions[i].answers[x][0] == '+'){
					questions[i].correctAnswer = x;
				}
				for(int k = 0; questions[i].answers[x][k + 1] != '\0'; k++){
					// Entfernen des Vorzeichens und Leerzeichens
					questions[i].answers[x][k] = questions[i].answers[x][k + 2];
				}
			}
			i++;
		}
		fclose(path);
	}
}

/*!
 * @brief Prints a quiz question
 * @param question - Question to print
 */
void printQuestion(Question question) {
	printf("\n%s\n", question.question);
	for(int i = 0; i < ANSWER_COUNT; i++) {
		printf("%c.) %s\n", 'a' + i, question.answers[i]);
	}
}

/*!
 * @brief Gets the answer of a player
 * @param player - Player to get the question of
 * @param answer - Answer of the player
 */
void getAnswer(Player player, char *answer) {
	// Eingabe der Antwort des Spielers
	printf("\nBitte geben Sie Ihre Antwort ein %s: ", player.name);
	scanf("%c", answer);
	while (getchar()!= '\n');
}

/*!
 * @brief Checks the answer of a player
 * @param question - Question asked to the player
 * @param playerindex - Index of the player int the global array
 * @param answer - Answer of the player
 * @param level - Current level of the game
 * @return Wether the answer is valid
 */
int checkAnswer(Question question, int playerindex, char answer, int level) {
	// Überprüfen der Antwort
	int input;
	if(answer >= 'a' && answer <= 'd') {
		input = answer - 'a';
	}
	else if(answer >= 'A' && answer <= 'D') {
		input = answer - 'A';
	}
	else if(answer == '%') {
		printChance(question ,playerindex);
		return 0;
	}
	else {
		printf("\n[ERROR] Ung%cltige Antwort!\n", 129);
		return 0;
	}
	// Setzen der Punkte
	if(question.correctAnswer == input) {
		players[playerindex].score = prices[level];
	}
	else {
		players[playerindex].lost = 1;
	}
	return 1;
}

/*!
 * @brief Prints the 50-50 chance for a player
 * @param question - Question to create the chance for
 * @param playerindex - Index of the player to create the chance for
 */
void printChance(Question question, int playerindex) {
	// Überprüfen auf 50-50 Chance
	if(players[playerindex].chanceUsed) {
		printf("\nDu hast deine 50-50 Chance bereits verwendet!\n");
		return;
	}
	int answer = random(0, ANSWER_COUNT);

	while(answer == question.correctAnswer) {
		answer = random(0, ANSWER_COUNT);
	}
	int index1 = min(answer, question.correctAnswer);
	int index2 = max(answer, question.correctAnswer);
	
	// Ausgabe der 50-50 Chance
	printf("\n50-50 Chance:\n");
	printf("%c.) %s\n", 'a' + index1, question.answers[index1]);
	printf("%c.) %s\n", 'a' + index2, question.answers[index2]);
	players[playerindex].chanceUsed = 1;
}

/*!
 * @brief Prints the score of the game
 * @param playercount - Count of players of the game
 * @return Wether the score has been successfully saved
 */
int printScore(int playercount) {
	// Sortieren der Spielstände
	sortPlayers(playercount);
	printf("\n\nSpiel beendet!\n");
	printf("--------------\n");
	
	// Speichern der Ergebnisse in Datei
	FILE *file = fopen(SCORE_FILE, "a+");
	if(file == NULL) {
		printf("\n[ERROR] Spielstand konnte nicht gespeichert werden!\n");
		return 0;
	}
	// Ausgabe des Spielstands / der Ergebnisse
	time_t now;
	time(&now);
	fprintf(file, "\n%s\n",ctime(&now));
	for(int i = 0; i < playercount; i++) {
		printf("Platz %d: %s mit einem Highscore von %i Euro\n", i + 1, players[i].name, players[i].score);
		fprintf(file, "Platz %d: %s mit einem Highscore von %i Euro\n", i + 1, players[i].name, players[i].score);
	}
	fclose(file);
	
	return 1;
}
/*!
 * @brief Gets a random integer value in an intervall
 * @param min - Minimum value of the random value
 * @param max - Maximum value of the random value
 * @return The random generated value
 */
int random(int min, int max) {
	return (rand() % (max - min)) + min;
}

/*!
 * @brief Shuffles the values of an integer array
 * @param array - Array with the integer values
 * @param size - Size of the integer array
 */
void shuffle(int array[], int size){
	for (int i = size - 1; i > 0; i--){
		swapInt(array, random(0, size - 1), i);
	}
}

/*!
 * @brief Swaps two values of an integer array
 * @param array - Array with the integer values
 * @param index1 - Index of the first value
 * @param index2 - Index of the second value
 */
void swapInt(int array[], int index1, int index2){
	int temp = array[index1];
	array[index1] = array[index2];
	array[index2] = temp;
}

/*!
 * @brief Swaps two players of the player array
 * @param index1 - Index of the first player
 * @param index2 - Index of the second player
 */
void swapPlayer(int index1, int index2){
	Player temp = players[index1];
	players[index1] = players[index2];
	players[index2] = temp;
}

/*!
 * @brief Sorts the players of the player array
 * @param playercount - Count of players of the array
 */
void sortPlayers(int playercount){
	int index;
	for(int i = 0; i < playercount; i++) {
		index = i;
		for(int j = i; j < playercount; j++){
			if (players[j].score >= players[index].score) {
				index = j;
			}
		}
		swapPlayer(index, i);
	}
}
