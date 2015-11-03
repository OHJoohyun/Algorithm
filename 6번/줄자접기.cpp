#include <stdio.h>

int main()
{
	int length;
	int i, j;
	float arr[3][3];
	float start, end, mid;
	float temp;
	float result = 0;

	scanf_s("%d", &length);
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 2; j++)
		{
			scanf_s("%f", &arr[i][j]);
			arr[i][2] = 0;
		}
	}
	start = 0;
	end = length;
	for (i = 0; i < 3; i++)
	{
		if (arr[i][2] == 0)
		{
			mid = (arr[i][0] + arr[i][1]) / 2; // 중간값
			for (j = i + 1; j < 3; j++) // 밑으로 중간값이 같은 지 확인
			{
				if ((arr[j][0] + arr[j][1]) / 2 == mid)
				{
					arr[j][2] = 1;
				}
			}
			if (end - mid > mid - start) // 오른쪽이 더 길다
			{
				start = mid;
				for (j = i + 1; j < 3; j++) // 자리 이동
				{
					if (arr[j][2] == 0)
					{
						if (arr[j][0] < mid)
						{
							temp = mid - arr[j][0];
							arr[j][0] = mid + temp;
						}
						if (arr[j][1] < mid)
						{
							temp = mid - arr[j][1];
							arr[j][1] = mid + temp;
						}
					}
				}
			}
			else // 왼쪽이 더 길다
			{
				end = mid;
				for (j = i + 1; j < 3; j++) // 자리 이동
				{
					if (arr[j][2] == 0)
					{
						if (arr[j][0] > mid)
						{
							temp = arr[j][0] - mid;
							arr[j][0] = mid - temp;
						}
						if (arr[j][1] > mid)
						{
							temp = arr[j][1] - mid;
							arr[j][1] = mid - temp;
						}
					}
				}
			}
		}
	}

	//printf("%f\n", start);
	//printf("%f\n", end);
	printf("%.1f\n", end - start);

}