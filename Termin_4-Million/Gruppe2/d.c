typedef struct Question;
typedef struct Player;
typedef struct State;

State* stateMenu;
State* statePlaying;
State* stateJoker;
State* stateWon;
State* stateLost;

State* currentState = stateMenu;

int main(void) {
	currentState->init();
	while (1) {	
		currentState->handle_input();
		currentState->update();
		currentState->render();
	}
	return 0;
}
