#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <algorithm>

using namespace std;

int seq[31] = { 0 }; //pre-order sequence

int findRchild(int s, int e, int root) {
	for (int i = s; i <= e; i++) {
		if (labs(seq[i]) >= labs(root)) {
			return i;
		}
	}
	return -1;
}

int RBbhCheck(int s, int e) {
	if (s < 0 || e < 0) { //NIL, Leave node
		return 1;
	}
	if (s == e) { //the node is no leave node but has no child
		return seq[s] > 0 ? 2 : 1;
	}

	//s < e, the node is interior node

	int root = seq[s];
	int l_index = (labs(root) > labs(seq[s + 1])) ? s + 1 : -1;
	int r_index = findRchild(s + 1, e, root);

	//property (4)
	if (root < 0 && ((l_index >= 0 && seq[l_index] < 0) || (r_index >= 0 && seq[r_index] < 0))) {
		return -1;
	}

	int bh_l = RBbhCheck(l_index, r_index - 1);
	int bh_r = RBbhCheck(r_index, e);

	//property (5)
	if (bh_r != bh_l || bh_l == -1 || bh_r == -1) {
		return -1;
	}

	//the current RB tree is legal
	if (root > 0) {
		return bh_l + 1;
	}
	else {
		return bh_l;
	}
}

int main() {

	int K, N;
	scanf_s("%d", &K);

	while (K--) {
		scanf_s("%d", &N);
		for (int i = 0; i < N; i++) {
			scanf_s("%d", seq + i);
		}
		printf("%s\n", (seq[0] < 0 || RBbhCheck(0, N - 1) == -1) ? "No" : "Yes");
		fill_n(seq, N, 0);
	}

	system("pause");
	return 0;
}