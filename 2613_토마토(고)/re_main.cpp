#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int row;
	int col;
	int day;
} _COORDI;

_COORDI point[1000000];

int map[1000][1000];

int Dy[4] = { -1,1,0,0 };
int Dx[4] = { 0,0,-1,1 };

int N, M;

int head = 0, tail = 0;

int min = 0;

int bfs(int row, int col)
{
	int i;
	int row_t, col_t;

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
					point[tail].day = point[head].day + 1;
					tail++;
				}
			}
		}
		head++;
	}

	return point[head - 1].day;
}

int main()
{
	int i, j;
	scanf("%d %d", &M, &N);
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			scanf("%d", &map[i][j]);
			if (map[i][j] == 1)
			{
				point[tail].row = i;
				point[tail].col = j;
				point[tail].day = 0;
				tail++;
			}
		}
	}
	
	if (tail == 0)
	{
		printf("-1\n");
		return 0;
	}
	
	if (tail == N*M)
	{
		printf("0\n");
		return 0;
	}
	
	min = bfs(0, 0);

	int find = 0;

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			if (map[i][j] == 0)
			{
				find = 1;
				break;
			}
		}
	}

	if (find == 1)
	{
		printf("-1\n");
	}
	else
	{
		printf("%d\n", min);
	}

	return 0;
}