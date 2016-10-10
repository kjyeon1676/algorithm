#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
typedef struct node {
	int x;
	int y;
	int w;
}Node;
Node info[100002];
bool cmp(const Node a, const Node b) { return a.w < b.w; }
int set[10002];
int rankH[10002];
void make_set(int n)
{
	for (int i = 1; i <= n; i++)
	{
		set[i] = i;
		rankH[i] = 0;
	}
}
int find(int x)
{
	if (set[x] == x) return x;
	else return set[x] = find(set[x]);
}
void union_find(int r1, int r2)
{
	r1 = find(r1);
	r2 = find(r2);
	if (r1 == r2) return;
	if (rankH[r1] < rankH[r2]) set[r1] = r2;
	else 
	{
		set[r2] = r1;
		if (rankH[r1] == rankH[r2]) rankH[r1]++;
	}
}
int main()
{
	freopen("input.txt", "rt", stdin);
	int v, e, cost = 0;
	cin >> v >> e;
	for (int i = 0; i < e; i++)
		scanf("%d %d %d", &info[i].x, &info[i].y, &info[i].w);
	//가중치 기준으로 오름차순 정렬
	sort(info, info + e, cmp);
	//노드 갯수만큼 set 만들고
	make_set(v);
	for (int i = 0; i < e; i++)
	{
		int _x = info[i].x;
		int _y = info[i].y;
		//두 노드의 루트가 같지 않다면
		if (find(_x) != find(_y))
		{
			union_find(_x, _y);
			cost += info[i].w;
		}
	}
	cout << cost << endl;
	return 0;
}