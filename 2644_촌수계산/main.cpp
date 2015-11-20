#include <stdio.h>

int family[101][101] = { 0 };
int check[101] = { 0 };
int N, start, end, M;
int result = 0;

void show()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			printf("%d ", family[i][j]);
		}
		printf("\n");
	}
}

void dfs(int index, int count)
{
	//printf("index = %d\n", index);
	if (index == end)
	{
		result = count;
		return;
	}

	for (int i = 1; i <= N; i++)
	{
		if (check[i] == 0 && family[index][i] == 1)
		{ 
			check[i] = 1;
			dfs(i, count + 1);
			check[i] = 0;
		}
	}
	return;
}

int main()
{
	int i, fisrt, second;
	scanf("%d", &N);
	scanf("%d %d", &start, &end);
	scanf("%d", &M);
	for (i = 0; i < M; i++)
	{
		scanf("%d %d", &fisrt, &second);
		family[fisrt][second] = family[second][fisrt] = 1;
	}
	
	//show();

	for (i = 1; i <= N; i++)
	{
		if (family[start][i] == 1 && check[start] == 0)
		{
			check[i] = 1;
			dfs(i, 1);
			check[i] = 0;
		}
	}

	if (result == 0)
		printf("-1\n");
	else
		printf("%d\n", result);

	return 0;
}