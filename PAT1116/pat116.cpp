#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <map>

using namespace std;

int rankist[10001];
bool isPrime[10001]; //false denotes that index is a prime number;

void constructPrimeTable() {
	int prime[10001];
	int index = 0; //the total number of primes
	for (int i = 2; i < 10001; i++) {
		if (!isPrime[i]) {
			prime[index++] = i;
		}
		int tmp;
		for (int j = 0; j < index; j++) {
			tmp = i * prime[j];
			if (tmp > 10001) {
				break;
			}
			isPrime[tmp] = true;
			if (i%prime[j] == 0) {
				break;
			}
		}
	}
}

int main() {

	//initialization
	fill_n(rankist, 10001, 0);
	fill_n(isPrime, 10001, false);
	constructPrimeTable();
	isPrime[1] = true; //1 is not a prime number

	int N, K;
	scanf_s("%d", &N);
	
	int id;
	for (int i = 0; i < N; i++) {
		scanf_s("%d", &id);
		rankist[id] = i + 1;
	}
	
	int rank;
	scanf_s("%d", &K);
	for (int i = 0; i < K; i++) {
		scanf_s("%d", &id);
		rank = rankist[id];
		if (rank > 0) {
			if (rank == 1) {
				printf("%04d: Mystery Award\n", id);
			}
			else if (!isPrime[rank]) {
				printf("%04d: Minion\n", id);
			}
			else {
				printf("%04d: Chocolate\n", id);
			}
			rankist[id] = -1;
		}
		else if (rank == 0) {
			printf("%04d: Are you kidding?\n", id);
		}
		else {
			printf("%04d: Checked\n", id);
		}
	}

	system("pause");
	return 0;
}