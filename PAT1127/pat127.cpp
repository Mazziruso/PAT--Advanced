#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <deque>

using namespace std;

int N;
int child[31][2];
int inSeq[31];
int postSeq[31];
int zzSeq[31];

int findIn(int s, int e, int key) {
	for (int i = s; i <= e; i++) {
		if (inSeq[i] == key) {
			return i;
		}
	}
	return 0;
}

int constructTree(int inS, int inE, int postS, int postE) {
	if (inS > inE && postS > postE) {
		return -1;
	}

	int root = postSeq[postE];
	int rootIn = findIn(inS, inE, root);
	int postPivot = rootIn - inS + postS - 1;

	child[root][0] = constructTree(inS, rootIn - 1, postS, postPivot);
	child[root][1] = constructTree(rootIn + 1, inE, postPivot + 1, postE - 1);

	return root;
}

void zzTravel(int root) {
	//initialization
	fill_n(zzSeq, 31, 0);
	deque<int> q;
	/*代表层次遍历方向, false代表向左, true代表向右, 每次遍历完一层就换方向，由于第二层是向右因此第一层向左*/
	bool direct = false; 
	int levelEnd = root; //代表每层最后结点的值
	int index = 0;

	int node;

	q.push_back(root);
	while (!q.empty()) {
		if (direct) {
			node = q.front();
			q.pop_front();
			for (int i = 0; i < 2; i++) {
				if (child[node][i] != -1) {
					q.push_back(child[node][i]);
				}
			}
		}
		else {
			node = q.back();
			q.pop_back();
			for (int i = 1; i >= 0; i--) { //注意左右子结点反过来
				if (child[node][i] != -1) {
					q.push_front(child[node][i]);
				}
			}
		}
		zzSeq[index++] = node;
		if (node == levelEnd && !q.empty()) {
			direct = !direct;
			levelEnd = direct ? q.back() : q.front();
		}
	}
}

int main() {
	//initialization
	for (int i = 0; i < 31; i++) {
		child[i][0] = -1;
		child[i][1] = -1;
	}
	fill_n(inSeq, 31, -1);
	fill_n(postSeq, 31, -1);
	fill_n(zzSeq, 31, -1);

	scanf_s("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf_s("%d", inSeq + i);
	}
	for (int i = 0; i < N; i++) {
		scanf_s("%d", postSeq + i);
	}

	int root = constructTree(0, N - 1, 0, N - 1);

	zzTravel(root);

	printf("%d", zzSeq[0]);
	for (int i = 1; i < N; i++) {
		printf(" %d", zzSeq[i]);
	}
	printf("\n");

	system("pause");
	return 0;
}