#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;

bool visit[11] = { false };
int tree[11][2];
int N;
int index;

int findRoot() {
	for (int i = 0; i < N; i++) {
		if (!visit[i]) {
			return i;
		}
	}
	return 0;
}

bool flag = false; //保证输出格式正确，控制空格
void InOrder(int root) {
	if (root != -1) {
		InOrder(tree[root][1]);
		if (!flag) {
			printf("%d", root);
			flag = true;
		}
		else {
			printf(" %d", root);
		}
		InOrder(tree[root][0]);
	}
}

void BFS(int root) {
	//initialization
	queue<int> q;

	int node;
	q.push(root);
	while (!q.empty()) {
		node = q.front();
		q.pop();
		if (node == root) {
			printf("%d", node);
		}
		else {
			printf(" %d", node);
		}
		for (int i = 1; i >= 0; i--) {
			if (tree[node][i] != -1) {
				q.push(tree[node][i]);
			}
		}
	}
}

int main() {
	
	scanf_s("%d", &N);
	char c1[2];
	char c2[2];
	int id;
	for (int i = 0; i < N; i++) {
		scanf_s("%s", c1, 2);
		scanf_s("%s", c2, 2);
		id = (c1[0] != '-') ? (c1[0] - '0') : -1;
		visit[id] = true;
		tree[i][0] = id;
		id = (c2[0] != '-') ? (c2[0] - '0') : -1;
		visit[id] = true;
		tree[i][1] = id;
	}

	int root = findRoot();
	BFS(root);
	printf("\n");
	InOrder(root);
	printf("\n");

	system("pause");
	return 0;
}