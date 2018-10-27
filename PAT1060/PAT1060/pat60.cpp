#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	int N;
	char a[110];
	char b[110];

	scanf_s("%d", &N);
	scanf_s("%s", a, 110);
	scanf_s("%s", b, 110);
	
	string num1 = string(a);
	string num2 = string(b);

	bool flag = true;
	bool flag1zero = false;
	bool flag2zero = false;
	int bit1 = 0;
	int bit2 = 0;

	int index = 0;
	int k1 = 0;
	while (index < num1.size() && num1.at(index) == '0') {
		index++;
	}
	if (index >= num1.size()) {
		bit1 = index;
	}
	else if (num1.at(index) != '.') {
		bit1 = index;
		while (index < num1.size() && num1.at(index) != '.') {
			index++;
			k1++;
		}
	}
	else {
		index++;
		while (index < num1.size() && num1.at(index) == '0') {
			index++;
			k1--;
		}
		bit1 = index;
	}

	if (bit1 >= num1.size()) {
		flag1zero = true;
	}

	index = 0;
	int k2 = 0;
	while (index < num2.size() && num2.at(index) == '0') {
		index++;
	}
	if (index >= num2.size()) {
		bit2 = index;
	}
	else if (num2.at(index) != '.') {
		bit2 = index;
		while (index < num2.size() && num2.at(index) != '.') {
			index++;
			k2++;
		}
	}
	else {
		index++;
		while (index < num2.size() && num2.at(index) == '0') {
			index++;
			k2--;
		}
		bit2 = index;
	}

	if (bit2 >= num2.size()) {
		flag2zero = true;
	}

	flag = true;
	num1.append(100, '0');
	num2.append(100, '0');

	char d1[110];
	char d2[110];
	fill(d1, d1 + 110, '\0');
	fill(d2, d2 + 110, '\0');
	for (int i = 0; i < N; i++) {
		if (num1.at(bit1) == '.') {
			bit1++;
		}
		if (num2.at(bit2) == '.') {
			bit2++;
		}
		d1[i] = num1.at(bit1);
		d2[i] = num2.at(bit2);
		bit1++;
		bit2++;
		
		if (d1[i] != d2[i]) {
			flag = false;
		}
	}

	if (flag1zero && flag2zero) {
		printf("YES 0.%s*10^0\n", d1);
		return 0;
	}
	else if (flag1zero) {
		printf("NO 0.%s*10^0 0.%s*10^%d\n", d1, d2, k2);
		return 0;
	}
	else if(flag2zero) {
		printf("NO, 0.%s*10^%d 0.%s*10^0", d1, k1, d2);
		return 0;
	}

	if (k1 != k2 || !flag) {
		printf("NO 0.%s*10^%d 0.%s*10^%d\n", d1, k1, d2, k2);
	}
	else {
		printf("YES 0.%s*10^%d\n", d1, k1);
	}

	return 0;
}