#include <stdio.h>

int N, M;
int number[300];
int part[300];

int main()
{
	int i;
	int max = 0;
	int max_index;
	int sum = 0;
	int avg;

	scanf("%d %d", &N, &M);
	for (i = 0; i < N; i++)
	{
		scanf("%d", &number[i]);
		if (max < number[i])
		{ 
			max_index = i;
		}
		sum = sum + number[i];
	}

	printf("max = %d\n", max);
	printf("sum = %d\n", sum);
	while (1)
	{
		avg = (max + sum) / 2;
		if (avg < max) break;
		sum = avg;
	}

	printf("%d\n", avg);
}