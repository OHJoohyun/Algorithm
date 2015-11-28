#include <stdio.h>
#include <string.h>

typedef struct {
	int row;
	int col;
} _COORDI;

_COORDI point[100000];

int Dy[4] = { -1,1,0,0 };
int Dx[4] = { 0,0,-1,1 };

int tmp[300][300];
int map[300][300];

int N, M;

void land(int row, int col)
{
	int row_t, col_t;
	int i, head, tail;
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
				if (tmp[row_t][col_t] > 0)
				{
					point[tail].row = row_t;
					point[tail].col = col_t;
					tail++;
					tmp[row_t][col_t] = 0;
				}
			}
		}
		head++;
	}
	return;
}

void bfs(int row, int col)
{
	int row_t, col_t;
	int i;
	
	for (i = 0; i < 4; i++)
	{
		row_t = row + Dy[i];
		col_t = col + Dx[i];
		if (row_t >= 0 && row_t < N && col_t >= 0 && col_t < M)
		{
			if (tmp[row_t][col_t] == 0)
			{
				map[row][col] = map[row][col] - 1;
				if (map[row][col] < 0)
					map[row][col] = 0;
			}
		}
	}

	return;
}

int main()
{
	int i, j;
	int land_count;
	int year;
	scanf("%d %d", &N, &M);
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}

	year = 0;
	while (1)
	{
		land_count = 0;
		memmove(tmp, map, sizeof(map));
		for (i = 0; i < N; i++)
		{
			for (j = 0; j < M; j++)
			{
				if (tmp[i][j] > 0)
				{
					land(i, j);
					land_count++;
				}
			}
		}

		if (land_count >= 2) // 2 덩이 이상 분리
		{
			printf("%d\n", year);
			return 0;
		}
		if (land_count == 0) // 분리 ㄴㄴ
		{
			printf("0\n");
			return 0;
		}
		
		memmove(tmp, map, sizeof(map));
		
		for (i = 0; i < N; i++)
		{
			for (j = 0; j < M; j++)
			{
				if (map[i][j] > 0)
				{
					bfs(i, j);
				}
			}
		}
		
		/*
		printf("\n");
		for (i = 0; i < N; i++)
		{
			for (j = 0; j < M; j++)
			{
				printf("%d ", map[i][j]);
			}
			printf("\n");
		}
		*/
		year++;
	}
	return 0;
}