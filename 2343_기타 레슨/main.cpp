#include <stdio.h>

int N, M;
int lesson[100001];
int min = 999999;

void b_search(int left, int right, int mid)
{
	int count = 1;
	int i, sum = 0;

	for (i = 1; i <= N; i++)
	{
		if (lesson[i - 1] > mid)
		{
			count += 12341234;
			continue;
		}
		
		if (lesson[i - 1] + sum <= mid)
		{
			sum += lesson[i - 1];
			continue;
		}

		sum = 0;
		sum += lesson[i - 1];
		count++;
	}

	if (left > right)
	{
		printf("%d\n", min);
		return;
	}

	if (count > M)
	{
		b_search(mid + 1, right, (mid + 1 + right) / 2);
	}

	else
	{
		if (mid < min)
		{
			min = mid;
		}
		//printf("min = %d\n", min);
		b_search(left, mid - 1, (left + mid - 1) / 2);
	}
}

int main()
{
	int i, maxsum = 0;
	scanf("%d %d", &N, &M);
	for (i = 0; i < N; i++)
	{
		scanf("%d", &lesson[i]);
		maxsum += lesson[i];
	}

	b_search(0, maxsum, maxsum);

	return 0;
}