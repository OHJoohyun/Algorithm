#include <stdio.h>
#include <string.h>
typedef struct {
	int row;
	int col;
} _COORDI;

int cheese[100][100];
int visit[100][100];
_COORDI point[10000];

int Dy[4] = { 0, 0, -1, 1 };
int Dx[4] = { 1, -1, 0, 0 };

int N, M;

void air(int row, int col)
{
	int i, j;
	int head, tail;
	int row_t, col_t;

	head = 0;
	tail = 0;

	point[tail].row = row;
	point[tail].col = col;
	tail++;

	while (1)
	{
		if (head == tail) break;

		for (i = 0; i < 4; i++)
		{
			row_t = point[head].row + Dy[i];
			col_t = point[head].col + Dx[i];

			if (row_t >= 0 && row_t < N && col_t >= 0 && col_t < M)
			{
				if (cheese[row_t][col_t] == 0 && visit[row_t][col_t] == 0)
				{
					point[tail].row = row_t;
					point[tail].col = col_t;
					tail++;
					visit[row_t][col_t] = 2;
				}
			}
		}
		head++;
	}
	return;
}

void bfs(int row, int col)
{
	int i, j;
	int head, tail;
	int row_t, col_t;
	int count = 0;

	count = 0;
	
	for (i = 0; i < 4; i++)
	{
		row_t = row + Dy[i];
		col_t = col + Dx[i];
		
		if (row_t >= 0 && row_t < N && col_t >= 0 && col_t < M)
		{
			if (visit[row_t][col_t] == 2)
			{
				count++;
				if (count == 2)
				{
					cheese[row][col] = 0;
					return;
				}
			}
		}
	}

	return;
}

int main()
{
	int i, j;
	int res;
	int count = 0;
	scanf("%d %d", &N, &M);

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			scanf("%d", &cheese[i][j]);
		}
	}

	while (1)
	{
		res = 0;
	
		memmove(visit, cheese, sizeof(cheese));
		air(0, 0);

		for (i = 0; i < N; i++)
		{
			for (j = 0; j < M; j++)
			{
				if (cheese[i][j] == 1)
				{
					bfs(i, j);
					res = 1;
				}
			}
		}
		if (res == 0) break;
		count++;
		
	}
	printf("%d\n", count);
}

