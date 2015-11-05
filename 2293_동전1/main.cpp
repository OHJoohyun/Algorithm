#include <stdio.h>

int main()
{
	int N, K;
	int coin[101];
	int anw[10001] = { 1, 0 };
	int i, j;
	int tmp;

	scanf("%d %d", &N, &K);
	for (i = 0; i < N; i++)
	{
		scanf("%d", &coin[i]);
	}
	
	for (i = 0; i < N; i++)
	{
		tmp = coin[i];
		for (j = tmp; j <= K; j++)
		{
			anw[j] = anw[j] + anw[j - tmp];
		}
	}

	printf("%d\n", anw[K]);

	return 0;
}