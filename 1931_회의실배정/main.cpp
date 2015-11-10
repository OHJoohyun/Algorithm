#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	int start;
	int end;
} _MEETING;

_MEETING meeting[100000];
_MEETING tmp;

int N;

int compare(const void *arg1, const void * arg2) {
	int v1, v2, v3, v4;
	v1 = ((_MEETING *)arg1)->end;
	v2 = ((_MEETING *)arg2)->end;

	v3 = ((_MEETING *)arg1)->start;
	v4 = ((_MEETING *)arg2)->start;

	if (v1 < v2) return -1;
	else if (v1 == v2) 
	{ 
		if (v3 < v4) return -1;
		else if (v3 == v4) return 0;
		else return 1;
	}
	else return 1;
}

int main()
{	
	int i, j;
	int end_time;
	int count;
	int min_index;

	memset(meeting, 0, sizeof(meeting));

	count = 1;

	scanf("%d", &N);
	for (i = 0; i < N; i++)
	{
		scanf("%d", &meeting[i].start);
		scanf("%d", &meeting[i].end);
	}

	qsort(meeting, N, sizeof(_MEETING), compare);


	/*
	printf("\n");
	for (i = 0; i < N; i++)
	{
		printf("%d %d\n", meeting[i].start, meeting[i].end);
	}
	*/

	end_time = meeting[0].end;

	for (i = 1; i < N; i++)
	{
		if (end_time <= meeting[i].start)
		{
			end_time = meeting[i].end;
			count++;
		}
	}

	printf("%d\n", count);

	return 0;
}

