/*
섬의 개수(4963)

>> 문제
정사각형으로 이루어져 있는 섬과 바다 지도가 주어진다. 섬의 개수를 세는 프로그램을 작성하시오.
한 정사각형과 가로, 세로 또는 대각선으로 연결되어 있는 사각형은 걸어갈 수 있는 사각형이다.

두 정사각형이 같은 섬에 있으려면, 한 정사각형에서 다른 정사각형으로 걸어서 갈 수 있는 경로가 있어야 한다.
지도는 바다로 둘러쌓여 있으며, 지도 밖으로 나갈 수 없다.

>> 입력
입력은 여러 개의 테스트 케이스로 이루어져 있다. 각 테스트 케이스의 첫째 줄에는 지도의 너비 w와 높이 h가 주어진다. 
w와 h는 50보다 작거나 같은 양의 정수이다.

둘째 줄부터 h개 줄에는 지도가 주어진다. 1은 땅, 0은 바다이다.
입력의 마지막 줄에는 0이 두 개 주어진다.

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

>> 출력
각 테스트 케이스에 대해서, 섬의 개수를 출력한다.
0
1
1
3
1
9
*/
/*
깊이탐색(DFS)
1. 지도를 바다(0)로 감싼다.
2. (1,1)부터 탐색을 시작.
3. 인접한 위치에 섬(1)이 있으면 자신의 위치를 큐에 넣고 다음 섬으로 이동.
4. 3을 반복해 끝까지 간다.
5. 처음으로 되돌아와 이어서 인접한 섬을 찾는다.
6. 3으로 돌아가 5번까지 반복한다.
7. 인접하지 않은 곳에서 섬(1)을 발견해야 섬 개수가 +1 된다.
*/

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include <stdio.h>
int around_w[8] = { 1, 1, 0, -1, -1, -1, 0, 1 };
int around_h[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int island[52][52];
bool checked[52][52];
// DFS
//void DepthSearch(int j, int i)
//{
//	for (int k = 0; k < 8; ++k)
//	{
//		int ww = j + around_w[k];
//		int hh = i + around_h[k];
//		if (island[ww][hh] == 1 && checked[ww][hh] == false) {
//			checked[ww][hh] = true;
//			DepthSearch(ww, hh);
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
//					checked[j][i] = true;
//					DepthSearch(j, i);
//					++count;
//				}
//			}
//		}
//		printf("%d\n", count);
//	}
//}

/*
1 1 1 0 1
1 0 1 0 1
1 0 1 0 1
1 0 1 1 1
*/
#include <queue>
using namespace std;
queue<pair<int, int>> q;
void BreadthFirstSearch(int j, int i)
{
	q.push(make_pair(j, i));
	while (!q.empty())
	{
		int first = q.front().first;
		int second = q.front().second;
		checked[first][second] = true; // 여기에 있으면 채점에서 메모리 초과
		q.pop();
		for (int k = 0; k < 8; ++k)
		{
			int ww = first + around_w[k];
			int hh = second + around_h[k];
			if (island[ww][hh] == 1 && checked[ww][hh] == false) {
				q.push(make_pair(ww, hh));
				// checked[first][second] = true; 여기로 옮기면 안 나. 블로그에 정리할 것
			}
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
					BreadthFirstSearch(j, i);
					++count;
				}
			}
		}
		printf("%d\n", count);
	}
}
int main()
{
	ProblemSolved();
	return 0;
}