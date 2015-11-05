#include <stdio.h>
#include <string.h>

int main()
{
	int N, K;
	int anw[10001];
	int i, j;
	int coin;

	scanf("%d %d", &N, &K);

	memset(anw, 1000000, sizeof(anw));
	anw[0] = 0;
	for (i = 0; i < N; i++)
	{
		scanf("%d", &coin);
		for (j = coin; j <= K; j++)
		{
			if (anw[j] > anw[j - coin] + 1)
			{
				anw[j] = anw[j - coin] + 1;
			}
		}
	}

	printf("%d\n", anw[K]);
}