// to do
// Bestenliste
// Ungültige Antwort einfach überspringen und die Frage neu schreiben
// bei jeder Frage den Kontostand zeigen
// Endbildschirm beim Verlieren / Gewinnen

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <dirent.h>

#define MAX_NAME_SIZE 32
//#define clear_console() printf("\033[H\033[J")

typedef struct {
	char* question;
	char* answers[4];
	int nr_correct;
} Question;

typedef struct {
	int credits;
	int level;
	bool joker_available;
	char name[MAX_NAME_SIZE];
	bool done;
} Player;

typedef struct {
	void (*init) (void);
	bool (*handle_input) (void);
} State;

void State_Menu_init();
bool State_Menu_handle_input();

void State_CreateUser_init();
bool State_CreateUser_handle_input();

void State_AskQuestion_init();
bool State_AskQuestion_handle_input();

void State_Joker_init();
bool State_Joker_handle_input();

void State_Won_init();
bool State_Won_handle_input();

void State_Lost_init();
bool State_Lost_handle_input();

State stateMenu = {
	&State_Menu_init,
	&State_Menu_handle_input
};
State stateCreateUser = {
	&State_CreateUser_init,
	&State_CreateUser_handle_input
};
State stateAskQuestion = {
	&State_AskQuestion_init,
	&State_AskQuestion_handle_input
};
State stateJoker =  {
	&State_Joker_init,
	&State_Joker_handle_input
};
State stateWon = {
	&State_Won_init,
	&State_Won_handle_input
};
State stateLost = {
	&State_Lost_init,
	&State_Lost_handle_input
};

State* currentState = NULL;
Player player = { .credits = 0, .level = 1, .joker_available = true, .name = {}, .done = false };
char filenames[200][27];
int number_of_questions = 0;
Question currentQuestion;


///refresh question data for next call
void refresh_data(int r, char* p){//Anika
	strcpy(filenames[r], filenames[number_of_questions]);	///replace used filename
	number_of_questions = number_of_questions -1;	///new number of available questions
	free(p);	///p is the path to the used file
}

int read_question(FILE* fl, Question* questions){//Anika
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
	    	///Fragen zufällig anordnen???
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

int choose_question(Question* questions){ // Anika
    int random;
    FILE* fl;
    char* path_to_file;
	
	path_to_file = (char*)malloc(50*sizeof(char));  //da "et19004_1.txt" 13 Zeichen und "../Fragen-DB/" ebenfalls 13 Zeichen
	strcpy(path_to_file, "../Fragen-DB/");
	
	///choose rondom question
    random=rand()% number_of_questions;
	strcat(path_to_file, filenames[random]);
    fl = fopen(path_to_file, "r");
	if(fl==NULL){
		printf("Die Datei %s konnte nicht geöffnet werden. Es wird eine andere Frage ausgewählt.\n", filenames[random]);
		refresh_data(random, path_to_file);
		if(number_of_questions >0){
			choose_question(questions);
		}else{
			printf("Es können keine neuen Fragen gelesen werden!\n");
			return 0;
		}
	}
	
	if(read_question(fl, questions)==0){
		printf("Die Datei %s enthält einen Fehler. Es wird eine andere Frage ausgewählt.\n", filenames[random]);
		refresh_data(random, path_to_file);
		if(number_of_questions >0){
			choose_question(questions);
		}else{
			printf("Es können keine neuen Fragen gelesen werden!\n");
			return 0;
		}
	}
    
    
	refresh_data(random, path_to_file);
    return 1;
}



int main(void) {
	srand(time(NULL));

	currentState = &stateMenu;
	currentState->init();

	while ( currentState->handle_input() );

	return 0;
}


void State_Menu_init() {
	system("clear");
	printf("Herzlich Willkommen\n zu\n WER WIRD MILLIONAER");
	printf("\nHerr Jauch stellt Ihnen eine Frage und wenn Sie diese richtig beantworten,\n kommen Sie eine Runde weiter. Es gibt 7 Runden.");
	printf("\nFuer jede Runde gibt es ein Preisgeld. Beantworten Sie die Frage falsch, verlieren sie all Ihr Geld");
	printf("\nSie haben einen 50:50 Joker der mit <j> eingesetzt werden kann.");
	printf("\nViel Spass und Viel Erfolg wuenscht Ihnen Guenther Jauch\n");
	printf("Zum Spielbeginn drücken Sie <ENTER>\n");

	// read filenames
	struct dirent* rd;
	DIR* dir;
	dir = opendir("../Fragen-DB/");

	if (dir == NULL) {
		printf("Öffnen fehlgeschlagen.");
	}

	while ((rd = readdir(dir)) != NULL) {
		if(rd->d_name[0] != '.'){
			strcpy(&(filenames[number_of_questions][0]), rd->d_name);
			//printf("%s\n", filenames[number_of_questions]);
			number_of_questions=number_of_questions+1;
		}
	}
}

bool State_Menu_handle_input() {
	if (getchar() == '\n') {
		currentState = &stateCreateUser;
		currentState->init();
	}
	return true;
}


void State_CreateUser_init() {
	printf("Geben Sie Ihren Name bitte ein: ");
	fgets(player.name, MAX_NAME_SIZE, stdin);
	currentState = &stateAskQuestion;
	currentState->init();
}

bool State_CreateUser_handle_input() {
	if (getchar() == '\n') { // or other condition to start playing
		currentState = &stateAskQuestion;
		currentState->init();
	}
	return true;
}


void State_AskQuestion_init() {
	system("clear");
    choose_question(&currentQuestion);
	printf("Frage %d\n", player.level);
	printf("%s\n\n", currentQuestion.question);
	for (int i = 0; i < 4; ++i) {
		printf("%c) %s\n", 'a' + i, currentQuestion.answers[i]);
	}
	if (player.joker_available) printf("j) Joker\n");
}

bool State_AskQuestion_handle_input() {
	// get user input and check answer
	char user_answer = getchar();
	if (user_answer == 'j' && player.joker_available){
		player.joker_available = false;
		currentState = &stateJoker;
		currentState->init();
	} else if (user_answer == 'a' + currentQuestion.nr_correct || user_answer == '0' + currentQuestion.nr_correct){
		// right answer
		if (player.level == 1) {
			player.credits = 10;
		} else {
			player.credits *= 10;
		}
		++player.level;
		if (player.level == 8) {
			currentState = &stateWon;
		} else if (currentState == &stateJoker) {
			currentState = &stateAskQuestion;
		}
		currentState->init();
	} else if (user_answer >= 'a' && user_answer <= 'd'){
		player.done = true;
		currentState = &stateLost;
		currentState->init();
	}
	return true;
}


void State_Joker_init() {	
	system("clear");
	printf("Frage %d\n", player.level);
	printf("%s\n\n", currentQuestion.question);

	int num = (rand() % (4));
	
	while(num == currentQuestion.nr_correct)
	{
		num = (rand() % (4));
	}
	
	if(num < currentQuestion.nr_correct)
	{
		printf("%c) %s \n", 'a' + num, currentQuestion.answers[num]);
		printf("%c) %s \n", 'a' + currentQuestion.nr_correct, currentQuestion.answers[currentQuestion.nr_correct]);
	}
	else
	{
		printf("%c) %s \n", 'a' + currentQuestion.nr_correct, currentQuestion.answers[currentQuestion.nr_correct]);
		printf("%c) %s \n", 'a' + num, currentQuestion.answers[num]);
	}
}

bool State_Joker_handle_input() {
	return State_AskQuestion_handle_input();
}


void State_Won_init() {
	// print_winning_screen();
	// show_game_results();
	printf("Won!\n");
}

bool State_Won_handle_input() {
	if (getchar() == '\n') {
		//save_player_stats();
		return false; // false means game is done and will close
	}
	return true;
}


void State_Lost_init() {
	// print_losing_screen();
	// show_game_results();
	printf("Lost!\n");
}

bool State_Lost_handle_input() {
	if (getchar() == '\n') {
		//save_player_stats();
		return false; // false means game is done and will close
	}
	return true;
}
