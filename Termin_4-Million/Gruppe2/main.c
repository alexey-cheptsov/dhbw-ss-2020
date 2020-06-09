#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <dirent.h>

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

}
Player player;

// Writes filenames from directory to array
// Luis
void read_filenames(int* m, char** filenames) {
	//int m = 0;
	//char filenames[100][15];
	struct dirent* rd;
	DIR* dir;
	
	dir = opendir("../Fragen-DB/");
	if (dir == NULL) {
		printf("Oeffnen fehlgeschlagen.");
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

int choose_question(Question* questions, char** filenames, int* max_questions){// Anika
    srand(time(NULL));
    int random;
    FILE* fl;
    char* path_to_file;
	
	path_to_file = (char*)malloc(27*sizeof(char));  //da "et19004_1.txt" 13 Zeichen und "../Fragen-DB/" ebenfalls 13 Zeichen
	strcpy(path_to_file, "../Fragen-DB/");
	
	///choose rondom question
    random=rand()% *max_questions;
	strcat(path_to_file, filenames[random]);
    fl = fopen(path_to_file, "r");
	if(fl==NULL){
		printf("Die Datei %s konnte nicht geöffnet werden. Es wird eine andere Frage ausgewählt.\n", filenames[random]);
		filenames[random] = filenames[*max_questions];
		*max_questions= *max_questions-1;
		free(path_to_file);
		if(*max_questions >0){
			choose_question(questions, filenames, max_questions);
		}else{
			printf("Es können keine neuen Fragen gelesen werden!\n");
			return 0;
		}
	}
	
	if(read_question(fl, questions)==0){
		printf("Die Datei %s enthält einen Fehler. Es wird eine andere Frage ausgewählt.\n", filenames[random]);
		filenames[random] = filenames[*max_questions];
		*max_questions= *max_questions-1;
		free(path_to_file);
		if(*max_questions >0){
			choose_question(questions, filenames, max_questions);
		}else{
			printf("Es können keine neuen Fragen gelesen werden!\n");
			return 0;
		}
	}
    
    ///refresh data for next call
	filenames[random]=filenames[*max_questions];
	*max_questions= *max_questions-1;
	free(path_to_file);
    return 1;
}

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


// int main(int argc, char ** argv) {
int main(void) {
	Player player;
	int credits;
	char str[NAME_SIZE];
	print_welcome_message();
	player.name = userInput(&player.credits, player.name);
	player.level = 1;
	player.joker_available = 1;
	
	int max =0;
	char filenames[100][13];
	read_filenames(&max, filenames);
	
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
