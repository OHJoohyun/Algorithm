#include <stdio.h>

int main()
{
	int A, B, V;
	int length = 0;
	int count = 0;
	scanf("%d %d %d", &A, &B, &V);
	while (1)
	{
		count++;
		length = length + A;
		if (length >= V) break;
		length = length - B;
	}
	printf("%d\n", count);
}