#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <string>
using namespace std;
int main()
{
	freopen("input.txt", "rt", stdin);
	int nCount;		/* 문제의 테스트 케이스 */
	cin >> nCount;	/* 테스트 케이스 입력 */

	for (int itr = 0; itr<nCount; itr++)
	{
		cout << "#testcase" << (itr + 1) << endl;
		string input, output;
		int start, end;
		cin >> input;
		start = 0; end = input.length() - 1;
		while(end - start >= 0)
		{
			if (start == end) //마지막 하나가 남은 경우
			{
				output.push_back(input[start]);
				break;
			}
			if (input[start] < input[end]) // 사전 순으로 더 빠르다면
			{
				output.push_back(input[start]);
				//input.erase(0, start);
				start++;
			}
			else if (input[start] == input[end]) //사전순으로 같다면 acdbcb, ccbbccc 이후 검사해서 더 작은게 있는쪽으로 제거
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
				if (back) // 뒤에서 빼는 경우
				{
					output.push_back(input[end]);
					end--;
					back = false;
				}
				else //앞에서 빼는 경우
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

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}