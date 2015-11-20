// DFS로 풀면 시간 초과, DP? GREEDY?

#include <stdio.h>

int left[2000];
int right[2000];

int N, max = 0;

void dfs(int l, int r, int sum)
{
	if (l == N || r == N)
	{
		//printf("sum = %d\n", sum);
		if (sum > max)
			max = sum;
		return;
	}

	if (left[l] > right[r])
	{
		dfs(l, r + 1, sum + right[r]);
	}
	else
	{
		if(left[l+1] > right[r+1]) 
			dfs(l + 1, r + 1, sum);
		if(left[l+1], right[r])
			dfs(l + 1, r, sum);
	}

	return;
}

int main()
{
	int i;
	scanf("%d", &N);

	for (i = 0; i < N; i++)
	{
		scanf("%d", &left[i]);
	}
	for (i = 0; i < N; i++)
	{
		scanf("%d", &right[i]);
	}

	dfs(0, 0, 0);

	printf("%d\n", max);
}