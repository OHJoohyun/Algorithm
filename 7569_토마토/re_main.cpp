#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	int row;
	int col;
	int height;
	int day;
} _COORDI;

_COORDI point[1000000];

int map[100][100][100];

int Dy[6] = { -1,1,0,0,0,0 };
int Dx[6] = { 0,0,-1,1,0,0 };
int Dz[6] = { 0,0,0,0,-1,1 };

int N, M, H;

int head = 0, tail = 0;

int bfs()
{
	int i;
	int row_t, col_t, h_t;

	while (1)
	{
		if (head == tail) break;
		for (i = 0; i < 6; i++)
		{
			row_t = point[head].row + Dy[i];
			col_t = point[head].col + Dx[i];
			h_t = point[head].height + Dz[i];
			if (row_t >= 0 && row_t < N && col_t >= 0 && col_t < M && h_t >= 0 && h_t < H)
			{
				if (map[row_t][col_t][h_t] == 0)
				{
					map[row_t][col_t][h_t] = 1;
					point[tail].row = row_t;
					point[tail].col = col_t;
					point[tail].height = h_t;
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
	int i, j, h;
	int min;
	scanf("%d %d %d", &M, &N, &H);
	for (h = 0; h < H; h++)
	{
		for (i = 0; i < N; i++)
		{
			for (j = 0; j < M; j++)
			{
				scanf("%d", &map[i][j][h]);
				if (map[i][j][h] == 1)
				{
					point[tail].row = i;
					point[tail].col = j;
					point[tail].height = h;
					point[tail].day = 0;
					tail++;
				}
			}
		}
	}
	
	if (tail == 0)
	{
		printf("-1\n");
		return 0;
	}
	if (tail == N*M*H)
	{
		printf("0\n");
		return 0;
	}

	min = bfs();

	int find = 0;

	for (h = 0; h < H; h++)
	{
		for (i = 0; i < N; i++)
		{
			for (j = 0; j < M; j++)
			{
				if (map[i][j][h] == 0)
					find = 1;
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