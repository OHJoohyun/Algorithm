#include <stdio.h>
#include <string.h>

int T;
int M, N, K;
int map[50][50];

typedef struct {
	int row;
	int col;
} _COODI;

_COODI cabbage[2500];

int Dy[4] = { -1, 0, 1, 0 };
int Dx[4] = { 0, -1, 0, 1 };

void bfs(int row, int col)
{
	int head, tail;
	int i;
	int row_t, col_t;
	head = 0;
	tail = 0;

	cabbage[tail].row = row;
	cabbage[tail].col = col;
	tail++;
	map[row][col] = 0;

	while (1)
	{
		if (head == tail) break;
		for (i = 0; i < 4; i++)
		{
			row_t = cabbage[head].row + Dy[i];
			col_t = cabbage[head].col + Dx[i];

			if (row_t >= 0 && row_t < N && col_t >= 0 && col_t < M)
			{
				if (map[row_t][col_t] == 1)
				{
					cabbage[tail].row = row_t;
					cabbage[tail].col = col_t;
					tail++;
					map[row_t][col_t] = 0;
				}
			}
		}
		head++;
	}
}
int main()
{
	int i, j;
	int a, b;
	int row, col;
	int anw ;
	scanf("%d", &T);

	for (i = 0; i < T; i++)
	{
		anw = 0;

		memset(map, 0, sizeof(map));

		scanf("%d %d %d", &M, &N, &K);
		for (j = 0; j < K; j++)
		{
			scanf("%d %d", &col, &row);
			map[row][col] = 1;
		}

		for (a = 0; a < N; a++)
		{
			for (b = 0; b < M; b++)
			{
				
				if(map[a][b] == 1)
				{ 
					bfs(a, b);
					anw++;
				}
			}

		}
		printf("%d\n", anw);
	}
}