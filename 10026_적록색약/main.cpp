#include <stdio.h>
#include <string.h>

typedef struct {
	int row;
	int col;
	char color;
} _COORDI;

_COORDI point[10201];

char map[101][101];
char visit[101][101];

int N;

int Dy[4] = { -1, 1,0,0 };
int Dx[4] = { 0,0,-1,1 };

void bfs1(int row, int col, int color)
{
	int head, tail;
	int i;
	int row_t, col_t;

	head = 0;
	tail = 0;
	point[tail].row = row;
	point[tail].col = col;
	point[tail].color = color;
	tail++;

	while (1)
	{
		if (head == tail) break;

		for (i = 0; i < 4; i++)
		{
			row_t = point[head].row + Dy[i];
			col_t = point[head].col + Dx[i];
			if (row_t >= 0 && row_t < N && col_t >= 0 && col_t < N)
			{
				if (visit[row_t][col_t] == color)
				{
					visit[row_t][col_t] = 'Z';
					point[tail].row = row_t;
					point[tail].col = col_t;
					point[tail].color = color;
					tail++;
				}
			}
		}

		head++;
	}
	return;
}

void bfs2(int row, int col, int color)
{
	int head, tail;
	int i;
	int row_t, col_t;

	head = 0;
	tail = 0;
	point[tail].row = row;
	point[tail].col = col;
	point[tail].color = color;
	tail++;

	while (1)
	{
		if (head == tail) break;

		for (i = 0; i < 4; i++)
		{
			row_t = point[head].row + Dy[i];
			col_t = point[head].col + Dx[i];
			if (row_t >= 0 && row_t < N && col_t >= 0 && col_t < N)
			{
				if (color == 'R' || color == 'G')
				{
					if (visit[row_t][col_t] == 'R' || visit[row_t][col_t] == 'G')
					{
						visit[row_t][col_t] = 'Z';
						point[tail].row = row_t;
						point[tail].col = col_t;
						point[tail].color = color;
						tail++;
					}
				}
				else if (color == 'B')
				{
					if (visit[row_t][col_t] == 'B')
					{
						visit[row_t][col_t] = 'Z';
						point[tail].row = row_t;
						point[tail].col = col_t;
						point[tail].color = color;
						tail++;
					}
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
	int count1, count2;
	scanf("%d", &N);
	for (i = 0; i < N; i++)
	{
		scanf("%s", map[i]);
	}

	count1 = 0;
	count2 = 0;

	memset(visit, 0, sizeof(visit));
	memcpy(visit, map, sizeof(map));
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			if (visit[i][j] == 'R' || visit[i][j] == 'B' || visit[i][j] == 'G')
			{
				bfs1(i, j, visit[i][j]);
				count1++;
			}
		}
	}

	memset(visit, 0, sizeof(visit));
	memcpy(visit, map, sizeof(map));

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			if (visit[i][j] == 'R' || visit[i][j] == 'B' || visit[i][j] == 'G')
			{
				bfs2(i, j, visit[i][j]);
				count2++;
			}
		}
	}

	printf("%d %d\n", count1, count2);

	return 0;
}