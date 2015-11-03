#include <stdio.h>

int N, M, j;

int main()
{
	int i;
	int apple;
	int anw;
	int start;
	int end;

	scanf("%d %d", &N, &M);
	scanf("%d", &j);

	start = 1;
	end = M;
	anw = 0;

	for (i = 0; i < j; i++)
	{
		scanf("%d", &apple);
		int tmp;
		if (apple < start)
		{
			tmp = start - apple;
			start = start - tmp;
			end = end - tmp;
			anw = anw + tmp;
		}
		else if (apple > end)
		{
			tmp = apple - end;
			start = start + tmp;
			end = end + tmp;
			anw = anw + tmp;
		}
	}

	printf("%d\n", anw);
}