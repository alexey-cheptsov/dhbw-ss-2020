#include <stdio.h>

enum Operations {
            PLUS  = 0,
            MINUS = 1,
            MULT  = 2,
            DIV   = 3
};

// Performs the given Operation on a and b
// Returns the result c = a <op> b
int perform_operation(int a, int b, int op) {
	switch(op) {
		case PLUS:
			return perform_sum(a,b);
	}
// Kollege 1

}

// Performs the "plus" operation on a and b
// Returns the result c = a + b
int perform_sum (int a, int b) {
	return a + b;
// Kollege 200

}

// Prints results of a <op> b = c
void ausgabe (int a, int b, int op, int c) {
	switch(op){
		case PLUS:
			printf("%i + %i = %i",a,b,c);
// Kollegin 3
}
}

int main() {

    int a = 1;
    int b = 1;
	int c = perform_operation(a,b,PLUS);
	ausgabe(a,b,PLUS,c);
	return 1;
    // int c = a PLUS b;
}

