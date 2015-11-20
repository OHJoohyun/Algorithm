#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b)
{
	return strcmp((char *)a, (char *)b);
}

char spell[100];
int check[100] = { 0 };
char word[100];
int N;

void dfs(int depth, int value)
{
	int i;
	
	if (depth == strlen(spell))
	{
		puts(word);
		return;
	}

	for (i = 0; i < strlen(spell); i++)
	{
		if(check[spell[i]] == 0)
		{ 
			word[depth] = spell[i];
			check[spell[i]] = 1;
			dfs(depth + 1, value + 1);
			check[spell[i]] = 0;
		}
	}

	return;
}

int main()
{
	int i;
	scanf("%d", &N);
	scanf("%s", spell);
	
	qsort(spell, strlen(spell), sizeof(char), compare);

	dfs(0, 0);
}