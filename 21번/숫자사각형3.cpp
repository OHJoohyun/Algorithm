#include <stdio.h>

int main()
{
	int n;
	int i, j, k = 1;
	int arr[100][100];

	scanf_s("%d", &n);

	for (j = 0; j < n; j++)
	{
		for (i = 0; i < n; i++)
		{
			arr[i][j] = k;
			k++;
		}
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}

}
