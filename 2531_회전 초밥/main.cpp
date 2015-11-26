#include <stdio.h>
#include <string.h>

int check[3001];
int N, d, k, c;
int sushi[30001];

int main()
{
	int i, j;
	int count;
	int sum;
	int max = 0;
	
	scanf("%d %d %d %d", &N, &d, &k, &c);
	for (i = 0; i < N; i++)
	{
		scanf("%d", &sushi[i]);
	}
	for (i = 0; i < N; i++)
	{
		memset(check, 0, sizeof(check));
		sum = 1;
		count = 1;
		check[sushi[i]] = 1;
		j = i + 1;
		if (j == N) j = 0;
		
		while (1)
		{
			if (count == k) break;
			if (check[sushi[j]] == 0)
			{
				sum++;
				count++;
				check[sushi[j]] = 1;
				j++;
				if (j == N) j = 0;
			}
			else if (check[sushi[j]] == 1)
			{
				j++;
				count++;
				if (j == N) j = 0;
			}
		}
		
		if (check[c] == 0) sum++;
		
		if (sum > max)
		{
			max = sum;
		}
	}
	printf("%d\n", max);
}