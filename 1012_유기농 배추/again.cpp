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
	int i, j;
	int row_t, col_t;

	head = 0;
	tail = 0;
	cabbage[tail].row = row;
	cabbage[tail].col = col;
	tail++;

	while (1)
	{
		if (head == tail) break;
		
		for (i = 0; i < 4; i++)
		{
			row_t = cabbage[head].row + Dy[i];
			col_t = cabbage[head].col + Dx[i];

			if (row_t >= 0 && row_t < N&& col_t >= 0 && col_t < M)
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

	return;
}

int main()
{
	int T, test_case;
	scanf("%d", &T);

	for (test_case = 0; test_case < T; test_case++)
	{
		int i, j;
		int row, col;
		int count = 0;
		scanf("%d %d %d", &M, &N, &K);
		memset(map, 0, sizeof(map));
		for (i = 0; i < K; i++)
		{
			scanf("%d %d", &col, &row);
			map[row][col] = 1;
		}

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