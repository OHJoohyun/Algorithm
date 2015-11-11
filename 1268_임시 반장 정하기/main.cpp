#include <stdio.h>
#include <string.h>

int N;
int student[1000][5];
int same[1000][1000];

int main()
{
	int i, j, k;
	int max = 0;
	int max_index;
	int sum = 0;

	scanf("%d", &N);
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < 5; j++)
		{
			scanf("%d", &student[i][j]);
		}
	}

	memset(same, 0, sizeof(same));
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			for (k = 0; k < 5; k++)
			{
				if (student[i][k] == student[j][k])
				{
					same[i][j] = 1;
					break;
				}
			}
		}
	}

	for (i = 0; i < N; i++)
	{
		sum = 0;
		for (j = 0; j < N; j++)
		{
			sum = sum + same[i][j];
		}

		if (sum > max)
		{
			max = sum;
			max_index = i;
		}
	}
	
	printf("%d\n", max_index + 1);
}