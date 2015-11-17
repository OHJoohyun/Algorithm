#include <stdio.h>


int seat[41] = { 0 };
int number[41];
int count = 0;
int N, M;

int main()
{
	int i;
	int start, end, count;
	unsigned int sum, anwser = 1;
	scanf("%d", &N);
	scanf("%d", &M);
	for (i = 0; i < M; i++)
	{
		scanf("%d", &seat[i]);
	}

	seat[M] = N + 1;

	start = 0;

	number[0] = 0;
	number[1] = 1;
	number[2] = 2;

	for (i = 3; i < 41; i++)
	{
		number[i] = number[i - 2] + number[i - 1];
	}

	for (i = 0; i <= M; i++)
	{
		end = seat[i];
		count = end - start - 1;
		if (count <= 0)
		{
			start = seat[i];
			continue;
		}
		anwser *= number[count];
		start = seat[i];
	}

	printf("%d\n", anwser);
}