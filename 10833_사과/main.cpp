#include <stdio.h>

int main()
{
	int N;
	scanf("%d", &N);
	int student, apple, rem = 0;

	for (int i = 0; i < N; i++)
	{
		scanf("%d %d", &student, &apple);
		rem += apple % student;
	}

	printf("%d\n", rem);
	return 0;
}