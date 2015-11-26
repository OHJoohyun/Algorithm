#include <stdio.h>
#include <string.h>

int path[801][801];
int check[801] = { 0 };

int N, E;
int fisrt, second;
int min = 999999;

void dfs(int row, int value, int special)
{
	int i;

	if (row == N)
	{
		//printf("%d\n", value);
		if (special == 2)
		{
			if (min > value)
				min = value;
			//printf("Áö³ª°¨: %d\n", value);
		}
		return;
	}

	for (i = row + 1; i <= N; i++)
	{
		if (path[row][i] > 0)
		{
			if (i == fisrt || i == second)
				dfs(i, value + path[row][i], special + 1);
			else
				dfs(i, value + path[row][i], special);
		}
	}
	return;
}

int main()
{
	int i, j;
	int row, col, weight;
	scanf("%d %d", &N, &E);

	for (i = 0; i < E; i++)
	{
		scanf("%d %d %d", &row, &col, &weight);
		path[row][col] = weight;
		path[col][row] = weight;
	}

	scanf("%d %d", &fisrt, &second);

	/*
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= N; j++)
		{
			printf("%d ", path[i][j]);
		}
		printf("\n");
	}
	*/

	check[1] = 1;

	for (i = 1; i <= N; i++)
	{
		if(path[1][i] > 0)
		{ 
			if (i == fisrt || i == second)
				dfs(i, path[1][i], 1);
			else
				dfs(i, path[1][i], 0);
		}
	}

	if (min == 999999) printf("-1\n");
	else
	{
		printf("%d\n", min);
	}
	return 0;
}