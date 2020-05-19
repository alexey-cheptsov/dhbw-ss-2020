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

// Performs the "minus" operation on a and b
// Returns the result c = a - b
int perform_diff (int a, int b) {
	return a - b;
}

// Performs the "mult" operation on a and b
// Returns the result c = a * b
int perform_mult(int a, int b) {
	return a * b;
}

// Performs the "div" operation on a and b
// Returns the result c = a / b
int perform_div (int a, int b) {
	if (b != 0) return a / b;
    else return 0; // error
}

// Performs the given Operation on a and b
// Returns the result c = a <op> b
int perform_operation(int a, int b, int op) {
	if (op == PLUS) {
		return perform_sum(a, b);
	}
    else if (op == MINUS) {
        return perform_diff(a,b);
    }
    else if (op == MULT) {
        return perform_mult(a, b);
    }
    else if (op == DIV) {
        return perform_div(a, b);
    }
}

// Prints results of a <op> b = c
void ausgabe (int a, int b, int op, int c) {
	char op_sign = 0;
	if (op == PLUS) op_sign = '+';
	else if (op == MINUS) op_sign = '-';
	else if (op == MULT) op_sign = '*';
	else if (op == DIV) op_sign = '/';
	printf("%d %c %d = %d\n", a, op_sign, b, c);
}

int main() {

    int a = 4;
    int b = 2;

    // int c = a PLUS b;
    int c = perform_operation(a, b, PLUS);
    ausgabe(a, b, PLUS, c);
    c = perform_operation(a, b, MINUS);
    ausgabe(a, b, MINUS, c);
    c = perform_operation(a, b, MULT);
    ausgabe(a, b, MULT, c);
    c = perform_operation(a, b, DIV);
    ausgabe(a, b, DIV, c);
}
