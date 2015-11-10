#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	int row;
	int col;
} _COORDI;

_COORDI point[625];
char apart[25][25];

int Dy[4] = { 0, 0, -1, 1 };
int Dx[4] = { -1, 1, 0, 0 };

int N;

int compare(const void *first, const void *second)
{
	if (*(int*)first > *(int*)second)
		return 1;
	else if (*(int*)first < *(int*)second)
		return -1;
	else
		return 0;
}

int bfs(int row, int col)
{
	int head, tail;
	int i, j;
	int row_t, col_t;
	int count = 0;

	head = 0;
	tail = 0;
	point[tail].row = row;
	point[tail].col = col;
	tail++;

	apart[row][col] = '0';
	count = 1;

	while (1)
	{
		if (head == tail) break;

		for (i = 0; i < 4; i++)
		{
			row_t = point[head].row + Dy[i];
			col_t = point[head].col + Dx[i];
			if (row_t >= 0 && row_t < N && col_t >= 0 && col_t < N)
			{
				if (apart[row_t][col_t] == '1')
				{
					point[tail].row = row_t;
					point[tail].col = col_t;
					tail++;
					apart[row_t][col_t] = '0';
					count++;
				}
			}
		}
		head++;
	}

	return count;
}

int main()
{
	int i, j, k;
	int anw[625];
	scanf("%d", &N);
	
	for (i = 0; i < N; i++)
	{
		scanf("%s", apart[i]);
	}


	k = 0;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			if (apart[i][j] == '1')
			{
				anw[k] = bfs(i, j);
				k++;
			}
		}
	}

	qsort(anw, k, sizeof(int), compare);

	printf("%d\n", k);
	for (i = 0; i < k; i++)
	{
		printf("%d\n", anw[i]);
	}

	return 0;
}