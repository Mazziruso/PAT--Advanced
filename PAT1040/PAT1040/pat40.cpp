#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

string s;

bool isSym(int start, int end) {
	while (start < end) {
		if (s.at(start) != s.at(end)) {
			return false;
		}
		start++;
		end--;
	}
	return true;
}

int main() {

	getline(cin, s);

	int N = s.size();
	int *dp = new int[N];
	fill(dp, dp + N, 0);

	int j;
	for (int i = 1; i < N; i++) {
			if (dp[i - 1] > 0 && s.at(i) == s.at(dp[i - 1] - 1)) {
				dp[i] = dp[i - 1] - 1;
			}
			else {
				j = dp[i - 1];
				while (j < i && !isSym(j, i)) {
					j++;
					while (s.at(j) != s.at(i)) {
						j++;
					}
				}
				dp[i] = j;
			}
	}

	int max = -1;
	for (int i = 0; i < N; i++) {
		if (max < (i - dp[i] + 1)) {
			max = i - dp[i] + 1;
		}
	}

	printf("%d\n", max);

	system("pause");
	return 0;
}