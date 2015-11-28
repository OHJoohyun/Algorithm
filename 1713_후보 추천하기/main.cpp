#include <stdio.h>

typedef struct {
	int num;
	int pri;
} _CANDI;

int main()
{
	_CANDI queue[1000];
	int head, tail;
	int pic, N;
	int i, j;
	int num[1000];
	int check[1000] = { 0 };
	int min_idx, min_pri;
	int min = 999999;
	int minpri = 99999;
	int pri = 0;

	head = 0;
	tail = 0;

	scanf("%d", &pic);
	scanf("%d", &N);
	for (i = 0; i < N; i++)
	{
		scanf("%d", &num[i]);
	}

	int count = 0;
	int find = 0;
	int tmp;
	for (i = 0; i < N; i++)
	{		
		if(check[num[i]] == 0)
		{ 
			if (count == pic)
			{
				min = 999999;
				minpri = 999999;
				min_idx = 0;

				find = 0;
				
				tmp = check[queue[head].num];
				for (j = head; j < head + pic; j++)
				{
					if (tmp != check[queue[j].num])
						find = 1;
				}
				
				if (find == 0)
				{
					check[queue[head].num] = 0;
					head++;
					count--;
				}
				else
				{
					for (j = head; j < head + pic; j++)
					{
						if (check[queue[j].num] < min && check[queue[j].pri] < minpri)
						{
							minpri = check[queue[j].pri];
							min = check[queue[j].num];
							min_idx = j;
						}
					}

					printf("i=%d\n", i);
					printf("num[i] = %d\n", num[i]);
					printf("min_idx=%d\n\n", min_idx);
				
					check[queue[min_idx].num] = 0;
					queue[min_idx].num = num[i];
					queue[min_idx].pri = pri;
					pri++;
					check[num[i]] = 1;
					continue;
				}
			}
			check[num[i]] = 1;
			queue[tail].num = num[i];
			queue[tail].pri = pri;
			pri++;
			tail++;
			count++;
		}

		else if (check[num[i]] != 0)
		{
			check[num[i]] += 1;
		}
	}
	
	for (i = 1; i <= 100; i++)
	{
		if (check[i] > 0)
		{
			printf("%d ", i);
		}
	}
	printf("\n");
	return 0;
}