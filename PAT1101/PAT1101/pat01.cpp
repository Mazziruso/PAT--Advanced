#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <set>

using namespace std;

set<long long int> validSet;


//if the number of output is 0, it will require display 0 in first line then prints the sequence next line
int main() {
	
	bool flag;
	long long int numMax;
	long long int numNew;
	set<long long int>::iterator it;

	int N;
	scanf_s("%d", &N);

	if (N == 0) {
		printf("0\n\n");
		return 0;
	}

	scanf_s("%lld", &numNew);
	numMax = numNew;
	flag = true;
	for (int i = 1; i < N; i++) {
		scanf_s("%lld", &numNew);

		if (numNew < numMax) {
			flag = false;
			it = validSet.lower_bound(numNew);
			validSet.erase(it, validSet.end());
		}
		else {
			if (flag) {
				validSet.insert(numMax);
			}
			numMax = numNew;
			flag = true;
		}
	}

	int n;
	int M;
	if (flag) {
		printf("%d\n", (validSet.size() + 1));
		for (it = validSet.begin(); it != validSet.end(); ++it) {
			printf("%lld ", *it);
		}
		printf("%lld\n", numMax);
	}
	else {
		n = 0;
		M = validSet.size();
		if (M == 0) {
			printf("0\n\n");
			system("pause");
			return 0;
		}
		printf("%d\n", M);
		n = 0;
		for (it = validSet.begin(); it != validSet.end(); ++it) {
			printf("%lld", *it);
			if (n<(M-1)) {
				printf(" ");
			}
			else {
				printf("\n");
			}
			n++;
		}
	}

	system("pause");
	return 0;
}