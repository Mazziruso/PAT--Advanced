#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#define INT_MAX 2147483647

using namespace std;

int *sumM;

int binarySearch(int start, int end, int val) {
	if (start <= end) {
		int mid = (start + end) / 2;
		if (sumM[mid] == val) {
			return mid;
		}
		else if (sumM[mid] < val) {
			return binarySearch(mid + 1, end, val);
		}
		else {
			return binarySearch(start, mid - 1, val);
		}
	}
	return start;
}

int main() {

	int N, M;
	scanf_s("%d %d", &N, &M);
	
	int *diam = new int[N];
	sumM = new int[N];
	for (int i = 0; i < N; i++) {
		scanf_s("%d", diam + i);

		if (i == 0) {
			sumM[i] = diam[i];
		}
		else {
			sumM[i] = sumM[i - 1] + diam[i];
		}
	}

	int *Dj = new int[N];
	int *lost = new int[N];

	int minL = INT_MAX;
	int tmp = M;
	for (int i = 0; i < N; i++) {
		Dj[i] = binarySearch(i, N - 1, tmp);
		if (Dj[i] >= N) {
			lost[i] = INT_MAX;
		}
		else {
			lost[i] = sumM[Dj[i]] - tmp;
		}
		tmp = M + sumM[i];

		if (lost[i] < minL) {
			minL = lost[i];
		}
	}

	for (int i = 0; i < N; i++) {
		if (minL == lost[i]) {
			printf("%d-%d\n", i + 1, Dj[i] + 1);
		}
	}

	system("pause");
	return 0;
}