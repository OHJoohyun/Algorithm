#include <stdio.h>

int N, M, S;
int graph[1001][1001] = { {0}, {0} };
int vertex_dfs[1001] = { 0 };
int vertex_bfs[1001] = { 0 };
int queue[1001];
int head = 0;
int tail = 0;
int pop;

void dfs(int start);
void bfs(int start);

int main()
{
	int i;
	int row, col;
	scanf("%d %d %d", &N, &M, &S);
	for (i = 0; i < M; i++)
	{
		scanf("%d %d", &row, &col);
		graph[row][col] = graph[col][row] = 1;
	}

	dfs(S);
	printf("\n");
	bfs(S);
	printf("\n");

	return 0;
}

void dfs(int start)
{
	int i;
	
	vertex_dfs[start] = 1;

	printf("%d ", start);
	
	for (i = 1; i < 1001; i++)
	{
		if (vertex_dfs[i] == 0 && graph[start][i] == 1)
		{
			dfs(i);
		}
	}
}

void bfs(int start)
{
	int i;
	vertex_bfs[start] = 1;
	queue[tail] = start;
	tail++;
	while (1)
	{
		if (head == tail) break;
		pop = queue[head];
		head++;
		printf("%d ", pop);
		for (i = 1; i < 1001; i++)
		{
			if (vertex_bfs[i] == 0 && graph[pop][i] == 1)
			{
				queue[tail] = i;
				tail++;
				vertex_bfs[i] = 1;
			}
		}
	}

}