#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <queue>
#include <cstring>
#include <string>
#include <cstdlib>

using namespace std;

int N;
int nodes[21] = { 0 }; //record child vertex
int tree[21][2] = { -1 }; //initialization

bool flag = false; //when we visits leaf vetex once, then turns to true
int last = 0;

bool BFS(int root) {
	//initialization
	flag = false;
	last = 0;
	queue<int> q;

	int node;
	q.push(root); 
	while (!q.empty()) {
		node = q.front();
		q.pop();
		for (int i = 0; i < 2; i++) {
			if (tree[node][i] == -1) { //encounter leaf vertex
				flag = true;
			}
			else {
				q.push(tree[node][i]);
			}
			if (flag && tree[node][i] != -1) {
				return false; //it is not a complete binary tree
			}
		}
	}
	last = node; // the index of last node
	return true;
}

int main() {
	
	char lc[3]; //left child
	char rc[3]; //right child
	scanf_s("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf_s("%s %s", lc, 3, rc, 3);
		if (lc[0] == '-') {
			tree[i][0] = -1;
		}
		else {
			tree[i][0] = atoi(lc);
			nodes[tree[i][0]]++;
		}
		if (rc[0] == '-') {
			tree[i][1] = -1;
		}
		else {
			tree[i][1] = atoi(rc);
			nodes[tree[i][1]]++;
		}
	}

	int root = 0;
	for (int i = 0; i < N; i++) {
		if (nodes[i] == 0 && (tree[i][0] != -1 || tree[i][1] != -1)) {
			root = i;
		}
	}

	if (BFS(root)) {
		printf("YES %d\n", last);
	}
	else {
		printf("NO %d\n", root);
	}

	system("pause");
	return 0;
}