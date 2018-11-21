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
	while (l <= (r + 1
		)) {
		if (root <= pre[l]) {
			return l;
		}
		else if (root > pre[r]) {
			return (r == e) ? -1 : (r + 1);
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

bool search(int root, int key) {
	if (root < 0) {
		return false;
	}

	if (key == pre[root]) {
		return true;
	}
	else if (key > pre[root]) {
		return search(child[root][1], key);
	}
	else {
		return search(child[root][0], key);
	}
}

void findAncestor(int s, int U, int V) {
	if (s < 0) {
		printf("ERROR: %d and %d are not found.\n", U, V);
		return;
	}
	//when U or V is another node' ancestor
	if (U == pre[s]) {
		bool flag = search(s, V);
		if (flag) {
			printf("%d is an ancestor of %d.\n", U, V);
		}
		else {
			printf("ERROR: %d is not found.\n", V);
		}
		return;
	} else if (V == pre[s]) {
		bool flag = search(s, U);
		if (flag) {
			printf("%d is an ancestor of %d.\n", V, U);
		}
		else {
			printf("ERROR: %d is not found.\n", U);
		}
		return;
	}

	//when two node is at the same subtree
	if (U < pre[s] && V < pre[s]) {
		findAncestor(child[s][0], U, V);
	}
	else if(U > pre[s] && V > pre[s]) {
		findAncestor(child[s][1], U, V);
	}
	else {
		bool flag2 = search(s, V);
		bool flag1 = search(s, U);
		if (flag1 && flag2) {
			printf("LCA of %d and %d is %d.\n", U, V, pre[s]);
		}
		else if (flag1 && !flag2) {
			printf("ERROR: %d is not found.\n", V);
		}
		else if (!flag1 && flag2) {
			printf("ERROR: %d is not found.\n", U);
		}
		else {
			printf("ERROR: %d and %d are not found.\n", U, V);
		}
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
		if (U != V) {
			findAncestor(0, U, V);
		}
		else {
			if (search(0, U)) {
				printf("%d is an ancestor of %d.\n", U, V);
			}
			else {
				printf("ERROR: %d and %d are not found.\n", U, V);
			}
		}
	}

	system("pause");
	return 0;
}