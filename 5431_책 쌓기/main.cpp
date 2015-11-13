#include <stdio.h>
#include <string.h>

int stack[51];
int N;

void back(int length)
{
	int i;
	for (i = length - 1; i >= 0; i--)
	{
		stack[i] = stack[i + 1];
	}
}

int main()
{
	int i;
	int num;
	int top = 0;
	int count = 0;
	int number[50];

	scanf("%d", &N);
	
	for (i = 0; i < N; i++)
	{
		scanf("%d", &number[i]);
	}
	stack[top] = number[0];
	top++;
	
	for (i = 1; i < N; i++)
	{
		if (stack[top - 1] < number[i])
		{
			stack[top] = num;
			top++;
		}
		else // ÀÛÀ½!
		{
			back(top);
			stack[0] = number[i];
			i = 0;

		}
	}

	return 0;
}