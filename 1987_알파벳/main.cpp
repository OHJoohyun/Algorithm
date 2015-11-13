#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//65 - 90
typedef struct {
	int row;
	int col;
} _COORDI;

_COORDI point[400];

int Dy[4] = { 0,0,-1,1 };
int Dx[4] = { -1, 1, 0,0 };

int R, C;
char board[21][21];
int visit[21][21];
int check[100] = { 0 };
int count = 0;
int max = 0;



void bfs(int row, int col)
{
	int i, j;
	int head, tail;
	int row_t, col_t;

	check[(int)board[row][col]] = 1;

	head = 0;
	tail = 0;

	point[tail].row = row;
	point[tail].col = col;
	tail++;

	while (1)
	{
		if (head == tail) return;

		check[(int)board[point[head].row][point[head].col]] = 1;

		for (i = 0; i < 4; i++)
		{
			row_t = point[head].row + Dy[i];
			col_t = point[head].col + Dx[i];
			if (row_t >= 0 && row_t < R && col_t >= 0 && col_t < C)
			{
				if (check[(int)board[row_t][col_t]] == 0)
				{
					//check[(int)board[row_t][col_t]] = 1;
					visit[row_t][col_t] = visit[point[head].row][point[head].col] + 1;
					if (max < visit[row_t][col_t])
						max = visit[row_t][col_t];
					point[tail].row = row_t;
					point[tail].col = col_t;
					tail++;
				}
			}
		}
		head++;
	}
}

void dfs(int row, int col, int count)
{
	int i;
	int row_t, col_t;

	if (count > max)
		max = count;

	check[(int)board[row][col]] = 1;

	for (i = 0; i < 4; i++)
	{
		row_t = row + Dy[i];
		col_t = col + Dx[i];
		if (row_t >= 0 && row_t < R && col_t >= 0 && col_t < C)
		{
			if (check[(int)board[row_t][col_t]] == 0)
			{
				dfs(row_t, col_t, count + 1);
				check[(int)board[row_t][col_t]] = 0;
			}
		}
	}

	return;
}

int main()
{
	int i, j;
	scanf("%d %d", &R, &C);
	for (i = 0; i < R; i++)
	{
		scanf("%s", board[i]);
	}

	//memset(visit, 0, sizeof(visit));

	//visit[0][0] = 1;

	//bfs(0, 0);

	dfs(0, 0, 1);

	printf("%d\n", max);
}