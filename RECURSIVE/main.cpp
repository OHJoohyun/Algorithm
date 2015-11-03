#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void print(int depth, int value);

int dice[6];
int number;

int main()
{

	scanf("%d", &number);
	print(0, 0);
}

void print(int depth, int value)
{
	int i;
	dice[depth] = value;
	if (depth == number)
	{
		for (i = 1; i <= number; i++)
		{
			printf("%d ", dice[i]);
		}
		printf("\n");
	}
	else
	{
		for (i = 1; i <= 6; i++)
		{
			print(depth + 1, i);
		}
	}
}