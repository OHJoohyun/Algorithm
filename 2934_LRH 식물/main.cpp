#include <stdio.h>

int main()
{
	int start[100001];
	int end[100001];
	int a, b, i, j;
	int N;
	int sum;
	scanf("%d", &N);
	for (i = 1; i <= N; i++)
	{
		scanf("%d %d", &start[i], &end[i]);
	}

	for (i = 1; i <= N; i++)
	{
		sum = 0;
		for (j = 1; j < i; j++)
		{
			if (start[j] >= start[i] || start[j] <= end[i] || end[j] >= start[i] || end[j] <= end[i])
			{
				sum++;
			}
		}
		printf("%d\n", sum);
	}
}