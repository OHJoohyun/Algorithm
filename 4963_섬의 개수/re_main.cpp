#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	int row;
	int col;
} _COORDI;

_COORDI point[2500];

int map[50][50];

int Dy[8] = { 0,0,-1,1, -1, 1, -1, 1 };
int Dx[8] = { -1,1,0,0 , 1, -1, -1, 1};

int N, M;

void bfs(int row, int col)
{
	int head, tail;
	int i;
	int row_t, col_t;

	head = 0;
	tail = 0;
	point[tail].row = row;
	point[tail].col = col;
	tail++;

	map[row][col] = 0;

	while (1)
	{
		if (head == tail) break;
		for (i = 0; i < 8; i++)
		{
			row_t = point[head].row + Dy[i];
			col_t = point[head].col + Dx[i];
			if (row_t >= 0 && row_t < N && col_t >= 0 && col_t < M)
			{
				if (map[row_t][col_t] == 1)
				{
					map[row_t][col_t] = 0;
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

int main()
{
	int i, j;
	int count = 0;
	while (1)
	{
		memset(map, 0, sizeof(map));
		memset(point, 0, sizeof(point));

		scanf("%d %d", &M, &N);
		if (N == 0 && M == 0) break;
		for (i = 0; i < N; i++)
		{
			for (j = 0; j < M; j++)
			{
				scanf("%d", &map[i][j]);
			}
		}

		count = 0;

		for (i = 0; i < N; i++)
		{
			for (j = 0; j < M; j++)
			{
				if (map[i][j] == 1)
				{
					bfs(i, j);
					count++;
				}
			}
		}
		
		printf("%d\n", count);
	}

	return 0;
}