#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
using namespace std;
int adjust[102][102];
int visit[102];
int N;
void dfs(int i, int j)
{
	adjust[i][j] = 1;
	//모든 노드 방문
	for (int k = 0; k < N; k++)
	{
		if (adjust[j][k] == 1 && visit[k] == 0)
		{
			visit[k] = 1;
			dfs(i, k);
		}
	}
}
void init()
{
	memset(visit, 0, sizeof(visit));
}
int main()
{
	freopen("input.txt", "rt", stdin);
	cin >> N;
	int node;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> node;
			adjust[i][j] = node;
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (adjust[i][j] == 1)
			{
				init();
				dfs(i, j);
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cout << adjust[i][j] << " ";
		cout << endl;
	}
	return 0;
}