#include <stdio.h>
#include <string.h>

typedef struct {
	int row;
	int col;
} _COORDI;

int N, M;
int mount[300][300];
int visit[300][300];
int tmp[300][300];
int count = 0;
int year = 0;

_COORDI point[90000];

int Dy[4] = { -1, 0, 1, 0 };
int Dx[4] = { 0, -1, 0, 1 };

void mount_count(int row, int col) // 빙산 수 확인,
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

		visit[point[head].row][point[head].col] = 0;
		for (i = 0; i < 4; i++)
		{
			row_t = point[head].row + Dy[i];
			col_t = point[head].col + Dx[i];

			if (row_t >= 0 && row_t < N && col_t >= 0 && col_t < M)
			{
				if (visit[row_t][col_t] > 0)
				{
					point[tail].row = row_t;
					point[tail].col = col_t;
					tail++;
					visit[row_t][col_t] = 0;
				}
			}
		}
		head++;
	}

	return;
}

void bfs(int row, int col) // 녹는 중,
{
	int i, j;
	int row_t, col_t;

	for (i = 0; i < 4; i++)
	{
		row_t = row + Dy[i];
		col_t = col + Dx[i];

		if (row_t >= 0 && row_t < N && col_t >= 0 && col_t < M)
		{
			if (tmp[row_t][col_t] == 0)
			{
				mount[row][col] -= 1;
				if (mount[row][col] < 0)
					mount[row][col] = 0;
			}
		}
	}

	return;
}

int main()
{
	int i, j;
	int res = 0;

	scanf("%d %d", &N, &M);
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			scanf("%d", &mount[i][j]);
		}
	}

	while (1)
	{
		memmove(visit, mount, sizeof(mount));
		memmove(tmp, mount, sizeof(mount));

		count = 0;

		for (i = 0; i < N; i++)
		{
			for (j = 0; j < M; j++)
			{
				if (visit[i][j] > 0)
				{
					//printf("몇ㅂㄴ?\n");
					mount_count(i, j);
					count++;
				}
			}
		}

		if (count >= 2) break; // break로 변경,

		res = 0;

		for (i = 0; i < N; i++)
		{
			for (j = 0; j < M; j++)
			{
				if (tmp[i][j] != 0)
				{
					bfs(i, j);
					res = 1;
				}
			}
		}
		if (res == 0) break;
		year++;
	}

	/*
	printf("\n");
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			printf("%d ", visit[i][j]);
		}
		printf("\n");
	}
	
	printf("%d\n", count);
	*/

	if (res == 0) printf("0\n");
	else printf("%d\n", year);
}