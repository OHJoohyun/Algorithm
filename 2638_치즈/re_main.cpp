#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int row;
	int col;
} _COORDI;

_COORDI point[10000];

int map[100][100];
int visit[100][100];

int N, M;
int Dy[4] = { -1,1,0,0 };
int Dx[4] = { 0,0,-1,1 };

void air(int row, int col)
{
	int i;
	int row_t, col_t;
	int head, tail;

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
	int count = 0;
	int i;
	int row_t, col_t;
	
	for (i = 0; i < 4; i++)
	{
		row_t = row + Dy[i];
		col_t = col + Dx[i];
		if (row_t >= 0 && row_t < N && col_t >= 0 && col_t < M)
		{
			if (visit[row_t][col_t] == 2)
			{
				count++;
			}
		}
	}
	if (count >= 2)
	{
		map[row][col] = 0;
	}
}
int main()
{
	int i, j, count = 0;
	int find;
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
		find = 0;
		for (i = 0; i < N; i++)
		{
			for (j = 0; j < M; j++)
			{
				if (map[i][j] == 1)
				{
					find = 1;
				}
			}
		}
		if (find == 0) break;
	}

	printf("%d\n", count);
	return 0;
}