#include <stdio.h>

int N, K;
int com[101][101] = { 0 };
int virus[100] = { 0 };

void dfs(int row)
{
	int i;

	for (i = 1; i <= N; i++)
	{
		if (com[row][i] == 1)
		{
			if(virus[i] == 0)
			{ 
				virus[i] = 1;
				dfs(i);
			}
		}
	}
}

int main()
{
	int i, j;
	int row, col;
	int top = 0;

	scanf("%d %d", &N, &K);
	for (i = 0; i < K; i++)
	{
		scanf("%d %d", &row, &col);
		com[row][col] = 1;
		com[col][row] = 1;
	}

	virus[1] = 1;
	for (i = 1; i <= N; i++)
	{
		if (com[1][i] == 1)
		{
			virus[i] = 1;
			dfs(i);
		}
	}

	int sum = 0;
	for (i = 2; i <= N; i++)
	{
		if (virus[i] == 1)
			sum++;
	}
	printf("%d\n", sum);
}