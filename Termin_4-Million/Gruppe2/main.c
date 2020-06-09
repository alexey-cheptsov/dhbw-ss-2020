#include <stdio.h>
#include <_Bool.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "dirent.h"

typedef struct {
	char* question;
	char* answers[4];
	int nr_correct;
} Question;

typedef struct {
	int credits;
	int level;
	_Bool joker_available;
	char* name;
} Player;

Player player;

// Writes filenames from directory to array
// Luis
void read_filenames(char** question_1, char** question_2, char** question_3) {
	DIR* dir;
	struct dirent* rd;

	dir = opendir("../FRAGEN-DB/");
	if (dir == NULL) {
		printf("Öffnen fehlgeschlagen.");
	}

	while ((rd = readdir(dir)) != NULL) {
		printf("name: %s\n", rd->d_name);
	}

}

int choose_question(Question* questions); // Anika
// Dominik
void print_question(const Question question) {
	printf("%s\n", question.question);
	for (int i = 0; i < 4; ++i) {
		printf("%c) %s\n", 'a' + i, question.answers[i]);
	}
}

void print_question_50_50(const Question question)
{
	srand(time(0));
	
	int num1 = (rand() % (4));					// int num = (rand() % (upper - lower + 1)) + lower;
	int num2 = (rand() % (4));
	
	while(num1 == question.nr_correct)
	{
		num1 = (rand() % (4));
	}
	
	while(num2 == question.nr_correct || num2 == num1)
	{
		num2 = (rand() % (4));
	}
	
	printf("%s \n", question.answers[num1]);
	printf("%s \n", question.answers[num2]);
	
	
} // Sven

void user_input(); // Max
_Bool check_answer(Question question, int answer);


int main(void) {
	print_welcome_message();
	player.name = input_name();
	player.level = 1;
	player.joker_available = 1;
	return 0;
}
