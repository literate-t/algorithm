/*
Ʈ��(1068)

>> ����
Ʈ������ ���� ����, �ڽ��� ������ 0�� ��带 ���Ѵ�. Ʈ���� �־����� ��, ��� �� �ϳ��� ������ ���̴�.
�� ��, ���� Ʈ������ ���� ����� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

>> �Է�
ù° �ٿ� Ʈ���� ����� ���� N�� �־�����. N�� 50���� �۰ų� ���� �ڿ����̴�.
��° �ٿ��� 0�� ������ N-1�� ������, �� ����� �θ� �־�����. ���� �θ� ���ٸ� (��Ʈ) -1�� �־�����. ��° �ٿ��� ���� ����� ��ȣ�� �־�����.

>> ���
ù° �ٿ� �Է����� �־��� Ʈ������ �Է����� �־��� ��带 ������ ��, ���� ����� ������ ����Ѵ�.

>> ���� �Է�
5
-1 0 0 1 1
2

>> ���� ���
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