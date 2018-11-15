#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int N;
int pre[10001];
int child[10001][2];

int findRchild(int s, int e, int root) {
	int l = s;
	int r = e;
	while (l <= (r + 1)) {
		if (root <= pre[l]) {
			return l;
		}
		else if (root > pre[r]) {
			return (r == e) ? -1 : (e + 1);
		}
		l++;
		r--;
	}
	return -1;
}

void constructTree(int s, int e) {
	if (s < 0) {
		return;
	}
	if (s == e) {
		return;
	}

	int root = pre[s];
	child[s][0] = (pre[s] > pre[s + 1]) ? s + 1 : -1;
	child[s][1] = findRchild(s + 1, e, root);

	constructTree(child[s][0], (child[s][1] < 0) ? e : (child[s][1] - 1));
	constructTree(child[s][1], e);
}

bool findAncestor(int s, int U, int V) {
	if (s < 0) {
		return false;
	}
	int root = pre[s];
	if (U == V && root == U) {
		return true;
	}
	if (V == root) {

	}
}

int main() {
	//initialization
	fill_n(pre, 10001, 0);
	for (int i = 0; i < 10001; i++) {
		child[i][0] = -1;
		child[i][1] = -1;
	}

	int M;

	scanf_s("%d %d", &M, &N);
	for (int i = 0; i < N; i++) {
		scanf_s("%d", pre + i);
	}

	constructTree(0, N - 1);

	int U, V;
	while (M--) {
		scanf_s("%d %d", &U, &V);
		if (U == V) {
			printf("%d is an ancestor of %d.\n", U, V);
		}
		else if (U > V) {

		}
		else {

		}
	}

	system("pause");
	return 0;
}