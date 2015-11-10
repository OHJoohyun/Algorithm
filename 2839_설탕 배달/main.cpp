#include <stdio.h>
#include <string.h>

int main()
{
	int N;
	int anw[5001];
	int i;
	scanf("%d", &N);
	memset(anw, 1000000, sizeof(anw));
	anw[0] = 0;
	for (i = 3; i <= N; i++)
	{
		if (anw[i] > anw[i - 3] + 1)
		{
			anw[i] = anw[i - 3] + 1;
		}
	}
	for (i = 5; i <= N; i++)
	{
		if (anw[i] > anw[i - 5] + 1)
		{
			anw[i] = anw[i - 5] + 1;
		}
	}
	if (anw[N] > 1000000)
	{
		printf("-1\n");
	}
	else
		printf("%d\n", anw[N]);
}