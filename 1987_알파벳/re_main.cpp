#include <stdio.h>

int N, M;
char map[30][30];
int check[100] = { 0 };

int Dy[4] = { -1,1,0,0 };
int Dx[4] = { 0,0,-1,1 };

int max = 0;

void dfs(int row, int col, int count)
{
	int i;
	int row_t, col_t;

	if (max < count)
	{
		max = count;
	}

	check[(int)map[row][col]] = 1;

	for (i = 0; i < 4; i++)
	{
		row_t = row + Dy[i];
		col_t = col + Dx[i];
		if (row_t >= 0 && row_t < N && col_t >= 0 && col_t < M)
		{
			if(check[(int)map[row_t][col_t]] == 0)
			{ 
				//check[(int)map[row_t][col_t]] = 1;
				dfs(row_t, col_t, count + 1);
				check[(int)map[row_t][col_t]] = 0;
			}
		}
	}
	return;
}

int main()
{
	int i;
	scanf("%d %d", &N, &M);
	for (i = 0; i < N; i++)
	{
		scanf("%s", map[i]);
	}

	dfs(0, 0, 1);

	printf("%d\n", max);
}