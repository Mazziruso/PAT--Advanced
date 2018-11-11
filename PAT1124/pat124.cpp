#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <set>

using namespace std;


int main() {

	int N, M, S;
	string name;
	set<string> winners;

	scanf_s("%d %d %d", &N, &M, &S);

	for (int i = 1; i <= N; i++) {
		cin >> name;
		if (i >= S && (i-S)%M == 0) {
			if (winners.count(name) == 0) {
				printf("%s\n", name.c_str());
				winners.insert(name);
			}
			else {
				S++;
			}
		}
	}
	
	if (winners.empty()) {
		printf("Keep going...\n");
	}

	system("pause");
	return 0;
}