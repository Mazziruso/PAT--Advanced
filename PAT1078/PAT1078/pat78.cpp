#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int *prime;
int *hashTable;

//Å·À­É¸Ñ¡
int getPrimeTable(int N) {
	bool *visit = new bool[N];
	fill_n(visit, N, false);
	prime = new int[N];

	int tmp;
	int index = 0;
	for (int i = 2; i <= N; i++) {
		if (!visit[i]) {
			prime[index++] = i;
		}
		for (int j = 0; j < index; j++) {
			tmp = i * prime[j];
			if (tmp > N) {
				break;
			}
			visit[tmp] = true;
			if (i%prime[j] == 0) {
				break;
			}
		}
	}
	return index;
}

int hashInsert(int key, int M) {
	int index;
	bool flag = false;
	for (int i = 0; i < M; i++) {
		index = (key + i * i) % M;
		if (hashTable[index] == -1) {
			hashTable[index] = key;
			flag = true;
			break;
		}
	}

	//while flag denotes false, it is known that probing is failure and return -1
	return flag ? index : -1;
}

int main() {
	int Msize, N;
	scanf_s("%d %d", &Msize, &N);

	//special case
	if (N == 0) {
		return 0;
	}

	int len = getPrimeTable(10010);

	//check Msize
	int index = 0;
	while (index<len && prime[index] < Msize) {
		index++;
	}
	Msize = prime[index];

	//initialization
	hashTable = new int[Msize];
	fill_n(hashTable, Msize, -1);

	int key; //insert data

	scanf_s("%d", &key);
	index = hashInsert(key, Msize);
	if (index == -1) {
		printf("-");
	}
	else {
		printf("%d", index);
	}

	for (int i = 1; i < N; i++) {
		scanf_s("%d", &key);
		index = hashInsert(key, Msize);
		if (index == -1) {
			printf(" -");
		}
		else {
			printf(" %d", index);
		}
	}
	printf("\n");


	system("pause");
	return 0;
}