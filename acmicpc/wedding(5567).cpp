/*
>> 문제
상근이는 자신의 결혼식에 학교 동기 중 자신의 친구와 친구의 친구를 초대하기로 했다.
상근이의 동기는 모두 N명이고, 이 학생들의 학번은 모두 1부터 N까지이다. 상근이의 학번은 1이다.
상근이는 동기들의 친구 관계를 모두 조사한 리스트를 가지고 있다. 이 리스트를 바탕으로 결혼식에 초대할 사람의 수를 구하는 프로그램을 작성하시오.

>> 입력
첫째 줄에 상근이의 동기의 수 n (2 ≤ n ≤ 500)이 주어진다. 둘째 줄에는 리스트의 길이 m (1 ≤ m ≤ 10000)이 주어진다.
다음 줄부터 m개 줄에는 친구 관계 ai bi가 주어진다. (1 ≤ ai < bi ≤ n) ai와 bi가 친구라는 뜻이며, bi와 ai도 친구관계이다.

>> 출력
첫째 줄에 상근이의 결혼식에 초대하는 동기의 수를 출력한다.

>> 예제 입력
6
5
1 2
1 3
3 4
2 3
4 5

>> 예제 출력
3

>> 힌트
2, 3번은 상근이의 친구, 4번은 3의 친구이므로 친구의 친구. 총 3명
*/
#pragma warning(disable:6031)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;
//void ProblemSolved()
//{
//	int m, n, answer = 0;
//	int a, b;
//	queue<int> q;
//	int* myman[501] = { nullptr };
//	bool flag[501] = { false };
//	scanf("%d", &n); scanf("%d", &m);
//
//	for (int i = 0; i < 501; ++i)
//		myman[i] = new int[501];
//	for (int i = 0; i < m; ++i)
//	{
//		scanf("%d", &a); scanf("%d", &b);
//		myman[a][b] = 1; myman[b][a] = 1;
//	}
//	q.push(1);
//	flag[1] = true;
//	while (!q.empty())
//	{
//		int man = q.front(); q.pop();
//		for (int i = 1; i <= n; ++i)
//		{
//			if (myman[man][i] == 1 && flag[i] == false)
//			{
//				if (man == 1)
//				{
//					q.push(i); 
//					flag[i] = true;
//					++answer;
//				}
//				else
//				{
//					flag[i] = true;
//					++answer;
//				}
//			}
//		}
//	}
//	printf("%d\n", answer);
//	for (int i = 0; i < 501; ++i)
//		delete[] myman[i];
//}
void ProblemSolved()
{
	vector<vector<int>> v;
	v.resize(501);
	int m, n, answer = 0;
	int a, b;
	bool flag[501] = { false };
	scanf("%d%d", &n, &m);
	while (m--)
	{
		scanf("%d%d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	flag[1] = true;
	for (int i = 0; i < v[1].size(); ++i)
	{
		int f = v[1][i];
		if (flag[f] == false)
		{
			flag[f] = true;
			++answer;
		}
		for (int j = 0; j < v[f].size(); ++j)
		{
			int ff = v[f][j];
			if (flag[ff] == false)
			{
				flag[ff] = true;
				++answer;
			}
		}
	}
	printf("%d\n", answer);
}

int main()
{
	ProblemSolved();
	return 0;
}