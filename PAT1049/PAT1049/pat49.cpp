#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {

	long long int ones[10][10];
	fill(ones[0], ones[0] + 100, 0);
	
	fill(ones[0], ones[0] + 10, 0);
	ones[0][1] += 1;
	long long int total = ones[0][0];
	for (int i = 1; i < 10; i++) {
		total += ones[0][i];
		ones[0][i] = total;
	}

	long long int pow10 = 10;
	for (int i = 1; i < 10; i++) {
		fill(ones[i], (ones[i] + 10), total);
		ones[i][1] += pow10;
		total = ones[i][0];
		for (int j = 1; j < 10; j++) {
			total += ones[i][j];
			ones[i][j] = total;
		}
		pow10 *= 10;
	}

	long long int N;
	scanf_s("%lld", &N);

	pow10 = 10;
	long long int rem = N % pow10;
	long long int dec = rem;
	rem = 0;
	int bits = 0;

	long long int counts = 0;

	//bits==0
	counts += ones[bits][dec];
	rem = N % (pow10 * 10);
	dec = rem / pow10;
	rem = rem % pow10;
	pow10 *= 10;
	bits++;

	while (rem != N) {
		if (dec == 0) {
			counts += 0;
		}
		else if (dec == 1) {
			counts += (ones[bits][dec - 1] + rem + 1);
		}
		else {
			counts += ones[bits][dec - 1];
		}
		rem = N % (pow10 * 10);
		dec = rem / pow10;
		rem = rem % pow10;
		pow10 *= 10;
		bits++;
	}

	printf("%lld\n", counts);

	system("pause");
	return 0;
}