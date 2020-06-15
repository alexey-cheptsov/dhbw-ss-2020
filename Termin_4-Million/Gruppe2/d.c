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
	char name[MAX_NAME_SIZE];
	bool done;
} Player;

typedef struct {
	void (*init) (void);
	void (*handle_input) (void);
} State;

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
Player player = { credits = 0, level = 1, joker_available = true, name = {}, done = false };
Question currentQuestion;



void State_Menu_init() {
	// print welcome message
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
}

bool State_CreateUser_handle_input() {
	if (getchar() == '\n') { // or other condition to start playing
		currentState = &stateAskQuestion;
		currentState->init();
	}
	return true;
}


void State_AskQuestion_init() {
	print_question(currentQuestion);
	// print_joker_info();
}

bool State_AskQuestion_handle_input() {
	// get user input and check answer
	char user_answer = getchar();
	//if (user_answer == currentQuestion.nr_correct) { increase level, credits, go to next Q };
	//else if (user_answer == joker) .. joker
	// else wrong answer: currentState = &stateLost;
	// currentState->init();
	return true;
}


void State_Joker_init() {
	// print remaining 2 answers
}

bool State_Joker_handle_input() {
	// check answer
	return true;
}


void State_Won_init() {
	// print_winning_screen();
	// show_game_results();
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
}

bool State_Lost_handle_input() {
	if (getchar() == '\n') {
		//save_player_stats();
		return false; // false means game is done and will close
	}
	return true;
}



int main(void) {
	currentState = &stateMenu;
	currentState->init();

	while ( currentState->handle_input() );

	return 0;
}


