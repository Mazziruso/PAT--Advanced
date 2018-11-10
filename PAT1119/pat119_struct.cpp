#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstdlib>

using namespace std;

struct node {
	int key;
	struct node *lchild;
	struct node *rchild;
	node() : key(-1), lchild(nullptr), rchild(nullptr) {};
	node(int k) : key(k), lchild(nullptr), rchild(nullptr) {};
};

int N;
int preSeq[31];
int postSeq[31];
bool flag = true;
int inSeq[31];
int index = 0;

int findPre(int key) {
	for (int i = 1; i < N; i++) {
		if (preSeq[i] == key) {
			return i;
		}
	}
	return 1;
}

int findPost(int key) {
	for (int i = 0; i < N - 1; i++) {
		if (postSeq[i] == key) {
			return i;
		}
	}
	return 1;
}

void constructTree(struct node *root, int preS, int preE, int postS, int postE) {
	if (preS + 1 == preE && postS + 1 == postE) {
		root->lchild = new struct node(preSeq[preS + 1]);
		flag = false;
	}
	else if (preS + 1 < preE && postS + 1 < postE) {
		int l_index = findPost(preSeq[preS + 1]);
		int r_index = findPre(postSeq[postE - 1]);
		root->lchild = new struct node(preSeq[preS + 1]);
		root->rchild = new struct node(postSeq[postE - 1]);
		constructTree(root->lchild, preS + 1, r_index - 1, postS, l_index);
		constructTree(root->rchild, r_index, preE, l_index + 1, postE - 1);
	}
}

void inOrder(struct node *root) {
	if (root != nullptr) {
		inOrder(root->lchild);
		inSeq[index++] = root->key;
		inOrder(root->rchild);
	}
}

int main() {
	
	struct node *root = new struct node();
	flag = true;

	scanf_s("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf_s("%d", preSeq + i);
	}
	for (int i = 0; i < N; i++) {
		scanf_s("%d", postSeq + i);
	}

	root->key = preSeq[0];
	constructTree(root, 0, N - 1, 0, N - 1);

	if (flag) {
		printf("Yes\n");
	}
	else {
		printf("No\n");
	}

	inOrder(root);
	for (int i = 0; i < N - 1; i++) {
		printf("%d ", inSeq[i]);
	}
	printf("%d\n", inSeq[N - 1]);

	system("pause");
	return 0;
}