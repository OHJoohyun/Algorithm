#include <stdio.h>

int min = 999999;

void dfs(int value, int count)
{
	if (value == 1)
	{
		if (min > count)
			min = count;
		return;
	}

	if (value % 3 == 0 && value % 2 == 0)
	{
		dfs(value / 3, count + 1);
		dfs(value / 2, count + 1);
	}
	else if (value % 3 == 0 && value % 2 != 0)
	{
		dfs(value / 3, count + 1);
	}
	else if (value % 3 != 0 && value % 2 == 0)
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
	int N;
	int i = 0;
	scanf("%d", &N);

	/*
	while (1)
	{
		if (N % 3 == 0) 
		{
			N = N / 3;
		}
		else if (N % 2 == 0)
		{
			N = N / 2;
		}
		else
			N = N - 1;
			
		i++;
		if (N == 1) break;
	}
	*/

	dfs(N, 0);
	printf("%d\n", min);
}