#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int L, C;
char password[16];
char temp[16];

int compare(const void *a, const void *b)
{
	return strcmp((char *)a, (char *)b);
}

void dfs(int depth, int value)
{
	int ja = 0, mo = 0;

	if (depth == L)
	{
		for (int i = 0; i < L; i++)
		{
			
			if (temp[i] == 'a' || temp[i] == 'e' || temp[i] == 'i' || temp[i] == 'o' || temp[i] == 'u')
			{
				mo++;
			}
			else
				ja++;
		}


		if (mo >= 1 && ja >= 2)
		{
			puts(temp);
		}

		return;
	}

	int i;
	for (i = value; i < C; i++)
	{
		temp[depth] = password[i];
		dfs(depth + 1, i + 1);
	}
}



int main()
{
	int i;
	char tmp;
	scanf("%d %d", &L, &C);
	for (i = 0; i < C; i++)
	{
		scanf("%c", &tmp);
		scanf("%c", &password[i]);
	}

	qsort(password, C, sizeof(char), compare);

	dfs(0, 0);


}