#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <set>

using namespace std;

int main() {

	int N, K;
	scanf_s("%d %d", &N, &K);

	char ch[10];
	string name;
	set<string> *List = new set<string>[K];

	int k;
	int course;
	for (int i = 0; i < N; i++) {
		scanf_s("%s %d", ch, &k);
		name = string(ch);
		while (k--) {
			scanf_s("%d", &course);
			List[course - 1].insert(name);
		}
	}

	vector<string> nameList;
	for (int i = 0; i < K; i++) {
		printf("%d %d\n", i + 1, List[i].size());
		if (!List[i].empty()) {
			for (auto iter : List[i]) {
				printf("%s\n", iter.c_str());
			}
		}
	}

	system("pause");
	return 0;
}