#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#define INT_MAX 2147483647

using namespace std;

int N;
int graphL[501][501] = { -1 }; //direct graph
int graphT[501][501] = { -1 }; //direct graph
bool visit[501] = { false };
int dist[501] = { INT_MAX };
int fast[501] = { INT_MAX };
int prevD[501] = { -1 };
int prevT[501] = { -1 };
vector<int> pathD;
vector<int> pathT;

//fastest and fewest path
int dijkstraTime(int s, int dest) {
	//initialization
	for (int i = 0; i < N; i++){
		visit[i] = false;
		dist[i] = INT_MAX;
		fast[i] = INT_MAX;
	}

	//dijkstra
	int tmp;
	int k = 0;
	fast[s] = 0;
	dist[s] = 0;
	prevT[s] = s;
	for (int i = 0; i < N - 1; i++) {
		k = -1;
		for (int j = 0; j < N; j++) {
			if (!visit[j] && (k < 0 || fast[k] > fast[j])) {
				k = j;
			}
		}
		visit[k] = true;
		for (int j = 0; j < N; j++) {
			if (!visit[j] && graphT[k][j] > 0) {
				tmp = fast[k] + graphT[k][j];
				if (tmp < fast[j]) {
					fast[j] = tmp;
					dist[j] = dist[k] + 1;
					prevT[j] = k;
				}
				else if (tmp==fast[j] && dist[j]>dist[k]+1) {
					dist[j] = dist[k] + 1;
					prevT[j] = k;
				}
			}
		}
	}
	return fast[dest];
}

//shortest and fastest
int dijkstraDist(int s, int dest) {
	//initialization
	for (int i = 0; i < N; i++) {
		visit[i] = false;
		dist[i] = INT_MAX;
		fast[i] = INT_MAX;
	}

	//dijkstra
	int tmp;
	int k = 0;
	fast[s] = 0;
	dist[s] = 0;
	prevD[s] = s;
	for (int i = 0; i < N - 1; i++) {
		k = -1;
		for (int j = 0; j < N; j++) {
			if (!visit[j] && (k < 0 || dist[k] > dist[j])) {
				k = j;
			}
		}
		visit[k] = true;
		for (int j = 0; j < N; j++) {
			if (!visit[j] && graphL[k][j] > 0) {
				tmp = dist[k] + graphL[k][j];
				if (tmp < dist[j]) {
					dist[j] = tmp;
					fast[j] = fast[k] + graphT[k][j];
					prevD[j] = k;
				}
				else if (tmp == dist[j] && fast[j] > fast[k] + graphT[k][j]) {
					fast[j] = fast[k] + graphT[k][j];
					prevD[j] = k;
				}
			}
		}
	}
	return dist[dest];
}

void getPathD(int dest) {
	while (prevD[dest] != dest) {
		pathD.push_back(dest);
		dest = prevD[dest];
	}
	pathD.push_back(dest); //source pushed into vector
}

int main() {

	int M;
	scanf_s("%d %d", &N, &M);
	int v1, v2;
	int oneWay;
	int len;
	int time;
	for (int i = 0; i < M; i++) {
		scanf_s("%d %d %d %d %d", &v1, &v2, &oneWay, &len, &time);
		graphL[v1][v2] = len;
		graphT[v1][v2] = time;
		if (oneWay == 0) {
			graphL[v2][v1] = len;
			graphT[v2][v1] = time;
		}
	}

	int source, dest;
	scanf_s("%d %d", &source, &dest);

	int minD = dijkstraDist(source, dest);
	int minT = dijkstraTime(source, dest);

	getPathD(dest);
	//judge same path
	int index = 0;
	bool flag = false;
	while (prevT[dest] != dest) {
		pathT.push_back(dest);
		if (index >= pathD.size() || dest != pathD[index]) {
			flag = true; //not same path
		}
		dest = prevT[dest];
		index++;
	}
	pathT.push_back(dest);

	if (flag) {
		printf("Distance = %d: %d", minD, pathD[pathD.size() - 1]);
		for (int i = pathD.size() - 2; i >= 0; i--) {
			printf(" -> %d", pathD[i]);
		}
		printf("\n");
		printf("Time = %d: %d", minT, pathT[pathT.size() - 1]);
		for (int i = pathT.size() - 2; i >= 0; i--) {
			printf(" -> %d", pathT[i]);
		}
		printf("\n");
	}
	else {
		printf("Distance = %d; Time = %d: %d", minD, minT, pathD[pathD.size() - 1]);
		for (int i = pathD.size() - 2; i >= 0; i--) {
			printf(" -> %d", pathD[i]);
		}
		printf("\n");
	}

	system("pause");
	return 0;
}