#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

typedef struct {
	int check;
	int sl;
	int sw;
} _ham;

int main()
{
	_ham ham[5000];
	_ham tmp;
	int number, i, j;
	int min_index;
	int count1 = 0;
	int count2 = 0;
	int temp_num = 0;

	scanf("%d", &number);
	for (i = 0; i < number; i++)
	{
		ham[i].check = 0;
		scanf("%d", &ham[i].sl);
		scanf("%d", &ham[i].sw);
	}
	
	for (i = 0; i < number; i++) // SL 기준으로 오름차순 정렬
	{
		min_index = i;
		for (j = i; j < number; j++)
		{
			if (ham[min_index].sl > ham[j].sl)
			{
				min_index = j;
			}
			else if (ham[min_index].sl == ham[j].sl)
			{
				if (ham[min_index].sw > ham[j].sw)
					min_index = j;
			}
		}
		tmp = ham[min_index];
		ham[min_index] = ham[i];
		ham[i] = tmp;
	}

	/*
	for (i = 0; i < number; i++)
	{
		printf("%d %d\n", ham[i].sl, ham[i].sw);
	}
	*/
	while(1)
	{ 
		temp_num = 0;
		if (count2 == number) break;
		//printf("들어옴!\n");
		for (i = 0; i < number; i++)
		{
			if (ham[i].sw >= temp_num && ham[i].check == 0)
			{ 
				//printf("너란놈뭐냐\n");
				ham[i].check = 1;
				count2++;
				temp_num = ham[i].sw;
			}
			
		}
		count1++;
	}

	printf("%d\n", count1);

	return 0;
}