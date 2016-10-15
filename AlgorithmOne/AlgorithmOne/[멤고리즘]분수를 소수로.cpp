#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
using namespace std;
int fArr[1000];
int isOneType(int last, int q)
{
	return (last * 10) / q;
}
int main()
{
	freopen("input.txt", "rt", stdin);
	int nCount;		/* ������ �׽�Ʈ ���̽� */
	cin >> nCount;	/* �׽�Ʈ ���̽� �Է� */
	for (int itr = 0; itr<nCount; itr++)
	{
		cout << "#testcase" << (itr + 1) << endl;
		int p, q, first, last;
		int iCnt = 0;
		int fIndex = 0;
		bool oneType = false, diffType = false;
		scanf("%d %d", &p, &q);
		if (q % 2 != 0 || q % 5 != 0)
		{
			while (p % q != 0)
			{
				p *= 10;
				if (iCnt == 0)  // ó���� ������ ����
				{
					fArr[iCnt++] = p / q;
					p = p % q;
					first = fArr[0];
					fIndex = 0;
					continue;
				}
				else
				{
					last = p / q;
					if (first == last) // �ݺ��Ǵ� ������ ã�� ��� �������ϰ� �ѹ� �� ��
					{
						if (isOneType(p % q, q) == fArr[fIndex + 1])
						{
							diffType = true;
							break;
						}
					}
					else if (first != last) // 0.142857142857
					{
						if (isOneType(p % q, q) == last) // 0.188888 , 0.123444444 ���� ���
						{
							oneType = true;
							fIndex = iCnt;
							fArr[iCnt++] = last;
							break;
						}
						fArr[iCnt++] = last;
						p = p % q;
						continue;
					}
				}
			}
			//���
			if (diffType) // 0.(142857), 0.(02)
			{
				for (int i = 0; i < iCnt; i++)
				{
					if (i == 0) printf("0.(");
					printf("%d", fArr[i]);
				}
				printf(")\n");
			}
			else if (oneType)
			{
				for (int i = 0; i < fIndex; i++)
				{
					if (i == 0) printf("0.");
					printf("%d", fArr[i]);
				}
				for (int i = fIndex; i < iCnt; i++)
				{
					if (i == 0) printf("(");
					printf("%d", fArr[i]);
				}
				printf(")\n");
			}
			else // �Ϲ����� 0.5, 1.4�� ���
			{
				for (int i = 0; i < iCnt; i++)
				{
					if (i == 0) printf("0.");
					printf("%d", fArr[i]);
				}
				printf("\n");
			}

		}
		else
		{
			printf("%d\n", p / q);
		}
		memset(fArr, 0, sizeof(fArr));
	}
	return 0;	/* �ݵ�� return 0���� ���ּž��մϴ�. */
}