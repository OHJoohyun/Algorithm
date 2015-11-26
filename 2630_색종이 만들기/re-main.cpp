#include <stdio.h>

int N;
int map[128][128];

int blue, white;

void dfs(int row, int col, int size)
{
	int i, j;
	int check;
	
	if (size == 0) return;

	check = 0;

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
		//printf("size = %d\n", size);
		white++;
		return;
	}

	if (check == size * size)
	{
		//printf("size = %d\n", size);
		blue++;
		return;
	}

	dfs(row, col, size / 2);

	dfs(row + size / 2, col, size / 2);

	dfs(row, col + size / 2, size / 2);

	dfs(row + size / 2, col + size / 2, size / 2);

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
			scanf("%d", &map[i][j]);
		}
	}

	white = 0;
	blue = 0;

	dfs(0, 0, N);

	printf("%d\n", white);
	printf("%d\n", blue);
}