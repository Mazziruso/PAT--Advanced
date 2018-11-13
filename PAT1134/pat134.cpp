/*每一次query的时间复杂度为O(2M)， 且存储与顶点相关的边所用的vector数组占空间为O(2M)*/
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

bool visit[10001] = { false }; //false denotes the corresponding edge is visited
vector<int> edges[100001]; //the set of edge related to the corresponding vertex

int main() {

	int N, M, K, Nv;

	scanf_s("%d %d", &N, &M);
	
	int v1, v2;
	for (int i = 0; i < M; i++) {
		scanf_s("%d %d", &v1, &v2);
		edges[v1].push_back(i);
		edges[v2].push_back(i);
	}

	scanf_s("%d", &K);
	bool flag = true;;
	while (K--) {
		flag = true;
		scanf_s("%d", &Nv);
		while (Nv--) {
			scanf_s("%d", &v1);
			for (int i = 0; i < edges[v1].size(); i++) {
				visit[edges[v1][i]] = true;
			}
		}
		//check the edges
		for (int i = 0; i < M; i++) {
			if (!visit[i]) {
				flag = false;
				break;
			}
		}
		printf("%s\n", flag ? "Yes" : "No");
		fill_n(visit, M, false);
	}

	system("pause");
	return 0;
}