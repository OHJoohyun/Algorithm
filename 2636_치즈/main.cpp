#include <stdio.h>
#include <string.h>

typedef struct {
	int row;
	int col;
} _COORDI;

int N, M;
int cheese[101][101];
int tmp[101][101];
int anw[1000];
int count = 0;

_COORDI point[10201];

int Dy[4] = { -1, 0, 1, 0 };
int Dx[4] = { 0, -1, 0, 1 };

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
				if (cheese[row_t][col_t] == 0 && tmp[row_t][col_t] == 0)
				{
					point[tail].row = row_t;
					point[tail].col = col_t;
					tail++;
					tmp[row_t][col_t] = 2;
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
	int row_t, col_t;

	for (i = 0; i < 4; i++)
	{
		row_t = row + Dy[i];
		col_t = col + Dx[i];

		if (row_t >= 0 && row_t < N && col_t >= 0 && col_t < M)
		{
			if (tmp[row_t][col_t] == 2)
			{
				cheese[row][col] = 0;
				break;
			}
		}
	}
	
	return;
}



int main()
{
	int i, j;
	int res = 9;

	scanf("%d %d", &N, &M);

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			scanf("%d", &cheese[i][j]);
		}
	}
	//memset(point, 0, sizeof(point));

	//air(0, 0);

	while (1)
	{
		res = 0;
		memmove(tmp, cheese, sizeof(cheese));
		air(0, 0);
		
		for (i = 0; i < N; i++)
		{
			for (j = 0; j < M; j++)
			{
				if (cheese[i][j] == 1)
				{
					anw[count] = anw[count] + 1;
					bfs(i, j);
					res = 1;
				}
			}
		}
		if (res == 0) break;
		count++;
		anw[count] = 0;
	}

	printf("%d\n", count);
	printf("%d\n", anw[count - 1]);
	
}