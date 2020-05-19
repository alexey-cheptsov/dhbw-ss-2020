#include <stdio.h>

enum Operations{
            PLUS =0,
            MINUS=1,
            MULT=2,
            DIV=3,

};

//Verantwortlichkeiten festlegen

//Kollege 1
//int perform_operation(int a, int b, int op);

//Kollege 2
//int perform_sum(int a, int b);

//Kollege 3
//void ausgabe( int a, int b, int op, int c);



//Performs the given Operation on a and b
//Returns the result c = a <op> b
int perform_operation(int a, int b, int op){
    int c = 0;

    if (op == PLUS)
        c = perform_sum(a, b);

    return c;
}

//Performs the "plus" Operation
//Returns the result c = a + b
int perform_sum(int a, int b){
    int c = 0;

    c = a+b;

    return c;

}

//prints the result of a <op> b = c
void ausgabe( int a, int b, int op, int c){

    printf("Result of operation: ");
    printf("%d ", a);
    if(op==PLUS)
        printf("%c ", '+');
    printf("%d ", b);
    printf(" = %d\n", c);

}

int main()
{
    int a = 1;
    int b = 1;
    int c = 0;
    c = perform_operation(a, b, PLUS);
    ausgabe(a, b, PLUS, c);
}
