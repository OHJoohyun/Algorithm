#include <stdio.h>

int map[101][101] = { 0 };
int check[101] = { 0 };

int N, K;
int count = 0;

void dfs(int virus)
{
	int i, j;

	check[virus] = 1;

	for (i = 1; i <= N; i++)
	{
		if (map[virus][i] == 1 && check[i] == 0)
		{
			count++;
			dfs(i);
		}
	}
}
int main()
{
	int i;
	int row, col;

	scanf("%d", &N);
	scanf("%d", &K);
	for (i = 0; i < K; i++)
	{
		scanf("%d %d", &row, &col);
		map[row][col] = 1;
		map[col][row] = 1;
	}

	dfs(1);

	printf("%d\n", count);

	return 0;
}
