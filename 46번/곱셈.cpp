#include <stdio.h>

int main()
{
	int num1, num2;
	int arr[3];

	scanf_s("%d", &num1);
	scanf_s("%d", &num2);

	arr[0] = num2 / 100;
	arr[1] = (num2 - (arr[0]*100)) / 10;
	arr[2] = num2 % 100;
	arr[2] = arr[2] % 10;

	printf("%d\n", num1 * arr[2]);
	printf("%d\n", num1 * arr[1]);
	printf("%d\n", num1 * arr[0]);
	printf("%d\n", num1 * num2);

}