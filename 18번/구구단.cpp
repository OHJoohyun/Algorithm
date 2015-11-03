#include <stdio.h>

void gugudan(int s, int e);

int main()
{
	int s, e;

	while (1) 
	{
		scanf_s("%d %d", &s, &e);
		if ((s < 2 || s > 9) || (e < 2 || e > 9))
		{
			printf("INPUT ERROR!\n");
		}
		else
		{
			gugudan(s, e);
			break;
		}
	}
}

void gugudan(int s, int e)
{
	int i, j;

	if(s > e)
	{ 
		for (i = 1; i < 10; i++)
		{
			for (j = s; j >= e; j--)
			{
				printf("%d * %d = %2d", j, i, j*i);
				printf("%3s", " ");
			}
			printf("\n");
		}
	}
	else
	{
		for (i = 1; i < 10; i++)
		{
			for (j = s; j <= e; j++)
			{
				printf("%d * %d = %2d", j, i, j*i);
				printf("%3s", " ");
			}
			printf("\n");
		}
	}
	
}