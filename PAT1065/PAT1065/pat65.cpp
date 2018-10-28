/*用long long来表示整型，但是要考虑加法运算后的溢出
也可以用long double来表示数，不用考虑溢出*/
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

int main() {

	long long A;
	long long B;
	long long C;
	long long sum;

	bool flag;
	int T;
	scanf_s("%d", &T);
	for (int i = 1; i <= T; i++) {
		scanf_s("%lld %lld %lld", &A, &B, &C);
		sum = A + B;
		if (A > 0 && B > 0 && sum <= 0) {
			flag = true;
		}
		else if (A < 0 && B < 0 && sum >= 0) {
			flag = false;
		}
		else {
			flag = (A + B) > C;
		}

		printf("Case #%d: %s\n", i, flag ? "true" : "false");
	}

	system("pause");
	return 0;
}