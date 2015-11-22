#include <stdio.h>

int main()
{
	int num[4];
	int number[4];
	int i;
	int num1, num2, num3, num4;
	int min = 10000;

	scanf("%d %d %d %d", &num[0], &num[1], &num[2], &num[3]);

	number[0] = num1 = num[0] * 1000 + num[1] * 100 + num[2] * 10 + num[3];
	number[1] = num2 = num[1] * 1000 + num[2] * 100 + num[3] * 10 + num[0];
	number[2] = num3 = num[2] * 1000 + num[3] * 100 + num[0] * 10 + num[1];
	number[3] = num4 = num[3] * 1000 + num[0] * 100 + num[1] * 10 + num[2];
	
	for (i = 0; i < 4; i++)
	{
		if (number[i] < min)
		{
			min = number[i];
		}
	}

	printf("%d\n", min);

}