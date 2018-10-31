#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#define INT_MAX 2147483647

using namespace std;

int N;
int *dist;
vector<int> leafDepth;
vector<int> *Tree;

int BFS(int root) {
	//initialization
	int minDepth = INT_MAX;
	fill_n(dist, N, 0);
	queue<int> q;

	q.push(root);
	dist[root] = 0;
	
	int node;

	while (!q.empty()) {
		node = q.front();
		q.pop();
		if (Tree[node].empty()) {
			minDepth = (dist[node] < minDepth) ? dist[node] : minDepth;
			leafDepth.push_back(dist[node]);
		}
		for (auto iter : Tree[node]) {
			q.push(iter);
			dist[iter] = dist[node] + 1;
		}
	}
	return minDepth;
}

int main() {

	double P, r;
	scanf_s("%d %lf %lf", &N, &P, &r);
	r = 1 + r / 100;

	int K;
	int node;
	Tree = new vector<int>[N];
	dist = new int[N];
	for (int i = 0; i < N; i++) {
		scanf_s("%d", &K);
		while (K--) {
			scanf_s("%d", &node);
			Tree[i].push_back(node);
		}
	}

	int minDepth = BFS(0);

	int num = 0;
	for (auto iter : leafDepth) {
		if (minDepth == iter) {
			num++;
		}
	}

	printf("%.4f %d\n", P*pow(r, minDepth), num);

	system("pause");
	return 0;
}