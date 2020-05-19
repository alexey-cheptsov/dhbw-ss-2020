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

	int c=0;

	if(op == PLUS){
		c = perform_sum(a,b);
	}

	return c;
}

// Performs the "plus" operation on a and b
// Returns the result c = a + b
int perform_sum (int a, int b) {

	int c=0;

	c= a + a;

	return c;

}

// Prints results of a <op> b = c
void ausgabe (int a, int b, int op, int c) {

	if(op == PLUS){
		printf("Result: %d + %d = %d", a, b, c);
	}
}

int main() {

    int a = 1;
    int b = 1;
    int op = PLUS;
    int c=0;
    
    c= perform_operation(a,b, op);
    
    ausgabe(a,b,op,c);

    // int c = a PLUS b;
}
