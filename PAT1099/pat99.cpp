#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;

int tree[101][2];
int nodes[101] = { 0 };
int keys[101];
int index;
int N;

void InOrder(int root) {
	if (root != -1) {
		InOrder(tree[root][0]);
		nodes[root] = keys[index++];
		InOrder(tree[root][1]);
	}
}

void BFS(int root) {
	//initial
	queue<int> q;

	int node;
	q.push(root);
	while (!q.empty()) {
		node = q.front();
		q.pop();
		if (node == root) {
			printf("%d", nodes[node]);
		}
		else {
			printf(" %d", nodes[node]);
		}
		for (int i = 0; i < 2; i++) {
			if (tree[node][i] != -1) {
				q.push(tree[node][i]);
			}
		}
	}
}

int main() {
	scanf_s("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf_s("%d %d", &tree[i][0], &tree[i][1]);
	}
	for (int i = 0; i < N; i++) {
		scanf_s("%d", keys + i);
	}

	//排序构造中序遍历结果
	sort(keys, keys+N);

	//通过中序遍历填入键值
	index = 0;
	InOrder(0);

	//BFS进行层次遍历输出
	BFS(0);
	printf("\n");

	system("pause");
	return 0;
}