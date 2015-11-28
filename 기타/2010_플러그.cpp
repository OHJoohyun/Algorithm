#include <stdio.h>

int main()
{
	int max = 0;
	int N;
	int num;
	scanf("%d", &N);
	if (N == 1)
	{
		scanf("%d", &num);
		printf("%d\n", num);
		return 0;
	}
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &num);
		if (i != N - 1)
			max = max + (num - 1);
		else
			max = max + num;
	}
	printf("%d\n", max);
	return 0;
}