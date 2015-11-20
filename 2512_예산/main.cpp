#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int N, M;
int city[10000];
int max = 0;

int compare(const void *a, const void *b)
{
	if (*(int*)a > *(int*)b) return 1;
	else if (*(int*)a == *(int*)b) return 0;
	else return -1;
}

void b_search(int left, int right, int mid)
{
	int i;
	int sum = 0;

	if (left > right)
	{
		printf("%d\n", max);
		return;
	}
	
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

	if (sum == M)
	{
		printf("%d\n", mid);
		return;
	}
	else if (sum < M)
	{
		if (mid > max)
			max = mid;
		b_search(mid + 1, right, (mid + 1 + right) / 2);
	}
	else
		b_search(left, mid - 1, (left + mid - 1) / 2);
}

int main()
{
	int i;
	int sum = 0;

	scanf("%d", &N);
	for (i = 0; i < N; i++)
	{
		scanf("%d", &city[i]);
		sum = sum + city[i];
	}

	scanf("%d", &M);
	qsort(city, N, sizeof(int), compare);

	b_search(0, city[N - 1], city[N - 1]);

	return 0;
}