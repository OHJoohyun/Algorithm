#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int M, N;
	int i, j;
	int *check;
	

	scanf("%d %d", &M, &N);
	check = (int*)malloc(sizeof(int)*(N+1));

	for (i = 2; i <= N; i++)
	{
		if (check[i] != 1)
		{
			if(i >= M)
				printf("%d\n", i);
			for (j = i; j <= N; j = j + i)
			{
				check[j] = 1;
			}
		}
	}

	return 0;
}