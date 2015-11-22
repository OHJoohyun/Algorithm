#include <stdio.h>
#include <string.h>

int path[801][801];
int check[801];
int queue[801] = { 0 };

int N, E;
int fisrt, second;
int min = 999999;
int head = 0, tail = 0;
int find = 0;

int main()
{
	int i, j;
	int row, col, weight;
	scanf("%d %d", &N, &E);

	for (i = 0; i < E; i++)
	{
		scanf("%d %d %d", &row, &col, &weight);
		path[row][col] = weight;
		path[col][row] = weight;
	}

	scanf("%d %d", &fisrt, &second);

	
	for (i = 1; i <= N; i++)
	{
	for (j = 1; j <= N; j++)
	{
	printf("%d ", path[i][j]);
	}
	printf("\n");
	}
	

	memset(check, 0x1f, sizeof(check));

	check[1] = 0;

	//printf("%d", check[0]);

	for (i = 2; i < N; i++)
	{
		if (path[1][i] > 0)
		{
			queue[tail] = i;
			tail++;
			check[i] = path[1][i];
		}
	}

	while (1)
	{
		if (head == tail) break;

		for (i = 1; i <= N; i++)
		{
			if(path[queue[head]][i] > 0)
			{ 
				if (check[i] == 0x1f)
				{
					queue[tail] = i;
					tail++;
				}

				if (check[i] > check[queue[head]] + path[queue[head]][i])
					check[i] = check[queue[head]] + path[queue[head]][i];
			}
		}
		head++;
	}

	for (i = 1; i <= N; i++)
	{
		printf("%d ", check[i]);
	}
	printf("\n");
	
	return 0;

}