#include <stdio.h>

int main()
{
	int n, m;
	int i, j;

	scanf_s("%d %d", &n, &m);
	for (i = 1; i <= (n * m); i = i + m)
	{
		for (j = i; j < i+m; j++)
		{
			printf("%d ", j);
		}
		printf("\n");
	}

	return 0;
}