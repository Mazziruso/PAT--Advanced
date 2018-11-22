#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#define INT_MAX 2147483647

using namespace std;

int N;
int graph[201][201];
bool visit[201];

int main() {
	//initialization
	for (int i = 0; i < 201; i++) {
		fill_n(graph[i], 201, 0);
	}
	fill_n(visit, 201, false);

	int M, K;
	int v1, v2, dist;
	
	scanf_s("%d %d", &N, &M);
	while (M--) {
		scanf_s("%d %d %d", &v1, &v2, &dist);
		graph[v1][v2] = dist;
		graph[v2][v1] = dist;
	}

	scanf_s("%d", &K);

	int visitN;
	int totalDist;
	int shortest = INT_MAX;
	int path;
	int n, start;
	int status = 0;
	for (int k = 1; k <= K; k++) {
		scanf_s("%d", &n);
		status = 0;
		totalDist = 0;

		scanf_s("%d", &v1);
		start = v1;
		v2 = v1; //previous city of v1
		n--;
		while (n--) {
			scanf_s("%d", &v1);
			if (status == 3) {
				continue;
			}
			if (graph[v1][v2] == 0) {
				status = 3;
				continue;
			}
			else if (visit[v1]) {
				status = 2;
			}
			visit[v1] = true;
			totalDist += graph[v1][v2];
			v2 = v1;
		}

		visitN = 0;
		for (int i = 1; i <= N; i++) {
			visitN += (visit[i]) ? 1 : 0;
			visit[i] = false;
		}
		//judge whether the path is a cycle containing all nodes
		if ((status==0 || status==2) && visitN < N || v1!=start) {
			status = 1;
		}
		if ((status ==0 || status==2) && shortest > totalDist) {
			shortest = totalDist;
			path = k;
		}
		//display
		if (status == 0) {
			printf("Path %d: %d (TS simple cycle)\n", k, totalDist);
		}
		else if (status == 1) {
			printf("Path %d: %d (Not a TS cycle)\n", k, totalDist);
		}
		else if (status == 2) {
			printf("Path %d: %d (TS cycle)\n", k, totalDist);
		}
		else {
			printf("Path %d: NA (Not a TS cycle)\n", k);
		}
	}

	printf("Shortest Dist(%d) = %d\n", path, shortest);

	system("pause");
	return 0;
}