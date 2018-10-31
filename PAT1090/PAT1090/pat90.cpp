#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N;
vector<int> *Tree;
int *dist;

int BFS(int root) {
	//initialization
	int maxDepth;
	fill_n(dist, N, 0);
	queue<int> q;

	q.push(root);
	dist[root] = 0;
	maxDepth = 0;
	
	int node;
	while (!q.empty()) {
		node = q.front();
		q.pop();
		for (auto iter : Tree[node]) {
			q.push(iter);
			dist[iter] = dist[node] + 1;
			maxDepth = (maxDepth < dist[iter]) ? dist[iter] : maxDepth;
		}
	}
	return maxDepth;
}

int main() {

	double P, r;
	scanf_s("%d %lf %lf", &N, &P, &r);
	r = 1 + r / 100;

	Tree = new vector<int>[N];
	dist = new int[N];

	int root = -1;
	int node;
	for (int i = 0; i < N; i++) {
		scanf_s("%d", &node);
		root = (node == -1) ? i : root;
		if (node >= 0) {
			Tree[node].push_back(i);
		}
	}

	int maxDepth = BFS(root);

	int num = 0;
	for (int i = 0; i < N; i++) {
		if (dist[i] == maxDepth) {
			num++;
		}
	}

	printf("%.2f %d\n", pow(r, maxDepth)*P, num);

	system("pause");
	return 0;
}