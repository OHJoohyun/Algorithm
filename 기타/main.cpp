#include <stdio.h>


int seat[41] = { 0 };
int count = 0;
int N, M;

void dfs(int depth, int value)
{
	if (depth == N - M)
	{
		count++;
		return;
	}

	if (value - 1 > 0 && value - 1 <= N && seat[value - 1] == 0)
	{
		seat[value - 1] = 1;
		dfs(depth + 1, value - 1);
		seat[value - 1] = 0;
	}
	if (value > 0 && value <= N && seat[value] == 0)
	{
		seat[value] = 1;
		dfs(depth + 1, value);
		seat[value] = 0;
	}
	if (value + 1 > 0 && value + 1 <= N && seat[value + 1] == 0)
	{
		seat[value + 1] = 1;
		dfs(depth + 1, value + 1);
		seat[value + 1] = 0;
	}
	return;
}

int main()
{
	int i,vip, start;
	scanf("%d", &N);
	scanf("%d", &M);
	for (i = 0; i < M; i++)
	{
		scanf("%d", vip);
		seat[vip] = 1;
	}

	for (i = 1; i < N; i++)
	{
		if (seat[i] == 0)
		{
			start = i;
			break;
		}
	}

	if(start - 1 > 0 && start - 1 <= N && seat[start - 1] == 0)
	{ 
		seat[start - 1] = 1;
		dfs(1, start - 1);
		seat[start - 1] = 0;
	}
	if (start > 0 && start <= N && seat[start] == 0)
	{
		seat[start] = 1;
		dfs(1, start);
		seat[start] = 0;
	}
	if (start + 1 > 0 && start + 1 <= N && seat[start + 1] == 0)
	{
		seat[start + 1] = 1;
		dfs(1, start + 1);
		seat[start + 1] = 0;
	}
}