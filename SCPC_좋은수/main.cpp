#include <stdio.h>
#include <string.h>
int main(void) {
	int T;
	int test_case;
	/* �Ʒ� freopen �Լ��� input.txt �� read only �������� �� ��,
	������ ǥ�� �Է�(Ű����) ��� input.txt ���Ϸ� ���� �о���ڴٴ� �ǹ��� �ڵ��Դϴ�.
	���� ������ PC ���� �׽�Ʈ �� ����, �Է°��� input.txt�� ������ �� freopen �Լ��� ����ϸ�,
	�� �Ʒ����� scanf �Լ��� ����Ͽ� ǥ�� �Է� ��� input.txt ���Ϸ� ���� �Է°��� �о� �� �� �ֽ��ϴ�.
	���� ������ PC ���� �׽�Ʈ �� ������ �Ʒ� �ּ��� ����� �� �Լ��� ����ϼŵ� �˴ϴ�.
	��, �� �ý��ۿ��� "�����ϱ�" �� ������ �ݵ�� freopen �Լ��� ����ų� �ּ� ó�� �ϼž� �մϴ�. */
	freopen("sample_input.txt", "r", stdin);

	/* setbuf �Լ��� ������� ������, ������ ���α׷��� ���� �ð� �ʰ��� ���� ���� �Ǿ��� ��,
	printf�� ����� ������ ���� ǥ�� ��¿� ��ϵ��� �ʰ� ä���� ���� ���� �� �ֽ��ϴ�.
	���� ������ ���� �ݵ�� setbuf(stdout, NULL) �Լ��� ����Ͻñ� �ٶ��ϴ�. */
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
		//	�� �κп��� ������ ����Ͻʽÿ�.
		printf("Case #%d\n%d\n", test_case, count);

	}

	return 0;	//	�������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}