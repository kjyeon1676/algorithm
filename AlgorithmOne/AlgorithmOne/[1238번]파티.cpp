#define _CRT_SECURE_NO_WARNINGS
#define VVV 9999999
#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int N, M, X;
int adjust[1002][1002];
int main()
{
	freopen("input.txt", "rt", stdin);
	int x, y, w, MAX = -9999999, sNum= 0;
	scanf("%d %d %d", &N, &M, &X);
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (i != j) adjust[i][j] = VVV;
		}
	}
	for (int i = 1; i <= M; i++)
	{
		scanf("%d %d %d", &x, &y, &w);
		if(adjust[x][y] > w)
			adjust[x][y] = w;
	}
	for (int k = 1; k <= N; k++)
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (adjust[i][k] == VVV || adjust[k][j] == VVV)
					continue;
				if (adjust[i][j] > adjust[i][k] + adjust[k][j])
					adjust[i][j] = adjust[i][k] + adjust[k][j];
			}
		}
	}
	for (int i = 1; i <= N; i++)
	{
		//2번 -> 4번 + 4번 -> 2번 가중치값 더한거 중에 최대값
		sNum = adjust[i][X] + adjust[X][i];
		if(MAX < sNum)
			MAX = sNum;
	}
	printf("%d\n", MAX);
	return 0;
}