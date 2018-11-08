#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#define INT_MAX 2147483647

using namespace std;

int child[2][1001];
int level[1001] = { 0 };
int lowest;

int main() {
	
	//initialization
	fill_n(child[0], 1001, -1);
	fill_n(child[1], 1001, -1);
	fill_n(level, 1001, 0);
	lowest = -1;

	int N;
	int nodes[1001];
	scanf_s("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf_s("%d", nodes + i);
	}

	int root = 0;
	int node = 0;
	level[0] = 1; //根结点层高
	lowest = level[0];
	for (int i = 1; i < N; i++) {
		root = 0;
		node = (nodes[i] <= nodes[root]) ? child[0][root] : child[1][root];
		while (node != -1) {
			root = node;
			node = (nodes[i] <= nodes[root]) ? child[0][root] : child[1][root];
		}
		if (nodes[i] <= nodes[root]) {
			child[0][root] = i;
		}
		else {
			child[1][root] = i;
		}
		level[i] = level[root] + 1;
		if (lowest < level[i]) {
			lowest = level[i];
		}
	}

	int count1 = 0; //the number of the lowest level
	int count2 = 0; //the number of the above
	for (int i = 0; i < N; i++) {
		count1 += (lowest == level[i]) ? 1 : 0;
		count2 += (lowest - 1 == level[i]) ? 1 : 0;
	}
	printf("%d + %d = %d\n", count1, count2, count1 + count2);

	system("pause");
	return 0;
}