#include <stdio.h>

enum Operations {
            PLUS  = 0,
            MINUS = 1,
            MULT  = 2,
            DIV   = 3
};


// Converts input string (PLUS, MINUS, ...) into Integer (Operations)
void StringToInt(char* string, int* op){
	if(string[0] == 'P' && string[1] == 'L' && string[2] == 'U' && string[3] == 'S'){
		*op = PLUS;
	}
	
	if(string[0] == 'M' && string[1] == 'I' && string[2] == 'N' && string[3] == 'U' && string[4] == 'S'){
		*op = MINUS;
	}
	
	if(string[0] == 'M' && string[1] == 'U' && string[2] == 'L' && string[3] == 'T'){
		*op = MULT;
	}
	
	if(string[0] == 'D' && string[1] == 'I' && string[2] == 'V'){
		*op = DIV;
	}
}

// Output
void eingabe (int* a, int* b, char* string){
	
	printf("*********************************** \n");
	printf("Operator: PLUS, MINUS, MULT oder DIV \n");
	printf("*********************************** \n");
	printf("Bitte Rechenoperation in der Form \"Ganzzahl Operator Ganzzahl\" eingeben (z.B. 3 PLUS 3): \n \n");
	scanf("%d", a);
	scanf("%s",&string[0]);
	scanf("%d", b);
	printf("\n");
	
}

// Performs the "plus" operation on a and b
// Returns the result c = a + b
int perform_sum (int a, int b) {
	
	int c = a + b;
	return c;
}

// Performs the "minus" operation on a and b
// Returns the result c = a - b
int perform_sub (int a, int b) {
	
	int c = a - b;
	return c;
}

// Performs the "mult" operation on a and b
// Returns the result c = a * b
int perform_mult (int a, int b) {
	
	int c = a * b;
	return c;
}

// Performs the "div" operation on a and b
// Returns the result c = a / b
int perform_div (int a, int b) {
	
	if(b != 0){
		int c = a / b;
		return c;
	}
	return 0;
}

// Performs the given Operation on a and b
// Returns the result c = a <op> b
int perform_operation(int a, int b, int op) {
	
	int c = 0;
	
	if(op == PLUS){
		c = perform_sum(a,b);
	return c;
	}
	
	if(op == MINUS){
		c = perform_sub(a,b);
	return c;
	}
	
	if(op == MULT){
		c = perform_mult(a,b);
	return c;
	}
	
	if(op == DIV){
		c = perform_div(a,b);
	 return c;
	}
	
	return 0;
}



// Prints results of a <op> b = c
void ausgabe (int a, int b, int op, int c) {
	
	if(op == PLUS)
		printf("Ergebnis: %d + %d = %d", a, b, c);
		
	if(op == MINUS)
		printf("Ergebnis: %d - %d = %d", a, b, c);
		
	if(op == MULT)
		printf("Ergebnis: %d * %d = %d", a, b, c);
		
	if(op == DIV)
		printf("Ergebnis: %d / %d = %d", a, b, c);
		printf("\n \n \n");	
}

int main() {

	int a = 0;
	int b = 0;
	int op = 0;
	char string [6];

	while(1){
		eingabe(&a, &b, string);
		StringToInt(string, &op);
		int c = perform_operation(a, b, op);
		ausgabe (a, b , op, c);
	}
	return 0;
}
