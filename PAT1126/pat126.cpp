/*无向图的连通性不能由结点的度来判断，除了用DFS和BFS，还可以用并查集降低时间复杂度*/
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int degree[501] = { 0 }; //hash table stores the degrees of all vertices

int father[501] = { 0 };

int findFather(int root) {
	if (root == father[root]) {
		return root;
	}
	father[root] = findFather(father[root]);
	return father[root];
}

void unionSet(int v1, int v2) {
	int root1 = findFather(v1);
	int root2 = findFather(v2);
	if (root1 != root2) {
		father[root1] = root2;
	}
}

int main() {
	//initialization
	fill_n(degree, 501, 0);
	for (int i = 0; i < 501; i++) {
		father[i] = i;
	}

	int N, M;
	scanf_s("%d %d", &N, &M);

	int v1, v2;
	for (int i = 0; i < M; i++) {
		scanf_s("%d %d", &v1, &v2);
		degree[v1]++;
		degree[v2]++;
		unionSet(v1, v2);
	}

	//进行路径压缩，统一好所以集合的标识
	for (int i = 1; i <= N; i++) {
		findFather(i);
	}
	//判断图是否连通，即是否只有一个集合
	bool flag = true;
	for (int i = 2; i <= N; i++) {
		if (father[i] != father[i - 1]) {
			flag = false; //不连通
		}
	}

	/*status代表当前图的四种状态：Eulerian, 只有一个奇数度的情况, Semi-Eulerian, Non-Eulerian
	分别用0, 1, 2, 3来表示*/
	int status = 0;

	printf("%d", degree[1]);
	if (!flag) {
		status = 3;
	}
	else if (degree[1] % 2 == 1) {
		status = 1;
	}
	for (int i = 2; i <= N; i++) {
		printf(" %d", degree[i]);
		//有限状态机
		if (degree[i] % 2 == 1) {
			status++;
			status = (status > 3) ? 3 : status;
		}
	}
	printf("\n%s\n", (status == 0) ? "Eulerian" : (status == 2) ? "Semi-Eulerian" : "Non-Eulerian");

	system("pause");
	return 0;
}