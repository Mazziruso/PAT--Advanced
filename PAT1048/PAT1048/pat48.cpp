#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {

	int N, M;
	scanf_s("%d %d", &N, &M);
	
	int *coins = new int[N];
	for (int i = 0; i < N; i++) {
		scanf_s("%d", coins + i);
	}

	sort(coins, coins + N);

	int indexL = 0;
	int indexU = N - 1;

	while (indexL < indexU) {
		if ((coins[indexL] + coins[indexU]) == M) {
			break;
		}
		else if ((coins[indexL] + coins[indexU]) < M) {
			indexL++;
		}
		else {
			indexU--;
		}
	}

	if (indexL < indexU) {
		printf("%d %d\n", coins[indexL], coins[indexU]);
	}
	else {
		printf("No Solution\n");
	}

	system("pause");
	return 0;
}