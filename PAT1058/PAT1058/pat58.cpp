#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {

	long long int a, b, c;
	long long int sum;

	scanf_s("%lld.%lld.%lld", &a, &b, &c);
	sum = 493 * a + 29 * b + c;
	scanf_s("%lld.%lld.%lld", &a, &b, &c);
	sum = sum + 493 * a + 29 * b + c;

	c = sum % 29;
	sum = (sum - c) / 29;
	b = sum % 17;
	sum = (sum - b) / 17;
	a = sum;

	printf("%lld.%lld.%lld\n", a, b, c);

	system("pause");
	return 0;
}