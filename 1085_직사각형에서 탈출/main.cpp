#include <stdio.h>

int map[1010][1010] = { 0 };
int row, col, M, N;

typedef struct {
	int row;
	int col;
} _MAP;

_MAP queue[1020100];

int Dy[4] = { -1, 1, 0 ,0 };
int Dx[4] = { 0, 0, -1, 1 };

int min = 999999;
int result;

// row_t <= 0 || row_t >= N || col_t <= 0 || col_t >= M

void bfs(int row, int col)
{
	int head, tail;
	int i;
	int row_t, col_t;
	 
	head = 0;
	tail = 0;

	queue[tail].row = row;
	queue[tail].col = col;
	tail++;

	while (1)
	{
		if (head == tail) break;

		for (i = 0; i < 4; i++)
		{
			row_t = queue[head].row + Dy[i];
			col_t = queue[head].col + Dx[i];
			if(map[row_t][col_t] == 0)
			{ 
				if (row_t >= 0 && row_t <= N && col_t >= 0 && col_t <= M)
				{
					queue[tail].row = row_t;
					queue[tail].col = col_t;
					tail++;
					map[row_t][col_t] = map[queue[head].row][queue[head].col] + 1;
				}
			}

			if (row_t <= 0 || row_t >= N || col_t <= 0 || col_t >= M)
			{
				result = map[queue[head].row][queue[head].col] + 1;
				if (min > result)
					min = result;
			}
		}
		head++;
	}
}

int main()
{
	int i, j;
	scanf("%d %d %d %d", &col, &row, &M, &N);

	map[row][col] = 1;

	bfs(row, col);

	printf("%d\n", min - 1);
}