#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;

int N;
int heap[1010];

int parent(int index) {
	return (index - 1) / 2;
}

int lchild(int index) {
	return 2 * index + 1;
}

int rchild(int index) {
	return 2 * index + 2;
}

bool isMaxHeap() {
	queue<int> q;

	int node;
	int lnode;
	int rnode;

	q.push(0);
	while (!q.empty()) {
		node = q.front();
		q.pop();

		lnode = lchild(node);
		if (lnode < N) {
			if (heap[node] < heap[lnode]) {
				return false;
			}
			q.push(lnode);
		}

		rnode = rchild(node);
		if (rnode < N) {
			if (heap[node] < heap[rnode]) {
				return false;
			}
			q.push(rnode);
		}
	}
	return true;
}

bool isMinHeap() {
	queue<int> q;

	int node;
	int lnode;
	int rnode;

	q.push(0);
	while (!q.empty()) {
		node = q.front();
		q.pop();

		lnode = lchild(node);
		if (lnode < N) {
			if (heap[node] > heap[lnode]) {
				return false;
			}
			q.push(lnode);
		}

		rnode = rchild(node);
		if (rnode < N) {
			if (heap[node] > heap[rnode]) {
				return false;
			}
			q.push(rnode);
		}
	}
	return true;
}

void postOrder(int root) {
	if (root < N) {
		postOrder(lchild(root));
		postOrder(rchild(root));
		if (root == 0) {
			printf("%d\n", heap[root]);
		}
		else {
			printf("%d ", heap[root]);
		}
	}
}

int main() {
	int M;
	scanf_s("%d %d", &M, &N);

	while (M--) {
		for (int n = 0; n < N; n++) {
			scanf_s("%d", heap + n);
		}
		if (isMaxHeap()) {
			printf("Max Heap\n");
		}
		else if (isMinHeap()) {
			printf("Min Heap\n");
		}
		else {
			printf("Not Heap\n");
		}
		postOrder(0);
	}

	system("pause");
	return 0;
}