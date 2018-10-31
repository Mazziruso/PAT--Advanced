#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

vector<int> *graph;
int N;
int L;
bool *visit;
int *dist;

int BFS(int s) {
	//initialization
	fill_n(visit, N, false);
	fill_n(dist, N, 0);
	int total = 0;
	queue<int> q;

	int node;
	vector<int>::iterator iter;

	q.push(s);
	visit[s] = true;
	while (!q.empty()) {
		node = q.front();
		q.pop();

		if (dist[node] == L) {
			continue;
		}

		for (iter = graph[node].begin(); iter != graph[node].end(); ++iter) {
			if (!visit[*iter]) {
				q.push(*iter);
				visit[*iter] = true;
				dist[*iter] = dist[node] + 1;
				total++;
			}
		}
	}
	return total;
}

int main() {

	int K;
	scanf_s("%d %d", &N, &L);

	visit = new bool[N];
	dist = new int[N];

	int M, node;
	graph = new vector<int>[N];
	for (int i = 0; i < N; i++) {
		scanf_s("%d", &M);
		while (M--) {
			scanf_s("%d", &node);
			graph[node - 1].push_back(i);
		}
	}

	scanf_s("%d", &K);
	while (K--) {
		scanf_s("%d", &node);
		printf("%d\n", BFS(node - 1));
	}

	system("pause");
	return 0;
}