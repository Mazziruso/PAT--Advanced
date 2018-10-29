#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#define INT_MAX 2147483647

using namespace std;

int **graph;
int Nv;
int *dist;
bool *visit;

//dijkstra
void dijkstra(int s) {
	//initialize
	for (int i = 0; i < Nv; i++) {
		dist[i] = INT_MAX;
		visit[i] = false;
	}
	dist[s] = 0;

	int distTmp;
	int minIndex;
	for (int i = 0; i < Nv - 1; i++) {
		minIndex = -1;
		for (int k = 0; k < Nv; k++) {
			if (!visit[k] && (minIndex < 0 || dist[k] < dist[minIndex])) {
				minIndex = k;
			}
		}

		visit[minIndex] = true;
		for (int k = 0; k < Nv; k++) {
			if (!visit[k] && graph[minIndex][k] > 0) {
				distTmp = dist[minIndex] + graph[minIndex][k];
				if (distTmp < dist[k]) {
					dist[k] = distTmp;
				}
			}
		}
	}
}

int getID(string str, int N) {
	int id;
	int len = str.size();

	if (str.at(0) == 'G') {
		id = stoi(str.substr(1, len - 1)) + N;
	}
	else {
		id = stoi(str);
	}
	return id;
}

int main() {

	int N, M, K, Ds;
	scanf_s("%d %d %d %d", &N, &M, &K, &Ds);
	
	Nv = N + M;
	dist = new int[Nv];
	visit = new bool[Nv];
	graph = new int*[1020];
	for (int i = 0; i < 1020; i++) {
		graph[i] = new int[1020];
		fill(graph[i], graph[i] + 1020, 0);
	}

	//construct graph with double dimensional array
	string str;
	int p1, p2, d;
	for (int i = 0; i < K; i++) {
		cin >> str;
		p1 = getID(str, N);
		cin >> str;
		p2 = getID(str, N);
		scanf_s("%d", &d);
		graph[p1 - 1][p2 - 1] = d;
		graph[p2 - 1][p1 - 1] = d;
	}

	//dijkstra evaluates shortest path
	int *minD = new int[M];
	double *avgD = new double[M];
	int *maxD = new int[M];

	int minn;
	int maxn;
	double sum;
	for (int i = 0; i < M; i++) {
		p2 = i + N;
		dijkstra(p2);

		//construct solution
		minn = INT_MAX;
		maxn = -1;
		sum = 0;
		for (int j = 0; j < N; j++) {
			sum += dist[j];
			if (minn > dist[j]) {
				minn = dist[j];
			}
			if (maxn < dist[j]) {
				maxn = dist[j];
			}
		}
		avgD[i] = sum / N;
		minD[i] = minn;
		maxD[i] = maxn;
	}

	int index = -1;
	maxn = -1;
	double minAvg = 0;
	for (int i = 0; i < M; i++) {
		if (maxD[i] <= Ds) {
			if (maxn < minD[i]) {
				index = i;
				maxn = minD[i];
				minAvg = avgD[i];
			}
			else if (maxn == minD[i] && minAvg - avgD[i] > 0.0001) {
				index = i;
				minAvg = avgD[i];
			}
		}
	}

	if (index == -1) {
		printf("No Solution\n");
	}
	else {
		printf("G%d\n%d.0 %.1f\n", index + 1, minD[index], avgD[index]);
	}

	system("pause");
	return 0;
}