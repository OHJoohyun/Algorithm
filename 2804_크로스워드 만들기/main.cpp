#include <stdio.h>
#include <string.h>

int main()
{
	char n1[30];
	char n2[30];
	int tmp1, tmp2;
	tmp1 = -1;
	tmp2 = -1;

	scanf("%s %s", n1, n2);

	int i, j;
	for (i = 0; i < strlen(n1); i++)
	{
		for (j = 0; j < strlen(n2); j++)
		{
			if (n1[i] == n2[j])
			{
				tmp1 = i;
				tmp2 = j;
				break;
			}
		}
		if (tmp1 > -1) break;
	}

	//printf("%d %d\n", tmp1, tmp2);

	for (i = 0; i < strlen(n2); i++)
	{
		if (i == tmp2)
		{
			puts(n1);
			continue;
		}
		for (j = 0; j < strlen(n1); j++)
		{
			if (j == tmp1)
			{
				printf("%c", n2[i]);
			}
			else printf(".");
		}
		printf("\n");
	}
}