// N-QUEEN

#include <stdio.h>

int check[15];
int N;
int count = 0;

void dfs(int depth)
{
	if (depth == N)
	{
		//for (int k = 0; k < N; k++)
			//printf("%d ", check[k]);
		//printf("\n");
		count++;
		return;
	}

	int find;
	for (int i = 0; i < N; i++)
	{
		find = 0;
		for (int j = 0; j < depth; j++)
		{
			if (check[j] == i || check[j] + (depth - j) == i || check[j] - (depth - j) == i)
			{
				find = 1;
				break;
			}
		}

		if (find == 0)
		{
			check[depth] = i;
			dfs(depth + 1);
		}
	}
}

int main()
{
	int i;
	scanf("%d", &N);

	for (i = 0; i < N; i++)
	{
		check[0] = i;
		dfs(1);
	}

	printf("%d\n", count);
	return 0;
}