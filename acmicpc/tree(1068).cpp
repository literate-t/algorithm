/*
트리(1068)

>> 문제
트리에서 리프 노드란, 자식의 개수가 0인 노드를 말한다. 트리가 주어졌을 때, 노드 중 하나를 제거할 것이다.
그 때, 남은 트리에서 리프 노드의 개수를 구하는 프로그램을 작성하시오.

>> 입력
첫째 줄에 트리의 노드의 개수 N이 주어진다. N은 50보다 작거나 같은 자연수이다.
둘째 줄에는 0번 노드부터 N-1번 노드까지, 각 노드의 부모가 주어진다. 만약 부모가 없다면 (루트) -1이 주어진다. 셋째 줄에는 지울 노드의 번호가 주어진다.

>> 출력
첫째 줄에 입력으로 주어진 트리에서 입력으로 주어진 노드를 지웠을 때, 리프 노드의 개수를 출력한다.

>> 예제 입력
5
-1 0 0 1 1
2

>> 예제 출력
2
*/
#pragma warning(disable:6031)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
std::vector<int> node[50];
int count, delete_node;
void CountLeafNode(int& now)
{
	if (now == delete_node) return;
	size_t size = node[now].size();
	switch (size)
	{
	case 0:
		++count;
		break;
	case 1:
		if (node[now][0] == delete_node) ++count;
		else CountLeafNode(node[now][0]);
		break;
	default:
		for (int i = 0; i < size; ++i)
			CountLeafNode(node[now][i]);
		break;
	}
}

void ProblemSolved()
{
	int parent, N, root;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &parent);
		if (parent == -1)
			root = i;
		else
			node[parent].push_back(i);
	}
	scanf("%d", &delete_node);
	CountLeafNode(root);
	printf("%d\n", count);
}
int main()
{
	ProblemSolved();
	return 0;
}