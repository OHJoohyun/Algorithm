#include <stdio.h>
#include <string.h>


typedef struct {
	int row;
	int col;
} _COORI;

int N, M;

int map[101][101];
int visited[101][101];
_COORI point[10201];

int Dy[4] = { -1, 0, 1, 0 };
int Dx[4] = { 0, -1, 0, 1 };

void bfs(int row, int col)
{
	int head, tail;
	int i, j, k;
	int row_t, col_t;

	head = 0;
	tail = 0;

	point[tail].row = row;
	point[tail].col = col;
	tail++;

	visited[row][col] = 1;

	while (1)
	{
		if (head == tail) break;
		for (i = 0; i < 4; i++)
		{
			row_t = point[head].row + Dy[i];
			col_t = point[head].col + Dx[i];

			if (row_t > 0 && row_t <= N && col_t > 0 && col_t <= M)
			{
				if (map[row_t][col_t] == 1 && visited[row_t][col_t] == -1)
				{
					point[tail].row = row_t;
					point[tail].col = col_t;
					tail++;
					visited[row_t][col_t] = visited[point[head].row][point[head].col] + 1;
				}
			}
		}
		head++;
	}

}

int main()
{
	int i, j, k;
	int tmp[101];
	scanf("%d %d", &N, &M);


	for (i = 1; i <= N; i++)
	{
		scanf("%d", &tmp[i]);
		for (j = M; j > 0; j--)
		{
			map[i][j] = tmp[i] % 10;
			tmp[i] = tmp[i] / 10;
		}
	}

	/*
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= M; j++)
		{
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
	*/
		
	memset(visited, -1, sizeof(visited));
	memset(point, -1, sizeof(point));

	bfs(1, 1);
	/*
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= M; j++)
		{
			printf("%d ", visited[i][j]);
		}
		printf("\n");
	}
	*/

	printf("%d\n", visited[N][M]);
}