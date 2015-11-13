#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int row;
	int col;
	int check;
} _STONE;

_STONE stone[10000];

int compare_row(const void *arg1, const void * arg2) {
	int v1, v2;
	v1 = ((_STONE *)arg1)->row;
	v2 = ((_STONE *)arg2)->row;

	if (v1 < v2) return -1;
	else if (v1 == v2)
	{
		return 0;
	}
	else return 1;
}

int compare_col(const void *arg1, const void * arg2) {
	int v1, v2;
	v1 = ((_STONE *)arg1)->col;
	v2 = ((_STONE *)arg2)->col;

	if (v1 < v2) return -1;
	else if (v1 == v2)
	{
		return 0;
	}
	else return 1;
}


int main()
{
	int N, K;
	int i;
	int tmp_num;
	int count = 0;
	int max_row = 0;
	int max_row_idx;
	int max_col = 0;
	int max_col_idx;
	int index;
	int result = 0;
	int check_count;

	scanf("%d %d", &N, &K);

	for (i = 0; i < K; i++)
	{
		scanf("%d %d", &stone[i].row, &stone[i].col);
		stone[i].check = 0;
	}


	while(1)
	{ 
		tmp_num = 0;
		check_count = 0;
		count = 0;
		max_row = 0;
		qsort(stone, K, sizeof(_STONE), compare_row);
		for (i = 0; i < K; i++)
		{
			if (stone[i].check == 0)
			{
				if (tmp_num == 0)
				{
					tmp_num = stone[i].row;
					//printf("%d\n", tmp_num);
					continue;
				}

				if (tmp_num == stone[i].row)
				{
					count++;
					if (count > max_row)
					{
						max_row = count;
						max_row_idx = stone[i].row;
					}
				}
				else
				{
					count = 1;
					tmp_num = stone[i].row;
				}
			}
			else
				check_count++;
		}

		//printf("row = %d\n", max_row_idx);

		if (check_count == K) break;

		qsort(stone, K, sizeof(_STONE), compare_col);

		count = 0;
		tmp_num = 0;
		check_count = 0;
		max_col = 0;
		for (i = 0; i < K; i++)
		{
			if (stone[i].check == 0)
			{
				if (tmp_num == 0)
				{
					tmp_num = stone[i].col;
					continue;
				}

				if (tmp_num == stone[i].col)
				{
					count++;
					if (count > max_col)
					{
						max_col = count;
						max_col_idx = stone[i].col;
					}
				}
				else
				{
					count = 1;
					tmp_num = stone[i].col;
				}
			}
			else
				check_count++;
		}

		//printf("col = %d\n", max_col_idx);

		if (check_count == K) break;

		

		// row, col 수 중 가장 많은 거 돌멩이 줍기
		if (max_row > max_col)
		{
			for (i = 0; i < K; i++)
			{
				if (stone[i].row == max_row_idx)
				{

						if (stone[i].check == 0)
						{
							stone[i].check = 1;
						}
					
				}
			}
			result++;
		}
		else 
		{
			for (i = 0; i < K; i++)
			{
				if (stone[i].col == max_col_idx)
				{

						if (stone[i].check == 0)
						{
							stone[i].check = 1;
						}
					
				}
			}
			result++;
		}
	}
	
	printf("%d\n", result);

}