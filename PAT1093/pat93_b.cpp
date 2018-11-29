/*
背包问题，三个状态
P_dp[i] = P_dp[i-1]+1 (=='P')
A_dp[i] = A_dp[i-1]+P_dp[i] (=='A')
T_dp[i] = T_dp[i-1] + A_dp[i] (=='T')
可将空间复杂度缩为O(1)
*/
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <string>
#define maxn 1000000007

using namespace std;

int dp[3];

int main() {

	char str[100010];
	scanf_s("%s", str, 100010);

	//initialization
	fill_n(dp, 3, 0);
	//dp
	for (int i = 0; str[i]; i++) {
		if (str[i] == 'P') {
			dp[0]++;
			dp[0] %= maxn;
		}
		else if (str[i] == 'A') {
			dp[1] += dp[0];
			dp[1] %= maxn;
		}
		else {
			dp[2] += dp[1];
			dp[2] %= maxn;
		}
	}

	printf("%d\n", dp[2]);

	system("pause");
	return 0;
}
