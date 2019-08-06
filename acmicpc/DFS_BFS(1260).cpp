/*
DFS�� BFS(1260)

>> ����
�׷����� DFS�� Ž���� ����� BFS�� Ž���� ����� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
��, �湮�� �� �ִ� ������ ���� ���� ��쿡�� ���� ��ȣ�� ���� ���� ���� �湮�ϰ�,
�� �̻� �湮�� �� �ִ� ���� ���� ��� �����Ѵ�. ���� ��ȣ�� 1������ N�������̴�.

>> �Է�
ù° �ٿ� ������ ���� N(1 �� N �� 1,000), ������ ���� M(1 �� M �� 10,000),
Ž���� ������ ������ ��ȣ V�� �־�����. ���� M���� �ٿ��� ������ �����ϴ� �� ������ ��ȣ�� �־�����.
� �� ���� ���̿� ���� ���� ������ ���� �� �ִ�. �Է����� �־����� ������ ������̴�.

���
ù° �ٿ� DFS�� ������ �����, �� ���� �ٿ��� BFS�� ������ ����� ����Ѵ�. V���� �湮�� ���� ������� ����ϸ� �ȴ�.

���� �Է�
5 5 3
5 4
5 2
1 2
3 4
3 1

���� ���
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