#include <stdio.h>

int visit[100][100] = { 0 };
int map[100][100];
int check[100][100];

int Dy[4] = { -1,1,0,0 };
int Dx[4] = { 0,0,-1,1 };

int N, M;
int min = 999999;

void dfs(int row, int col, int count)
{
	int i, row_t, col_t;
	if (count > min) return;
	if (row == N - 1 && col == M - 1)
	{
		if (count < min)
			min = count;
		return;
	}
	
	if (count >= check[row][col]) return;
	
	check[row][col] = count;

	for (i = 0; i < 4; i++)
	{
		row_t = row + Dy[i];
		col_t = col + Dx[i];
		if (row_t >= 0 && row_t < N && col_t >= 0 && col_t < M)
		{
			if (visit[row_t][col_t] == 0 && map[row_t][col_t] == 1)
			{
				visit[row_t][col_t] = 1;
				dfs(row_t, col_t, count + 1);
				visit[row_t][col_t] = 0;
			}
		}
	}
}
int main()
{
	int i, j;
	scanf("%d %d", &N, &M);
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			scanf("%1d", &map[i][j]);
			check[i][j] = 999999;
		}
	}

	visit[0][0] = 1;
	dfs(0, 0, 1);

	printf("%d\n", min);
	return 0;
}