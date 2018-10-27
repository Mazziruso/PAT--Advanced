#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

string BigAdd(string A, string B) {
	int indexA = A.size() - 1;
	int indexB = B.size() - 1;

	string C;
	int carry = 0;
	int sum = 0;
	while (indexA >= 0 && indexB >= 0) {
		sum = A.at(indexA) - '0' + B.at(indexB) - '0' + carry;
		carry = sum / 10;
		C.append(1, (sum % 10) + '0');
		indexA--;
		indexB--;
	}
	while (indexA >= 0) {
		sum = A.at(indexA) - '0' + carry;
		carry = sum / 10;
		C.append(1, sum % 10 + '0');
		indexA--;
	}
	while (indexB>=0) {
		sum = B.at(indexB) - '0' + carry;
		carry = sum / 10;
		C.append(1, sum % 10 + '0');
		indexB--;
	}
	if (carry > 0) {
		C.append(1, carry + '0');
	}
	return C;
}

string BigSubtract(string A, string B) {

}

int main() {
	int T;
	string A;
	string B;
	string C;

	scanf_s("%d", &T);
	for (int i = 1; i <= T; i++) {
		cin >> A >> B >> C;
		if (A.at(0) == '-' && B.at(0) == '-') {

		}
		else if (A.at(0) == '-') {

		}
		else if (B.at(0) == '-') {

		}
		else {

		}
	}

	system("pause");
	return 0;
}