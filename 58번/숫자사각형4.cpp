#include <stdio.h>

int main()
{
	int n, m;
	int arr[100][100];
	int i, j, k = 1;

	scanf_s("%d %d", &n, &m);

	if (m == 1)
	{
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= n; j++)
			{
				printf("%d ", i);
			}
			printf("\n");
		}
	}
	else if (m == 2)
	{
		for (i = 0; i < n; i++)
		{
			if (i % 2 == 0)
			{
				k = 1;
				for (j = 0; j < n; j++)
				{
					arr[i][j] = k;
					k++;
				}
			}
			else
			{
				k = n;
				for (j = 0; j < n; j++)
				{
					arr[i][j] = k;
					k--;
				}
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
	else // m == 3
	{
		for (i = 0; i < n; i++)
		{
			k = i + 1;
			for (j = 0; j < n; j++)
			{
				arr[i][j] = k;
				k = k + i + 1;
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


	return 0;
}