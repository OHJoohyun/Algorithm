#include <stdio.h>
#include <string.h>

typedef struct {
	int row;
	int col;
} _MAZE;

_MAZE point[2500];
int maze[50][50];
int count[50][50];
int N;

int Dy[4] = { 0,0,-1,1 };
int Dx[4] = { -1,1, 0,0 };

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
		if (head == tail) return;
		
		if(maze[point[head].row][point[head].col == 1])
		{ 
			for (i = 0; i < 4; i++)
			{
				row_t = point[head].row + Dy[i];
				col_t = point[head].col + Dx[i];
				if (row_t >= 0 && row_t < N && col_t >= 0 && col_t < N)
				{
					if (count[row_t][col_t] < count[point[head].row][point[head].col])
						count[point[head].row][point[head].col] = count[row_t][col_t];
					point[tail].row = row_t;
					point[tail].col = col_t;
					tail++;
			
				}
			}
			head++;
		}
		else
		{
			for (i = 0; i < 4; i++)
			{
				row_t = point[head].row + Dy[i];
				col_t = point[head].col + Dx[i];
				if (row_t >= 0 && row_t < N && col_t >= 0 && col_t < N)
				{
					if (count[row_t][col_t] < count[point[head].row][point[head].col])
						count[point[head].row][point[head].col] = count[row_t][col_t] + 1;

				}
			}
		}
	
	}
}

int main()
{
	int i, j;
	scanf("%d", &N);

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			scanf("%1d", &maze[i][j]);
		}
	}

	memset(count, 0x1f, sizeof(count));
	count[0][0] = 0;
	
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			printf("%d ", maze[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	
	bfs(0, 0);
	
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			printf("%d ", count[i][j]);
		}
		printf("\n");
	}

	
	printf("%d\n", count[N - 1][N - 1]);

	return 0;

}