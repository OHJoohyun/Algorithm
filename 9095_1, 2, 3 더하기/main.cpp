#include <stdio.h>
#include <string.h>

int main()
{
	int T, t_case;

	scanf("%d", &T);

	for (t_case = 0; t_case < T; t_case++)
	{
		int arr[12];
		
		int i, N;
		
		scanf("%d", &N);

		memset(arr, 0, sizeof(arr));

		arr[0] = 1;

		for (i = 1; i <= N; i++)
		{
			arr[i] = arr[i] + arr[i - 1];
		}

		for (i = 2; i <= N; i++)
		{
			arr[i] = arr[i] + arr[i - 2];
		}

		for (i = 3; i <= N; i++)
		{
			arr[i] = arr[i] + arr[i - 3];
		}

		printf("%d\n", arr[N]);
	}
	return 0;
}