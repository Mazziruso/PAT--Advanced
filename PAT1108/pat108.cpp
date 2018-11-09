#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

float number;

bool checkLegal(string str) {
	int index = (str[0] == '-') ? 1 : 0;
	while (index < str.size() && str[index] >= '0' && str[index] <= '9') {
		index++;
	}
	if (index != str.size()) {
		if (str[index] != '.') {
			return false;
		}
		else {
			index++;
		}
	}
	int count = 0;
	while (index < str.size() && str[index] >= '0' && str[index] <= '9') {
		index++;
		count++;
	}
	if (index < str.size() || count > 2) {
		return false;
	}
	number = stof(str);
	if (number < -1000 || number >1000) {
		return false;
	}
	return true;
}

int main() {
	
	int N;
	string str;
	scanf_s("%d", &N);

	float num = 0.0;
	int count = 0;
	for (int i = 0; i < N; i++) {
		cin >> str;
		if (checkLegal(str)) {
			num += number;
			count++;
		}
		else {
			printf("ERROR: %s is not a legal number\n", str.c_str());
		}
	}
	
	if (count == 0) {
		printf("The average of 0 numbers is Undefined\n");
	}
	else if (count == 1) {
		printf("The average of 1 number is %.2f\n", num);
	}
	else {
		printf("The average of %d numbers is %.2f\n", count, num / count);
	}

	system("pause");
	return 0;
}