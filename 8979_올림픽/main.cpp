#include <stdio.h>
#include <stdlib.h>



typedef struct {
	int num;
	int gold;
	int silver;
	int brozen;
} _MEDAL;

_MEDAL medal[1001];

int N, K;

int main()
{
	int i, find = 0;
	int count = 1;
	scanf("%d %d", &N, &K);

	medal[0].num = 0;
	medal[0].gold = 0;
	medal[0].silver = 0;
	medal[0].brozen = 0;
	
	for (i = 1; i <= N; i++)
	{
		scanf("%d %d %d %d", &medal[i].num, &medal[i].gold, &medal[i].silver, &medal[i].brozen);
		if (medal[i].num == K) find = i;
	}

	for (i = 0; i <= N; i++)
	{
		if (medal[i].gold > medal[find].gold ||
			(medal[i].gold == medal[find].gold && medal[i].silver > medal[find].silver) ||
			(medal[i].gold == medal[find].gold && medal[i].silver == medal[find].silver && medal[i].brozen > medal[find].brozen))
			count++;
	}
	printf("%d\n", count);
}