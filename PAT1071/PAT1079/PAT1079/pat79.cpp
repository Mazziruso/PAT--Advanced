/*
注意点：double，不能用float
*/
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

int N;
double P;
double rate; //1+r%
vector<int> *Tree;
double *amount;

double treeTrave(int root, double ratePow) {
	if (Tree[root].empty()) {
		return P * ratePow * amount[root];
	}

	double total = 0;
	for (auto iter : Tree[root]) {
		total += treeTrave(iter, ratePow*rate);
	}

	return total;
}

int main() {

	double r;
	scanf_s("%d %lf %lf", &N, &P, &r);
	rate = 1 + (r / 100);

	Tree = new vector<int>[N];
	amount = new double[N];
	fill_n(amount, N, 0);

	int K;
	int id;
	for (int i = 0; i < N; i++) {
		scanf_s("%d", &K);
		if (K == 0) {
			scanf_s("%lf", amount + i);
		}
		while (K--) {
			scanf_s("%d", &id);
			Tree[i].push_back(id);
		}
	}

	printf("%.1f\n", treeTrave(0, 1));

	system("pause");
	return 0;
}