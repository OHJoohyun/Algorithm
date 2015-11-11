#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int num;
	int row;
	int col;
	int h;
	int power;
} _VIRUS;

_VIRUS virus[250000];

int Dy[6] = { 1, -1 , 0, 0, 0, 0 };
int Dx[6] = { 0, 0, 1, -1, 0, 0 };
int Dz[6] = { 0, 0, 0, 0, 1, -1 };


int compare(const void *arg1, const void * arg2) {
	int v1, v2, v3, v4;
	v1 = ((_VIRUS *)arg1)->power;
	v2 = ((_VIRUS *)arg2)->power;

	if (v1 > v2) return -1;
	else if (v1 == v2) return 0;
	else return 1;
}

int main()
{
	int N, M;
	int box[50][50][50] = { {0}, {0}, {0} };
	int head, tail;
	int i, j, k;
	int row, col, height;
	int count[50] = { 0 };
	int max = 0;

	head = 0;
	tail = 0;

	scanf("%d %d", &N, &M);
	
	for (i = 0; i < M; i++)
	{
		scanf("%d", &virus[i].row);
		scanf("%d", &virus[i].col);
		scanf("%d", &virus[i].h);
		scanf("%d", &virus[i].power);
		virus[i].num = i + 1;
		box[virus[i].row][virus[i].col][virus[i].h] = virus[i].num;
		tail++;
	}

	qsort(virus, M, sizeof(_VIRUS), compare);


	while (1)
	{
		if (head == tail) break;

		for (i = 0; i < 6; i++)
		{
			row = virus[head].row + Dy[i];
			col = virus[head].col + Dx[i];
			height = virus[head].h + Dz[i];
			if (row >= 0 && row < N && col >= 0 && col < N && height >= 0 && height < N && box[row][col][height] == 0)
			{
				box[row][col][height] = virus[head].num;
				virus[tail].row = row;
				virus[tail].col = col;
				virus[tail].h = height;
				virus[tail].power = virus[head].power;
				virus[tail].num = virus[head].num;
				tail++;
			}
		}

		head++;
	}

	for (k = 0; k < N; k++)
	{
		for (i = 0; i < N; i++)
		{
			for (j = 0; j < N; j++)
			{
				//printf("%d", box[i][j][k]);
				count[box[i][j][k]] += 1;
			}
			//printf("\n");
		}
		//printf("\n");
	}

	for (i = 0; i < 50; i++)
	{
		if (count[i] > max)
		{
			max = count[i];
		}
	}
	
	printf("%d\n", max);

}