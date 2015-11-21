#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	int row;
	int col;
	char type;
	int count;
} _FIRE;

_FIRE fire[1000000];
char map[1001][1001];

int head;
int tail;

int Dy[4] = { -1, 1, 0, 0 };
int Dx[4] = { 0, 0, -1, 1 };

int count, find;

int result;

int T, N, M;

void show()
{
	int i, j;
	
	printf("\n");
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			printf("%c", map[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int compare(const void *a, const void * b) {
	char v1, v2;
	v1 = ((_FIRE *)a)->type;
	v2 = ((_FIRE *)b)->type;

	if (v1 < v2) return 1;
	else if (v1 == v2) return 0;
	else return -1;
}

void bfs()
{
	int i, j;
	int row_t, col_t;
	char tmp;
	
	while (1)
	{
		if (head == tail) break;

		for (i = 0; i < 4; i++)
		{
			row_t = fire[head].row + Dy[i];
			col_t = fire[head].col + Dx[i];
			tmp = fire[head].type;
			if (tmp == '*')
			{
				if (map[row_t][col_t] == '.' || map[row_t][col_t] == '@')
				{
					if (row_t >= 0 && row_t < N && col_t >= 0 && col_t < M)
					{ 
						map[row_t][col_t] = '*';
						fire[tail].row = row_t;
						fire[tail].col = col_t;
						fire[tail].type = tmp;
						tail++;
					}
				}
			}
			else if (tmp == '@' && map[fire[head].row][fire[head].col] == '@')
			{
				if (map[row_t][col_t] == '.')
				{
					map[row_t][col_t] = '@';
					fire[tail].row = row_t;
					fire[tail].col = col_t;
					fire[tail].type = tmp;
					fire[tail].count = fire[head].count + 1;
					tail++;
				}

				if (row_t < 0 || row_t >= N || col_t < 0 || col_t >= M)
				{
					find = fire[head].count + 1;
					if (find < result)
						result = find;
				}	
			}
		}
		//show();
		head++;
	}
}

int main()
{
	int i, j;
	int t_case;
	char a;
	scanf("%d", &T);

	for (t_case = 0; t_case < T; t_case++)
	{
		memset(map, 0, sizeof(map));
		
		memset(fire, 0, sizeof(fire));

		find = 0;
		head = 0;
		tail = 0;
		result = 999999;
		
		scanf("%d %d", &M, &N);
		
		for (i = 0; i < N; i++)
		{
			scanf("%s", map[i]);
		}

		for (i = 0; i < N; i++)
		{
			for (j = 0; j < M; j++)
			{
				if (map[i][j] == '*' || map[i][j] == '@')
				{
					fire[tail].row = i;
					fire[tail].col = j;
					fire[tail].type = map[i][j];
					fire[tail].count = 0;
					tail++;
				}
			}
		}
	
		qsort(fire, tail, sizeof(_FIRE), compare);

		bfs();
		
		if (find == 0)
			printf("IMPOSSIBLE\n");
		else
			printf("%d\n", result);
	}
	return 0;
}