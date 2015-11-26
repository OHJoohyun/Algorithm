#include <stdio.h>

int map[64][64];
int N;

void dfs(int row, int col, int size)
{
	int i, j;
	int check = 0;
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			if (map[i + row][j + col] == 1)
			{
				check++;
			}
		}
	}

	if (check == 0)
	{
		printf("0");
		return;
	}

	if (check == size * size)
	{
		printf("1");
		return;
	}

	printf("(");
	dfs(row, col, size / 2);
	dfs(row, col + size / 2, size / 2);
	dfs(row + size / 2, col, size / 2);
	dfs(row + size / 2, col + size / 2, size / 2);
	printf(")");
	return;
}

int main()
{
	int i, j;
	scanf("%d", &N);
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			scanf("%1d", &map[i][j]);
		}
	}
	
	//printf("(");
	dfs(0, 0, N);
	//printf(")");
	printf("\n");
	return 0;
}