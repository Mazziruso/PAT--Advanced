#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <map>

using namespace std;

int main() {

	int N;
	map<int, int> uniNum;
	scanf_s("%d", &N);

	int num;
	map<int, int>::iterator iter;
	for (int i = 0; i < N; i++) {
		scanf_s("%d", &num);
		iter = uniNum.find(num);
		if (iter == uniNum.end()) {
			uniNum.insert(pair<int, int>(num, i));
		}
		else {
			iter->second = N + 1;
		}
	}

	int minIndex = INT_MAX;
	for (iter = uniNum.begin(); iter != uniNum.end(); ++iter) {
		if (iter->second < minIndex) {
			minIndex = iter->second;
			num = iter->first;
		}
	}

	if (minIndex > N) {
		printf("None\n");
	}
	else {
		printf("%d\n", num);
	}

	system("pause");
	return 0;
}