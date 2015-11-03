#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct {
	int index;
	int height;
	int see;
} _building;


_building building[100001];
_building stack[100001];


int main()
{
	int number;
	int i, j;
	
	int top = 0;
	int tmp;

	scanf("%d", &number);
	for (i = 1; i <= number; i++)
	{
		scanf("%d", &building[i].height);
		building[i].index = i;
		building[i].see = 0;
	}
	
	stack[top] = building[1];
	building[number+1].height = 1000001;
	building[number+1].index = 0;
	building[number+1].see = 0;

	for (i = 1; i <= number; i++)
	{
		if (stack[top].height >= building[i].height) // 작거나 같으면 STACK에 PUSH
		{
			stack[++top] = building[i];
		}
		else
		{
			for (j = top; j >= 0; j--)
			{
				if (stack[top].height >= building[i].height)
				{
					stack[++top] = building[i];
					break;
				}
				else
				{
					tmp = stack[top].index;
					building[tmp].see = i;
					top--;
				}
				
				if (top == -1)
				{
					stack[++top] = building[i];
					break;
				}
				
			}
		}
	}

	for (i = 1; i <= number; i++)
	{
		printf("%d\n", building[i].see);
	}

	return 0;

}