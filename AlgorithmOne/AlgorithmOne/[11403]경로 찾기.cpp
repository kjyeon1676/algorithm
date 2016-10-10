#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int adjust[102][102];
int N;
int main()
{
	freopen("input.txt", "rt",stdin);
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
	for (int k = 0; k < N; k++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (adjust[i][k] && adjust[k][j])
					adjust[i][j] = 1;
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