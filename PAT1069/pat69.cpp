#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

bool lessCmp(int a, int b) {
	return a < b;
}

bool greaterCmp(int a, int b) {
	return a > b;
}

pair<int, int> differential(int N) {
	int *digit = new int[4];
	fill(digit, digit + 4, 0);
	string digits = to_string(N);
	for (int i = 0; i < digits.size(); i++) {
		digit[i] = digits.at(i) - '0';
	}
	sort(digit, digit + 4, lessCmp);
	int upper = digit[3] * 1000 + digit[2] * 100 + digit[1] * 10 + digit[0];
	sort(digit, digit + 4, greaterCmp);
	int lower = digit[3] * 1000 + digit[2] * 100 + digit[1] * 10 + digit[0];

	return pair<int, int>(upper, lower);
}

int main() {

	int N;
	scanf("%d", &N);

	if (N % 1111 == 0) {
		printf("%04d - %04d = 0000\n", N, N);
		return 0;
	}

	int diff = N;
	pair<int, int> p;
	while (diff != 6174) {
		p = differential(diff);
		diff = p.first - p.second;
		printf("%04d - %04d = %04d\n", p.first, p.second, diff);
	}

	return 0;
}
