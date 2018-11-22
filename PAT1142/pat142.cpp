#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int graph[201][201];
int vertice[201];
bool visit[201];

bool isMaximal(int len) {
	bool flag = false;
	int v, u;
	for (int i = 0; i < len; i++) {
		v = vertice[i];
		for (int j = 0; j < N; j++) {
			if (!visit[j] && graph[v][j] == 1) {
				flag = false;
				for (int k = 0; k < len; k++) {
					u = vertice[k];
					if (k != i && graph[j][u] != 1) {
						flag = true;
						break;
					}
				}
				if (!flag) {
					return false;
				}
				visit[j] = true;
			}
		}
	}
	return true;
}

int main() {

	//initialization
	fill_n(visit, 201, false);
	for (int i = 0; i < 201; i++) {
		fill_n(graph[i], 201, 0);
	}

	int Ne, M, K;
	scanf_s("%d %d", &N, &Ne);

	int v1, v2;
	for (int i = 0; i < Ne; i++) {
		scanf_s("%d %d", &v1, &v2);
		graph[v1][v2] = 1;
		graph[v2][v1] = 1;
	}

	scanf_s("%d", &M);

	bool flag = true;
	int len = 0;
	while (M--) {
		scanf_s("%d", &K);
		len = 0;
		flag = true;
		while (K--) {
			scanf_s("%d", &v1);
			if (!flag) { //not clique
				continue;
			}
			vertice[len++] = v1;
			visit[v1] = true;
			for (int i = 0; i < len - 1; i++) {
				if (graph[vertice[len - 1]][vertice[i]] != 1) {
					flag = false;
					break;
				}
			}
		}
		if (!flag) {
			printf("Not a Clique\n");
		}
		else {
			printf("%s\n", isMaximal(len) ? "Yes" : "Not Maximal");
		}
		fill_n(visit, N + 1, false);
	}

	system("pause");
	return 0;
}