#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int row;
	int col;
	int count;
	char type;
} _COORDI;

_COORDI point[1000000];

char map[1000][1000];

int N, M;

int Dy[4] = { -1,1,0,0 };
int Dx[4] = { 0,0,-1,1 };

int head = 0, tail = 0;

int compare(const void*a, const void*b)
{
	char v1, v2;
	v1 = ((_COORDI *)a)->type;
	v2 = ((_COORDI *)b)->type;
	if (v1 < v2) return 1;
	else if (v1 == v2) return 0;
	else return -1;
}

int bfs()
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
				if (point[head].type == 'S')
				{
					if (map[row_t][col_t] == 'D')
					{
						return point[head].count + 1;
					}
					
					if (map[row_t][col_t] == '.')
					{
						map[row_t][col_t] = 'S';
						point[tail].row = row_t;
						point[tail].col = col_t;
						point[tail].count = point[head].count + 1;
						point[tail].type = point[head].type;
						tail++;
					}
				}
				else if (point[head].type == '*')
				{
					if (map[row_t][col_t] != 'X' && map[row_t][col_t] != 'D')
					{
						map[row_t][col_t] = '*';
						point[tail].row = row_t;
						point[tail].col = col_t;
						point[tail].count = 0;
						point[tail].type = point[head].type;
						tail++;
					}
				}
			}

		}
		head++;
	}
	return 0;
}

int main()
{
	int i, j;
	char tmp;
	scanf("%d %d", &N, &M);

	memset(map, 0, sizeof(map));
	memset(point, 0, sizeof(point));

	for (i = 0; i < N; i++)
	{
		scanf("%s", map[i]);
	}

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			if (map[i][j] == 'S')
			{
				point[tail].row = i;
				point[tail].col = j;
				point[tail].count = 0;
				point[tail].type = map[i][j];
				tail++;
			}
		}
	}

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			if (map[i][j] == '*')
			{
				point[tail].row = i;
				point[tail].col = j;
				point[tail].count = 0;
				point[tail].type = map[i][j];
				tail++;
			}
		}
	}

	int res = bfs();
	if (res != 0)
	{
		printf("%d\n", res);
	}
	else
	{
		printf("impossible\n");
	}
	return 0;
}