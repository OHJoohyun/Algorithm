#include <stdio.h>

int main()
{
	int N, M;
	int sum, news;
	scanf("%d %d", &N, &M);
	sum = N * M;
	for (int i = 0; i < 5; i++)
	{
		scanf("%d", &news);
		printf("%d ", news - sum);
	}
	printf("\n");
	return 0;

}