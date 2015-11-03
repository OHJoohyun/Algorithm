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

	if (s > e)
	{
		for (j = s; j >= e; j--)
		{
			for (i = 1; i < 10; i=i+3)
			{
				printf("%d * %d = %2d", j, i, j*i);
				printf("%3s", " ");
				printf("%d * %d = %2d", j, i + 1, j*(i + 1));
				printf("%3s", " ");
				printf("%d * %d = %2d", j, i + 2, j*(i + 2));
				printf("\n");
			}
			printf("\n");
		}
	}
	else
	{
		for (j = s; j <= e; j++)
		{
			for (i = 1; i < 10; i = i + 3)
			{
				printf("%d * %d = %2d", j, i, j*i);
				printf("%3s", " ");
				printf("%d * %d = %2d", j, i + 1, j*(i + 1));
				printf("%3s", " ");
				printf("%d * %d = %2d", j, i + 2, j*(i + 2));
				printf("\n");
			}
			printf("\n");
		}
	}
}