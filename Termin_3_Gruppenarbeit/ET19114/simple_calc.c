// Matrikelnummer: 7879892

#include <stdio.h>


enum Operations
{
	PLUS = 0,
	MINUS = 1,
	MULT = 2,
	DIV = 3
};

//Addiert a und b
//weist c das Ergebnis der Addition zu

int addiere(int a, int b, int op)
{
	int c = 0;
	
	if(op == PLUS)
		c = a + b;
	
	return c;
}

//gibt a, b, den Operator und das das Ergebnis c aus

void gibAus(int a, int b, int op, int c)
{

	printf("Ergebnis: ");
	printf("%d ", a);
	if (op == PLUS)
	printf("%c", '+');
	printf(" %d ", b);
	printf(" = %d\n", c);
}

int main()
{
	int a = 1;
	int b = 1;
	int c = 0;
	c = addiere(a, b, PLUS);
	gibAus(a, b, PLUS, c);
}
