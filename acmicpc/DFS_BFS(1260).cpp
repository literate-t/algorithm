/*
DFS와 BFS(1260)

>> 문제
그래프를 DFS로 탐색한 결과와 BFS로 탐색한 결과를 출력하는 프로그램을 작성하시오.
단, 방문할 수 있는 정점이 여러 개인 경우에는 정점 번호가 작은 것을 먼저 방문하고,
더 이상 방문할 수 있는 점이 없는 경우 종료한다. 정점 번호는 1번부터 N번까지이다.

>> 입력
첫째 줄에 정점의 개수 N(1 ≤ N ≤ 1,000), 간선의 개수 M(1 ≤ M ≤ 10,000),
탐색을 시작할 정점의 번호 V가 주어진다. 다음 M개의 줄에는 간선이 연결하는 두 정점의 번호가 주어진다.
어떤 두 정점 사이에 여러 개의 간선이 있을 수 있다. 입력으로 주어지는 간선은 양방향이다.

출력
첫째 줄에 DFS를 수행한 결과를, 그 다음 줄에는 BFS를 수행한 결과를 출력한다. V부터 방문된 점을 순서대로 출력하면 된다.

예제 입력
5 5 3
5 4
5 2
1 2
3 4
3 1

예제 출력
3 1 2 5 4
3 1 4 2 5
*/

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include <stdio.h>
#include <queue>
using namespace std;
queue<int> q;
int N, M, V;
int vertex[1001][1001] = { 0 };
int vertex2[1001][1001] = { 0 };
bool visted[1001] = { false };
bool visted2[1001] = { false };

void DFS(int V)
{
	printf("%d ", V);
	visted[V] = true;
	int num = N;
	for (int i = 1; i <= N; ++i) {
		if (vertex[V][i] == 1 && visted[i] == false) {
			vertex[V][i] = 0;
			vertex[i][V] = 0;
			visted[i] = true;
			num = i;
			DFS(num);
		}
		if (i == N)
			return;
	}
}
//void DFS(int V)
//{
//	printf("%d ", V);
//	int num = N;
//	for (int i = 1; i <= N; ++i) {
//		if (vertex[V][i] == 1) {
//			vertex[V][i] = 0;
//			vertex[i][V] = 0;
//			vertex[V][V] = 1;
//			num = i;
//			DFS(num);
//		}
//		if (i == N)
//			return;
//	}
//}
void BFS()
{
	while (!q.empty()) {
		int point = q.front();
		printf("%d ", point);
		q.pop();
		visted[point] = true;
		for (int i = 1; i <= N; ++i) {
			if (vertex2[point][i] == 1 && visted2[i] == false) {
				vertex2[point][i] = 0;
				vertex2[i][point] = 0;
				visted2[i] = true;
				q.push(i);
			}
		}
	}
}
void ProblemSolved()
{
	scanf("%d", &N); scanf("%d", &M); scanf("%d", &V);
	int first, second;
	for (int i = 1; i <= M; ++i) {
		scanf("%d", &first); scanf("%d", &second);
		vertex[first][second] = 1; vertex[second][first] = 1;
		vertex2[first][second] = 1; vertex2[second][first] = 1;
	}
	DFS(V);
	printf("\n");
	q.push(V);
	BFS();
	printf("\n");
}
int main()
{
	ProblemSolved();
	return 0;
}