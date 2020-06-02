#include <stdio.h>														
#include <stdlib.h>			
#include <math.h>
#include <string.h>	

	
int main()
{
	int array_basis [3][5] = {{ 0, 1, 2, 3, 4},{ 5, 6, 7, 8, 9},{10,11,12,13,14}};
	int array_result[15];
	int j = 0;
	for(int x=0; x < 3; x++)
	{
		for(int i=0; i < 5;i++)
		{
			printf("%d ",array_basis[x][i]);
			array_result[j] = array_basis[x][i];
			j++;
		}
		printf("\n");
	}
	int u = 0;
	for(int y=0;y <15;y++)
	{
		printf("%d ",array_result[y]);
		u++;
		if(u==5)
		{
			printf("\n");
		}
		if(u==10)
		{
			printf("\n");
		}
		if(u==15)
		{
			printf("\n");
		}
	}
}
