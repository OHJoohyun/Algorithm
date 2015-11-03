#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int row;
	int col;
	int count;
} _TOMATO;

_TOMATO tomato[1000000];

int Dy[4] = { -1, 0, 1, 0 };
int Dx[4] = { 0, -1, 0, 1 };

int main()
{
	int N, M;
	int **box;
	int i, j, k;
	int head = 0,  tail = 0;
	int count;
	int row, col;

	scanf("%d %d", &M, &N);

	box = (int**)malloc(sizeof(int*) * N);
	for (i = 0; i < N; i++) 
	{
		box[i] = (int*)malloc(sizeof(int) * M);
	}
	
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			scanf("%d", &box[i][j]);
			if (box[i][j] == 1)
			{
				tomato[tail].row = i;
				tomato[tail].col = j;
				tomato[tail].count = 0;
				tail++;
			}
		}
	}

	//printf("%d\n", tomato[0].row);
	//printf("%d\n", tomato[0].col);
	//printf("%d\n", tomato[0].count);
	//printf("%d\n", tail);
	k = -1; // ť index
	count = 0;

	while (1)
	{
		if (head == tail) break;
		//count = tomato[k].count + 1;
		for (i = 0; i < 4; i++)
		{
			row = tomato[head].row + Dy[i];
			col = tomato[head].col + Dx[i];
			if (row >= 0 && row < N && col >= 0 && col < M && box[row][col] == 0)
			{
				box[row][col] = 1;
				tomato[tail].row = row;
				tomato[tail].col = col;
				tomato[tail].count = tomato[head].count + 1;
				tail++;
			}
		}
		head++;
	}
	
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			if (box[i][j] == 0)
				head = 0;
		}
	}

	if (head == 0)
	{
		printf("-1\n");
	}
	else 
	{
		printf("%d\n", tomato[tail - 1].count);
	}
	return 0;





}