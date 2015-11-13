#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int N, M;
//float start, end;
int mid;
int city[10000];
int result;

int compare(const void *a, const void *b)
{
	if (*(int*)a > *(int*)b) return 1;
	else if (*(int*)a == *(int*)b) return 0;
	else return -1;
}

/*
int search(float s, float e, float m)
{
	int i;
	float sum = 0.0;

	for (i = 0; i < N; i++)
	{
		if (city[i] < m)
		{
			sum = sum + city[i];
		}
		else
		{
			sum = sum + m;
		}
	}

	printf("mid = %f\n", m);
	printf("sum = %f\n", sum);
	printf("-------------\n");

	if (sum > M)
	{
		start = s;
		end = e;
		mid = sum / N;
		return search(start, end, mid);
	}
	else if (sum < M)
	{
		start = s;
		end = e;
		mid = sum / N;
		return search(start, end, mid);
	}
	else
		return m;
}
*/

int main()
{
	int i;
	int sum = 0;
	int max = 0;
	int min = 1;
	
	result = 0;
	
	scanf("%d", &N);

	for (i = 0; i < N; i++)
	{
		scanf("%d", &city[i]);
		sum = sum + city[i];
	}

	scanf("%d", &M);

	qsort(city, N, sizeof(int), compare);

	if (sum < M)
	{
		printf("%d\n", city[N - 1]);
		return 0;
	}

	min = 1;
	max = city[N - 1];

	while (1)
	{
		if (min > max) break;
		mid = (min + max) / 2;

		sum = 0;

		for (i = 0; i < N; i++)
		{
			if (city[i] < mid)
			{
				sum = sum + city[i];
			}
			else
			{
				sum = sum + mid;
			}
		}

		if (sum > M)
		{
			max = mid - 1;
		}
		else
		{
			if (result < mid) 
				result = mid;
			min = mid + 1;
		}
	}
	printf("%d\n", result);
	return 0;
}