// https://www.acmicpc.net/problem/10844

// Dynamic Programming 

#include <stdio.h>
#include <string.h>


int number[101][10];
int N;
long long count;
long long anw;
int divide = 1000000000;

int Dx[2] = { -1, 1 };

void dfs(int depth)
{
	int i, j;
	for (i = 0; i < 10; i++)
	{
		if (i - 1 != -1)
		{
			number[depth][i] = (number[depth][i] +  number[depth - 1][i - 1]) % divide;
		}
		if (i + 1 != 10)
		{
			number[depth][i] = (number[depth][i] + number[depth - 1][i + 1]) % divide;
		}
	}
}

int main()
{
	int i, j, k;
	int N;

	count = 0;
	anw = 0;

	scanf("%d", &N);

	memset(number, 0, sizeof(number));

	for (j = 1; j < 10; j++)
	{
		number[1][j] = 1;
	}
	
	for (i = 2; i <= N; i++)
	{
		dfs(i);
	}

	for (i = 0; i < 10; i++)
	{
		count = count + number[N][i];
	}
	//anw = count % divide;
	printf("%lld\n", count % divide);
}
