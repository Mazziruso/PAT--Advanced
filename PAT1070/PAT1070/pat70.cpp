/*注意点：月饼库存可能是浮点数，不一定是整数
*/
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

typedef struct mooncake {
	double amount;
	double price;
	double profit;
} cake;

bool cmp(cake c1, cake c2) {
	return c1.profit >= c2.profit;
}

int main() {

	int N;
	double D;
	scanf_s("%d %lf", &N, &D);

	cake *c = new cake[N];
	double amount;
	double price;
	for (int i = 0; i < N; i++) {
		scanf_s("%lf", &amount);
		c[i].amount = amount;
	}
	for (int i = 0; i < N; i++) {
		scanf_s("%lf", &price);
		c[i].price = price;
		c[i].profit = c[i].price / c[i].amount;
	}

	sort(c, c + N, cmp);

	double totalProfit = 0;
	for (int i = 0; i < N; i++) {
		if (D - c[i].amount > 0.00001) {
			totalProfit += c[i].price;
			D -= c[i].amount;
		}
		else {
			totalProfit += c[i].profit*D;
			D = 0;
			break;
		}
	}

	printf("%.02f\n", totalProfit);

	system("pause");
	return 0;
}