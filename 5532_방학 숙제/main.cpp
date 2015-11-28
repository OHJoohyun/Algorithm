#include <stdio.h>
int main() {
	int L, A, B, C, D;
	int day1, day2;
	scanf("%d %d %d %d %d", &L, &A, &B, &C, &D); 
	
	day1 = A / C;
	if (A % C != 0) day1++;
	
	day2 = B / D;
	if (B % D != 0) day2++;
	
	if (day1 > day2) 
		printf("%d\n", L - day1);
	
	else 
		printf("%d\n", L - day2);

	return 0;
}