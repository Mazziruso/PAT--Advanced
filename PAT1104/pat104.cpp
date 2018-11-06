#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {

	int N;
	double *seq;
	scanf("%d", &N);
	seq = new double[N];
	for (int i = 0; i < N; i++) {
		scanf("%lf", seq + i);
	}

	double sum = 0.0;
	int num;
	for (int i = 0; i < N; i++) {
		num = i + 1;
		sum += seq[i] * num * (N - num + 1);
	}

	printf("%.2f\n", sum);

	return 0;
}