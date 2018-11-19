#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <string>

#define INT_MAX 2147483647

using namespace std;

int Cmax;
int N;
int Sp;
int M;

int **graph;
int *numB;
int *visit;
int *pre;
int *dist;
int *sent;
int *collection;

void dijkstra(int s) {
	//init
	for (int i = 0; i < N; i++) {
		visit[i] = 0;
		pre[i] = -1;
		dist[i] = INT_MAX;
		sent[i] = 0;
		collection[i] = 0;
	}
	dist[s] = 0;

	int k;
	int tempCS;
	int tempC;
	int tempS;
	int temp;
	for (int i = 0; i < N; i++) {
		k = -1;
		for (int j = 0; j < N; j++) {
			if (visit[j] == 0 && (k < 0 || dist[j] < dist[k])) {
				k = j;
			}
		}

		visit[k] = 1;
		for (int j = 0; j < N; j++) {
			if (visit[j] == 0 && graph[k][j] > 0) {
				temp = graph[k][j] + dist[k];
				if (dist[j] > temp) {
					dist[j] = temp;
					tempCS = Cmax / 2 - numB[j] - collection[k];
					collection[j] = (tempCS >= 0) ? 0 : -tempCS;
					sent[j] = (tempCS >= 0) ? (sent[k] + tempCS) : sent[k];
					pre[j] = k;
				}
				else if (dist[j] == temp) {
					tempCS = Cmax / 2 - numB[j] - collection[k];
					tempC = (tempCS >= 0) ? 0 : -tempCS;
					tempS = (tempCS >= 0) ? (sent[k] + tempCS) : sent[k];
					if(tempS<sent[j]) {
						sent[j] = tempS;
						collection[j] = tempC;
						pre[j] = k;
					}
					else if (tempS == sent[j] && tempC < collection[j]) {
						collection[j] = tempC;
						pre[j] = k;
					}
				}
			}
		}
	}
}

void printPath(int src, int dest) {
	if (dest != src) {
		printPath(src,pre[dest]);
		printf("->%d", dest);
	}
	else {
		printf("%d", dest);
	}
}

int main() {

	int Ntmp;
	scanf_s("%d %d %d %d", &Cmax, &Ntmp, &Sp, &M);

	N = Ntmp + 1;

	numB = new int[N];
	graph = new int*[N];
	for (int i = 0; i < N; i++) {
		graph[i] = new int[N];
	}
	//Input numBike
	numB[0] = 0;
	for (int i = 1; i < (N); i++) {
		scanf_s("%d", numB+i);
	}
	//Input graph
	int indexI;
	int indexJ;
	int temp;
	for (int i = 0; i < M; i++) {
		scanf_s("%d %d %d", &indexI, &indexJ, &temp);
		graph[indexI][indexJ] = temp;
		graph[indexJ][indexI] = temp;
	}

	//init
	visit = new int[N];
	pre = new int[N];
	dist = new int[N];
	sent = new int[N];
	collection = new int[N];

	dijkstra(0);

	printf("%d ", sent[Sp]);
	printPath(0, Sp);
	printf(" %d\n", collection[Sp]);

	system("pause");
	return 0;
}
