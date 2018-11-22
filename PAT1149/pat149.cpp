#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

/*
int N;
int M;
int graph[1001][1001];
int ID[100000];

int main() {
	fill_n(ID, 100000, 0);
	for (int i = 0; i < 1001; i++) {
		fill_n(graph, 1001, 0);
	}

	scanf_s("%d %d", &N, &M);
	
	int id = 1;
	int v1, v2;
	while (N--) {
		scanf_s("%d %d", &v1, &v2);
		ID[v1] = (ID[v1] == 0) ? (id++) : ID[v1];
		ID[v2] = (ID[v2] == 0) ? (id++) : ID[v2];
		graph[ID[v1]][ID[v2]] = 1;
		graph[ID[v2]][ID[v1]] = 1;
	}

	int K;
	bool flag = true;
	int goods[1001];
	int len = 0;
	while (M--) {
		scanf_s("%d", &K);
		len = 0;
		flag = true;

		scanf_s("%d", &v1);
		goods[len++] = v1;
		K--;
		while (K--) {
			scanf_s("%d", &v1);
			if (!flag) {
				continue;
			}
			goods[len++] = v1;
			for (int i = 0; i < len - 1; i++) {
				if (graph[ID[goods[i]]][ID[v1]] == 1) {
					flag = false;
					break;
				}
			}
		}
		printf("%s\n", flag ? "Yes" : "No");
	}

	system("pause");
	return 0;
}
*/

vector<int> graph[100001];

bool checkIn(int v1, int v2) {
	int len1 = graph[v1].size();
	int len2 = graph[v2].size();
	int i = 0; 
	bool flag = false;
	while (i < len1 && i < len2) {
		if (v1 != graph[v2][i] && v2 != graph[v1][i]) {
			i++;
		}
		else {
			flag = true;
			break;
		}
	}
	return flag;
}

int main() {

	int N, M;
	scanf_s("%d %d", &N, &M);

	int id = 1;
	int v1, v2;
	while (N--) {
		scanf_s("%d %d", &v1, &v2);
		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
	}

	int K;
	bool flag = true;
	int goods[1001];
	int len = 0;
	while (M--) {
		scanf_s("%d", &K);
		len = 0;
		flag = true;

		scanf_s("%d", &v1);
		goods[len++] = v1;
		K--;
		while (K--) {
			scanf_s("%d", &v1);
			if (!flag) {
				continue;
			}
			goods[len++] = v1;
			for (int i = 0; i < len - 1; i++) {
				if (checkIn(goods[i], v1)) {
					flag = false;
					break;
				}
			}
		}
		printf("%s\n", flag ? "Yes" : "No");
	}

	system("pause");
	return 0;
}