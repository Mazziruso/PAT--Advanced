#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstdlib>

using namespace std;

int main() {

	int N;
	int *set;
	scanf_s("%d", &N);
	set = new int[N];

	for (int i = 0; i < N; i++) {
		scanf_s("%d", set + i);
	}
	
	sort(set, set + N, greater<int>());

	int diff = N % 2;

	int sum = 0;
	for (int i = 0; i < N; i++) {
		if (i < (N + 1) / 2) {
			sum += set[i];
		}
		else {
			sum -= set[i];
		}
	}

	printf("%d %d\n", diff, sum);

	system("pause");
	return 0;
}