#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;

int main() {

	int N;
	int M;
	int K;
	int value;

	scanf("%d", &N);

	set<int> *sets = new set<int>[N];

	for (int i = 0; i < N; i++) {
		scanf("%d", &M);
		while (M--) {
			scanf("%d", &value);
			sets[i].insert(value);
		}
	}

	scanf("%d", &K);
	int index1, index2;
	int size1, size2;
	int count;
	while (K--) {
		scanf("%d %d", &index1, &index2);
		size1 = sets[index1 - 1].size();
		size2 = sets[index2 - 1].size();
		count = 0;

		if (size1 <= size2) {
			for (auto iter : sets[index1 - 1]) {
				if (sets[index2 - 1].count(iter)) {
					count++;
				}
			}
		}
		else {
			for (auto iter : sets[index2 - 1]) {
				if (sets[index1 - 1].count(iter)) {
					count++;
				}
			}
		}

		printf("%.1f\%%\n", (double)(100.0*count / (size1 + size2 - count)));
	}

	return 0;
}