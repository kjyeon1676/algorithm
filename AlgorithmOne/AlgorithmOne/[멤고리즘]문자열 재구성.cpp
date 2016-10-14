#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <string>
using namespace std;
int main()
{
	freopen("input.txt", "rt", stdin);
	int nCount;		/* ������ �׽�Ʈ ���̽� */
	cin >> nCount;	/* �׽�Ʈ ���̽� �Է� */

	for (int itr = 0; itr<nCount; itr++)
	{
		cout << "#testcase" << (itr + 1) << endl;
		string input, output;
		int start, end;
		cin >> input;
		start = 0; end = input.length() - 1;
		while(end - start >= 0)
		{
			if (start == end) //������ �ϳ��� ���� ���
			{
				output.push_back(input[start]);
				break;
			}
			if (input[start] < input[end]) // ���� ������ �� �����ٸ�
			{
				output.push_back(input[start]);
				//input.erase(0, start);
				start++;
			}
			else if (input[start] == input[end]) //���������� ���ٸ� acdbcb, ccbbccc ���� �˻��ؼ� �� ������ �ִ������� ����
			{
				int restart = start + 1;
				int reEnd = end - 1;
				bool front = false, back = false;
				while (reEnd - restart >= 0)
				{
					if (input[restart] == input[reEnd])
					{
						restart++;
						reEnd--;
						continue;
					}
					else if (input[restart] < input[reEnd])
					{
						front = true;
						break;
					}
					else
					{
						back = true;
						break;
					}
					restart++;
					reEnd--;
				}
				if (back) // �ڿ��� ���� ���
				{
					output.push_back(input[end]);
					end--;
					back = false;
				}
				else //�տ��� ���� ���
				{
					output.push_back(input[start]);
					start++;
					front = false;
				}
			}
			else
			{
				output.push_back(input[end]);
				end--;
			}
		}
		cout << output << endl;
	}

	return 0;	/* �ݵ�� return 0���� ���ּž��մϴ�. */

}