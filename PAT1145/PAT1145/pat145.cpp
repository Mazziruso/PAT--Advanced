#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

bool primes[10010];
int hashTable[10010];

//°£Ê½É¸Ñ¡
void getPrimes() {
	//initialization
	fill_n(primes, 10010, true);
	for (int i = 2; i < 20001; i++) {
		if (primes[i]) {
			for (int j = i + i; j < 20001; j += i) {
				primes[j] = false;
			}
		}
	}
}

bool hashInsert(int key, int Msize) {
	int index;
	for (int i = 0; i < Msize; i++) {
		index = (key + i * i) % Msize;
		if (hashTable[index] == 0) {
			hashTable[index] = key;
			return true;
		}
	}
	return false;
}

int hashSearch(int key, int Msize) {
	int index;
	int cnt = 1;
	for (int i = 0; i < Msize; i++) {
		index = (key + i * i) % Msize;
		if (hashTable[index] == key || hashTable[index] == 0) {
			return cnt;
		}
		else {
			cnt++;
		}
	}
	return cnt;
}

int main() {
	//initialization
	fill_n(hashTable, 10010, 0);
	getPrimes();

	int Msize, N, M;
	int num;

	scanf_s("%d %d %d", &Msize, &N, &M);

	if (!primes[Msize]) {
		while (!primes[Msize]) {
			Msize++;
		}
	}

	int cnt = 1;
	while (N--) {
		scanf_s("%d", &num);
		if (cnt <= Msize && hashInsert(num, Msize)) {
			cnt++;
		}
		else {
			printf("%d cannot be inserted.\n", num);
		}
	}

	int sum = 0;
	for (int i = 0; i < M; i++) {
		scanf_s("%d", &num);
		sum += hashSearch(num, Msize);
	}
	
	printf("%.1f\n", (1.0 * sum) / M);

	system("pause");
	return 0;
}