#include <stdio.h>

typedef struct {
	char* question;
	char* answers[4];
	int nr_correct;
} Question;

void read_filenames(char** filenames);
int choose_question(char** filenames);
void print_question(Question* question);
void print_question_50_50(Question* question);

int main(void) {
	return 0;
}
