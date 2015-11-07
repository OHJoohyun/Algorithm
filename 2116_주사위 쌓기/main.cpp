#include <stdio.h>

int main()
{
	int count;
	int i, j, k;
	int dice[10001][6];
	int floor, top;
	int f_pos, t_pos;
	int max = 0;
	int sum = 0;
	int total = 0;
	int start_floor;

	scanf("%d", &count);
	for (i = 0; i < count; i++)
	{
		for (j = 0; j < 6; j++)
		{
			scanf("%d", &dice[i][j]);
		}
	}

	for (i = 1; i < 7; i++) // 바닥이 1-6 시작 1,2,3,4,5,6 6번 진행
	{
		start_floor = i;
		floor = i;
		for (k = 0; k < count; k++) // 주사위 갯수 만큼 반복
		{
			for (j = 0; j < 6; j++)
			{
				if (dice[k][j] == floor)
					f_pos = j;
			}

			if (f_pos == 0)
				top = dice[k][5];
			else if (f_pos == 1)
				top = dice[k][3];
			else if (f_pos == 2)
				top = dice[k][4];
			else if (f_pos == 3)
				top = dice[k][1];
			else if (f_pos == 4)
				top = dice[k][2];
			else if (f_pos == 5)
				top = dice[k][0];

			for (j = 0; j < 6; j++)
			{
				if (dice[k][j] == top)
					t_pos = j;
			}

			for (j = 0; j < 6; j++)
			{
				if (dice[k][j] != floor && dice[k][j] != top)
				{
					if (dice[k][j] > max)
					{
						max = dice[k][j];
					}
				}
			}

			sum = sum + max;

			max = 0;
			floor = top;
		}

		if (total < sum)
		{
			total = sum;
		}
		sum = 0;
	}

	printf("%d\n", total);

}
