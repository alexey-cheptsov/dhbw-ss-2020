//Matrikelnummer:2089623//
# include <stdio.h>


enum Operations
{
	PLUS = 0,
	MINUS = 1,
	MULT = 2,
	DIV = 3
};

int perform_operation(int a, int b, int op)
{
	int c = 0;
	if (op == PLUS)
	c = a + b;                                   //Berechnung
	return c;
}

void ausgabe(int a, int b, int op, int c)
{
	if (op == PLUS)
	{
		printf("Result:");
		printf("%d ", a);
		printf("%c", '+');
		printf(" %d = %d", b, c);
	}
}

int main()
{
	int a = 1;
	int b = 1;
	int c = 0;
	
	c = perform_operation(a, b, PLUS);
	
	ausgabe(a, b, PLUS, c);
}
