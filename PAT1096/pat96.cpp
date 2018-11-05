//DP, O(N^2)
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int *factors;
int N;

int factorCal() {
	int index = 0;
	int factor = 2;
	int maxF = sqrt(N);
	while (factor <= maxF) {
		if (N%factor == 0) {
			factors[index] = factor;
			index++;
		}
		factor++;
	}
	return index;
}

pair<int, int> findMaxNum(int len) {
	pair<int, int> res;
	int index = 1;
	int maxLen = -1;
	int seqEnd = 0;
	int start;
	int product = 1;
	while (index < len) {
		start = index - 1;
		product = factors[index - 1];
		while (index < len && factors[index] == factors[index - 1] + 1) {
			product *= factors[index];
			if (N%product == 0) {
				index++;
			}
			else {
				break;
			}
		}
		if (maxLen < index - start) {
			maxLen = index - start;
			seqEnd = index - 1;
		}
		index = start + 2;
	}
	res.first = (maxLen==-1) ? 1 : maxLen;
	res.second = seqEnd;
	return res;
}

int main() {
	scanf_s("%d", &N);
	factors = new int[sqrt(N)];

	int len = factorCal();

	//special case, N is a prime
	if (len == 0) {
		printf("%d\n%d\n", 1, N);
		return 0;
	}

	pair<int, int> res = findMaxNum(len);

	printf("%d\n", res.first);
	for (int i = res.second - res.first + 1; i < res.second; i++) {
		printf("%d*", factors[i]);
	}
	printf("%d\n", factors[res.second]);

	system("pause");
	return 0;
}