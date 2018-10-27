/*
关键在于最后的多条路径之间的比较
*/

#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

typedef struct stringRes {
	string s;
	double w;
} sr;

int S;
vector<int> *nodes;
int *weight;
int *pre;
vector<int> leaf;
sr *s;

int dfs(int root, int UPW) {
	UPW += weight[root];

	//leaf node
	if (nodes[root].empty()) {
		if (UPW == S) {
			leaf.push_back(root);
		}
		return UPW;
	}

	int sum = UPW;
	bool flag = false;
	for (auto i : nodes[root]) {
		sum = dfs(i, UPW);
		if (sum == S) {
			pre[i] = root;
			flag = true;
		}
	}

	return flag ? S : sum;
}

void printPath(int leaf, int index) {
	if (leaf > 0) {
		s[index].w = s[index].w / 1000.0 + weight[leaf];
		printPath(pre[leaf], index);
		s[index].s.append(" ").append(to_string(weight[leaf]));
	}
	else {
		s[index].s.append(to_string(weight[leaf]));
		s[index].w += weight[leaf];
	}
}

bool cmp(sr s1, sr s2) {
	return s1.w > s2.w;
}

int main() {

	int N, M;
	scanf_s("%d %d %d", &N, &M, &S);

	nodes = new vector<int>[N];
	weight = new int[N];
	pre = new int[N];
	fill(pre, pre + N, 0);

	for (int i = 0; i < N; i++) {
		scanf_s("%d", weight + i);
	}

	int ID;
	int K;
	int child;
	for (int i = 0; i < M; i++) {
		scanf_s("%d %d", &ID, &K);
		while (K--) {
			scanf_s("%d", &child);
			nodes[ID].push_back(child);
		}
	}

	int pathWeight = dfs(0, 0);

	if (pathWeight != S) {
		return 0;
	}
	
	int size = leaf.size();
	int index = 0;
	s = new sr[size];
	for (auto i : leaf) {
		s[index].w = 0;
		printPath(i, index);
		index++;
	}

	sort(s, s + size, cmp);

	for (int i = 0; i < size; i++) {
		cout << s[i].s << endl;
	}

	system("pause");
	return 0;
}