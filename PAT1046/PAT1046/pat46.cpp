#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {

	int N, M;
	scanf_s("%d", &N);

	int *distD = new int[N];

	for (int i = 0; i < N; i++) {
		scanf_s("%d", distD + i);
	}

	int *distanceF1 = new int[N];
	fill(distanceF1, distanceF1 + N, 0);

	int index;
	int total;
	for (int i = 0; i < N; i++) {
		index = (i + 1) % N;
		distanceF1[index] = distanceF1[i] + distD[i];
	}
	total = distanceF1[0];
	distanceF1[0] = 0;

	scanf_s("%d", &M);
	int start;
	int end;
	int dist;
	for (int i = 0; i < M; i++) {
		scanf_s("%d %d", &start, &end);
		dist = (start <= end) ? distanceF1[end-1] - distanceF1[start-1] : distanceF1[start-1] - distanceF1[end-1];
		if (dist <= (total - dist)) {
			printf("%d\n", dist);
		}
		else {
			printf("%d\n", (total - dist));
		}
	}

	system("pause");
	return 0;
}