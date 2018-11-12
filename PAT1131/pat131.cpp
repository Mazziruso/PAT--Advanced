#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <queue>
#define INT_MAX 2147483647

using namespace std;

typedef struct station {
	int id;
	int line;
} sta;

int N;
vector<sta> graph[10001]; //Adjacency List
//dijkstra或SPFA
int dist[10001] = { INT_MAX }; //the total number of stops from the start to the current station
int trans[10001] = { INT_MAX }; //the total number of transfers from the start to the current station
bool visit[10001] = { false };
int pre[10001] = { -1 };
int line[10001] = { 0 }; //代表当前结点在当前过程中的线路

void dijkstra(int s, int dest) {
	//initialization
	fill_n(trans, 10001, INT_MAX);
	fill_n(dist, 10001, INT_MAX);
	fill_n(line, 10001, 0);
	fill_n(visit, 10001, false);
	fill_n(pre, 10001, -1);

	int tmp;
	int k;
	dist[s] = 0;
	trans[s] = 0;
	for (int i = 0; i <  10000; i++) {
		k = -1;
		for (int j = 0; j < 10001; j++) {
			if (!visit[j] && (k < 0 || dist[j] < dist[k])) {
				k = j;
			}
		}
		visit[k] = true;
		//提前退出
		if (k == dest) {
			break;
		}
		for (auto iter : graph[k]) {
			if (!visit[iter.id]) {
				tmp = (line[k] != iter.line) ? trans[k] + 1 : trans[k];
				if (dist[iter.id] > dist[k] + 1) {
					pre[iter.id] = k;
					line[iter.id] = iter.line;
					trans[iter.id] = tmp;
					dist[iter.id] = dist[k] + 1;
				}
				else if (dist[iter.id] == dist[k] + 1 && trans[iter.id] >= tmp) {
					pre[iter.id] = k;
					line[iter.id] = iter.line;
					trans[iter.id] = tmp;
				}
			}
		}
	}
}

void SPFA(int s, int dest) {
	//intialization
	fill_n(visit, 10001, false);
	fill_n(dist, 10001, INT_MAX);
	fill_n(trans, 10001, INT_MAX);
	fill_n(pre, 10001, -1);
	fill_n(line, 10001, 0);
	//queue
	queue<int> q;
	q.push(s);
	dist[s] = 0;
	trans[s] = 0;
	visit[s] = true;
	//SPFA
	int node;
	int tmp;
	while (!q.empty()) {
		node = q.front();
		q.pop();
		visit[node] = false;
		for (auto iter : graph[node]) {
			tmp = (line[node] != iter.line) ? trans[node] + 1 : trans[node];
			if (dist[iter.id] > dist[node] + 1) {
				dist[iter.id] = dist[node] + 1;
				trans[iter.id] = tmp;
				pre[iter.id] = node;
				line[iter.id] = iter.line;
				if (!visit[iter.id]) {
					q.push(iter.id);
					visit[iter.id] = true;
				}
			}
			else if (dist[iter.id] == dist[node] + 1 && trans[iter.id] >= tmp) {
				trans[iter.id] = tmp;
				pre[iter.id] = node;
				line[iter.id] = iter.line;
				if (!visit[iter.id]) {
					q.push(iter.id);
					visit[iter.id] = true;
				}
			}
		}
	}
}

void printLine(int s, int dest) {
	sta res[10001];
	int index = 0;

	sta tmp;
	int node = dest;
	tmp.id = node;
	tmp.line = line[node];
	res[index++] = tmp;

	while (pre[node] != -1) {
		if (line[node] != line[pre[node]]) {
			tmp.line = line[pre[node]];
			tmp.id = pre[node];
			res[index++] = tmp;
		}
		node = pre[node];
	}
	
	while (index >= 2) {
		printf("Take Line#%d from %04d to %04d.\n", res[index - 2].line, res[index - 1].id, res[index - 2].id);
		index--;
	}
}

int main() {

	int M, K;
	int sl, sc;
	sta node;

	scanf_s("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf_s("%d", &M);

		if (M == 0) {
			continue;
		}

		scanf_s("%d", &sl);
		M--;
		node.line = i;

		while (M--) {
			scanf_s("%d", &sc);
			node.id = sc;
			graph[sl].push_back(node);
			node.id = sl;
			graph[sc].push_back(node);
			sl = sc;
		}
	}

	scanf_s("%d", &K);
	int source, dest;
	while (K--) {
		scanf_s("%d %d", &source, &dest);
		SPFA(source, dest);
		printf("%d\n", dist[dest]);
		printLine(source, dest);
	}

	system("pause");
	return 0;
}
