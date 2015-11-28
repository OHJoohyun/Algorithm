#include <stdio.h>
#include <string.h>

typedef struct {
	int red_row;
	int red_col;
	int blue_row;
	int blue_col;
	int red_count;
	int blue_count;
} _COORDI;

_COORDI point[2500] = { 0 };

int map[50][50] = { 0 };

int Dy[4] = { -1,1,0,0 };
int Dx[4] = { 0,0,-1,1 };

int N, M;

int min = 999999;

int bfs(int red_row, int red_col, int blue_row, int blue_col)
{
	int i, head, tail;
	int r_row_t, r_col_t, b_row_t, b_col_t;
	int res = 999999;
	
	head = 0;
	tail = 0;

	point[tail].red_row = red_row;
	point[tail].red_col = red_col;
	point[tail].blue_row = blue_row;
	point[tail].blue_col = blue_col;
	point[tail].red_count = 0;
	point[tail].blue_count = 0;
	tail++;

	while (1)
	{
		if (head == tail) break;

		for (i = 0; i < 4; i++)
		{
			r_row_t = point[head].red_row + Dy[i];
			r_col_t = point[head].red_col + Dx[i];
			b_row_t = point[head].blue_row + Dy[i];
			b_col_t = point[head].blue_col + Dx[i];
			if(map[r_row_t][r_col_t] == 2 && map[b_row_t][b_col_t] != 2)
			{
				//printf("╣И╬Н©х!\n");
				point[tail].red_row = r_row_t;
				point[tail].red_col = r_col_t;
				point[tail].blue_row = b_row_t;
				point[tail].blue_col = b_col_t;
				point[tail].red_count = point[head].red_count + 1;
				point[tail].blue_count = point[head].blue_count + 1;
				if (res > point[tail].red_count)
					res = point[tail].red_count;
				//return point[tail].red_count;
			}
			if (map[r_row_t][r_col_t] == 2 && map[b_row_t][b_col_t] == 2)
			{
				//return -1;
			}
			if (r_row_t == b_row_t && r_col_t == b_col_t)
			{
				//return -1;
			}
			if (map[r_row_t][r_col_t] != 1 && map[b_row_t][b_col_t] != 1)
			{
				point[tail].red_row = r_row_t;
				point[tail].red_col = r_col_t;
				point[tail].blue_row = b_row_t;
				point[tail].blue_col = b_col_t;
				point[tail].red_count = point[head].red_count + 1;
				point[tail].blue_count = point[head].blue_count + 1;
				tail++;
			}
			if (map[r_row_t][r_col_t] != 1 && map[b_row_t][b_col_t] == 1)
			{
				point[tail].red_row = r_row_t;
				point[tail].red_col = r_col_t;
				point[tail].blue_row = point[head].blue_row;
				point[tail].blue_col = point[head].blue_col;
				point[tail].red_count = point[head].red_count + 1;
				point[tail].blue_count = point[head].blue_count;
				tail++;
			}
			if (map[r_row_t][r_col_t] == 1 && map[b_row_t][b_col_t] != 1)
			{
				point[tail].red_row = point[head].red_row;
				point[tail].red_col = point[head].red_col;
				point[tail].blue_row = b_row_t;
				point[tail].blue_col = b_col_t;
				point[tail].red_count = point[head].red_count;
				point[tail].blue_count = point[head].blue_count + 1;
				tail++;
			}
		}
		head++;
	}
	return res;
}



void dfs(int red_row, int red_col, int blue_row, int blue_col, int count)
{
	if (count > 10)
	{
		//printf("-1\n");
		return;
	}
	
	if (map[red_row][red_col] == 2)
	{
		//printf("%d\n", count);
		if(count < min)
			min = count;
		return;
	}

	if (map[blue_row][blue_col] == 2)
	{
		return;
	}

	if (red_row == blue_row && red_col == blue_col)
	{
		//printf("-1\n");
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int red_row_t = red_row + Dy[i];
		int red_col_t = red_col + Dx[i];
		int blue_row_t = blue_row + Dy[i];
		int blue_col_t = blue_col + Dx[i];

		if (map[red_row_t][red_col_t] != 1 && map[blue_row_t][blue_col_t] != 1)
		{
			dfs(red_row_t, red_col_t, blue_row_t, blue_col_t, count + 1);
		}
		else if (map[red_row_t][red_col_t] != 1  && map[blue_row_t][blue_col_t] == 1)
		{
			dfs(red_row_t, red_col_t, blue_row, blue_col, count + 1);
		}
		else if (map[red_row_t][red_col_t] == 1 && map[blue_row_t][blue_col_t] != 0)
		{
			dfs(red_row, red_col, blue_row_t, blue_col_t, count + 1);
		}
	}

	return;
}

int main()
{
	int i, j;
	int r_row, r_col, b_row, b_col;
	//int goal_row, goal_col;
	int result;
	scanf("%d %d", &N, &M);

	for (i = 0; i < N; i++) // ют╥б
	{
		for (j = 0; j < M; j++)
		{
			scanf("%d", &map[i][j]);
			if (map[i][j] == 4)
			{
				r_row = i;
				r_col = j;
			}
			if (map[i][j] == 3)
			{
				b_row = i;
				b_col = j;
			}
		}
	}

	//dfs(r_row, r_col, b_row, b_col, 0);

	result = bfs(r_row, r_col, b_row, b_col);

	printf("%d\n", result);
}