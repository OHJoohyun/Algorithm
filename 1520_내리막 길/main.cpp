#include <stdio.h>
#include <string.h>

int Dy[4] = { 0,0,-1, 1 };
int Dx[4] = { -1, 1, 0,0 };

int map[500][500];
int visit[500][500];

int N, M;


int dp(int row, int col)
{
	int i, j;
	int row_t, col_t;

	if (row == 0 && col == 0) return visit[row][col] = 1;

	if(visit[row][col] == 0)
	{ 
		for (i = 0; i < 4; i++)
		{
			row_t = row + Dy[i];
			col_t = col + Dx[i];

			if (row_t >= 0 && row_t < N && col_t >= 0 && col_t < M)
			{
				if (map[row_t][col_t] > map[row][col])
				{
					visit[row][col] += dp(row_t, col_t);
				}
			}
		}
	}

	return visit[row][col];
}
int main()
{
	int i, j;
	int result;
	scanf("%d %d", &N, &M);

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}
	

	memset(visit, 0, sizeof(visit));

	result = dp(N - 1, M - 1);

	/*
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			printf("%d ", visit[i][j]);
		}
		printf("\n");
	}
	*/
	
	printf("%d\n", result);
	
	return 0;
}