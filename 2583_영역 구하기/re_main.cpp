#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int row;
	int col;
} _COORDI;

_COORDI point[10000];

int map[100][100] = { 0 };
int anw[10000];

int Dy[4] = { -1,1,0,0 };
int Dx[4] = { 0,0,-1,1 };

int N, M, K;

void show()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
}

int compare(const void *a, const void *b)
{
	if (*(int*)a > *(int*)b) return 1;
	else if (*(int*)a == *(int*)b) return 0;
	else return -1;
}

int bfs(int row, int col)
{
	int i, j;
	int head, tail;
	int row_t, col_t;
	int count = 1;

	tail = 0;
	head = 0;
	point[tail].row = row;
	point[tail].col = col;
	tail++;
	map[row][col] = 1;

	while (1)
	{
		if (head == tail) break;

		for (i = 0; i < 4; i++)
		{
			row_t = point[head].row + Dy[i];
			col_t = point[head].col + Dx[i];
			if (row_t >= 0 && row_t < N && col_t >= 0 && col_t < M)
			{
				if (map[row_t][col_t] == 0)
				{
					map[row_t][col_t] = 1;
					point[tail].row = row_t;
					point[tail].col = col_t;
					tail++;
					count++;
				}
			}
		}
		head++;
	}

	//printf("%d\n", count);

	return count;
}

int main()
{
	int i, j, a, b, count;
	int s_row, s_col, e_row, e_col;
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

	//show();

	count = 0;

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			if (map[i][j] == 0)
			{
				anw[count] = bfs(i, j);
				count++;
			}
		}
	}

	qsort(anw, count, sizeof(int), compare);

	printf("%d\n", count);
	for (i = 0; i < count; i++)
	{
		printf("%d ", anw[i]);
	}
	printf("\n");

	return 0;
}