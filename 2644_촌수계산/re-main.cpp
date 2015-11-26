#include <stdio.h>

int N, start, end, M;
int map[101][101] = { 0 };
int check[101] = { 0 };
int min = 999999;

void dfs(int depth, int value)
{
	if (value == end)
	{
		if (depth < min)
		{
			min = depth;
		}
		return;
	}

	for (int i = 1; i <= N; i++)
	{
		if (map[value][i] == 1 && check[i] == 0)
		{
			check[i] = 1;
			dfs(depth + 1, i);
			check[i] = 0;
		}
	}
	
	return;
}

int main()
{
	int x, y;
	scanf("%d", &N);
	scanf("%d %d", &start, &end);
	scanf("%d", &M);
	int i, j;
	for (i = 0; i < M; i++)
	{
		scanf("%d %d", &x, &y);
		map[x][y] = 1;
		map[y][x] = 1;
	}


	for (i = 1; i <= N; i++)
	{
		if (map[start][i] == 1)
		{
			check[i] = 1;
			dfs(1, i);
			check[i] = 0;
		}
	}

	if (min == 999999)
	{
		printf("-1\n");
	}
	else
	{
		printf("%d\n", min);
	}

	return 0;

}