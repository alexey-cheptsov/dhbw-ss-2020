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


void getSettings(Player *players, int *count);

void readQuestiones(Question *questions, int size);
void printQuestion(Question question);
void getAnswer(Player *player, char *answer);
int checkAnswer(Question question, char *answer);

void printChance(Question question, Player player);
int printScore(FILE *file, Player *players);

int random(int min, int max);

int main(int argc, char **argv) {	
	return 0;
}

void getSettings(Player *players, int *count) {
	// Abfrage Anzahl der Spieler
	// Eingabe der Spielernamen

	// Lukas Hauser
}

void readQuestiones(Question *questions, int size) {
	// Speichern der Fragen
char filename [] = "ET19xxx_x.txt"; 
	FILE *path;
	int filenumber;
	int tempnumber;
	srand(time(NULL));
	
	questions =  malloc (size * sizeof(Question));
		
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
			while (fgetc(path)!= '\n');
			
				
			for (int n = 0; n < 4; n++){ 	//n muss noch geshuffelt werden
				questions[i].answers[n] =(char*) malloc (100*sizeof(char));
				
				while (fgetc(path)!= '\n');
					fscanf(path,"%[^\n]",questions[i].answers[n]);
					if (questions[i].answers[n][0] == '+'){
						 questions[i].correctAnswer = n;
					}
				
				
				
			}
		}
	}
	// Fabian Himmelsbach
}

void printQuestion(Question question) {
	// Ausgabe der Frage (Zufaellige Nummerierung)

	// Fabian Himmelsbach
}

void getAnswer(Player *player, char *answer) {
	// Eingabe der Antwort des Spielers

	// Deniz Akdeniz
}

int checkAnswer(Question question, char answer) {
	// Überprüfen der Antwort
	// Setzen der Punkte

	// Nick Hof
}

void printChance(Question question, Player player) {
	// Ausgabe der 50-50 Chance

	// Oliver Gerstl
}

int printScore(FILE *file, Player *players) {
	// Ausgabe des Spielstands / der Ergebnisse
	// Speichern der Ergebnisse in Datei

	// To be continued...
}

int random(int min, int max) {
	return (rand() % (max - min + 1)) + min;
}
