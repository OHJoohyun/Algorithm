#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	int row;
	int col;
} _COORDI;

_COORDI point[10000];

int map[100][100];
int visit[100][100];
int anwser[10000];

int Dy[4] = { -1,1,0,0 };
int Dx[4] = { 0,0,-1,1 };

int N, M;

void air(int row, int col)
{
	int head, tail;
	int i;
	int row_t, col_t;

	head = 0;
	tail = 0;
	point[tail].row = row;
	point[tail].col = col;
	tail++;
	visit[row][col] = 2;

	while (1)
	{
		if (head == tail) break;
		for (i = 0; i < 4; i++)
		{
			row_t = point[head].row + Dy[i];
			col_t = point[head].col + Dx[i];
			if (row_t >= 0 && row_t < N && col_t >= 0 && col_t < M)
			{
				if (visit[row_t][col_t] == 0)
				{
					visit[row_t][col_t] = 2;
					point[tail].row = row_t;
					point[tail].col = col_t;
					tail++;
				}
			}
		}
		head++;
	}
	return;
}

void bfs(int row, int col)
{
	int i;
	int row_t, col_t;

	int find = 0;

	for (i = 0; i < 4; i++)
	{
		row_t = row + Dy[i];
		col_t = col + Dx[i];
		if (row_t >= 0 && row_t < N && col_t >= 0 && col_t < M)
		{
			if (visit[row_t][col_t] == 2)
			{
				find = 1;
				break;
			}
		}
	}
	if (find == 1)
	{
		map[row][col] = 0;
	}
}
int main()
{
	int i, j;
	int count = 0;
	int cheese;
	scanf("%d %d", &N, &M);
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}

	while (1)
	{
		memset(point, 0, sizeof(point));
		memset(visit, 0, sizeof(visit));
		memcpy(visit, map, sizeof(map));

		air(0, 0);

		for (i = 0; i < N; i++)
		{
			for (j = 0; j < M; j++)
			{
				if (map[i][j] == 1)
				{
					bfs(i, j);
				}
			}
		}

		count++;
		cheese = 0;

		for (i = 0; i < N; i++)
		{
			for (j = 0; j < M; j++)
			{
				if (map[i][j] == 1)
				{
					cheese++;
				}
			}
		}
		if (cheese == 0) break;
		anwser[count] = cheese;
	}


	printf("%d\n", count);
	printf("%d\n", anwser[count - 1]);

	return 0;
}