#include <stdio.h>

int main()
{
	int N; // 참가자
	int M; // 장르
	int K; // 본선 진출자
	float singer[101][101];
	float capacity[101];
	int i, j;
	int tmp;
	float temp;
	float max;
	float anw = 0.0;

	scanf("%d %d %d", &N, &M, &K);
	for (j = 1; j <= M; j++)
	{
		for (i = 0; i < N; i++)
		{
			scanf("%d", &tmp);
			scanf("%f", &singer[tmp][j]);
		}
	}

	

	for (i = 1; i <= N; i++)
	{
		max = 0;
		for (j = 1; j <= M; j++)
		{
			if (singer[i][j] > max)
			{
				max = singer[i][j];
			}
		}
		capacity[i] = max;
	}

	//for (i = 1; i <= N; i++)
	//	printf("%1.1f ", capacity[i]);
	
	for (i = 1; i <= N; i++)
	{
		max = capacity[i];
		tmp = i;
		for (j = i + 1; j <= N; j++)
		{
			if (capacity[j] > max)
			{ 
				max = capacity[j];
				tmp = j;
			}
		}
		temp = capacity[i];
		capacity[i] = capacity[tmp];
		capacity[tmp] = temp;
	}

	
	for (i = 1; i <= K; i++)
		anw = anw + capacity[i];
	
	printf("%1.1f\n", anw);
}