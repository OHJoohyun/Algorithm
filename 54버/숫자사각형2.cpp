#include <stdio.h>

int main()
{
	int n, m;
	int i, j, k;

	scanf_s("%d %d", &n, &m);
	for (i = 1; i <= (n*m); i = i+(2*m))
	{
		for (j = i; j < i + m; j++)
		{
			printf("%d ", j);
		}
		printf("\n");
		
		if (i + (2 * m) - 1 > n*m) break;

		for (k = i + (2 * m) - 1; k >= i + m; k--)
		{
			printf("%d ", k);
		}
		printf("\n");
	}
	return 0;
}