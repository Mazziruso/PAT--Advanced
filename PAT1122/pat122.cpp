#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

int graph[201][201];
bool visit[201];

int main() {
	//initialization
	for (int i = 0; i < 201; i++) {
		fill_n(graph[0], 201, 0);
	}

	int N, M, K;
	int v1, v2;
	while (M--) {
		scanf_s("%d %d", &v1, &v2);
		graph[v1][v2] = 1;
		graph[v2][v1] = 1;
	}

	scanf_s("%d", &K);
	system("pause");
	return 0;
}