#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
typedef struct node {
	int Ti;
	int Ki;
}Node;
Node info[22];
int visit[22];
int N, L, result;
void dfs(int start, int Kisum, int Tisum)
{
	if (Kisum > L)
		return;
	else{
		if(result < Tisum)
			result = Tisum;
	}
	for (int i = start; i < N; i++)
	{
		if (visit[i] == 0)
		{
			visit[i] = 1;
			dfs(i + 1, Kisum + info[i].Ki, Tisum + info[i].Ti);
			visit[i] = 0;
		}
	}
}
int main()
{
	freopen("input.txt", "rt", stdin);
	int nCount;		/* 문제의 테스트 케이스 */
	cin >> nCount;	/* 테스트 케이스 입력 */
	for (int itr = 0; itr<nCount; itr++)
	{
		cout << "#testcase" << (itr + 1) << endl;
		scanf("%d %d", &N, &L);
		for (int i = 0; i < N; i++)
			scanf("%d %d", &info[i].Ti, &info[i].Ki);
		dfs(0, 0, 0);
		printf("%d\n", result);
		result = 0;
		memset(visit, 0, sizeof(visit));
	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}