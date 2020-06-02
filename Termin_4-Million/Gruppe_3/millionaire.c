/*
 * millionaire.c
 * 
 * Copyright 2020 et19110 <et19110@lehre.dhbw-stuttgart.de>
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

typedef struct Player {
	char* name;
	int score;
} Player;

typedef struct Question {
	char* question;
	char* answers[4];
	int correctAnswer;
} Question;

Player *players;
Question *questions;


void getSettings(char **names, int *count);

int printQuestion(int id);
void getAnswer(char *name, char *answer);
int checkAnswer(int id, char *answer);

int printChance(int id, char* name);
int printScore(char** names, int *scores);
int saveScore(FILE *file, char** names, int *scores);

int main(int argc, char **argv) {	
	return 0;
}

void getSettings(char **names, int *count) {
	
}

int printQuestion(int id) {
	return 0;
}

void getAnswer(char *name, char *answer) {
	
}

int checkAnswer(int id, char *answer) {
	return 0;
}

int printChance(int id, char* name) {
	return 0;
}

int printScore(char** names, int *scores) {
	return 0;
}

int saveScore(FILE *file, char** names, int *scores) {
	return 0;
}
