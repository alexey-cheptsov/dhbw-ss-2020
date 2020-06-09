#include <stdio.h>
#include <_Bool.h>
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

<<<<<<< HEAD
typedef struct {
	void (*handle_input) (void);
	void (*update) (void);
	void (*render) (void);
} State;

State* currentState;
=======
<<<<<<< HEAD
=======
struct State {
>>>>>>> d55f023067ca68456950f567592cb9b15f995f76


Player player;
>>>>>>> 30715eaeed016b839094904d4aad37f3ff0ea97f

// Writes filenames from directory to array
// Luis
<<<<<<< HEAD
void read_filenames(char** question_1, char** question_2, char** question_3) {
	DIR* dir;
	struct dirent* rd;

	dir = opendir("../FRAGEN-DB/");
	if (dir == NULL) {
		printf("�ffnen fehlgeschlagen.");
=======
void read_filenames() {
	char question_1[26][14];
	char question_2[26][14];
	char question_3[26][14];
	char* matrikel[] = { "004", "017", "020", "021", "023", "036", "037", "052", "057", "070", "073", "078", "080", "082", "084", "088", "095", "099", "104", "107", "110", "114", "115", "131", "135", "140" };
	for (int m = 0; m <= 25; m++) {
		sprintf(question_1[m], "ET19%s_1.txt", matrikel[m]);
		sprintf(question_2[m], "ET19%s_2.txt", matrikel[m]);
		sprintf(question_3[m], "ET19%s_2.txt", matrikel[m]);
>>>>>>> d55f023067ca68456950f567592cb9b15f995f76
	}

	while ((rd = readdir(dir)) != NULL) {
		printf("name: %s\n", rd->d_name);
	}

}

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
	printf("Herzlich Willkommen\n zu\n WER WIRD MILLIONÄR");
	printf("\nHerr Jauch stellt Ihnen eine Frage und wenn Sie diese richtig beantworten,\n kommen Sie eine Runde weiter. Es gibt 7 Runden.");
	printf("\nFür jede Runde gibt es ein Preisgeld. Beantworten Sie die Frage falsch, verlieren sie all Ihr Geld");
	printf("Sie haben einen 50:50 Joker der mit xxxx eingesetzt werden kann.");
	printf("\nViel Spass und Viel Erfolg wünscht Ihnen Günther Jauch");
	return 0;
}

void userInput(int *credits, char *str)
{	
	*credits = 0;
	printf("Geben Sie Ihren Name bitte ein: ");
	fgets(str, MAX_NAME_SIZE, stdin);
}
