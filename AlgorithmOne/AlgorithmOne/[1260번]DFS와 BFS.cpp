#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <string.h>
#include <stdio.h>
using namespace std;
vector<vector<int>> node(1002, vector<int>(1002));
queue<int> q;
int N, M, V;
int visit[1002];
void init()
{
	memset(visit, 0, sizeof(visit));
}
void dfs(int start)
{
	visit[start] = 1;
	printf("%d ", start);
	for (int i = 1; i <= N; i++)
	{
		//아직 방문하지 않은 노드이고
		if (visit[i] == 0 && node[start][i] == 1)
			dfs(i);
	}
}
void bfs(int first)
{
	//처음 노드 방문시 체크
	visit[first] = 1;
	q.push(first);
	int start = 0;
	while (!q.empty())
	{
		start = q.front();
		q.pop();
		printf("%d ", start);
		//꺼내온 노드로부터 모든 노드들 담기
		for (int i = 1; i <= N; i++)
		{
			if (visit[i] == 0 && node[start][i] == 1)
			{
				visit[i] = 1;
				q.push(i);
			}
		}
	}
}
int main()
{
	freopen("input.txt", "rt", stdin);
	scanf("%d %d %d", &N, &M, &V);
	int x, y, dep = 0;
	for (int i = 0; i < M; i++)
	{
		scanf("%d %d", &x, &y);
		node[x][y] = node[y][x] = 1;
	}
	dfs(V);
	init();
	printf("\n");
	bfs(V);
	printf("\n");
	
	return 0;
}
//http://blog.naver.com/PostView.nhn?blogId=easter3163&logNo=220700879693