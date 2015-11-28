#include <stdio.h>

int N, m, M, T, R;

int main()
{
	int mac = 0;
	int count = 0;
	int time = 0;
	scanf("%d %d %d %d %d", &N, &m, &M, &T, &R);

	if (m + T > M)
	{
		printf("-1\n");
		return 0;
	}

	mac = m;

	while (1)
	{
		if (count == N) break;
		//printf("mac = %d\n", mac);
		if (mac + T <= M)
		{
			mac = mac + T;
			count++;
			time++;
		}
		else if (mac + T > M)
		{
			mac = mac - R;
			if (mac < m)
				mac = m;
			time++;
		}
	}

	printf("%d\n", time);

	return 0;
}