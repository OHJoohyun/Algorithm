#include <stdio.h>

int super, sub;
int N;

int room[1000];

int main()
{
	int i, j;
	int min = 999999;
	scanf("%d", &N);
	
	scanf("%d %d", &super, &sub);
	
	for (i = 0; i < N; i++)
	{
		scanf("%d", &room[i]);
	}

	int tmp1, tmp2, tmp3;
	int sum1, sum2, sum3;

	for (i = 0; i < N; i++)
	{
		sum3 = 0;
		for (j = 0; j < N; j++)
		{
			sum1 = 0;
			tmp1 = 0;
			tmp2 = 0;
			if (i == j)
			{
				if (room[i] - super <= 0)
				{
					sum1 = 1;
				}
				else
				{
					tmp1 = room[i] - super;
					tmp2 = tmp1 / sub;
					if (tmp1 % sub > 0) tmp2++;
					sum1 = tmp2 + 1;
				}
			}
			
			if (i != j)
			{
				tmp1 = room[j] / sub;
				if (room[j] % sub > 0) tmp1++;
				sum1 = tmp1;
			}

			sum3 = sum3 + sum1;
		}
		if (min > sum3)
			min = sum3;
	}
	printf("%d\n", min);
	return 0;
}