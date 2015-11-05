#include <stdio.h>

int arr[3][4];

int main()
{
	int i, j;
	int count;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 4; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}
	

	for (i = 0; i < 3; i++)
	{
		count = 0;
		for (j = 0; j < 4; j++)
		{
			if (arr[i][j] == 1)
			{
				count++;
			}
		}
		switch (count)
		{
			case 0: printf("D\n"); break;
			case 1: printf("C\n"); break;
			case 2: printf("B\n"); break;
			case 3: printf("A\n"); break;
			case 4: printf("E\n"); break;
			default: break;
		}
	}




}