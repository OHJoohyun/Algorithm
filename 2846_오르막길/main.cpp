#include <stdio.h>

int main()
{
	int stack[1000];
	int path[1000];
	int top;
	int i, N;
	int max, anw;

	top = 1;
	max = 0;
	anw = 0;

	scanf("%d", &N);
	for (i = 0; i < N; i++)
	{
		scanf("%d", &path[i]);
	}

	stack[0] = -1;
	stack[top] = path[0];
	stack[N] = 1001;
	top++;

	for (i = 1; i <= N; i++)
	{
		if (path[i] > stack[top - 1])
		{
			stack[top] = path[i];	
			top++;
		}
		else
		{
			anw = stack[top - 1] - stack[1];
			stack[1] = path[i];
			top = 2;
			//printf("anw = %d\n", anw);
			if (anw > max)
			{
				max = anw;
			}
		}	
	}
	printf("%d\n", max);
}