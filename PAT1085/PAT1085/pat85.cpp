#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

long long int *sequence;

int findSeqProd(long long int num, int start, int end) {
	int mid;
	while (start <= end) {
		mid = (start + end) / 2;
		if (sequence[mid] == num) {
			end = mid;
			break;
		}
		else if (sequence[mid] > num) {
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}
	return end;
}

int main() {

	int N;
	long long int p;

	scanf_s("%d %lld", &N, &p);
	sequence = new long long int[N];
	for (int i = 0; i < N; i++) {
		scanf_s("%lld", sequence + i);
	}

	sort(sequence, sequence + N, less<long long int>());

	//遍历所有m建立maximum number表，再确定最大值
	int maxLen = -1;
	long long int product;
	int index;
	for (int i = 0; i < N; i++) {
		product = sequence[i] * p;
		index = findSeqProd(product, i, N - 1);
		if (index - i + 1 > maxLen) {
			maxLen = index - i + 1;
		}
		if (index == N - 1) {
			break;
		}
	}

	printf("%d\n", maxLen);

	system("pause");
	return 0;
}