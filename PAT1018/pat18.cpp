#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>

#define INT_MAX 2147483647

using namespace std;

int N;
int Cmax;
int graph[501][501];
int bikes[501];
int dist[501];
bool visit[501];
vector<int> pre[501];
//DFS Result
vector<int> Path;
vector<int> tmpPath;
int optSent;
int optCollect;

void dijkstra(int s, int dest) {
	//initialization
	fill_n(dist, 501, INT_MAX);
	fill_n(visit, 501, false);

	dist[s] = 0;
	int k, tmp;
	for (int i = 1; i <= N; i++) {
		k = -1;
		for (int j = 0; j <= N; j++) {
			if (!visit[j] && (k<0 || dist[k]>dist[j])) {
				k = j;
			}
		}
		if (k == dest) {
			break;
		}
		visit[k] = true;
		for (int j = 1; j <= N; j++) {
			if (!visit[j] && graph[k][j] > 0) {
				tmp = dist[k] + graph[k][j];
				if (tmp < dist[j]) {
					dist[j] = tmp;
					pre[j].clear();
					pre[j].push_back(k);
				}
				else if (tmp == dist[j]) {
					pre[j].push_back(k);
				}
			}
		}
	}
}

void DFS(int node, int sent, int collect) {
	//bound
	if (node == 0) {
		tmpPath.push_back(node);
		if (sent < optSent) {
			Path = tmpPath;
			optSent = sent;
			optCollect = collect;
		}
		else if (sent == optSent && collect < optCollect) {
			Path = tmpPath;
			optCollect = collect;
		}
		tmpPath.pop_back();
		return;
	}

	int lack;
	tmpPath.push_back(node);
	lack = Cmax / 2 - bikes[node];
		if (lack > 0) {
			sent += lack;
		}
		else {
			lack = -lack;
			collect += (lack > sent) ? (lack - sent) : 0;
			sent = (lack > sent) ? 0 : (sent - lack);
		}
	for (auto u : pre[node]) {
		DFS(u, sent, collect);
	}
	tmpPath.pop_back();
}

int main() {
	//initialzation
	for (int n = 0; n < 501; n++) {
		fill_n(graph[n], 501, 0);
	}
	fill_n(bikes, 501, 0);
	optSent = INT_MAX;
	optCollect = INT_MAX;

	int sp, M;
	scanf_s("%d %d %d %d", &Cmax, &N, &sp, &M);

	for (int n = 1; n <= N; n++) {
		scanf_s("%d", bikes + n);
	}

	int u, v, cost;
	for (int m = 0; m < M; m++) {
		scanf_s("%d %d %d", &u, &v, &cost);
		graph[u][v] = cost;
		graph[v][u] = cost;
	}

	dijkstra(0, sp);
	DFS(sp, 0, 0);
	
	printf("%d 0", optSent);
	for (int i = Path.size() - 2; i >= 0; i--) {
		printf("->%d", Path[i]);
	}
	printf(" %d\n", optCollect);

	system("pause");
	return 0;
}