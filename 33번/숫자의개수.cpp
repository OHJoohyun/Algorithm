#include <stdio.h>
#include <string.h>

int main()
{
	int num1;
	int num2;
	int num3;
	int anw;
	char num[10];
	int i, j;
	int zero = 0, one = 0, two = 0, three = 0, four = 0, five = 0, six = 0, seven = 0, eight = 0, nine = 0;


	scanf_s("%d", &num1);
	scanf_s("%d", &num2);
	scanf_s("%d", &num3);

	anw = num1 * num2 * num3;
	for (i = 0; i < 10; i++)
	{ 
		if (anw == 0) break;
		num[i] = anw % 10;
		anw = anw / 10;
		
	}
	
	for (j = 0; j < 10; j++)
	{
		if (num[j] < 0)
		{
			break;
		}
		switch (num[j])
		{
			case 0: zero++; break;
			case 1: one++; break;
			case 2: two++; break;
			case 3: three++; break;
			case 4: four++; break;
			case 5: five++; break;
			case 6: six++; break;
			case 7: seven++; break;
			case 8: eight++; break;
			case 9: nine++; break;
			default: break;
		}
	}
	
	printf("%d\n", zero);
	printf("%d\n", one);
	printf("%d\n", two);
	printf("%d\n", three);
	printf("%d\n", four);
	printf("%d\n", five);
	printf("%d\n", six);
	printf("%d\n", seven);
	printf("%d\n", eight);
	printf("%d\n", nine);
	
	return 0;
}