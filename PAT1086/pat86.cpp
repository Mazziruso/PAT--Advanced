#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <stack>
#include <string>

using namespace std;

struct node {
	int key;
	node *p;
	node *l;
	node *r;
	node() : key(-1), p(nullptr), l(nullptr), r(nullptr) {};
};

inline void constructNode(node *nod, int key) {
	nod->key = key;
	nod->l = new node();
	nod->r = new node();
	nod->l->p = nod;
	nod->r->p = nod;
}

void postOrder(node *nod, node *root) {
	if (nod->key != -1) {
		postOrder(nod->l, root);
		postOrder(nod->r, root);
		if (nod == root) {
			printf("%d\n", nod->key);
		}
		else {
			printf("%d ", nod->key);
		}
	}
 }

int main() {

	int N;
	scanf_s("%d", &N);

	int count = 0;
	node *nod = new node();
	node *root = nod;
	int key;
	string str;
	for (int i = 0; i < 2 * N; i++) {
		cin >> str;
		if (str == "Pop") {
			while (nod == nod->p->r && count--) {
				nod = nod->p;
			}
			nod = nod->p;
		}
		else {
			cin >> key;
			if (nod->key == -1) {
				constructNode(nod, key);
				nod = nod->l;
			}
			else {
				nod = nod->r;
				constructNode(nod, key);
				nod = nod->l;
				count++;
			}
		}
	}

	postOrder(root, root);

	system("pause");
	return 0;
}