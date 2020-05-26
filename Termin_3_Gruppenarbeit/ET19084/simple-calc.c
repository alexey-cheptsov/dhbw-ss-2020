#include <stdio.h>
//Prototypen
int perform_sum(int , int);
int perform_min(int , int);
int perform_pro(int , int);
int perform_div(int , int);

enum Operations {
            PLUS  = 0,
            MINUS = 1,
            MULT  = 2,
            DIV   = 3
};

// Performs the given Operation on a and b
// Returns the result c = a <op> b
int perform_operation(int a, int b, int op) {
int c;
switch (op){
	case 0: c = perform_sum(a,b);break;
	case 1: c = perform_min(a,b);break;
	case 2: c = perform_pro(a,b);break;
	case 3: c = perform_div(a,b);break;
	default: printf("\n Fehler\n"); return 0;break;}
return c;
}

// Performs the "plus" operation on a and b
// Returns the result c = a + b
int perform_sum (int a, int b) {
int c = a + b;
return c;
}

// Performs the "minus" operation on a and b
// Returns the result c = a - b

int perform_min (int a, int b) {
int c = a - b;
return c;
}

// Performs the "mult" operation on a and b
// Returns the result c = a * b

int perform_pro (int a, int b) {
int c = a * b;
return c;
}

// Performs the "DIV" operation on a and b
// Returns the result c = a : b

int perform_div (int a, int b) {
int c = a / b;
return c;
}

// Prints results of a <op> b = c
void ausgabe (int a, int b, int op, int c) {

switch (op){
	case 0: c = printf("\n %d + %d = %d\n", a,b,c);break;
	case 1: c = printf("\n %d - %d = %d\n", a,b,c);break;
	case 2: c = printf("\n %d * %d = %d\n", a,b,c);break;
	case 3: c = printf("\n %d : %d = %d\n", a,b,c);break;
	default: printf("\n Fehler\n");break;}
}

int main() {
	int op = MINUS;
    int a = 1;
    int b = 1;
	
ausgabe(a, b, op, perform_operation(a,b,op));
 return 0;  
}
