#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {

	int N;
	int dist[100001] = { 0 };
	scanf_s("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf_s("%d", dist + i);
	}

	sort(dist, dist + N, greater<int>());

	int index = 0; //days E
	int E = N; //mile >=E
	while (index < N) {
		while (index<N && dist[index]>E) {
			index++;
		}
		if (index >= E) {
			break;
		}
		E--;
	}

	printf("%d\n", E);

	system("pause");
	return 0;
}