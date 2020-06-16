#include <stdio.h>
#include <stdbool.h>

typedef struct {
	char* question;
	char* answers[4];
	int nr_correct;
} Question;

typedef struct {
	int credits;
	int level;
	bool joker_available;
	char name[32];
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
Question currentQuestion;


int main(void) {
	currentState = &stateMenu;
	currentState->init();

	while ( currentState->handle_input() );

	return 0;
}


void State_Menu_init() {
	// print welcome message
	printf("Welcome\n");
}

bool State_Menu_handle_input() {
	if (getchar() == '\n') {
		currentState = &stateCreateUser;
		currentState->init();
	}
	return true;
}


void State_CreateUser_init() {
	// guide user through the creation of a player profile
	// printf("Name:") ...
	// fgets ...
	printf("Enter name ..\n");
}

bool State_CreateUser_handle_input() {
	if (getchar() == '\n') { // or other condition to start playing
		currentState = &stateAskQuestion;
		currentState->init();
	}
	return true;
}


void State_AskQuestion_init() {
	//print_question(currentQuestion);
	// print_joker_info();
	printf("Question %d\n", player.level);
}

bool State_AskQuestion_handle_input() {
	// get user input and check answer
	char user_answer = getchar();
	if (user_answer == '\n') {
		++player.level;
		if (player.level == 8) {
			currentState = &stateWon;
			currentState->init();
		} else {
			currentState->init();
		}
	}
	//if (user_answer == currentQuestion.nr_correct) { increase level, credits, go to next Q };
	//else if (user_answer == joker) .. joker
	// else wrong answer: currentState = &stateLost;
	// currentState->init();
	return true;
}


void State_Joker_init() {
	// print remaining 2 answers
	printf("Joker\n");
}

bool State_Joker_handle_input() {
	// check answer
	return true;
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