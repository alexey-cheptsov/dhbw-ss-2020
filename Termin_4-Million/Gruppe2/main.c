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

struct State {

};
Player player;

// Writes filenames from directory to array
// Luis

void read_filenames(int* m, char** filenames) {

	struct dirent* rd;
	DIR* dir;
	dir = opendir("../Fragen-DB/");
<<<<<<< HEAD
=======

>>>>>>> be4a755f9582e12de6cc59f3c5961f867e33de3b
	if (dir == NULL) {
		printf("�ffnen fehlgeschlagen.");
	}

	while ((rd = readdir(dir)) != NULL) {
		if(rd->d_name[0] != '.'){
			strcpy(&(filenames[*m][0]), rd->d_name);
			printf("%s", filenames[*m]);
			*m=*m+1;
		}
	}
}

int read_question(FILE* fl, Question* questions){
	 size_t input_size = 1;
	///read first line (question)
	if(getline(&questions->question, &input_size, fl) ==-1){
		return 0;
	}  
    ///empty line:
    if(getline(&questions->answers[0], &input_size, fl) == -1){
		return 0;
	}
    ///read answers:
    for(int i = 0; i<4; i++){
		input_size=1;
		if(getline(&questions->answers[i], &input_size, fl) == -1){
			return 0;
		}
		///save correct answers
		if(questions->answers[i][0] == '+'){
			questions->nr_correct = i;
		}
		///remove + / - 
		for(int c=0; c<input_size; c++){
			questions->answers[i][c]=questions->answers[i][c+2];
		}
	}
	return 1;
}
<<<<<<< HEAD
=======
=======
=======
>>>>>>> 
>>>>>>> be4a755f9582e12de6cc59f3c5961f867e33de3b


int choose_question(Question* questions); // Anika
void print_question(const Question question); // Dominik

void print_question_50_50(const Question question)
{
	srand(time(0));
	
	int num = (rand() % (4));
	
	while(num == question.nr_correct)
	{
		num = (rand() % (4));
	}
	
	if(num < question.nr_correct)
	{
		printf("%s \n", question.answers[num]);
		printf("%s \n", question.answers[question.nr_correct]);
	}
	else
	{
		printf("%s \n", question.answers[question.nr_correct]);
		printf("%s \n", question.answers[num]);
	}	
} // Sven

bool check_answer(Question question, int answer)
{
	if(question.nr_correct == answer)
	{
		return true;
	}
	else return false;
}

<<<<<<< HEAD
void user_input(int *credits, char *str); // Max
_Bool check_answer(Question question, int answer);
void print_welcome_message();
char* userInput(int* credits, char* str);
=======

>>>>>>> be4a755f9582e12de6cc59f3c5961f867e33de3b
// int main(int argc, char ** argv) {
int main(void) {
	Player player;
	int credits;
	char str[NAME_MAX];
	print_welcome_message();
	player.name = userInput(&player.credits, player.name);
	player.level = 1;
	player.joker_available = 1;
	
	int max =0;
	char filenames[100][13];
	read_filenames(&max, &filenames[0][0]);
	
	return 0;
}

void print_welcome_message()
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
