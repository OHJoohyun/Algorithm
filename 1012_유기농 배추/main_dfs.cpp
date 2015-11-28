#include <stdio.h>

int map[50][50] = { 0 };
int visit[50][50] = { 0 };
int check[50][50] = { 0 };

int N, M, K;
int T;

int Dy[4] = { -1,1,0,0 };
int Dx[4] = { 0,0,-1,1 };

void dfs(int row, int col)
{
	int i, j;
	int row_t, col_t;

	map[row][col] = 0;

	for (i = 0; i < 4; i++)
	{
		row_t = row + Dy[i];
		col_t = col + Dx[i];
		if (row_t >= 0 && row_t < N && col_t >= 0 && col_t < M)
		{
			if (map[row_t][col_t] == 1)
			{
				dfs(row_t, col_t);
			}
		}
	}
	return;
}

int main()
{
	int i, j, count = 0;
	int row, col;
	int t_case;
	scanf("%d", &T);
	for (t_case = 0; t_case < T; t_case++)
	{
		count = 0;
		scanf("%d %d %d", &M, &N, &K);
		for (i = 0; i < K; i++)
		{
			scanf("%d %d", &col, &row);
			map[row][col] = 1;
		}


		for (i = 0; i < N; i++)
		{
			for (j = 0; j < M; j++)
			{
				if (map[i][j] == 1)
				{
					count++;
					dfs(i, j);
				}
			}
		}

		printf("%d\n", count);
	}
	return 0;
}