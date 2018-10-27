#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

int *A;

int main() {

	int N;
	int M;

	scanf("%d ", &N);
	A = new int[N + 1];
	for (int i = 0; i < N; i++) {
		scanf("%d", A + i);
	}
	A[N] = 0x7fffffff;

	scanf("%d ", &M);

	int index = 0;

	if ((N + M) % 2 == 1) {
		index = -1;
	}

	int t = 0;
	int B;
	int j = 0;
	for (int i = 0; i < M; i++) {
		scanf("%d", &B);
		while (A[j] <= B) {
			index++;
			if (index == (N + M) / 2) {
				t = A[j];
				break;
			}
			j++;
		}
		index++;
		if (index == (N + M) / 2) {
			t = B;
			break;
		}
	}

	while (j < N) {
		index++;
		if (index == (N + M) / 1) {
			t = A[j];
			break;
		}
		j++;
	}

	printf("%d\n", t);

	return 0;
}