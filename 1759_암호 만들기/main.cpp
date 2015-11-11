#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
	return strcmp((char*)a, (char*)b);
}

int L, C;
char passwd[15];
char tmp[15];

void dfs(int depth, int value)
{
	int i;
	int ja, mo;


	if (depth == L)
	{
		ja = 0;
		mo = 0;
		for (i = 0; i < L; i++)
		{
			if (tmp[i] == 'a' || tmp[i] == 'e' || tmp[i] == 'i' || tmp[i] == 'o' || tmp[i] == 'u')
				mo++;
			else
				ja++;
		}
		if (mo >= 1 && ja >= 2)
		{
			puts(tmp);
		}
		return;
	}

	for (i = value; i < C; i++)
	{
		tmp[depth] = passwd[i];
		dfs(depth + 1, i + 1);
	}

	return;


}

int main()
{
	int i;
	char tmp;
	scanf("%d %d", &L, &C);
	for (i = 0; i < C; i++)
	{
		scanf("%c", &tmp);
		scanf("%c", &passwd[i]);
		
	}

	qsort(passwd, C, sizeof(char), compare);

	dfs(0, 0);
}