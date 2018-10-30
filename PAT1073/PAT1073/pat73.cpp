#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

int main() {

	bool sign;
	string num;
	int exponent;

	string str;
	cin >> str;
	sign = (str[0] == '+') ? true : false;

	num += str[1];
	unsigned int i = 3;
	while (str[i] != 'E') {
		num += str[i];
		i++;
	}

	bool signE = (str[i + 1] == '+') ? true : false;
	exponent = stoi(str.substr(i + 2));

	if (!sign) {
		printf("-");
	}
	if (signE) {
		i = 0;
		while (i < num.length()) {
			if (i > exponent) {
				break;
			}
			printf("%c", num[i]);
			i++;
		}
		while (i <= exponent) {
			printf("0");
			i++;
		}
		if (i < num.length()) {
			printf(".");
		}
		while (i < num.length()) {
			printf("%c", num[i]);
			i++;
		}
	}
	else {
		printf("0.");
		i = 1;
		while (i < exponent) {
			printf("0");
			i++;
		}
		printf("%s", num.c_str());
	}
	printf("\n");

	system("pause");
	return 0;
}