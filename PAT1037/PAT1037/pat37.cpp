#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

bool decOrder(int n1, int n2) {
	return n1 > n2;
}

int main() {

	int Np, Nc;
	int *coupon;
	int *product;
	
	scanf_s("%d", &Nc);
	coupon = new int[Nc];
	for (int i = 0; i < Nc; i++) {
		scanf_s("%d", coupon + i);
	}
	scanf_s("%d", &Np);
	product = new int[Np];
	for (int i = 0; i < Np; i++) {
		scanf_s("%d", product + i);
	}

	sort(coupon, coupon + Nc, decOrder);
	sort(product, product + Np, decOrder);

	long long amount = 0;

	int indexC = 0;
	int indexP = 0;
	while (indexC < Nc && indexP < Np && coupon[indexC] > 0 && product[indexP] > 0) {
		amount += coupon[indexC] * product[indexP];
		indexC++;
		indexP++;
	}

	indexC = Nc - 1;
	indexP = Np - 1;
	while (indexC >= 0 && indexP >= 0 && coupon[indexC] < 0 && product[indexP] < 0) {
		amount += coupon[indexC] * product[indexP];
		indexC--;
		indexP--;
	}

	printf("%lld\n", amount);

	system("pause");
	return 0;
}