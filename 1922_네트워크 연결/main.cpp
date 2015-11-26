#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int start;
	int end;
	int weight;
	int check;
} _EDGE;

_EDGE point[100000];
int check[1001];

int N, M;

int sum = 0;

int compare(const void *a, const void *b)
{
	int v1, v2;
	v1 = ((_EDGE *)a)->weight;
	v2 = ((_EDGE *)b)->weight;

	if (v1 > v2) return 1;
	else if (v1 == v2) return 0;
	else return -1;
}

void show()
{
	printf("\n");
	for (int i = 0; i < M; i++)
	{
		printf("%d %d %d\n", point[i].start, point[i].end, point[i].weight);
	}
}

int isCycle(int start, int end)
{
	int check1 = 0;
	int check2 = 0;

	for (int i = 0; i < M; i++)
	{
		if (point[i].check == 1)
		{
			if (point[i].start == start || point[i].end == start) 
				check1 = 1;
			if (point[i].start == end || point[i].end == end) 
				check2 = 1;
		}
	}

	if (check1 == 1 && check2 == 1)
		return 1;
	else
		return 0;
}

void kruskal()
{
	for (int i = 0; i < M; i++)
	{
		if (isCycle(point[i].start, point[i].end) == 0)
		{
			//printf("%d %d %d\n", point[i].start, point[i].end, point[i].weight);
			point[i].check = 1;
			sum = sum + point[i].weight;
		}
	}
}

int main()
{
	int i, row, col, weight;
	
	scanf("%d %d", &N, &M);
	for (i = 0; i < M; i++)
	{
		scanf("%d %d %d", &point[i].start, &point[i].end, &point[i].weight);
	}

	qsort(point, M, sizeof(_EDGE), compare);

	printf("\n");
	kruskal();
	show();

	printf("%d\n", sum);
}
