#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	int start;
	int end;
	int weight;
} _EDGE;

_EDGE edge[300000];

int V, E;
int S;
int path[20001];
int check[20001];
int queue[20001];

int compare(const void *arg1, const void *arg2)
{
	int v1, v2;
	v1 = ((_EDGE*)arg1)->start;
	v2 = ((_EDGE*)arg2)->start;

	if (v1 < v2) return -1;
	else if (v1 == v2) return 0;
	else return 1;
}

int main()
{
	int i, j, N;
	int head, tail;
	int tmp = 0;

	memset(path, 0x1f, sizeof(path));
	memset(check, 0, sizeof(check));

	head = 0;
	tail = 0;

	scanf("%d %d", &V, &E);
	scanf("%d", &S);

	for (i = 0; i < E; i++)
	{
		scanf("%d", &edge[i].start);
		scanf("%d", &edge[i].end);
		scanf("%d", &edge[i].weight);
	}

	qsort(edge, E, sizeof(_EDGE), compare);
		
	queue[tail] = S;
	tail++;
	check[S] = 1;
	path[S] = 0;

	for (i = 0; i < E; i++)
	{	
		if (head == tail) break;

		if (edge[i].start != queue[head])
		{
			head++;
		}

		if (edge[i].start == S)
		{
			path[edge[i].end] = edge[i].weight;
			if (check[edge[i].end] == 0)
			{
				queue[tail] = edge[i].end;
				tail++;
				check[edge[i].end] = 1;
			}
		}

		else if (edge[i].start == queue[head])
		{
			if (check[edge[i].end] == 0)
			{
				queue[tail] = edge[i].end;
				tail++;
				check[edge[i].end] = 1;
			}

			tmp = path[edge[i].start] + edge[i].weight;
			if (path[edge[i].end] > tmp)
			{
				path[edge[i].end] = tmp;
			}
		}
	}
	
	for (i = 1; i <= V; i++)
	{
		if (path[i] > 65535) printf("INF\n");
		else printf("%d\n", path[i]);
	}
	return 0;
}