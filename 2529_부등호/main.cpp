#include <stdio.h>
#include <string.h>

int N;
char sign[20];
int number[10];
int anw[10];
int check = 0;

void max_dfs(int depth, int value)
{
	int i;
	if (depth == N + 1)
	{
		check = 1;
		return;
	}

	for (i = 9; i >= 0; i--)
	{
		if (check == 1) break;
		if (sign[depth*2] == '>')
		{
			//printf("들오왔다\n");
			if (value > i && number[i] == 0)
			{
				number[i] = 1;
				anw[depth] = i;
				max_dfs(depth + 1, i);
			}
		}
		else if (sign[depth*2] == '<')
		{
			//printf("들오왔다\n");
			if (value < i && number[i] == 0)
			{
				number[i] = 1;
				anw[depth] = i;
				max_dfs(depth + 1, i);
			}
		}
	}

	number[value] = 0;
	return;
}

void min_dfs(int depth, int value)
{
	int i;
	if (depth == N + 1)
	{
		check = 1;
		return;
	}

	for (i = 0; i <= 9; i++)
	{
		if (check == 1) break;
		if (sign[depth * 2] == '>')
		{
			//printf("들오왔다\n");
			if (value > i && number[i] == 0)
			{
				number[i] = 1;
				anw[depth] = i;
				min_dfs(depth + 1, i);
			}
		}
		else if (sign[depth * 2] == '<')
		{
			//printf("들오왔다\n");
			if (value < i && number[i] == 0)
			{
				number[i] = 1;
				anw[depth] = i;
				min_dfs(depth + 1, i);
			}
		}
	}

	number[value] = 0;
	return;
}

int main()
{
	int i;
	int max, min;
	
	memset(number, 0, sizeof(number));
	memset(anw, 0, sizeof(anw));

	scanf("%d", &N);
	for (i = 1; i <= N * 2; i++)
	{
		scanf("%c", &sign[i]);
	}


	for (max = 9; max >= 0; max--)
	{
		if (check == 1) break;
		number[max] = 1;
		anw[0] = max;
		max_dfs(1, max);
	}

	for (i = 0; i <= N; i++)
	{
		printf("%d", anw[i]);
	}

	printf("\n");

	check = 0;
	memset(number, 0, sizeof(number));
	memset(anw, 0, sizeof(anw));

	for (min = 0; min <= 9; min++)
	{
		if (check == 1) break;
		number[min] = 1;
		anw[0] = min;
		min_dfs(1, min);
	}

	for (i = 0; i <= N; i++)
	{
		printf("%d", anw[i]);
	}

	printf("\n");

	return 0;
}