#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int graph[201][201];
bool visit[201] = { false };

bool checkHamCycle() {
	bool flag = true;
	for (int i = 1; i <= N; i++) {
		if (!visit[i]) {
			flag = false;
		}
		visit[i] = false;
	}
	return flag;
}

int main() {
	//initialization
	for (int i = 0; i < 201; i++) {
		fill_n(graph[0], 201, 0);
	}

	int M, K;
	int v1, v2;

	scanf_s("%d %d", &N, &M);

	while (M--) {
		scanf_s("%d %d", &v1, &v2);
		graph[v1][v2] = 1;
		graph[v2][v1] = 1;
	}

	scanf_s("%d", &K);
	
	int n;
	bool flag = true; //false代表重复经过一个点
	while (K--) {
		scanf_s("%d", &n);
		flag = true;
		scanf_s("%d", &v1);
		n--;
		while (n--) {
			scanf_s("%d", &v2);
			flag = visit[v2] ? false : flag;
			visit[v2] = (graph[v1][v2] == 1) ? true : visit[v2];
			v1 = v2;
		}
		//为什么这两个不能交换
		printf("%s\n", (checkHamCycle() && flag) ? "Yes" : "No");
	}
	system("pause");
	return 0;
}