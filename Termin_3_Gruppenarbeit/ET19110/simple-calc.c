#include <stdio.h>

enum Operations {
            PLUS  = 0,
            MINUS = 1,
            MULT  = 2,
            DIV   = 3
};

// Performs the "plus" operation on a and b
// Returns the result c = a + b
int perform_sum (int a, int b) {
	return a + b;
}

// Performs the given Operation on a and b
// Returns the result c = a <op> b
int perform_operation(int a, int b, int op) {
	int c = 0;
	
	switch(op) {
		case PLUS:
			c = perform_sum(a, b);
			break;
		case MINUS:
		case MULT:
		case DIV:
		default:
			break;
	}
	return c;
}

// Prints results of a <op> b = c
void ausgabe (int a, int b, int op, int c) {
	switch(op) {
		case PLUS:
			printf("%i + %i = %i", a, b, c);
			break;
		case MINUS:
		case MULT:
		case DIV:
		default:
			break;
	}
}

int main() {
    int a = 1;
    int b = 1;

    int c = perform_operation(a, b, PLUS);
    ausgabe(a, b, PLUS, c);
    
    return 0;
}
