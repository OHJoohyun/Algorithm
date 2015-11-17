#include <stdio.h>
#include <string.h>

typedef struct {
	int row;
	int col;
	int depth;
} _COORDI;

_COORDI dest;
_COORDI point[90000];

int Dy[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int Dx[8] = { -1, -2, -2, -1, 1, 2, 2, 1 };

int T, N;
int map[300][300] = { 0 };

void bfs(int row, int col)
{
	int head, tail;
	int i;
	int row_t, col_t;

	head = 0;
	tail = 0;

	map[row][col] = 1;
	point[tail].row = row;
	point[tail].col = col;
	point[tail].depth = 0;
	tail++;

	while (1)
	{
		if (head == tail) break;

		if (point[head].row == dest.row && point[head].col == dest.col)
		{
			dest.depth = point[head].depth;
			return;
		}

		for (i = 0; i < 8; i++)
		{
			row_t = point[head].row + Dy[i];
			col_t = point[head].col + Dx[i];
			
			if (row_t >= 0 && row_t < N && col_t >= 0 && col_t < N)
			{
				if(map[row_t][col_t] == 0)
				{ 
					map[row_t][col_t] = 1;
					point[tail].row = row_t;
					point[tail].col = col_t;
					point[tail].depth = point[head].depth + 1;
					tail++;
				}
			}
		}

		head++;
	}
}

int main()
{
	int tcase;
	scanf("%d", &T);
	for (tcase = 0; tcase < T; tcase++)
	{
		memset(map, 0, sizeof(map));
		int s_row, s_col;
		scanf("%d", &N);
		scanf("%d %d", &s_row, &s_col);
		scanf("%d %d", &dest.row, &dest.col);
		dest.depth = -1;
		bfs(s_row, s_col);

		printf("%d\n", dest.depth);
	}
	return 0;
}