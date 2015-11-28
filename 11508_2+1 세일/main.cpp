#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
	if (*(int*)a < *(int*)b) return 1;
	else if (*(int*)a == *(int*)b) return 0;
	else return -1;
}

int main()
{
	int i, j, N;
	int milk[100001];

	scanf("%d", &N);
	for (i = 0; i < N; i++)
	{
		scanf("%d", &milk[i]);
	}

	qsort(milk, N, sizeof(int), compare);

	int sum = 0;

	for (i = 0; i < N; i = i + 3)
	{
		if (i + 1 == N)
		{
			sum = sum + milk[i];
		}
		else
			sum = sum + milk[i] + milk[i + 1];

	}
	printf("%d\n", sum);
}