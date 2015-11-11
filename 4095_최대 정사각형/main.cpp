#include <stdio.h>
#include <string.h>

#define MIN(a,b) ((a) > (b) ? b : a)
#define MAX(a,b) ((a) < (b) ? b : a)
int map[1000][1000];
int tmp[1000][1000];

int N, M;
int main()
{
	int i,j;
	int max;

	while (1)
	{
		max = 0;
		memset(map, 0, sizeof(map));
		memset(tmp, 0, sizeof(tmp));

		scanf("%d %d", &N, &M);
		if (N == 0 && M == 0) return 0;
		
		for (i = 0; i < N; i++)
		{
			for (j = 0; j < M; j++)
			{
				scanf("%d", &map[i][j]);
			}
		}

		for (i = 0; i < N; i++)
		{
			if (map[i][0] == 1)
			{ 
				tmp[i][0] = 1;
				max = 1;
			}
		}

		for (j = 0; j < M; j++)
		{
			if (map[0][j] == 1)
			{
				tmp[0][j] = 1;
				max = 1;
			}
		}

		for (i = 1; i < N; i++)
		{
			for (j = 1; j < M; j++)
			{
				if (map[i][j] == 1)
				{
					tmp[i][j] = MIN(MIN(tmp[i - 1][j], tmp[i][j - 1]), tmp[i - 1][j - 1]) + 1;
					max = MAX(max, tmp[i][j]);
				}
			}
		}
		printf("%d\n", max);
	}
}