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
