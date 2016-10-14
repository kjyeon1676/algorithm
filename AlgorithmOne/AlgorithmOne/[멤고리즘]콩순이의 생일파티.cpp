#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
int N, M;
int fCount;
int visit[1004];
int adjust[1004][1004];
int main()
{
	freopen("input.txt", "rt", stdin);
	int nCount;		/* 문제의 테스트 케이스 */
	int a, b;
	cin >> nCount;	/* 테스트 케이스 입력 */
	for (int itr = 0; itr<nCount; itr++)
	{
		cout << "#testcase" << (itr + 1) << endl;
		scanf("%d %d", &N, &M);
		for (int i = 0; i <= N; i++)
			adjust[i][i] = 1;
		for (int i = 0; i < M; i++)
		{
			scanf("%d %d", &a, &b);
			adjust[a][b] = adjust[b][a] = 1;
		}
		visit[1] = 1;
		for (int i = 1; i <= N; i++)
		{
			if (adjust[1][i] == 1)
			{
				for (int j = 1; j <= N; j++)
				{
					if (adjust[i][j] == 1)
					{
						if (visit[j] == 0)
						{
							fCount++;
							visit[j] = 1;
						}
					}
				}
			}
		}
		printf("%d\n", fCount);
		memset(visit, 0, sizeof(visit));
		memset(adjust, 0, sizeof(adjust));
		fCount = 0;
	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}
/*

VCPP, GPP에서 사용

*/

//#include <iostream>
//#include<vector>
//#include<queue>
//using namespace std;
//
//class node {
//public:
//	int index;
//	int depth;
//	node() { index = 0; depth = 0; };
//};
//
//vector<int> people[501];
////queue<node> myq;
//int N, M, ans;
//
//bool visit[501];
//
//
//
//int main()
//{
//	freopen("input.txt", "rt", stdin);
//	int nCount;		/* 문제의 테스트 케이스 */
//
//	cin >> nCount;	/* 테스트 케이스 입력 */
//
//	for (int itr = 0; itr<nCount; itr++)
//	{
//		ans = 0;
//
//		scanf("%d %d", &N, &M);
//
//		for (int iCnt = 0; iCnt <= N; iCnt++)
//			people[iCnt].push_back(iCnt);
//
//		for (int iCnt = 0, temp, temp_v; iCnt < M; iCnt++)
//		{
//			scanf("%d %d", &temp, &temp_v);
//			people[temp].push_back(temp_v);
//			people[temp_v].push_back(temp);
//		}
//
//		node value;
//
//		visit[1] = true;
//
//		while (!people[1].empty())
//		{
//			value.index = people[1].back();
//			people[1].pop_back();
//			while (!people[value.index].empty())
//			{
//				int temp_node = people[value.index].back();
//				people[value.index].pop_back();
//				if (visit[temp_node] == false)
//				{
//					visit[temp_node] = true;
//					ans++;
//				}
//			}
//		}
//
//
//
//
//		cout << "#testcase" << (itr + 1) << endl;
//
//		cout << ans << endl;
//
//		memset(visit, 0, sizeof(visit));
//
//		for (int iCnt = 0; iCnt < 501; iCnt++)
//			people[iCnt].clear();
//
//		/*
//
//		알고리즘이 들어가는 부분
//
//		*/
//
//	}
//
//	return 0;	/* 반드시 return 0으로 해주셔야합니다. */
//
//}