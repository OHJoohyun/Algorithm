#include <stdio.h>

int N;
int min = 999999;
int check = 0;

void dfs(int value, int count)
{
	if (check == 1) return;
	if (value < 0) return;
	if (count >= min) return;
	if (value == 0)
	{
		if (count < min)
			min = count;
		check = 1;
		if (count == 0) check = 0;
		return;
	}

	dfs(value - 5, count + 1);
	dfs(value - 3, count + 1);

	return;
}

int main()
{
	scanf("%d", &N);

	dfs(N, 0);


	if (check == 0)
	{
		printf("-1\n");
		return 0;
	}
	printf("%d\n", min);
	return 0;
}