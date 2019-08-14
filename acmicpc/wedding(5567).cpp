/*
>> ����
����̴� �ڽ��� ��ȥ�Ŀ� �б� ���� �� �ڽ��� ģ���� ģ���� ģ���� �ʴ��ϱ�� �ߴ�.
������� ����� ��� N���̰�, �� �л����� �й��� ��� 1���� N�����̴�. ������� �й��� 1�̴�.
����̴� ������� ģ�� ���踦 ��� ������ ����Ʈ�� ������ �ִ�. �� ����Ʈ�� �������� ��ȥ�Ŀ� �ʴ��� ����� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

>> �Է�
ù° �ٿ� ������� ������ �� n (2 �� n �� 500)�� �־�����. ��° �ٿ��� ����Ʈ�� ���� m (1 �� m �� 10000)�� �־�����.
���� �ٺ��� m�� �ٿ��� ģ�� ���� ai bi�� �־�����. (1 �� ai < bi �� n) ai�� bi�� ģ����� ���̸�, bi�� ai�� ģ�������̴�.

>> ���
ù° �ٿ� ������� ��ȥ�Ŀ� �ʴ��ϴ� ������ ���� ����Ѵ�.

>> ���� �Է�
6
5
1 2
1 3
3 4
2 3
4 5

>> ���� ���
3

>> ��Ʈ
2, 3���� ������� ģ��, 4���� 3�� ģ���̹Ƿ� ģ���� ģ��. �� 3��
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