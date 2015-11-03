#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

typedef struct {
	int num;
	int start;
	int end;
} _meeting;

int main()
{
	int number;
	int i,j;
	_meeting meeting[500];
	_meeting tmp;
	_meeting anw[500];
	int min_index;
	int end_time;
	int idx = 1;

	scanf("%d", &number);
	for (i = 0; i < number; i++)
	{
		scanf("%d", &meeting[i].num);
		scanf("%d", &meeting[i].start);
		scanf("%d", &meeting[i].end);
	}

	for (i = 0; i < number; i++) // END 시간 기준으로 오름차순 정렬
	{
		min_index = i;
		for (j = i; j<number;j++)
		{ 
			if (meeting[min_index].end > meeting[j].end)
			{
				min_index = j;
			}
		}
		tmp = meeting[min_index];
		meeting[min_index] = meeting[i];
		meeting[i] = tmp;
	}

	end_time = meeting[0].end;
	anw[0] = meeting[0];

	for (i = 0; i < number; i++)
	{
		if (end_time <= meeting[i].start)
		{
			end_time = meeting[i].end;
			anw[idx] = meeting[i];
			idx++;
		}
	}

	printf("%d\n", idx);
	for (i = 0; i < idx; i++)
	{
		printf("%d ", anw[i].num);
	}
	
	return 0;
}

