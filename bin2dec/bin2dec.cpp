#include <stdio.h>
#include <math.h>


int bin2dec(int a);

int main()
{
	int bin;
	int result;

	scanf_s("%d", &bin);
	result = bin2dec(bin);
	printf("%d\n", result);
}

int bin2dec(int a)
{
	int bin = a;
	int dec = 0;
	int rem = 0;
	int tmp = 0;

	if (bin > 10000000)
	{
		bin = 11111111 - bin;
		bin = bin + 1;

		while (1)
		{
			if (bin == 0) break;
			rem = bin % 10;
			bin = bin / 10;

			dec = dec + rem * pow(2, tmp);
			tmp++;
		}
		return -dec;
	}
	else
	{
		while (1)
		{
			if (bin == 0) break;
			rem = bin % 10;
			bin = bin / 10;

			dec = dec + rem * pow(2, tmp);
			tmp++;
		}
		return dec;
	}
}