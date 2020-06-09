typedef struct Question;
typedef struct Player;
typedef struct State;

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
State sstatePlayingtateCreateUser = {
	&State_CreateUser_init,
	&State_CreateUser_handle_input
};
State stateCreateUser = {
	&State_CreateUser_init,
	&State_CreateUser_handle_input
};
State stateCreateUser = {
	&State_CreateUser_init,
	&State_CreateUser_handle_input
};
State statePlaying =  {
	&State_CreateUser_init,
	&State_CreateUser_handle_input
};
State stateCreateUser = {
	&State_CreateUser_init,
	&State_CreateUser_handle_input
};
State statePlaying;
State stateJoker;
State stateWon;
State stateLost;
State stateLeaderboard;

State* currentState = &stateMenu;

int main(void) {
	currentState->init();
	while (1) {	
		currentState->handle_input();
		currentState->update();
		currentState->render();
	}
	return 0;
}
