#include <stdio.h>


void quick(int number[], int left, int right);
int main()
{
	int arr[6] = { 4, 5, 1, 3 ,7 ,9 };
	quick(arr, 0, 5);
	for (int i = 0; i < 6; i++)
	{
		printf("%d\n", arr[i]);
	}
	return 0;
}

void quick(int number[], int left, int right)
{
	if (left == right) return;
	int i, j, pivot;
	i = left;
	j = right;
	pivot = number[left];

	while (left < right)
	{
		while (number[right] >= pivot && (left < right))
			right--;
		
		if (left != right)
		{
			number[left] = number[right];
			left++;
		}

		while (number[left] <= pivot && (left < right))
			left++;

		if (left != right)
		{
			number[right] = number[left];
			right--;
		}
	}

	number[left] = pivot;
	pivot = left;
	left = i;
	right = j;

	if (left < pivot)
		quick(number, left, pivot - 1);
	if (right > pivot)
		quick(number, pivot + 1, right);
}