#include <stdio.h>
#include <stdlib.h>

int N, M, K;
int row[200];
int col[200];

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
	int i, type, line;
	int a, b;
	int max_row, max_col;
	scanf("%d %d", &M, &N);
	scanf("%d", &K);


	row[0] = 0;
	col[0] = 0;
	a = 1;
	b = 1;

	for (i = 0; i < K; i++)
	{
		scanf("%d %d", &type, &line);
		if (type == 0) //0¹ø
		{
			row[a] = line;
			a++;
		}
		else // 1¹ø
		{
			col[b] = line;
			b++;
		}
	}

	qsort(row, a, sizeof(int), compare);
	qsort(col, b, sizeof(int), compare);
	
	if (a == 1) max_row = N;
	else
	{
		max_row = 0;
		row[a] = N;
		for (i = 1; i <= a; i++)
		{
			if (row[i] - row[i - 1] > max_row)
			{
				max_row = row[i] - row[i - 1];
			}
		}
	}

	if (b == 1) max_col = M;
	else
	{
		max_col = 0;
		col[b] = M;
		for (i = 1; i <= b; i++)
		{
			if (col[i] - col[i - 1] > max_col)
			{
				max_col = col[i] - col[i - 1];
			}
		}
	}

	//printf("%d\n", max_row);
	//printf("%d\n", max_col);
	printf("%d\n", (max_row * max_col));

}