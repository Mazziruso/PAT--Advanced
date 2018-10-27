#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <map>

using namespace std;

map<int, int> colorCount;
map<int, int>::iterator iter;

int main() {

	int M, N;
	scanf_s("%d %d", &M, &N);

	int color;
	int count;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			scanf_s("%d", &color);
			iter = colorCount.find(color);
			if (iter == colorCount.end()) {
				colorCount.insert(pair<int, int>(color, 1));
			}
			else {
				count = iter->second;
				colorCount.erase(iter);
				colorCount.insert(pair<int, int>(color, (count + 1)));
			}
		}
	}

	int threshold = M * N;
	for (iter = colorCount.begin(); iter != colorCount.end(); ++iter) {
		if (2 * (iter->second) >= threshold) {
			printf("%d\n", iter->first);
			break;
		}
	}

	system("pause");
	return 0;
}