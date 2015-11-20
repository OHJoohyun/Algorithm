#include <stdio.h>
#include <string.h>

int N, M, K;

int path[15][15];
int visit[15][15];

void print()
{
	int i, j;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			printf("%d ", path[i][j]);
		}
		printf("\n");
	}
}


int main()
{
	int i,j;
	int	total, no;
	scanf("%d %d %d", &N, &M, &K);

	memset(path, 0, sizeof(path));
	memset(visit, 0, sizeof(visit));

	//path[K / M][K % M - 1] = 1;

	int count = 0;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			count++;
			if (count == K) path[i][j] = 1;
		}
	}

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			if (i == 0 || j == 0)
			{
				visit[i][j] = 1;
			}
		}
	}


	for (i = 1; i < N; i++)
	{
		for (j = 1; j < M; j++)
		{
			visit[i][j] = visit[i - 1][j] + visit[i][j - 1];
		}
	}


	total = visit[N - 1][M - 1];
	
	memset(visit, 0, sizeof(visit));

	visit[0][0] = 1;

	if (K != 0 && K != N*M)
	{
		for (i = 0; i < N; i++) // 0행과 0열을 경우의 1가지로 초기화?
		{
			for (j = 0; j < M; j++)
			{
				if (i == 0 && j == 0) continue;
				
				if(i == 0 && j != 0 && path[i][j] == 0)
					visit[i][j] = visit[i][j - 1];
				
				if (i != 0 && j == 0 && path[i][j] == 0)
					visit[i][j] = visit[i - 1][j];
			}
		}

		
	
		for (i = 1; i < N; i++)
		{
			for (j = 1; j < M; j++)
			{
				if (path[i][j] == 1) continue;
				else if (path[i][j] == 0 && path[i - 1][j] == 0 && path[i][j - 1] == 0)
					visit[i][j] = visit[i - 1][j] + visit[i][j - 1];
				else if (path[i][j] == 0 && path[i - 1][j] == 0 && path[i][j - 1] == 1)
					visit[i][j] = visit[i - 1][j];
				else
					visit[i][j] = visit[i][j - 1];
			}
		}

		no = visit[N - 1][M - 1];
		printf("%d\n", total - no);
		return 0;
	}
	else
	{
		printf("%d\n", total);
		return 0;
	}
}