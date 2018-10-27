#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#define INT_MAX 2147483647

using namespace std;

int main() {

	int *hashTable;
	int N, M, L;
	int *stripe;
	int *dp;
	
	scanf_s("%d", &N);
	hashTable = new int[N + 10];
	fill(hashTable, hashTable + N + 10, INT_MAX);

	scanf_s("%d", &M);
	int color;
	for (int i = 0; i < M; i++) {
		scanf_s("%d", &color);
		hashTable[color] = i;
	}

	scanf_s("%d", &L);
	stripe = new int[L];
	dp = new int[L];

	int maxDp;
	for (int i = 0; i < L; i++) {
		scanf_s("%d", &color);
		stripe[i] = hashTable[color];

		//dp
		maxDp = 0;
		if (i == 0) {
			if (stripe[i] < INT_MAX) {
				dp[i] = 1;
			}
			else {
				dp[i] = 0;
			}
		}
		else {
			for (int j = i - 1; j >= 0; j--) {
				if (stripe[j] <= stripe[i] && maxDp < dp[j]) {
					maxDp = dp[j];
				}
			}
			dp[i] = maxDp + 1;
		}
	}

	maxDp = 0;
	for (int i = 0; i < L; i++) {
		if (stripe[i] < INT_MAX && maxDp < dp[i]) {
			maxDp = dp[i];
		}
	}
	printf("%d\n", maxDp);

	system("pause");
	return 0;
}