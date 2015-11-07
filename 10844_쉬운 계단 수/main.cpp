#include <stdio.h>

int Dx[2] = { -1, 1 };

int N;
long count = 0;
long tmp[10];

void dfs(int depth, int value)
{
	int i;
	int tmp;
	
	if (depth == N)
	{
		count++;
		return;
	}

	for (i = 0; i < 2; i++)
	{
		tmp = value + Dx[i];
		if (tmp > 0 && tmp < 10)
		{
			dfs(depth + 1, tmp);
		}
	}
}

int main()
{
	int i;
	long anw;
	
	scanf("%d", &N);

	for (i = 0; i < 10; i++)
	{
		dfs(1, i);
	}

	anw = count % 1000000000;
	printf("%d\n", anw);
}