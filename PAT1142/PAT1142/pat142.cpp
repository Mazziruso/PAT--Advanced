#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

int N;
vector<int> graph[201];
int vertice[201];
bool visit[201];

//hashTable
int me = 19913;
int hashTable[20000];

void hashInsert(int key) {
	int gk = (key + 1) % (me - 2);
	int hk = key % me;
	while (hashTable[hk] >= 0 && hashTable[hk] != key) {
		hk = (hk + gk) % me;
	}
	hashTable[hk] = key;
}

bool hashCheck(int key) {
	int gk = (key + 1) % (me - 2);
	int hk = key % me;
	while (hashTable[hk] >= 0 && hashTable[hk] != key) {
		hk = (hk + gk) % me;
	}
	return hashTable[hk] == key;
}

bool isMaximal(int len) {
	bool flag = false;
	int v, u;
	for (int i = 0; i < len; i++) {
		v = vertice[i];
		for (int j = 0; j < graph[v].size(); j++) {
			u = graph[v][j];
			flag = false;
			if (!visit[u]) {
				for (int k = 0; k < len; k++) {
					if (k != i && !hashCheck(200*u+vertice[k])) {
						flag = true;
						break;
					}
				}
				if (!flag) {
					return false;
				}
			}
		}
	}
	return true;
}

int main() {

	//initialization
	fill_n(visit, 201, false);
	fill_n(hashTable, 20000, -1);

	int Ne, M, K;
	scanf_s("%d %d", &N, &Ne);

	int v1, v2;
	for (int i = 0; i < Ne; i++) {
		scanf_s("%d %d", &v1, &v2);
		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
		hashInsert(200 * v1 + v2);
		hashInsert(200 * v2 + v1);
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
			for (int i = 1; i < len - 1; i++) {
				if (!hashCheck(200 * vertice[len - 1] + vertice[i])) {
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