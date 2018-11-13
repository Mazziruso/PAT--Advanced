#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <algorithm>

using namespace std;

int digits[1001] = { 0 };
int N;

void addBig() {
	int carry = 0;
	int res[1001] = { 0 };
	int sum;
	for (int i = N - 1; i >= 0; i--) {
		sum = digits[i] + digits[N - i - 1] + carry;
		carry = sum / 10;
		res[i] = sum % 10;
	}
	int index = 0;
	if (carry > 0) {
		digits[index++] = carry;
	}
	for (int i = 0; i < N; i++) {
		digits[index++] = res[i];
	}
	N = index;
}

bool check() {
	int s = 0;
	int e = N - s - 1;
	while (s < e) {
		if (digits[s] != digits[e]) {
			return false;
		}
		s++;
		e--;
	}
	return true;
}

void printDigits() {
	for (int i = 0; i < N; i++) {
		printf("%d", digits[i]);
	}
}

int main() {

	char c;
	N = 0;
	scanf_s("%c", &c, 1);
	while (c != '\n') {
		digits[N++] = c - '0';
		scanf_s("%c", &c, 1);
	}

	int cnt = 0;
	while (cnt<10 && !check()) {
		printDigits();
		printf(" + ");
		for (int i = N - 1; i >= 0; i--) {
			printf("%d", digits[i]);
		}
		printf(" = ");
		addBig();
		printDigits();
		printf("\n");
		cnt++;
	}

	if (cnt < 10) {
		printDigits();
		printf(" is a palindromic number.\n");
	}
	else {
		printf("Not found in 10 iterations.\n");
	}

	system("pause");
	return 0;
}