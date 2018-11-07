/*
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

struct solution {
	int K;
	int nk[401] = { -1 };
	bool operator<(struct solution &s1) {
		int sum1 = 0;
		int sum2 = 0;
		for (int i = 0; i < K; i++) {
			sum1 += this->nk[i];
			sum2 += s1.nk[i];
		}
		if (sum1 != sum2) {
			return sum1 > sum2;
		}
		int index = 0;
		while (index < K && this->nk[index] == s1.nk[index]) {
			index++;
		}
		return this->nk[index] > s1.nk[index];
	}
};

vector<solution> resList;
int dp[401][21] = { -1 };

int main() {

	int N, K, P;
	scanf_s("%d %d %d", &N, &K, &P);

	struct solution s;
	s.K = K;

	//construct DP
	int M = (int)pow(N, 1.0 / P);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			dp[i][j] = i - (int)pow(j, P);
		}
	}

	//Backtracking method reconstruct solution
	bool back = false; //if current vertex is back from post path then notes true
	int index = 0; //vertex depth
	int rem[401] = { -1 };
	s.nk[0] = M + 1; //initialization
	int remTmp = N; //local remain value
	while (s.nk[0] > 0) {
		rem[index] = back ? rem[index] : remTmp;
		s.nk[index] = back ? (s.nk[index] - 1) : ((int)pow(rem[index], 1.0 / P));

		if (s.nk[0] == 0) {
			break;
		}
		if (s.nk[index] <= 0) {
			index--;
			back = true;
			continue;
		}
		else if (index >= 1 && s.nk[index] > s.nk[index - 1]) {
			s.nk[index] = s.nk[index - 1];
		}

		remTmp = dp[rem[index]][s.nk[index]];
		index++;

		if (remTmp == 0 && index == K) {
			resList.push_back(s);
			index--;
			if (index == 0) {
				break;
			}
			else {
				index--;
			}
			back = true; //back to start
		}
		else if (remTmp == 0 && index < K) {
			index--;
			back = true;
		}
		else if (remTmp > 0 && index >= K) {
			index--;
			back = true;
		}
		else if (remTmp > 0 and index < K) {
			back = false; //forward
		}
	}

	//no solution case
	if (resList.size() == 0) {
		printf("Impossible\n");
		return 0;
	}

	//find unique solution
	sort(resList.begin(), resList.end());

	s = resList[0];
	printf("%d =", N);
	for (int i = 0; i < s.K - 1; i++) {
		printf(" %d^%d +", s.nk[i], P);
	}
	printf(" %d^%d\n", s.nk[s.K - 1], P);

	system("pause");

	return 0;
}
*/
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

struct solution {
	int K;
	int nk[401] = { 0 };
	int sum;
};

int K;
int P;
vector<solution> resList;
int dp[401][21] = { -1 };
struct solution s;
int nk[401] = { 0 };
int remZero[401] = { 0 }; //记录dp中每一列大于0的最小factor，防止反复调用pow(root,1.0/P)以至于超时

//base^exp
int myPow(int base, int exp) {
	if (base == 1) {
		return 1;
	}
	int res = 1;
	while(exp > 0) {
		if (base & 1) {
			res *= base;
		}
		base *= base;
		exp >>= 1;
	}
	return res;
}

//记录当前剩余值，因子，层数以及部分因子和
bool DFS(int root, int fac, int level, int facSum) {
	if (K - 1 == level && root==0) {
		nk[level] = fac;
		facSum += fac;
		if (facSum > s.sum) {
			copy_n(nk, K, s.nk);
			s.sum = facSum;
		}
		return true;
	}
	if (K - 1 == level && root > 0) {
		return false;
	}
	if (K - 1 > level && root == 0) {
		return false;
	}

	nk[level] = fac;
	facSum += fac;
	int rem = remZero[root];
	int minn = min(fac, rem);
	for (int i = minn; i >=1; i--) {
		if (DFS(dp[root][i], i, level + 1, facSum) && K == level) {
			return true;
		}
	}
	return false;
}

int main() {

	int N;
	scanf_s("%d %d %d", &N, &K, &P);

	s.K = K;

	//construct DP
	int M = (int)pow(N, 1.0 / P);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			dp[i][j] = i - (int)myPow(j, P);
			remZero[i] = (dp[i][j] >= 0) ? j : remZero[i];
		}
	}

	for (int i = M; i >=1; i--) {
		DFS(dp[N][i], i, 0, 0);
	}

	if (s.nk[0] == 0) {
		printf("Impossible\n");
		return 0;
	}

	printf("%d = %d^%d", N, s.nk[0], P);
	for (int i = 1; i < K; i++) {
		printf(" + %d^%d", s.nk[i], P);
	}
	printf("\n");

	system("pause");
	return 0;
}
