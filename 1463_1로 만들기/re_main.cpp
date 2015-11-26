#include <stdio.h>

int N;
int min = 999999;

void dfs(int value, int count)
{
	if (value == 1)
	{
		if (min > count)
			min = count;
		return;
	}

	if (value % 3 == 0)
	{
		dfs(value / 3, count + 1);
	}
	else if (value % 2 == 0)
	{
		dfs(value / 2, count + 1);
		dfs(value - 1, count + 1);
	}
	else
		dfs(value - 1, count + 1);
	return;
}

int main()
{
	scanf("%d", &N);
	
	dfs(N, 0);

	printf("%d\n", min);
}