#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	int row;
	int col;
} _COORDI;

_COORDI point[20000];
char map[200][200];
int visit[200][200] = { 0 };

int N, M;

int Dy[4] = { -1,1,0,0 };
int Dx[4] = { 0,0,-1,1 };

void bfs(int row, int col)
{
	int i, j;
	int head, tail;
	int row_t, col_t;

	head = 0;
	tail = 0;
	
	point[tail].row = row;
	point[tail].col = col;
	tail++;

	visit[row][col] = 1;

	while (1)
	{
		if (head == tail) break;
		for (i = 0; i < 4; i++)
		{
			row_t = point[head].row + Dy[i];
			col_t = point[head].col + Dx[i];

			if (row_t >= 0 && row_t < N && col_t >= 0 && col_t < M)
			{
				if (map[row_t][col_t] == '1' && visit[row_t][col_t] == 0)
				{
					visit[row_t][col_t] = visit[point[head].row][point[head].col] + 1;
					point[tail].row = row_t;
					point[tail].col = col_t;
					tail++;
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
	scanf("%d %d", &N, &M);
	for (i = 0; i < N; i++)
	{
		scanf("%s", map[i]);
	}
	bfs(0, 0);

	printf("%d\n", visit[N - 1][M - 1]);
	return 0;
}