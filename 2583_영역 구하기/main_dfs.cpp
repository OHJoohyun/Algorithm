#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int map[100][100] = { 0 };
int visit[100][100] = { 0 };
int anw[10000];

int N, M, K;

int count;

int Dy[4] = { -1,1,0,0 };
int Dx[4] = { 0,0,-1,1 };

int compare(const void *a, const void *b)
{
	if (*(int*)a > *(int*)b) return 1;
	else if (*(int*)a == *(int*)b) return 0;
	else return -1;
}

int dfs(int row, int col)
{
	int row_t, col_t;
	int i;
	visit[row][col] = 1;
	map[row][col] = 1;
	for (i = 0; i < 4; i++)
	{
		row_t = row + Dy[i];
		col_t = col + Dx[i];
		if (row_t >= 0 && row_t < N&&col_t >= 0 && col_t < M)
		{
			if (map[row_t][col_t] == 0 && visit[row_t][col_t] == 0)
			{
				dfs(row_t, col_t);
				count++;
			}
		}
	}

	return count;
}


int main()
{
	int i,j;
	int a, b;
	int s_col, s_row, e_col, e_row;
	int res;

	scanf("%d %d %d", &N, &M, &K);
	for (i = 0; i < K; i++)
	{
		scanf("%d %d %d %d", &s_col, &s_row, &e_col, &e_row);
		for (a = s_row; a < e_row; a++)
		{
			for (b = s_col; b < e_col; b++)
			{
				map[a][b] = 1;
			}
		}
	}

	int pos = 0;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			if (map[i][j] == 0)
			{
				count = 1;
				res = dfs(i, j);
				anw[pos] = res;
				pos++;
				//printf("%d\n", res);
			}
		}
	}
	
	qsort(anw, pos, sizeof(int), compare);

	printf("%d\n", pos);
	for (i = 0; i < pos; i++)
	{
		printf("%d ", anw[i]);
	}
	printf("\n");

	return 0;
}