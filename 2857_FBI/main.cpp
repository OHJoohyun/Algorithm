#include <stdio.h>
#include <string.h>

int main()
{
	char police[6][10];
	char *check;
	int count = 0;

	for (int i = 1; i < 6; i++)
	{
		scanf("%s", police[i]);
		check = strstr(police[i], "FBI");
		if (check == NULL) continue;
		else
		{
			count++;
			printf("%d\n", i);
		}
	}
	if (count == 0)
	{
		printf("HE GOT AWAY!\n");
	}
	return 0;
}