#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

long long int *prime;
bool *vis;
struct primes {
	long long int p;
	int cnt;
	primes() {
		p = 0;
		cnt = 0;
	}
} fac[40];

long long int findPrime(long long int num) {
	long long int index = 0;

	for (long long int i = 2; i*i < num; i++) {
		if (!vis[i]) {
			prime[index++] = i;
		}
		long long int tmp;
		for (long long int j = 0; j < index; j++) {
			tmp = i * prime[j];
			if (tmp*tmp > num) {
				break;
			}
			vis[tmp] = true;
			if (i%prime[j] == 0) {
				break;
			}
		}
	}
	return index;
}

int main() {

	long long int num;
	scanf_s("%lld", &num);
	printf("%lld=", num);

	if (num == 1 || num == 0) {
		printf("%lld\n", num);
		return 0;
	}

	unsigned int len = (unsigned int)sqrt(num*1.0);
	prime = new long long int[len + 1];
	vis = new bool[len + 1];
	fill(vis, vis + len + 1, false);

	long long int n = findPrime(num);

	//construct prime factors
	long long int i = 0;
	int cnt = 0;
	while (i < n && cnt < 40) {
		if (num%prime[i] == 0) {
			fac[cnt].p = prime[i];
			fac[cnt].cnt = 0;
			while (num%prime[i] == 0) {
				fac[cnt].cnt++;
				num /= prime[i];
			}
			cnt++;
		}
		i++;
	}
	if (num != 1) {
		fac[cnt].p = num;
		fac[cnt].cnt = 1;
	}

	i = 0;
	while (i<40 && fac[i].cnt == 0) {
		i++;
	}
	if (i < 40) {
		if (fac[i].cnt == 1) {
			printf("%lld", fac[i].p);
		}
		else if (fac[i].cnt > 1) {
			printf("%lld^%d", fac[i].p, fac[i].cnt);
		}
		i++;
	}
	while (i < 40) {
		if (fac[i].cnt == 1) {
			printf("*%lld", fac[i].p);
		}
		else if (fac[i].cnt > 1) {
			printf("*%lld^%d", fac[i].p, fac[i].cnt);
		}
		i++;
	}
	printf("\n");

	system("pause");
	return 0;
}