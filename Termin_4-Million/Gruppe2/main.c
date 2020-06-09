#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "dirent.h"

#define MAX_NAME_SIZE 20

typedef struct {
	char* question;
	char* answers[4];
	int nr_correct;
} Question;

typedef struct {
	int credits;
	int level;
	_Bool joker_available;
	char name[MAX_NAME_SIZE];
} Player;

typedef struct {
	void (*handle_input) (void);
	void (*update) (void);
	void (*render) (void);
} State;

State* currentState;
=======
=======
struct State {


Player player;

// Writes filenames from directory to array
// Luis
void read_filenames(struct dirent* rd) {
	DIR* dir;
	dir = opendir("../FRAGEN-DB/");
	if (dir == NULL) {
		printf("Öffnen fehlgeschlagen.");
	}
=======


int choose_question(Question* questions); // Anika
void print_question(const Question question); // Dominik

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

bool check_answer(Question question, int answer)
{
	if(question.nr_correct == answer)
	{
		return true;
	}
	else return false;
}

void user_input(int *credits, char *str); // Max
_Bool check_answer(Question question, int answer);


// int main(int argc, char ** argv) {
int main(void) {
	Player player;
	int credits;
	char str[NAME_SIZE];
	print_welcome_message();
	player.name = userInput(&player.credits, player.name);
	player.level = 1;
	player.joker_available = 1;
	return 0;
}

print_welcome_message()
{
	printf("Herzlich Willkommen\n zu\n WER WIRD MILLIONAER");
	printf("\nHerr Jauch stellt Ihnen eine Frage und wenn Sie diese richtig beantworten,\n kommen Sie eine Runde weiter. Es gibt 7 Runden.");
	printf("\nFuer jede Runde gibt es ein Preisgeld. Beantworten Sie die Frage falsch, verlieren sie all Ihr Geld");
	printf("Sie haben einen 50:50 Joker der mit xxxx eingesetzt werden kann.");
	printf("\nViel Spass und Viel Erfolg wuenscht Ihnen Guenther Jauch");
	return 0;
}

void userInput(int *credits, char *str)
{	
	*credits = 0;
	printf("Geben Sie Ihren Name bitte ein: ");
	fgets(str, MAX_NAME_SIZE, stdin);
}
