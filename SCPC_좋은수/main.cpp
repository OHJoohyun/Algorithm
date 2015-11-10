#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
	if (*(int*)a > *(int*)b)
		return 1;
	else if (*(int*)a < *(int*)b)
		return -1;
	else
		return 0;
}

int main()
{
	int array[10] = { 1,4,1,2,5,6,10,3,5,5 };

	qsort(array, 10, sizeof(int), compare);

	for (int i = 0; i < 10; i++)
	{
		printf("%d\n", array[i]);
	}

	return 0;
}