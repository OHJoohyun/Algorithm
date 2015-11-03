#include <stdio.h>

int main()
{
	int n;
	int i, j;
	char k;
	char arr[100][100];

	scanf_s("%d", &n);


	k = 'A';

	for (j = n - 1; j >= 0; j--)
	{
		for (i = n - 1; i >= 0; i--)
		{
			arr[i][j] = k;
			k++;
			if (k == '[')
				k = 'A';
		}
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%c ", arr[i][j]);
		}
		printf("\n");
	}

	 
}