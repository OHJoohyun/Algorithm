#include <stdio.h>


int N;
int tree[64][64];

void dfs(int row, int col, int size)
{
	int check;
	int i, j;

	//printf("row = %d\n", row);
	//printf("col = %d\n", col);
	//printf("size = %d\n\n", size);

	check = 0;
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			if (tree[i + row][j + col] == 1)
				check++;
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
}

int main()
{
	int i, j;

	scanf("%d", &N);

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			scanf("%1d", &tree[i][j]);
		}
	}

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			printf("%d ", tree[i][j]);
		}
		printf("\n");
	}

	dfs(0, 0, N);

	return 0;
}