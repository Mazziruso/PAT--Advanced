#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <map>
#include <vector>
#include <cstdlib>
#include <queue>

using namespace std;

int N;
map<int, int> keyID;
map<int, int> inKeyIndex;
int preSeq[10001];
int inSeq[10001];
int parent[10001];

void constructTree(int preS, int preE, int inS, int inE) {
	if (preS >= preE) {
		return;
	}

	int root = preSeq[preS];
	int index_in = inKeyIndex.find(root)->second;
	int lchild;
	int rchild;
	if (index_in == inS) { //没有左子树
		lchild = -1;
		rchild = preS + 1;
		parent[rchild] = preS;
		constructTree(rchild, preE, index_in + 1, inE);
	}
	else if (index_in == inE) { //没有右子树
		lchild = preS + 1;
		rchild = -1;
		parent[lchild] = preS;
		constructTree(lchild, preE, inS, index_in - 1);
	}
	else {
		lchild = preS + 1;
		rchild = lchild + index_in - inS;
		parent[lchild] = preS;
		parent[rchild] = preS;
		constructTree(lchild, rchild - 1, inS, index_in - 1);
		constructTree(rchild, preE, index_in + 1, inE);
	}
}

void findAncestor(int index1, int index2) {
	int k1 = preSeq[index1];
	int k2 = preSeq[index2];
	vector<int> path1;
	vector<int> path2;

	while (index1 != parent[index1]) {
		path1.push_back(preSeq[index1]);
		index1 = parent[index1];
	}
	path1.push_back(preSeq[index1]);
	while (index2 != parent[index2]) {
		path2.push_back(preSeq[index2]);
		index2 = parent[index2];
	}
	path2.push_back(preSeq[index2]);

	index1 = path1.size() - 1;
	index2 = path2.size() - 1;
	while (index1 >= 0 && index2 >= 0 && path1[index1] == path2[index2]) {
		index1--;
		index2--;
	}
	if (index1 < 0) {
		printf("%d is an ancestor of %d.\n", k1, k2);
	}
	else if (index2 < 0) {
		printf("%d is an ancestor of %d.\n", k2, k1);
	}
	else {
		printf("LCA of %d and %d is %d.\n", k1, k2, path1[index1 + 1]);
	}
}

int main() {
	//initialization
	fill_n(parent, 10001, 0);

	int M;
	scanf_s("%d %d", &M, &N);
	for (int i = 0; i < N; i++) {
		scanf_s("%d", inSeq + i);
		inKeyIndex[inSeq[i]] = i;
	}
	for (int i = 0; i < N; i++) {
		scanf_s("%d", preSeq + i);
		keyID[preSeq[i]] = i;
	}

	constructTree(0, N - 1, 0, N - 1);

	map<int, int>::iterator iter1;
	map<int, int>::iterator iter2;
	int k1, k2, ancestor;
	while (M--) {
		scanf_s("%d %d", &k1, &k2);
		iter1 = keyID.find(k1);
		iter2 = keyID.find(k2);
		if (iter1 == keyID.end() && iter2 == keyID.end()) {
			printf("ERROR: %d and %d are not found.\n", k1, k2);
		}
		else if (iter1 == keyID.end()) {
			printf("ERROR: %d is not found.\n", k1);
		}
		else if (iter2 == keyID.end()) {
			printf("ERROR: %d is not found.\n", k2);
		}
		else {
			findAncestor(iter1->second, iter2->second);
		}
	}

	system("pause");
	return 0;
}