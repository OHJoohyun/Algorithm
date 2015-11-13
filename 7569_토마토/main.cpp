#include <stdio.h>
#include <string.h>

typedef struct {
	int row;
	int col;
	int height;
} _TOMATO;

_TOMATO point[1000000];

int Dy[6] = { 1,-1,0,0,0,0 };
int Dx[6] = { 0,0,1,-1,0,0 };
int Dz[6] = { 0,0,0,0,1,-1 };

int N, M, H;

int box[100][100][100];
int count[100][100][100];

int head = 0, tail = 0;

int main()
{
	int i, j, h;
	int row_t, col_t, h_t;
	int day = 0;
	int check = 0;

	memset(count, 0, sizeof(count));

	scanf("%d %d %d", &M, &N, &H);
	for (h = 0; h < H; h++)
	{
		for (i = 0; i < N; i++)
		{
			for (j = 0; j < M; j++)
			{
				scanf("%d", &box[i][j][h]);
				if (box[i][j][h] == 1)
				{
					point[tail].row = i;
					point[tail].col = j;
					point[tail].height = h;
					tail++;
					//day = 1;
				}
				else if (box[i][j][h] == 0)
				{
					check = 1;
				}
			}
		}
	}

	/*
	if (check == 0)
	{
		printf("0\n");
		return 0;
	}
	*/

	if (tail == 0)
	{
		printf("-1\n");
		return 0;
	}

	while (1)
	{
		if (head == tail) break;
		for (i = 0; i < 6; i++)
		{
			row_t = point[head].row + Dy[i];
			col_t = point[head].col + Dx[i];
			h_t = point[head].height + Dz[i];
			if (row_t >= 0 && row_t < N && col_t >= 0 && col_t < M && h_t >= 0 && h_t < H)
			{
				if (box[row_t][col_t][h_t] == 0 && count[row_t][col_t][h_t] == 0)
				{
					box[row_t][col_t][h_t] = 1;
					point[tail].row = row_t;
					point[tail].col = col_t;
					point[tail].height = h_t;
					tail++;
					
					count[row_t][col_t][h_t] = count[point[head].row][point[head].col][point[head].height] + 1;
					
					if (count[row_t][col_t][h_t] > day)
						day = count[row_t][col_t][h_t];
				}
			}
		}
		head++;
		//printf("?\n");
	}

	head = 0;
	for (h = 0; h < H; h++)
	{
		for (i = 0; i < N; i++)
		{
			for (j = 0; j < M; j++)
			{
				
				if (box[i][j][h] == 0)
				{
					head = 1;
					break;
				}
				
				//printf("%d ", count[i][j][h]);
			}
			//printf("\n");
		}
		//printf("\n");
	}

	if (head == 1)
	{
		printf("-1\n");
	}
	else
	{
		//printf("¿©±â?\n");
		printf("%d\n", day);
	}




	return 0;

}