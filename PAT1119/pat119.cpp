#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int N;
int preSeq[31] = { 0 };
int postSeq[31] = { 0 };
int child[2][31];
bool flag = true; //true denotes unique
//output
int inSeq[31] = { 0 };
int index = 0;

int findPre(int s, int e, int key) {
	for (int i = s; i <= e; i++) {
		if (preSeq[i] == key) {
			return i;
		}
	}
	return s;
}

int findPost(int s, int e, int key) {
	for (int i = s; i <= e; i++) {
		if (postSeq[i] == key) {
			return i;
		}
	}
	return s;
}

void constructTree(int preS, int preE, int postS, int postE) {
	if (preS + 1 == preE && postS + 1 == postE) {
		child[0][preS] = preS + 1;
		child[1][preS] = -1;
		flag = false;
	}
	else if (preS + 1 < preE && postS + 1 < postE) {
		int l_index = findPost(postS, postE - 1, preSeq[preS + 1]);
		int r_index = findPre(preS + 1, preE, postSeq[postE - 1]);
		child[0][preS] = preS + 1;
		child[1][preS] = r_index;
		constructTree(preS + 1, r_index - 1, postS, l_index);
		constructTree(r_index, preE, l_index + 1, postE - 1);
	}
}

void inOrder(int root) {
	if (root != -1) {
		inOrder(child[0][root]);
		inSeq[index++] = preSeq[root];
		inOrder(child[1][root]);
	}
}

int main() {
	//initialization
	fill_n(child[0], 31, -1);
	fill_n(child[1], 31, -1);
	flag = true;

	scanf_s("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf_s("%d", preSeq + i);
	}
	for (int i = 0; i < N; i++) {
		scanf_s("%d", postSeq + i);
	}

	constructTree(0, N - 1, 0, N - 1);

	if (flag) {
		printf("Yes\n");
	}
	else {
		printf("No\n");
	}

	inOrder(0);
	for (int i = 0; i < N - 1; i++) {
		printf("%d ", inSeq[i]);
	}
	printf("%d\n", inSeq[N - 1]);

	system("pause");
	return 0;
}