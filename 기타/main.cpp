#include <stdio.h>

int number[21];
int check[21] = { 0 };
int N, S;
int count = 0;

void subset(int index, int weight, int total)
{
	if ((weight + total >= S) && (weight == S || weight + number[index + 1] <= S))
	{
		if (weight == S) count++;
		else
		{
			check[index + 1] = 1;
			subset(index + 1, weight + number[index + 1], total - number[index + 1]);
			check[index + 1] = 0;
			subset(index + 1, weight, total - number[index + 1]);
		}
	}
}
int main()
{
	int i, sum = 0;
	scanf("%d %d", &N, &S);
	for (i = 0; i < N; i++)
	{
		scanf("%d", &number[i]);
		sum += number[i];
	}

	subset(0, 0, sum);

	printf("%d\n", count);
	return 0;

}
