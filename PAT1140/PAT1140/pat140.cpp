#include <iostream>
#include <cstdio>
#include <algorithm>
#include  <cmath>

using namespace std;

int num[100000] = { 0 };
int len = 0;

void next() {
	int res[100000] = { 0 };
	int rlen = 0;
	int index = 1;
	int cnt = 1;
	while (index <= len) {
		while (index < len && num[index] == num[index - 1]) {
			index++;
			cnt++;
		}
		res[rlen++] = num[index - 1];
		res[rlen++] = cnt;
		index++;
		cnt = 1;
	}

	for (int i = 0; i < rlen; i++) {
		num[i] = res[i];
	}
	len = rlen;
}

int main() {

	int D, N;
	scanf_s("%d %d", &D, &N);

	//initialization
	num[0] = D;
	len = 1;

	for (int i = 1; i < N; i++) {
		next();
	}

	for (int i = 0; i < len; i++) {
		printf("%d", num[i]);
	}
	printf("\n");

	system("pause");
	return 0;
}