#include <stdio.h>
#include <string.h>

int H, W;
int map[50][50];
int count;

typedef struct {
	int row;
	int col;
} COODI;

COODI point[2500];

int Dy[8] = { -1, 0, 1, 0, -1, -1, 1, 1};
int Dx[8] = { 0, -1, 0, 1, -1, 1, -1, 1};

void bfs(int row, int col)
{
	int head, tail;
	int i, j;
	int row_t, col_t;

	head = 0;
	tail = 0;
	point[tail].row = row;
	point[tail].col = col;
	tail++;

	//memset(point, 0, sizeof(point));


	while (1)
	{
		if (head == tail) break;

		for (i = 0; i < 8; i++)
		{
			row_t = point[head].row + Dy[i];
			col_t = point[head].col + Dx[i];
			//printf("row = %d\n", row_t);
			//printf("col = %d\n", col_t);
			if (row_t >= 0 && row_t < H && col_t >= 0 && col_t < W)
			{
				if (map[row_t][col_t] == 1)
				{
					point[tail].row = row_t;
					point[tail].col = col_t;
					tail++;
					map[row_t][col_t] = 0;
				}
			}
		}
		head++;
	}

	count++;

}

int main()
{
	int i, j;

	while(1)
	{ 
		count = 0;
		memset(map, -1, sizeof(map));
		scanf("%d %d", &W, &H);

		if (W == 0 && H == 0) break;

		for (i = 0; i < H; i++)
		{
			for (j = 0; j < W; j++)
			{
				scanf("%d", &map[i][j]);
			}
		}
		for (i = 0; i < H; i++)
		{
			for (j = 0; j < W; j++)
			{
				if (map[i][j] == 1)
				{
					bfs(i, j);
				}
			}
		}
		printf("%d\n", count);
	}
}