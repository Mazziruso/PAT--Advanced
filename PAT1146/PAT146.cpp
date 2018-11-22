#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

bool graph[1001][1001];

int main() {

	//initialization
	for (int i = 0; i < 1001; i++) {
		fill_n(graph[i], 1001, false);
	}

	int N, M;
	scanf_s("%d %d", &N, &M);
	
	int u, v;
	while (M--) {
		scanf_s("%d %d", &u, &v);
		graph[u][v] = true;
	}

	int K;
	scanf_s("%d", &K);
	
	vector<int> res;
	bool flag = true;
	int seq[1001];
	for (int i = 0; i < K; i++) {
		flag = true;
		for (int j = 0; j < N; j++) {
			scanf_s("%d", seq + j);
			if (!flag) {
				continue;
			}
			for (int k = 0; k < j; k++) {
				if (graph[seq[j]][seq[k]]) {
					flag = false;
					res.push_back(i);
					break;
				}
			}
		}
	}

	printf("%d", res[0]);
	for (int i = 1; i < res.size(); i++) {
		printf(" %d", res[i]);
	}
	printf("\n");

	system("pause");
	return 0;
}