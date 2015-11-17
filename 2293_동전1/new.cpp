#include <stdio.h>

int main()
{
	int n, k, tmp;
	int coin[100];
	int count[10001] = { 0 };
	scanf("%d %d", &n, &k);

	int i, j;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &coin[i]);
	}
	count[0] = 1;

	for (i = 0; i < n; i++)
	{
		tmp = coin[i];
		for (j = tmp; j <= k; j++)
		{
			count[j] = count[j] + count[j - tmp];
		}
	}
	printf("%d\n", count[k]);
	return 0;
}