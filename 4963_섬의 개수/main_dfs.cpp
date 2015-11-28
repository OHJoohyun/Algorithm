#include <stdio.h>
#include <string.h>

int M, N;
int map[50][50];

int Dy[8] = { -1,1,0,0,-1,1,-1,1 };
int Dx[8] = { 0,0,-1,1,1,-1,-1,1 };

void dfs(int row, int col)
{
	int row_t, col_t;
	int i;

	for (i = 0; i < 8; i++)
	{
		row_t = row + Dy[i];
		col_t = col + Dx[i];
		if (row_t >= 0 && row_t < N && col_t >= 0 && col_t < M)
		{
			if (map[row_t][col_t] == 1)
			{
				map[row_t][col_t] = 0;
				dfs(row_t, col_t);
			}
		}
	}
}

int main()
{
	int i, j;
	int count;
	while (1)
	{
		scanf("%d %d", &M, &N);
		if (M == 0 && N == 0) break;
		
		memset(map, 0, sizeof(map));
		count = 0;
		
		for (i = 0; i < N; i++)
		{
			for (j = 0; j < M; j++)
			{
				scanf("%d", &map[i][j]);
			}
		}

		for (i = 0; i < N; i++)
		{
			for (j = 0; j < M; j++)
			{
				if (map[i][j] == 1)
				{
					dfs(i, j);
					count++;
				}
			}
		}

		printf("%d\n", count);
	}
	return 0;
}