#include <stdio.h>
#include <string.h>

int T, N, M;
int map[101][101] = { 0 };
int count[101] = { 0 };

int main()
{
	int t_case;
	int i, j, k;
	int sum;
	int tmp;
	scanf("%d", &T);
	for (t_case = 0; t_case < T; t_case++)
	{
		memset(map, 0, sizeof(map));
		memset(count, 0, sizeof(count));
		sum = 0;

		scanf("%d %d", &N, &M);
		for (i = 1; i <= N; i++)
		{
			for (j = 1; j <= M; j++)
			{
				scanf("%d", &map[i][j]);
				if (map[i][j] == 1)
				{
					count[j] = count[j] + 1;
				}
			}
		}
		
		for (j = 1; j <= M; j++)
		{
			tmp = 1;
			for (i = N; i >= 1; i--)
			{
				if (map[i][j] == 1)
				{
					sum = sum + ((N - i + 1) - tmp);
					tmp++;
				}
			}
		}
		printf("%d\n", sum);
	}
}