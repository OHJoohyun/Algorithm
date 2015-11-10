#include <stdio.h>

int array[129][129];
int N;
int white;;
int blue;

void dfs(int row, int col, int size)
{
	int i;
	int j;
	int check;

	check = 0;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			if (array[row + i][col +j] == 1)
			{
				check++;
			}
		}
	}

	if (check == 0)
	{
		white++; 
		return;
	}
	if (check == size*size)
	{
		blue++; 
		return;
	}

	dfs(row, col, size / 2);
	dfs(row + size / 2, col, size / 2);
	dfs(row, col + size / 2, size / 2);
	dfs(row + size / 2, col + size / 2, size / 2);
}

int main()
{
	int i, j;
	scanf("%d", &N);
	
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			scanf("%d", &array[i][j]);
		}
	}

	white = 0;
	blue = 0;

	dfs(0, 0, N);

	printf("%d\n", white);
	printf("%d\n", blue);

	return 0;
}