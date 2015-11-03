#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct {
	int depth;
	int row;
	int col;
} _position;

_position position[100000];
_position jol;

int main()
{
	int R, C, S, K;
	int count;
	int depth;
	int i, j, k;
	int map[101][101] = { {0}, {0} };
	int row;
	int col;
	int head = 0;
	int tail = 1;
	int N, M;
	int Dy[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };
	int Dx[8] = { -1, -2, -2, -1, 1, 2, 2, 1 };

	scanf("%d %d", &N, &M);
	scanf("%d %d", &R, &C);
	scanf("%d %d", &S, &K);

	jol.row = S;
	jol.col = K;
	jol.depth = 0;

	position[0].depth = 0;
	position[0].row = R;
	position[0].col = C;

	k = -1; // QUEUE INDEX
	count = 0; // 몇 번 만에?
	while (1)
	{
		k++; // 증가
		count = position[k].depth + 1; // 횟 수 증가
		for (i = 0; i < 8; i++)
		{
			row = position[k].row + Dy[i];
			col = position[k].col + Dx[i];

			if (row >= 1 && row <= N && col >= 1 && col <= M) // 범위 안에 있을 때 만 수행
			{
				if (map[row][col] == 0) // 아직 들리지 않았을 때만,
				{
					if (jol.row == row && jol.col == col)
					{
						printf("%d\n", count);
						return 0;
					}
					position[tail].row = row;
					position[tail].col = col;
					position[tail].depth = count;
					tail++;
					map[row][col] = 1;
				}
			}
		}
	}
	
	//printf("%d\n", jol.depth);

	return 0;
}
