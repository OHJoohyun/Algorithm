#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	int row;
	int col;
} _COORI;

_COORI point[10000];

int Dy[4] = { -1, 0, 1, 0 };
int Dx[4] = { 0, -1, 0, 1 };

int N, M, K;
int paper[100][100] = { 0 };
int visit[100][100] = { 0 };
int count[10000] = { 0 };

int compare(const void *a, const void *b)
{
	if (*(int*)a > *(int*)b)
		return 1;
	else if (*(int*)a < *(int*)b)
		return -1;
	else
		return 0;
}

int bfs(int row, int col)
{
	int i, j;
	int head, tail;
	int row_t, col_t;
	int count;

	count = 0;
	head = 0;
	tail = 0;
	point[tail].row = row;
	point[tail].col = col;
	tail++;
	count = 1;
	paper[row][col] = 1;

	while (1)
	{
		if (head == tail) break;
		for (i = 0; i < 4; i++)
		{
			row_t = point[head].row + Dy[i];
			col_t = point[head].col + Dx[i];
			if (row_t >= 0 && row_t < N && col_t >= 0 && col_t < M)
			{
				if (paper[row_t][col_t] == 0)
				{
					count++;
					point[tail].row = row_t;
					point[tail].col = col_t;
					tail++;
					paper[row_t][col_t] = 1;
				}
			}
		}
		head++;
	}
	//printf("%d ", count);
	return count;
}

int main()
{
	int i, j, a, b;
	int s_row, s_col, e_row, e_col;
	scanf("%d %d %d", &N, &M, &K);
	for (i = 0; i < K; i++)
	{
		scanf("%d %d %d %d", &s_col, &s_row, &e_col, &e_row);
		for (a = s_row; a < e_row; a++)
		{
			for (b = s_col; b < e_col; b++)
			{
				paper[a][b] = 1;
			}
		}
	}

	memmove(visit, paper, sizeof(paper));

	int k = 0;

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			if (paper[i][j] == 0)
			{
				count[k] = bfs(i, j);
				
				k++;
			}
		}
	}


	printf("%d\n", k);

	qsort(count, k, sizeof(int), compare);

	for (i = 0; i < k; i++)
	{
		printf("%d ", count[i]);
	}
	return 0;
	
}