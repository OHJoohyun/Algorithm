#include <stdio.h>
#include <stdlib.h>

long long *tree;
int N, M;
long long max = 0;

int compare(const void *a, const void *b)
{
	return * (long long *) a > * (long long*)b;
}

void b_search(long long left, long long right, long long mid)
{
	int i;
	long long sum = 0;

	if (left > right)
	{
		printf("%lld\n", max);
		return;
	}
	
	for (i = 0; i < N; i++)
	{
		if(tree[i] > mid)
		{ 
			sum = sum + (tree[i] - mid);
		}
	}

	//printf("sum = %d\n", sum);
	//printf("mid = %d\n", mid);

	if (sum == M)
	{
		printf("%lld\n", mid);
		return;
	}
	else if (sum > M)
	{
		if (mid > max)
			max = mid;
		b_search(mid + 1, right, (mid + 1 + right) / 2);
	}
	else
	{
		//printf("mid = %d\n");
		b_search(left, mid - 1, (left + mid - 1) / 2);
	}
}

int main()
{
	int i;
	long long sum, mid;
	
	scanf("%d %d", &N, &M);
	
	tree = (long long *)malloc(N * sizeof(long long));
	
	for (i = 0; i < N; i++)
	{
		scanf("%lld", &tree[i]);
	}

	qsort(tree, N, sizeof(long long), compare);
	
	sum = tree[N - 1];
	//mid = (tree[N - 1] + 0) / 2;

	//printf("sum = %d\n", mid);

	b_search(0, sum, sum);

	return 0;
}