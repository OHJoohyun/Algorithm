#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int L, C;
char key[15];
char save[15];

void dfs(int depth, int value)
{
	int i;
	if (depth == L)
	{
		int mo = 0, ja = 0;
		for (i = 0; i < L; i++)
		{
			if (save[i] == 'a' || save[i] == 'e' || save[i] == 'o' || save[i] == 'i' || save[i] == 'u') mo++;
			else ja++;
		}
		if (ja >= 2 && mo >= 1)
		{
			puts(save);
		}
		return;
	}
	for (i = value; i < C; i++)
	{
		save[depth] = key[i];
		dfs(depth + 1, i + 1);
	}
}

int compare(const void *a, const void *b)
{
	return strcmp((char*)a, (char*)b);
}

int main()
{
	int i, tmp;
	scanf("%d %d", &L, &C);
	for (i = 0; i < C; i++)
	{
		scanf("%c", &tmp);
		scanf("%c", &key[i]);
	}

	qsort(key, C, sizeof(char), compare);

	dfs(0, 0);
	
	return 0;
}