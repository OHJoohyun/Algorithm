#include <stdio.h>

int main()
{
	int money[10] = { 0 };
	int i, don = 1;
	int candy, K;
	int myMoney;
	int total, plus;
	for (i = 0; i < 10; i++)
	{
		money[i] = don;
		don *= 10;
	}
	scanf("%d %d", &candy, &K);
	myMoney = money[K];
	/*
	if (myMoney > candy)
	{
		printf("%d\n", myMoney);
		return 0;
	}
	*/

	total = candy / myMoney;
	plus = candy % myMoney;
	if (plus >= myMoney / 2 && myMoney != 1)
	{
		total++;
	}
	printf("%d\n", total * myMoney);
}