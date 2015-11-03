#include <stdio.h>

typedef struct {
	int start;
	int end;
	int check;
} _EDGE;

_EDGE edge[10000];
_EDGE edge2[10000];

int vertex[1001] = { 0 };
int vertex2[1001] = { 0 };
int N, M, S;

void dfs();
void bfs();

int main()
{
	int i;

	scanf("%d %d %d", &N, &M, &S);
	for (i = 0; i < M; i++)
	{
		scanf("%d %d", &edge[i].start, &edge[i].end);
		edge[i].check = 0;
		edge2[i].start = edge[i].start;
		edge2[i].end = edge[i].end;
		edge2[i].check = edge[i].check;
	}

	vertex[0] = 1;
	vertex2[0] = 1;

	dfs();
	bfs();
	return 0;
}

void dfs()
{
	int i;
	int con = 0;
	int tmp;
	while (1)
	{
		con = 0;
		for (i = 0; i < N; i++)
		{
			if(vertex[i] == 0)
			{ 
				con = 1;
				break;
			}
		}

		if (con == 1)
		{
			tmp = S;
			for (i = 0; i < M; i++)
			{
				if(edge[i].check == 0)
				{ 
					if (edge[i].start == tmp)
					{
						edge[i].check = 1;
						if (vertex[edge[i].start] == 0)
						{
							printf("%d ", edge[i].start);
							vertex[edge[i].start] = 1;
							tmp = edge[i].end;
							if (vertex[edge[i].end] == 0)
							{
								printf("%d ", edge[i].end);
								vertex[edge[i].end] = 1;
							}
						}

						if (vertex[edge[i].end] == 0)
						{
							printf("%d ", edge[i].end);
							vertex[edge[i].end] = 1;
						}
					}
				}
			}
		}
		else if (con == 0)
		{ 
			printf("\n");
			break;
		}
	}
}

void bfs()
{
	int i;
	int con = 0;
	int tmp;
	while (1)
	{
		con = 0;
		for (i = 0; i < N; i++)
		{
			if (vertex2[i] == 0)
			{
				con = 1;
				break;
			}
		}

		if (con == 1)
		{
			tmp = S;
			for (i = 0; i < M; i++)
			{
				if (edge2[i].check == 0)
				{
					if (edge2[i].start == tmp)
					{
						edge2[i].check = 1;
						if (vertex2[edge2[i].start] == 0)
						{
							printf("%d ", edge2[i].start);
							vertex2[edge2[i].start] = 1;
							//tmp = edge2[i].end;
							if (vertex2[edge2[i].end] == 0)
							{
								printf("%d ", edge2[i].end);
								vertex2[edge2[i].end] = 1;
							}
						}

						if (vertex2[edge2[i].end] == 0)
						{
							printf("%d ", edge2[i].end);
							vertex2[edge2[i].end] = 1;
						}
					}
				}
			}
		}
		else if (con == 0)
		{
			printf("\n");
			break;
		}
	}
}