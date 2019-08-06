/*
���� ����(4963)

>> ����
���簢������ �̷���� �ִ� ���� �ٴ� ������ �־�����. ���� ������ ���� ���α׷��� �ۼ��Ͻÿ�.
�� ���簢���� ����, ���� �Ǵ� �밢������ ����Ǿ� �ִ� �簢���� �ɾ �� �ִ� �簢���̴�.

�� ���簢���� ���� ���� ��������, �� ���簢������ �ٸ� ���簢������ �ɾ �� �� �ִ� ��ΰ� �־�� �Ѵ�.
������ �ٴٷ� �ѷ��׿� ������, ���� ������ ���� �� ����.

>> �Է�
�Է��� ���� ���� �׽�Ʈ ���̽��� �̷���� �ִ�. �� �׽�Ʈ ���̽��� ù° �ٿ��� ������ �ʺ� w�� ���� h�� �־�����. 
w�� h�� 50���� �۰ų� ���� ���� �����̴�.

��° �ٺ��� h�� �ٿ��� ������ �־�����. 1�� ��, 0�� �ٴ��̴�.
�Է��� ������ �ٿ��� 0�� �� �� �־�����.

1 1
0
2 2
0 1
1 0
3 2
1 1 1
1 1 1
5 4
1 0 1 0 0
1 0 0 0 0
1 0 1 0 1
1 0 0 1 0
5 4
1 1 1 0 1
1 0 1 0 1
1 0 1 0 1
1 0 1 1 1
5 5
1 0 1 0 1
0 0 0 0 0
1 0 1 0 1
0 0 0 0 0
1 0 1 0 1
0 0

>> ���
�� �׽�Ʈ ���̽��� ���ؼ�, ���� ������ ����Ѵ�.
0
1
1
3
1
9
*/
/*
����Ž��(DFS)
1. ������ �ٴ�(0)�� ���Ѵ�.
2. (1,1)���� Ž���� ����.
3. ������ ��ġ�� ��(1)�� ������ �ڽ��� ��ġ�� ť�� �ְ� ���� ������ �̵�.
4. 3�� �ݺ��� ������ ����.
5. ó������ �ǵ��ƿ� �̾ ������ ���� ã�´�.
6. 3���� ���ư� 5������ �ݺ��Ѵ�.
7. �������� ���� ������ ��(1)�� �߰��ؾ� �� ������ +1 �ȴ�.
*/

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include <stdio.h>
int around_w[8] = { 1, 1, 0, -1, -1, -1, 0, 1 };
int around_h[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int island[52][52];
bool checked[52][52];
// DFS
void DepthSearch(int j, int i)
{
	for (int k = 0; k < 8; ++k)
	{
		int ww = j + around_w[k];
		int hh = i + around_h[k];
		if (island[ww][hh] == 1 && checked[ww][hh] == false) {
			checked[ww][hh] = true;
			DepthSearch(ww, hh);
		}
	}
}
void ProblemSolved()
{
	int w, h, count;
	while (true)
	{
		scanf("%d", &w); scanf("%d", &h);
		if (w == 0 && h == 0) 
			break;
		for (int i = 1; i <= 50; ++i) {
			for (int j = 1; j <= 50; ++j) {
				island[j][i] = 0;
			}
		}
		for (int i = 1; i <= h; ++i) {
			for (int j = 1; j <= w; ++j) {
				scanf("%d", &island[j][i]);
			}
		}
		for (int i = 0; i <= 51; ++i) {
			for (int j = 0; j <= 51; ++j) {
				checked[j][i] = false;
			}
		}
		count = 0;
		for (int i = 1; i <= h; ++i) {
			for (int j = 1; j <= w; ++j) {
				if (island[j][i] == 1 && checked[j][i] == false) {
					checked[j][i] = true;
					DepthSearch(j, i);
					++count;
				}
			}
		}
		printf("%d\n", count);
	}
}

/*
1 1 1 1 1
1 1 1 1 1
1 0 1 0 1
1 0 1 1 1
*/
// BFS
//#include <queue>
//using namespace std;
//queue<pair<int, int>> q;
//void BreadthFirstSearch(int j, int i)
//{
//	q.push(make_pair(j, i));
//	while (!q.empty())
//	{
//		int first = q.front().first;
//		int second = q.front().second;
//		checked[first][second] = true; // ���⿡ ������ ä������ �޸� �ʰ�
//		q.pop();
//		for (int k = 0; k < 8; ++k)
//		{
//			int ww = first + around_w[k];
//			int hh = second + around_h[k];
//			if (island[ww][hh] == 1 && checked[ww][hh] == false) {
//				q.push(make_pair(ww, hh));
//				// checked[first][second] = true; ����� �ű�� �� ��. ��α׿� ������ ��
//			}
//		}
//	}
//}
//void ProblemSolved()
//{
//	int w, h, count;
//	while (true)
//	{
//		scanf("%d", &w); scanf("%d", &h);
//		if (w == 0 && h == 0) 
//			break;
//		for (int i = 1; i <= 50; ++i) {
//			for (int j = 1; j <= 50; ++j) {
//				island[j][i] = 0;
//			}
//		}
//		for (int i = 1; i <= h; ++i) {
//			for (int j = 1; j <= w; ++j) {
//				scanf("%d", &island[j][i]);
//			}
//		}
//		for (int i = 0; i <= 51; ++i) {
//			for (int j = 0; j <= 51; ++j) {
//				checked[j][i] = false;
//			}
//		}
//		count = 0;
//		for (int i = 1; i <= h; ++i) {
//			for (int j = 1; j <= w; ++j) {
//				if (island[j][i] == 1 && checked[j][i] == false) {
//					BreadthFirstSearch(j, i);
//					++count;
//				}
//			}
//		}
//		printf("%d\n", count);
//	}
//}
int main()
{
	ProblemSolved();
	return 0;
}