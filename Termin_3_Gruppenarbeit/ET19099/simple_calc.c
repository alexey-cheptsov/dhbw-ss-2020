# include <stdio.h>


enum Operations
{
	PLUS = 0,
	MINUS = 1,
	MULT = 2,
	DIV = 3
};

int subtraction(int a, int b, int c)
{
	c = a - b;

	return c;
}

int addition(int a, int b, int c)
{
	c = a + b;

	return c;
}

int multiplikation(int a, int b, int c)
{
	c = a * b;

	return c;
}

int division(int a, int b, int c)
{
	c = a / b;

	return c;
}


int perform_operation(int a, int b, int op)
{
	int c=0;
	switch(op)
	{
		case 1: c = subtraction(a, b, c);
				break;
		case 0: c = addition(a, b, c);
				break;
		case 2: c = multiplikation(a, b, c);
				break;
		case 3: c = division(a, b, c);
				break;
		default: printf("Falsche Eingabe");
				break;
	}
		return c;

}

void ausgabe(int a, int b, int op, int c)
{

	printf("Result: ");
	printf("%d ", a);
	if (op == MINUS)
		printf("%c", '-');
	if (op == PLUS)
		printf("%c", '+');
	if (op == MULT)
		printf("%c", '*');
	if (op == DIV)
		printf("%c", '/');
	printf(" %d ", b);
	printf(" = %d\n", c);
}

int main()
{
	int a = 1;
	int b = 1;
	int c = 0;
	c = perform_operation(a, b, PLUS);
	ausgabe(a, b, PLUS, c);
  return 0;
}
