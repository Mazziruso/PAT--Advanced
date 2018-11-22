#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int num[100001];

int main() {

	int N;
	scanf_s("%d", &N);

	int len = 0;
	int integer;
	for (int i = 0; i < N; i++) {
		scanf_s("%d", &integer);
		if (integer > 0) {
			num[len++] = integer;
		}
	}

	sort(num, num + len);

	if (num[0] != 1) {
		printf("1\n");
		return 0;
	}

	int index = 1;
	for (; index < len; index++) {
		if (num[index] > num[index - 1] + 1) {
			break;
		}
	}

	printf("%d\n", num[index - 1] + 1);

	system("pause");
	return 0;
}