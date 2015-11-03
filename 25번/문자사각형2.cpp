#include <stdio.h>

int main()
{
	int n;
	int i, j, k;
	char arr[100][100];

	scanf_s("%d", &n);

	k = 'A';
	for (j = 0; j < n; j++)
	{
		if (j % 2 == 1) // È¦¼ö ¿­
		{
			for (i = n - 1; i >= 0; i--)
			{
				arr[i][j] = k;
				k++;
				if (k == '[')
					k = 'A';
				if (k == '@')
					k = 'Z';

			}
		}
		else
		{
			for (i = 0; i < n; i++)
			{
				arr[i][j] = k;
				k++;	
				if (k == '[')
					k = 'A';
				if (k == '@')
					k = 'Z';
			}
			
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