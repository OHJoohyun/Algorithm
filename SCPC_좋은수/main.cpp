#include <stdio.h>
#include <string.h>
int main(void) {
	int T;
	int test_case;
	/* 아래 freopen 함수는 input.txt 를 read only 형식으로 연 후,
	앞으로 표준 입력(키보드) 대신 input.txt 파일로 부터 읽어오겠다는 의미의 코드입니다.
	만약 본인의 PC 에서 테스트 할 때는, 입력값을 input.txt에 저장한 후 freopen 함수를 사용하면,
	그 아래에서 scanf 함수를 사용하여 표준 입력 대신 input.txt 파일로 부터 입력값을 읽어 올 수 있습니다.
	따라서 본인의 PC 에서 테스트 할 때에는 아래 주석을 지우고 이 함수를 사용하셔도 됩니다.
	단, 이 시스템에서 "제출하기" 할 때에는 반드시 freopen 함수를 지우거나 주석 처리 하셔야 합니다. */
	freopen("sample_input.txt", "r", stdin);

	/* setbuf 함수를 사용하지 않으면, 본인의 프로그램이 제한 시간 초과로 강제 종료 되었을 때,
	printf로 출력한 내용이 실제 표준 출력에 기록되지 않고 채점이 되지 않을 수 있습니다.
	따라서 안전을 위해 반드시 setbuf(stdout, NULL) 함수를 사용하시기 바랍니다. */
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (test_case = 1; test_case <= T; test_case++) {
		int N;
		int number[5001];
		int anw[100001];
		int i, j, k, tmp;
		int a, b;
		int count;
		int find;

		count = 0;
		//find = 0;

		memset(number, 0, sizeof(number));
		memset(anw, 0, sizeof(anw));

		scanf("%d", &N);

		for (i = 1; i <= N; i++)
		{
			scanf("%d", &number[i]);
		}

		for (i = 2; i <= N; i++)
		{
			find = 0;
			k = number[i];
			
			for (j = 1; j < i; j++)
			{
				tmp = number[j];
				for (a = tmp; a <= k; a++)
				{
					anw[a] = anw[a - tmp] + 1;
					if (anw[k] == 3)
					{
						printf("k = %d\n", k);
						count++;
						find = 1;
						break;
					}
				}
				if (find == 1)
				{
					break;
				}
			}
		}
		//	이 부분에서 정답을 출력하십시오.
		printf("Case #%d\n%d\n", test_case, count);

	}

	return 0;	//	정상종료 시 반드시 0을 리턴해야 합니다.
}