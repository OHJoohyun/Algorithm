#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int start;
	int end;
	int weight;
} _BOX;

_BOX box[10000];

int N, C, M;

int compare(const void*a, const void*b)
{
	int v1, v2, v3, v4;
	v1 = ((_BOX *)a)->start;
	v2 = ((_BOX *)b)->start;
	v3 = ((_BOX *)a)->end;
	v4 = ((_BOX *)b)->end;

	if (v3 > v4) return 1;
	else if (v3 == v4)
	{
		if (v1 > v2) return 1;
		else if (v1 == v2) return 0;
		else return -1;
	}
	else return -1;
}

void show()
{
	for (int i = 0; i < M; i++)
	{
		printf("%d %d %d\n", box[i].start, box[i].end, box[i].weight);
	}
}

int main()
{
	int i;
	int s, e, w;
	int total = 0;

	scanf("%d %d", &N, &C);
	scanf("%d", &M);
	for (i = 0; i < M; i++)
	{
		scanf("%d %d %d", &s, &e, &w);
		box[i].start = s;
		box[i].end = e;
		box[i].weight = w;
	}

	qsort(box, M, sizeof(_BOX), compare);

	show();

	for (i = 0; i < M; i++)
	{
	






	}
}