#include <stdio.h>

int main()
{
	int paper[101][101] = { 0 };
	int anw[201] = { 0 };
	int s_row, s_col, width, height;
	int N;
	int i, j, r, c;

	scanf("%d", &N);
	
	for (i = 1; i <= N; i++)
	{
		scanf("%d %d %d %d", &s_col, &s_row, &width, &height);
		for (r = s_row; r < s_row + height; r++)
		{
			for (c = s_col; c < s_col + width; c++)
			{
				if (r >= 0 && r < 1001 && c >= 0 && c < 1001)
				{
					paper[r][c] = i;
				}
			}
		}
	}

	for (r = 0; r < 101; r++)
	{
		for (c = 0; c < 101; c++)
		{
			//printf("%d", paper[r][c]);
			anw[paper[r][c]] += 1;
		}
		//printf("\n");
	}
	
	for (i = 1; i <= N; i++)
	{
		printf("%d\n", anw[i]);
	}

	return 0;
}