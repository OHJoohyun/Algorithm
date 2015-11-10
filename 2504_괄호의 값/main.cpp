#include <stdio.h>

int main()
{
	int i = 0;
	int top;
	char array[31];
	char stack[31];
	int sum = 0;
	int tmp, tmp1;
	scanf("%s", array);

	top = 0;
	stack[top] = array[0];
	top++;

	i = 0;
	while (1)
	{
		tmp = 1;
		tmp1 = 0;
		if (array[i] == '\0') break;
		printf("i = %d\n", i);
		while (1)
		{
			
			if (array[i] == '(' || array[i] == '[')
			{
				stack[top] = array[i];
				top++;
				i++;
				if (tmp != 1)
				{
					sum = sum + tmp;
				}
			}
			
			else if (array[i] == ')' && stack[top - 1] == '(')
			{
				tmp = tmp * 2;
				top--;
				i++;
				if (top == 0) break;
			}
			else if (array[i] == ']' && stack[top - 1] == '[')
			{
				tmp = tmp * 3;
				top--;
				i++;
				if (top == 0) break;
			}
			
			else if(((array[i] == ']' && stack[top - 1] == '(') || (array[i] == ')' && stack[top - 1] == '[')))
			{
				printf("??\n");
				printf("0\n"); return 0;
			}
			else
			{				
				if (array[i] == '\0') break;
			}
		}
		//sum = sum + tmp;
	}

	printf("%d\n", sum);
	return 0;
}