#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <queue>
#include <string.h>
using namespace std;
typedef struct info {
	char place; //��������Ʈ, ȣ��, ����
	int playTime; // ���̼ҿ�ð�
	int happyValue; //������
}Info;
int top;
int stack[37];
int pop() { return stack[--top]; }
void push(int value) { stack[top++] = value; }

int N, M, resultHappy, totalHappy, resultIndex;
int lastPlace = 1;
int moveTime[37][37]; // �̵��ҿ�ð�
int visit[37];
int load[37];
int traceLoad[37];
int resultLoad[37];

Info node[37]; // N�� 3�̻� 35����

void init()
{
	memset(moveTime, 0, sizeof(moveTime));
	memset(traceLoad, 0, sizeof(traceLoad));
	memset(resultLoad, 0, sizeof(resultLoad));
	memset(visit, 0, sizeof(visit));
	memset(load, 0, sizeof(load));
	memset(stack, 0, sizeof(stack));
	top = 0;
	resultIndex = resultHappy = totalHappy = 0;
	lastPlace = 1;

}
void copyLoad()
{
	memset(traceLoad, 0, sizeof(traceLoad));
	for (int i = 0; i < top; i++)
		traceLoad[i] = stack[i];
}
void copyResult()
{
	for (int i = 0; traceLoad[i] != 0; i++)
		resultLoad[resultIndex++] = traceLoad[i];
}
void trip(int myTrip, int pIndex, int happySum, int totalPtime, int totalMtime)
{
	//�̵� + ���̿� �ҿ�Ǵ� �ð��� 9�ð��� ������ �ȵ�
	if (totalPtime + totalMtime > 540)
		return;
	if (node[pIndex].place == 'H' || node[pIndex].place == 'A') // ȣ���̰ų� �����̰� ���� �湮���� ������ ��
	{
		if (totalHappy < happySum)
		{
			totalHappy = happySum; // ������ ����
			memcpy(load, visit, sizeof(visit)); //��� ����
			copyLoad();
			lastPlace = pIndex; // ������ ��ġ ����
			return;
		}
	}
	int nextPlace = 0;
	for (int j = 1; j <= N; j++) // �������� �̵� �ҿ�ð� + ���� �ҿ� �ð��� 9�ð��� ���� �ʴ� ��ġ�� ã�´�
	{
		if (pIndex != j && moveTime[pIndex][j] + node[j].playTime + totalMtime + totalPtime < 540 && visit[j] == 0)
		{
			if (myTrip == 0 && j == 1) continue;
			visit[j] = 1;
			push(j); //��� ����
			trip(myTrip, j, node[pIndex].happyValue + happySum, node[pIndex].playTime + totalPtime, moveTime[pIndex][j] + totalMtime);
			visit[j] = 0;
			pop(); // ��ο��� ����
		}
	}
}
int main()
{
	freopen("input.txt", "rt", stdin);
	char p[2];
	int nCount;		/* ������ �׽�Ʈ ���̽� */
	int time;
	cin >> nCount;	/* �׽�Ʈ ���̽� �Է� */
	for (int itr = 0; itr<nCount; itr++)
	{
		//N�� ��������, M�� �ް� �Ⱓ, �Ϸ�� 1440��
		//M�� 1�̻� 5���� -> 1440 ~ 7200
		//�̵� �ҿ� �ð��� �д����� 30�� �̻� 240�� ����
		//���� �ҿ� �ð��� �д����� 30�� �̻� 240�� ����
		//��������Ʈ�� 1 ~ 10����
		cout << "#testcase" << (itr + 1) << endl;
		scanf("%d %d", &N, &M);
		//i�� �������� i+1 ~ N�� ���������� �̵��ҿ�ð�
		for (int i = 1; i < N; i++)
		{
			for (int j = i + 1; j <= N; j++)
			{
				scanf("%d", &time); // i�� �������� i+1 ~ N�� ���������� �̵� �ҿ� �ð� �Է�
				moveTime[i][j] = moveTime[j][i] = time;
			}
		}
		for (int i = 1; i <= N; i++)
		{
			//�����̳� ȣ���̸� ���� �ҿ� �ð�, ������ ����
			scanf("%s", &p);
			if (p[0]== 'A' || p[0] == 'H')
				node[i].place = p[0];
			else
			{
				node[i].place = p[0];
				scanf("%d %d", &node[i].playTime, &node[i].happyValue);
			}
		}
		//����� �������� �̵� ��θ� �������� ���, ��ΰ� ���ٸ� 0���� ����ϰ� ���x
		//25 2 3 9 5 6 10 4 1  //ù ��° �׽�Ʈ ���̽� ���
		//M���� �Ǳ���� �ݺ�����
		for (int i = 0; i < M; i++)
		{
			trip(i, lastPlace, 0, 0, 0);
			resultHappy += totalHappy;
			copyResult();
			memcpy(visit, load, sizeof(load));
			totalHappy = 0;
		}
		printf("%d ", resultHappy);
		for (int i = 0; i < resultIndex; i++)
			printf("%d ", resultLoad[i]);
		printf("\n");
		init();
	}
	return 0;	/* �ݵ�� return 0���� ���ּž��մϴ�. */

}