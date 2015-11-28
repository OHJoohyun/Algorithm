#include <stdio.h>

int map[50][50] = { 0 };
int visit[50][50] = { 0 };
int check[50][50] = { 0 };

int Dy[4] = { -1,1,0,0 };
int Dx[4] = { 0,0,-1,1 };

int N;
int min;

void dfs(int row, int col, int count)
{
	int i;
	int row_t, col_t;

	//printf("row = %d, col = %d\n", row, col);
	if (count > min) return;
	if (row == N - 1 && col == N - 1)
	{
		//printf("count = %d\n", count);
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
		if (row_t >= 0 && row_t < N && col_t >=0 && col_t<N)
		{ 
			if (visit[row_t][col_t] == 0 && map[row_t][col_t] == 1)
			{
				visit[row_t][col_t] = 1;
				dfs(row_t, col_t, count);
				visit[row_t][col_t] = 0;
			}
			if (visit[row_t][col_t] == 0 && map[row_t][col_t] == 0)
			{
				visit[row_t][col_t] = 1;
				dfs(row_t, col_t, count + 1);
				visit[row_t][col_t] = 0;
			}
		}
	}

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
			check[i][j] = 999999;
		}
	}

	min = 999999;
	
	visit[0][0] = 1;
	
	dfs(0, 0, 0);

	printf("%d\n", min);

	return 0;
}