#include <stdio.h>
#include <string.h>

int relation[100][100] = { 0 };
int check[100] = { 0 };
int point[100] = { 0 };
int anw[100] = { 0 };

int N, min;

typedef struct {
	int people;
	int depth;
} _QUEUE;

_QUEUE queue[1000];

void bfs(int start)
{
	memset(queue, 0, sizeof(queue));
	int head, tail;
	int i, all = 0;
	head = 0;
	tail = 0;
	
	check[start] = 1;

	for (i = 1; i <= N; i++)
	{
		if (relation[start][i] == 1)
		{
			check[i] = 1;
			queue[tail].people = i;
			queue[tail].depth = 1;
			tail++;
		}
	}
	
	while (1)
	{
		if (head == tail) break;
		
		all = 0;
		
		for (i = 1; i <= N; i++)
		{
			if (check[i] == 1)
			{ 
				all++;
			}
		}

		//printf("all = %d\n", all);
		if (all == N)
		{
			point[start] = queue[head].depth ;
			if (point[start] < min)
				min = point[start];
			break;
		}

		for (i = 1; i <= N; i++)
		{
			if (relation[queue[head].people][i] == 1 && check[i] == 0)
			{
				queue[tail].people = i;
				queue[tail].depth = queue[head].depth + 1;
				tail++;
				//check[i] = 1;
			}
		}

		head++;
		check[queue[head].people] = 1;
	}

	return;
}

int main()
{
	int p1, p2, i;
	scanf("%d", &N);

	min = 999999;

	while (1)
	{
		scanf("%d %d", &p1, &p2);
		if (p1 == -1 && p2 == -1) break;
		relation[p1][p2] = 1;
		relation[p2][p1] = 1;
	}


	for (i = 1; i <= N; i++)
	{
		memset(check, 0, sizeof(check));
		bfs(i);
	}

	int count = 0;
	for (i = 1; i <= N; i++)
	{
		if (point[i] == min)
		{ 
			anw[count] = i;
			count++;
		}
	}

	printf("%d %d\n", min, count);
	for (i = 0; i < count; i++)
	{
		printf("%d ", anw[i]);
	}
	printf("\n");

	return 0;
}