#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

pair<long int, long int> rationalSum(pair<long int, long int> a, pair<long int, long int> b) {
	return pair<long int, long int>(a.first*b.second + a.second*b.first, a.second*b.second);
}

long int gcd(long int a, long int b) {
	return (b == 0) ? a : gcd(b, a%b);
}

int main() {

	int N;
	long int numerator;
	long int denominator;

	//initialization
	pair<long int, long int> sum;
	sum.first = 0;
	sum.second = 1;
	long int gcdVal;

	scanf_s("%d", &N);
	//这里可能会溢出，所以要先约分才能保证不溢出
	while (N--) {
		scanf_s("%ld/%ld", &numerator, &denominator);
		sum = rationalSum(sum, pair<long int, long int>(numerator, denominator));
		gcdVal = gcd(max(sum.first, sum.second), min(sum.first, sum.second));
		sum.first /= gcdVal;
		sum.second /= gcdVal;
	}


	long int integerPart = sum.first / sum.second;
	sum.first %= sum.second;

	if (integerPart != 0) {
		printf("%ld", integerPart);
	}

	if (integerPart != 0 && sum.first != 0) {
		printf(" ");
		sum.first = labs(sum.first);
		sum.second = labs(sum.second);
	}
	else if (integerPart == 0 && sum.first == 0) { //special case
		printf("0");
	}

	//当整数为0时，判断分式的符号
	if (sum.first*sum.second < 0) {
		printf("-");
		sum.first = labs(sum.first);
		sum.second = labs(sum.second);
	}
	if (sum.first != 0) {
		printf("%ld/%ld", sum.first, sum.second);
	}
	printf("\n");

	system("pause");
	return 0;
}