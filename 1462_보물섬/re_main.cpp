#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	int row;
	int col;
} _COORDI;

_COORDI point[2500];

char map[50][50];
int visit[50][50];

int N, M;

int max = 0;

int Dy[4] = { 0,0,-1,1 };
int Dx[4] = { -1,1,0,0 };

int bfs(int row, int col)
{
	int i;
	int head, tail;
	int row_t, col_t;
	int count = 0;

	memset(visit, 0, sizeof(visit));
	memset(point, 0, sizeof(point));

	head = 0;
	tail = 0;

	point[tail].row = row;
	point[tail].col = col;
	tail++;
	visit[row][col] = 0;

	while (1)
	{
		if (head == tail) break;
		for (i = 0; i < 4; i++)
		{
			row_t = point[head].row + Dy[i];
			col_t = point[head].col + Dx[i];
			if (row_t >= 0 && row_t < N && col_t >= 0 && col_t < M)
			{
				if (map[row_t][col_t] == 'L' && visit[row_t][col_t] == 0)
				{
					point[tail].row = row_t;
					point[tail].col = col_t;
					tail++;
					visit[row_t][col_t] = visit[point[head].row][point[head].col] + 1;
					if (count < visit[row_t][col_t])
						count = visit[row_t][col_t];
				}
			}
		}
		head++;
	}

	return count;
}

int main()
{
	int i, j;
	int tmp;
	scanf("%d %d", &N, &M);
	
	for (i = 0; i < N; i++)
	{
		scanf("%s", map[i]);
	}

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			if (map[i][j] == 'L')
			{
				//printf("¿¹~\n");
				tmp = bfs(i, j);
				if (tmp > max)
					max = tmp;
			}
		}
	}

	printf("%d\n", max);
}