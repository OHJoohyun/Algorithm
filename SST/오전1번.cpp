#include <stdio.h>

int main()
{
	int super, sub, N;
	int classes[50];
	int i, j;
	int t1, t2, t3;
	int total = 0;
	int min = 99999;
	int sum = 0;

	scanf("%d %d", &super, &sub);
	scanf("%d", &N);
	for (i = 0; i < N; i++)
	{
		scanf("%d", &classes[i]);
	}

	for (i = 0; i < N; i++)
	{
		sum = 0;
		t1 = 0;
		t2 = 0;

		if (classes[i] - super > 0) // 고사장 인원이 총감독관이 감독하는 인원보다 많음
		{
			sum = 1;
			t1 = classes[i] - super;
			t2 = t1 / sub;
			if (t1%sub > 0)
			{
				t2++;
			}
			sum = sum + t2;
		}
		else // 고사장의 인원이 총감독관이 감독하는 인원보다 작음
		{
			sum = 1;
		}

		//printf("sum = %d\n", sum);
		
		for (j = 0; j < N; j++)
		{
			if (j == i) continue;
			t1 = classes[j] / sub;
			if (classes[j] % sub > 0)
			{
				t1++;
			}
			//printf("t1 = %d\n", t1);
			sum = sum + t1;
		}
		
		//printf("sum = %d\n", sum);
		
		if (min > sum)
		{
			min = sum;
		}
	}

	printf("%d\n", min);
}