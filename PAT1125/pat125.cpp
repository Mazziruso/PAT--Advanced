#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstdlib>

using namespace std;

int main() {

	int N;
	int *segments;
	scanf_s("%d", &N);

	segments = new int[N];
	for (int i = 0; i < N; i++) {
		scanf_s("%d", segments + i);
	}

	sort(segments, segments + N);

	double res = segments[0];
	for (int i = 1; i < N; i++) {
		res += segments[i];
		res /= 2;
	}

	printf("%d", (int)round(res));

	system("pause");
	return 0;
}