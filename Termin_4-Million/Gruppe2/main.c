#include <stdio.h>
#include <_Bool.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

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
void read_filenames(char** filenames); // Luis

int choose_question(Question* questions); // Anika
void print_question(const Question question); // Dominik
void print_question_50_50(const Question question); // Sven
void user_input(); // Max
_Bool check_answer(Question question, int answer);


int main(void) {
	print_welcome_message();
	player.name = input_name();
	player.level = 1;
	player.joker_available = 1;
	return 0;
}
