#include <stdio.h>
#include <string.h>

int path[1000][1000];
int visit[10000];
int dist[10000];
int check[10000];
int queue[10000];

int N, E;
int fisrt, second;
int find = 0;

void findpath(int vertex)
{
	int i;
	int head, tail;
	head = 0;
	tail = 0;

	//memset(check, 0x1f, sizeof(check));
	memset(queue, 0, sizeof(queue));

	for (i = 1; i <= N; i++)
	{
		check[i] == 9999;
	}

	check[vertex] = 0;

	//printf("%d", check[0]);

	for (i = 1; i <= N; i++)
	{
		if (path[vertex][i] > 0)
		{
			queue[tail] = i;
			tail++;
			check[i] = path[vertex][i];
		}
	}

	while (1)
	{
		if (head == tail) break;

		for (i = 1; i <= N; i++)
		{
			if (path[queue[head]][i] > 0)
			{
				if (check[i] == 9999)
				{
					queue[tail] = i;
					tail++;
				}

				if (check[i] > check[queue[head]] + path[queue[head]][i])
					check[i] = check[queue[head]] + path[queue[head]][i];
			}
		}
		head++;
	}

}

/*
void dikstra(int vertex)
{
	
	memset(visit, 0, sizeof(visit));

	int min = 999999;
	int temp;
	int i, j;

	for (i = 1; i <= N; i++)
	{
		dist[i] = 9999;
	}

	dist[vertex] = 0;
	for (i = 1; i <= N; i++)
	{
		min = 999999;
		for (j = 1; j <= N; j++)
		{
			if (min > dist[j] && visit[j] == 0)
			{
				min = dist[j];
				temp = j;
			}
		}

		visit[temp] = 1;

		for (j = 1; j <= N; j++)
		{
			if (dist[j] > dist[temp] + path[temp][j] && path[temp][j] != 0)
			{
				dist[j] = dist[temp] + path[temp][j];
			}
		}
	}

}
*/
int main()
{
	int i, j;
	int row, col, weight;
	scanf("%d %d", &N, &E);

	for (i = 0; i < E; i++)
	{
		scanf("%d %d %d", &row, &col, &weight);
		path[row][col] = weight;
		path[col][row] = weight;
	}

	scanf("%d %d", &fisrt, &second);

	int sum1 = 0;
	int sum2 = 0;

	findpath(1);
	sum1 += check[fisrt];
	sum2 += check[second];

	findpath(fisrt);
	sum1 += check[second];
	sum2 += check[N];

	findpath(second);
	sum1 += check[N];
	sum2 += check[fisrt];

	if (sum1 >= 9999 && sum2 >= 9999)
	{
		printf("-1\n");
		return 0;
	}

	if (sum1 > sum2)
	{
		printf("%d\n", sum2);
	}
	else
	{
		printf("%d\n", sum1);
	}

	return 0;

}