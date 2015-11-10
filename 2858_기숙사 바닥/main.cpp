#include <stdio.h>

int main()
{
	int R, B;
	int total;
	int L, W;
	int i;
	int sum;

	scanf("%d %d", &R, &B);
	total = R + B;

	i = 3;
	while (1)
	{
		if (total % i == 0)
		{
			L = i;
			W = total / i;
			sum = (L * 2) + ((W - 2) * 2);
			if(sum == R)
				break;
		}
		i++;
	}

	if (L >= W)
	{
		printf("%d %d\n", L, W);
	}
	else if (L < W)
	{
		printf("%d %d\n", W, L);
	}
}
