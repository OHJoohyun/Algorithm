#include <stdio.h>
#include <string.h>

char map[50][50];
int visited[50][50] = { 0 };
int max = 0;
int anw = 0;
int N, M;

typedef struct {
	int row;
	int col;
} _COODI;

_COODI point[2500];

int Dy[4] = { -1, 0, 1, 0 };
int Dx[4] = { 0, -1, 0, 1 };

int bfs(int row, int col)
{
	int head , tail;
	int max;
	int i;
	int row_t, col_t;

	max = -1;
	head = 0;
	tail = 0;

	memset(visited, -1, sizeof(visited)); // 초기화
	
	memset(point, -1, sizeof(point)); // 초기화

	point[tail].row = row;
	point[tail].col = col;
	visited[row][col] = 0;
	
	tail++;

	while (1)
	{
		if (head == tail) break;

		for (i = 0; i < 4; i++) // 상 하 좌 우 
		{
			row_t = point[head].row + Dy[i];
			col_t = point[head].col + Dx[i];
			//printf("row_t = %d\n", row_t);
			//printf("col_t = %d\n", col_t);
			if (row_t >= 0 && row_t < N && col_t >= 0 && col_t < M) // MAP 범위 안에 존재
			{
				if (visited[row_t][col_t] == -1 && map[row_t][col_t] == 'L')
				{
					point[tail].row = row_t;
					point[tail].col = col_t;
					tail++;
					visited[row_t][col_t] = visited[point[head].row][point[head].col] + 1;
					if (visited[row_t][col_t] > max)
					{ 
						max = visited[row_t][col_t];
						//printf("max = %d\n", max);
					}
				}
			}
		}
		
		head++;
	}
	//printf("max = %d\n", max);
	return max;
}

int main()
{
	int i, j, k;

	scanf("%d %d", &N, &M);
	for (i = 0; i < N; i++)
	{
		scanf("%s", map[i]);
	}

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			if (map[i][j] == 'L')
			{
				//printf("row = %d\n", i);
				//printf("col = %d\n", j);
				anw = bfs(i, j);
				if (anw > max)
				{
					max = anw;
				}
			}	
		}
	}
	printf("%d\n", max);
}
