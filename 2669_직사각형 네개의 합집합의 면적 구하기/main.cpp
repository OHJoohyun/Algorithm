#include <stdio.h>

int main()
{
	int map[101][101] = { 0 };
	int count = 0;
	int i, s_row, s_col, e_row, e_col;
	int y, x;
	for (i = 0; i < 4; i++)
	{
		scanf("%d %d %d %d", &s_col, &s_row, &e_col, &e_row);
		for (y = s_row; y < e_row; y++)
		{
			for (x = s_col; x < e_col; x++)
			{
				if (map[y][x] == 0)
				{
					map[y][x] = 1;
					count++;
				}
			}
		}
	}
	printf("%d\n", count);
}