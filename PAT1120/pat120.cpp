#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

int sumDigits(int num) {
	int sum = 0;
	int digit;
	while (num > 0) {
		digit = num % 10;
		num /= 10;
		sum += digit;
	}
	return sum;
}

int main() {

	int res[10001];
	bool sumTable[20001] = { false };
	int N;

	scanf_s("%d", &N);
	int sum;
	int num;
	for (int i = 0; i < N; i++) {
		scanf_s("%d", &num);
		sum = sumDigits(num);
		sumTable[sum] = true;
	}

	int len = 0;
	for (int i = 0; i < 20001; i++) {
		if (sumTable[i]) {
			res[len++] = i;
		}
	}

	printf("%d\n%d", len, res[0]);
	for (int i = 1; i < len; i++) {
		printf(" %d", res[i]);
	}
	printf("\n");

	system("pause");
	return 0;
}