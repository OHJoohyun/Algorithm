#include <stdio.h>

int main()
{
	char coin[20][20];
	char tmp[20][20];
	int N;
	int i, j;
	int row_idx, col_idx;
	int min, anw;
	int tail;
	min = 4001;
	scanf("%d", &N);
	for (i = 0; i < N; i++)
	{
		scanf("%s", coin[i]);
	}	

	for (i = 0; i < N; i++)
	{
		tail = 0;
		for (j = 0; j < N; j++)
		{
			if (coin[i][j] == 'T')
				tail++;
		}
		if (tail < min)
		{
			min = tail;
			row_idx = i;
		}
	}

	for (j = 0; j < N; j++)
	{
		tail = 0;
		for (i = 0; i < N; i++)
		{
			if (coin[i][j] == 'T')
				tail++;
		}
		if (tail < min)
		{
			min = tail;
			col_idx = j;
		}
	}

	
}