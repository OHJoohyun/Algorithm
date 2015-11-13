#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int height[100] = { 0 };
int land[100][100];
int visit[100][100];
int N;

typedef struct {
	int row;
	int col;
} _RAIN;

_RAIN point[10000];

int Dy[4] = { 0,0,-1,1 };
int Dx[4] = { -1,1,0,0 };

int compare(const void *a, const void *b)
{
	if (*(int *)a < *(int *)b) return 1;
	else if (*(int *)a == *(int *)b) return 0;
	else return -1;
}

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

	while (1)
	{
		if (head == tail) break;

		for (i = 0; i < 4; i++)
		{
			row_t = point[head].row + Dy[i];
			col_t = point[head].col + Dx[i];

			if (row_t >= 0 && row_t < N && col_t >= 0 && col_t < N)
			{
				if (visit[row_t][col_t] != 0)
				{
					visit[row_t][col_t] = 0;
					point[tail].row = row_t;
					point[tail].col = col_t;
					tail++;
				}
			}
		}
		head++;
	}
}

int main()
{
	int i, j, k;
	int top = 0;
	int check = 0;
	int result;
	int max = 0;
	scanf("%d", &N);
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			check = 0;
			scanf("%d", &land[i][j]);
			if (top == 0)
			{
				height[top] = land[i][j];
				top++;
				continue;
			}
			
			for (k = 0; k < top; k++)
			{
				if (height[k] == land[i][j])
				{
					check = 1;
					break;
				}
			}

			if (check == 0)
			{
				height[top] = land[i][j];
				top++;
			}
		}
	}

	if (top == 1)
	{
		printf("1\n");
		return 0;
	}

	qsort(height, top, sizeof(int), compare);

	for (k = 0; k < top; k++)
	{
		memmove(visit, land, sizeof(land));
		result = 0;

		for (i = 0; i < N; i++)
		{
			for (j = 0; j < N; j++)
			{
				if (land[i][j] <= height[k])
					visit[i][j] = 0;
			}
		}


		/*
		for (i = 0; i < N; i++)
		{
			for (j = 0; j < N; j++)
			{
				printf("%d ", visit[i][j]);
			}
			printf("\n");
		}
		printf("\n");
		*/

		for (i = 0; i < N; i++)
		{
			for (j = 0; j < N; j++)
			{
				if (visit[i][j] != 0)
				{ 
					result++;
					bfs(i, j);
				}
			}
		}

		//printf("높이 = %d, 결과 = %d\n", height[k], result);
		if (max < result)
			max = result;
	}

	printf("%d\n", max);
	return 0;
}