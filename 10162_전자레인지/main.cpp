#include <stdio.h>

int main()
{
	int T;
	scanf("%d", &T);
	int a, b, c;
	a = 0;
	b = 0;
	c = 0;
	while (1)
	{
		if (T >= 300)
		{
			T = T - 300;
			a++;
		}
		else if (T < 300 && T >= 60)
		{
			T = T - 60;
			b++;
		}
		else
		{
			T = T - 10;
			c++;
		}
		if (T == 0)
		{
			printf("%d %d %d\n", a, b, c);
			return 0;
		}
		if (T < 0)
		{
			printf("-1\n");
			return 0;
		}
	}
}