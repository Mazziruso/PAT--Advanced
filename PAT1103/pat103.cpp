//DP+DFS(Backtracking)
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
int dp[401][21] = { 0 };

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

		//if current path comes end, then back
		if (s.nk[index] <= 0) {
			index--;
			back = true;
			continue;
		}
		else if (index>=1 && s.nk[index] > s.nk[index - 1]) {
			s.nk[index] = s.nk[index - 1];
		}

		remTmp = dp[rem[index]][s.nk[index]];
		index++;

		if (remTmp == 0 && index == K) {
			resList.push_back(s);
			index = 0;
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
		system("pause");
		return 0;
	}

	//find unique solution
	sort(resList.begin(), resList.end());
	
	s = resList[0];
	printf("%d =", N);
	for (int i = 0; i < s.K-1; i++) {
		printf(" %d^%d +", s.nk[i], P);
	}
	printf(" %d^%d\n", s.nk[s.K - 1], P);


	system("color 3F");
	system("pause");
	return 0;
}