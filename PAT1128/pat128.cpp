#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main() {

	int K, N;
	int Q[1001];
	bool flag = true;

	scanf_s("%d", &K);
	while (K--) {
		scanf_s("%d", &N);
		flag = true;
		for (int i = 1; i <= N; i++) {
			scanf_s("%d", Q + i);
			if (!flag) {
				continue;
			}
			for (int k = 1; k < i; k++) {
				if (Q[i] == (Q[k] + i - k) || Q[i] == (Q[k] - i + k) || Q[i] == Q[k]) {
					flag = false;
					break;
				}
			}
		}
		printf("%s\n", flag ? "YES" : "NO");
	}

	system("pause");
	return 0;
}