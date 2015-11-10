#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
int main()
{
	int d, k, g = 0, sum[100];
	char result[500001] = { 0 };
	for (int i = 1; i <= 100000; i++)
	{
		d = i;
		k = 0;
		while (d>0) {
			sum[k] = d % 10;
			d = d / 10;
			k++;
		}

		for (int j = k - 1; j >= 0; j--)
		{
			result[g] = sum[j] + 48;
			g++;
		}
	}
	string b;
	int y;
	cin << b;
	for (int i = 0; i <= g; i++)
	{
		if (result[i] == b[y])
			y++;
		else
			y = 0;
		if (y == b.size())
		{
			cout << i - (b.size() - 2) << "\n"; break;
		}
	}
}
[출처] 2154. 수 이어 쓰기3 | 작성자 ㅎ