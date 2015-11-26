//https://www.acmicpc.net/problem/1429 결혼
#include <stdio.h>
#include <stdio.h>

int N, M;
int map[13][13];
int check[13][13];

int main()
{
	int i, j;
	scanf("%d %d", &N, &M);
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			scanf("%1d", &map[i][j]);
		}
	}

	int sum1, sum2;
	int max1, max2;
	int row, col;
	int count = 0;

	while(1)
	{ 
		int find2 = 0;

		for (i = 0; i < N; i++)
		{
			for (j = 0; j < M; j++)
			{
				if (map[i][j] == 1)
				{
					find2 = 1;
				}
			}
		}

		if (find2 == 0) break;
		
		// ROW에서 가장 큰 값을 찾자.
		max1 = 0;
		for (i = 0; i < N; i++)
		{
			sum1 = 0;
			for (j = 0; j < M; j++)
			{
				sum1 += map[i][j];
			}
			if (sum1 > max1)
			{
				max1 = sum1;
				row = i;
			}
		}

		// COL에서 가장 큰 값을 찾자.
		max2 = 0;
		for (j = 0; j < M; j++)
		{
			sum2 = 0;
			for (i = 0; i < N; i++)
			{
				sum2 += map[i][j];
			}
			if (sum2 > max2)
			{
				max2 = sum2;
				col = j;
			}
		}

		//printf("max1 = %d\n", max1);
		//printf("max2 = %d\n", max2);

		// 비교 후 0으로 변경
		if (max1 > max2)
		{
			for (j = 0; j < M; j++)
			{
				map[row][j] = 0;
			}
			count++;
		}
		else
		{
			for (i = 0; i < N; i++)
			{
				map[i][col] = 0;
			}
			count++;
		}


	}

	if (count == 0) printf("-1\n");
	else
		printf("%d\n", count);
}