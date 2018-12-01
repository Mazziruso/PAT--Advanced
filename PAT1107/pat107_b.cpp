#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

int father[1001];
//维持一个值来表示一个并查集集合大小，该值放置在集合头
int sizeOfC[1001];
int hobby[1001];
vector<int> res;

int findFather(int node) {
	if (node == father[node]) {
		return node;
	}
	father[node] = findFather(father[node]);
	return father[node];
}

void unionSet(int n1, int n2) {
	int f1 = findFather(n1);
	int f2 = findFather(n2);
	if (f1 != f2) {
		father[f2] = f1;
		sizeOfC[f1] += sizeOfC[f2]; //维护并查集大小
	}
}

int main() {
	//init
	fill_n(hobby, 1001, 0);
	fill_n(sizeOfC, 1001, 1);
	for (int i = 1; i < 1001; i++) {
		father[i] = i;
	}

	int N;
	int K, h;

	scanf_s("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf_s("%d: ", &K);
		while (K--) {
			scanf_s("%d", &h);
			if (hobby[h] == 0) {
				hobby[h] = i;
			}
			else {
				unionSet(i, hobby[h]);
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		if (father[i] == i) {
			res.push_back(sizeOfC[i]);
		}
	}

	sort(res.begin(), res.end(), greater<int>());
	int len = res.size();
	printf("%d\n%d", len, res[0]);
	for (int i = 1; i < len; i++) {
		printf(" %d", res[i]);
	}
	printf("\n");

	system("pause");
	return 0;
}
