#include <stdio.h>

#define MAX 80001

struct COW
{
	long int value;
	long int index;
};

struct COW stack[MAX];
struct COW cow[MAX];

int main()
{
	int number;
	int i, j;
	int top = 0;
	long int anw = 0;

	scanf_s("%d", &number);
	for (i = 0; i < number; i++)
	{
		scanf_s("%d", &cow[i].value);
		cow[i].index = i;
	}

	stack[top] = cow[0];
	cow[number].value = 1000000001;
	cow[number].index = number;

	for (i = 1; i < number + 1; i++)
	{
		if (cow[i].value >= stack[top].value) // i번째 소가 top 보다 크다.
		{
			for (j = top; j >= 0; j--)
			{
				if (stack[top].value > cow[i].value)
				{
					stack[++top] = cow[i];
					break;
				}
				
				else
				{
					anw = ((i - stack[top].index) - 1) + anw;
					top--;
				}

				if (top == -1)
				{
					stack[++top] = cow[i];
					break;
				}
			}
		}
		else // i번째 소가 top 보다 작거나 같다.
		{
			stack[++top] = cow[i];
		}
	}
	
	printf("%ld\n", anw);
	return 0;
}