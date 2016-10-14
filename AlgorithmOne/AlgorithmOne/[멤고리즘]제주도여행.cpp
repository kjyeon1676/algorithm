#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <queue>
#include <string.h>
using namespace std;
typedef struct info {
	char place; //관광포인트, 호텔, 공항
	int playTime; // 놀이소요시간
	int happyValue; //만족도
}Info;
int top;
int stack[37];
int pop() { return stack[--top]; }
void push(int value) { stack[top++] = value; }

int N, M, resultHappy, totalHappy, resultIndex;
int lastPlace = 1;
int moveTime[37][37]; // 이동소요시간
int visit[37];
int load[37];
int traceLoad[37];
int resultLoad[37];

Info node[37]; // N은 3이상 35이하

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
	//이동 + 놀이에 소요되는 시간이 9시간을 넘으면 안됨
	if (totalPtime + totalMtime > 540)
		return;
	if (node[pIndex].place == 'H' || node[pIndex].place == 'A') // 호텔이거나 공항이고 아직 방문하지 않으면 감
	{
		if (totalHappy < happySum)
		{
			totalHappy = happySum; // 만족도 갱신
			memcpy(load, visit, sizeof(visit)); //경로 갱신
			copyLoad();
			lastPlace = pIndex; // 마지막 위치 갱신
			return;
		}
	}
	int nextPlace = 0;
	for (int j = 1; j <= N; j++) // 지점에서 이동 소요시간 + 놀이 소요 시간이 9시간이 넘지 않는 위치를 찾는당
	{
		if (pIndex != j && moveTime[pIndex][j] + node[j].playTime + totalMtime + totalPtime < 540 && visit[j] == 0)
		{
			if (myTrip == 0 && j == 1) continue;
			visit[j] = 1;
			push(j); //경로 포함
			trip(myTrip, j, node[pIndex].happyValue + happySum, node[pIndex].playTime + totalPtime, moveTime[pIndex][j] + totalMtime);
			visit[j] = 0;
			pop(); // 경로에서 제외
		}
	}
}
int main()
{
	freopen("input.txt", "rt", stdin);
	char p[2];
	int nCount;		/* 문제의 테스트 케이스 */
	int time;
	cin >> nCount;	/* 테스트 케이스 입력 */
	for (int itr = 0; itr<nCount; itr++)
	{
		//N은 지점개수, M은 휴가 기간, 하루는 1440분
		//M은 1이상 5이하 -> 1440 ~ 7200
		//이동 소요 시간은 분단위로 30분 이상 240분 이하
		//놀이 소요 시간은 분단위로 30분 이상 240분 이하
		//관광포인트는 1 ~ 10제한
		cout << "#testcase" << (itr + 1) << endl;
		scanf("%d %d", &N, &M);
		//i번 지점에서 i+1 ~ N번 지점까지의 이동소요시간
		for (int i = 1; i < N; i++)
		{
			for (int j = i + 1; j <= N; j++)
			{
				scanf("%d", &time); // i번 지점에서 i+1 ~ N번 지점까지의 이동 소요 시간 입력
				moveTime[i][j] = moveTime[j][i] = time;
			}
		}
		for (int i = 1; i <= N; i++)
		{
			//공항이나 호텔이면 놀이 소요 시간, 만족도 없음
			scanf("%s", &p);
			if (p[0]== 'A' || p[0] == 'H')
				node[i].place = p[0];
			else
			{
				node[i].place = p[0];
				scanf("%d %d", &node[i].playTime, &node[i].happyValue);
			}
		}
		//출력은 만족도와 이동 경로를 공백으로 출력, 경로가 없다면 0으로 출력하고 경로x
		//25 2 3 9 5 6 10 4 1  //첫 번째 테스트 케이스 결과
		//M일차 되기까지 반복진행
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
	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}