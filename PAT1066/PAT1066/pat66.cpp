#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

typedef struct nodee {
	int key;
	int h;
	struct nodee *lchild;
	struct nodee *rchild;
} node;

void updateH(node *n) {
	int lh = n->lchild->h;
	int rh = n->rchild->h;
	n->h = (lh > rh) ? (lh + 1) : (rh + 1);
}

node* left_left_Rotate(node *k2) {
	node *k1 = k2->lchild;

	k2->lchild = k1->rchild;
	updateH(k2);

	k1->rchild = k2;
	updateH(k1);

	return k1;
}

node* right_right_Rotate(node *k1) {
	node *k2 = k1->rchild;

	k1->rchild = k2->lchild;
	updateH(k1);

	k2->lchild = k1;
	updateH(k2);

	return k2;
}

node* left_right_Rotate(node *k3) {

	k3->lchild = right_right_Rotate(k3->lchild);

	return left_left_Rotate(k3);
}

node *right_left_Rotate(node *k1) {

	k1->rchild = left_left_Rotate(k1->rchild);

	return right_right_Rotate(k1);
}

node* createNode(int key) {
	node *nod = new node;
	nod->key = key;
	nod->h = 1;
	nod->lchild = new node;
	nod->rchild = new node;
	nod->lchild->h = 0;
	nod->rchild->h = 0;
	return nod;
}

node *insertAVL(node *root, int key) {
	if (root->h == 0) {
		root = createNode(key);
		return root;
	}

	if (key < root->key) {
		root->lchild = insertAVL(root->lchild, key);
		if ((root->lchild->h - root->rchild->h) >= 2) {
			if (key < root->lchild->key) {
				root = left_left_Rotate(root);
			}
			else {
				root = left_right_Rotate(root);
			}
		}
	}
	else {
		root->rchild = insertAVL(root->rchild, key);
		if ((root->rchild->h - root->lchild->h) >= 2) {
			if (key >= root->rchild->key) {
				root = right_right_Rotate(root);
			}
			else {
				root = right_left_Rotate(root);
			}
		}
	}

	updateH(root);
	return root;
}

int main() {

	int N;
	scanf_s("%d", &N);

	int *keys = new int[N];
	for (int i = 0; i < N; i++) {
		scanf_s("%d", keys + i);
	}

	if (N == 1) {
		printf("%d\n", *keys);
		return 0;
	}

	node *root = createNode(keys[0]);

	for (int i = 1; i < N; i++) {
		root = insertAVL(root, keys[i]);
	}

	printf("%d\n", root->key);

	system("pause");
	return 0;
}