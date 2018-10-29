#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

int **dp;
int *lowIndex;
int *coins;

void printCoins(int index, int M) {
	int nextIndex = dp[index][M];
	if (index != nextIndex) {
		printf("%d ", coins[index]);
		printCoins(nextIndex, M-coins[index]);
	}
	else {
		printf("%d\n", coins[index]);
	}
}

int main() {

	//state array dp
	dp = new int*[10001];
	for (int i = 0; i < 10001; i++) {
		dp[i] = new int[101];
		fill(dp[i], dp[i] + 101, -1);
	}

	int N, M;
	scanf_s("%d %d", &N, &M);
	coins = new int[N];
	for (int i = 0; i < N; i++) {
		scanf_s("%d", coins + i);
	}

	sort(coins, coins + N, greater_equal<int>());

	if (coins[N-1] > M) {
		printf("No Solution\n");
		return 0;
	}

	lowIndex = new int[101];
	fill(lowIndex, lowIndex + 101, -1);

	//initialization
	int coin = coins[0];
	dp[0][coin] = 0;
	lowIndex[coin] = 0;
	//dp
	for (int i = 1; i < N; i++) {
		coin = coins[i];
		dp[i][coin] = i;
		for (int j = coin + 1; j <= M; j++) {
			if (lowIndex[j - coin] >= 0) {
				dp[i][j] = lowIndex[j - coin];
			}
		}
		for (int j = coin; j <= M; j++) {
			if (dp[i][j] >= 0) {
				lowIndex[j] = i;
			}
		}
	}

	//construct solution
	if (lowIndex[M] < 0) {
		printf("No Solution\n");
	}
	else {
		printCoins(lowIndex[M], M);
	}

	system("pause");
	return 0;
}