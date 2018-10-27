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
	while (indexB >= 0) {
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
	int indexA = A.size() - 1;
	int indexB = B.size() - 1;
	string C;
	int carry = 0;
	int sub;

	if (A.compare(B) >= 0) {
		while (indexA >= 0 && indexB >= 0) {
			if ((A.at(indexA) + carry) < B.at(indexB)) {
				sub = 10 + carry + A.at(indexA) - B.at(indexB);
				carry = -1;
			}
			else {
				sub = A.at(indexA) + carry - B.at(indexB);
				carry = 0;
			}
			C.append(1, sub + '0');
			indexA--;
			indexB--;
		}
		while (indexA >= 0) {
			if (A.at(indexA) + carry < '0') {
				sub = 10 + carry + A.at(indexA);
				carry = -1;
			}
			else {
				sub = A.at(indexA) + carry;
				carry = 0;
			}
			C.append(1, sub + '0');
			indexA--;
		}
	}
	else {
		while (indexA >= 0 && indexB >= 0) {
			if ((B.at(indexB) + carry) < A.at(indexA)) {
				sub = 10 + carry + B.at(indexB) - A.at(indexA);
				carry = -1;
			}
			else {
				sub = B.at(indexB) + carry - A.at(indexA);
				carry = 0;
			}
			C.append(1, sub + '0');
			indexA--;
			indexB--;
		}
		while (indexB >= 0) {
			if (B.at(indexB) + carry < '0') {
				sub = 10 + carry + B.at(indexB);
				carry = -1;
			}
			else {
				sub = carry + B.at(indexB);
				carry = 0;
			}
			C.append(1, sub + '0');
			indexB--;
		}
		C.append(1, '-');
	}
	return C;
}

string reverse(string str) {
	string res;
	for (string::reverse_iterator riter = str.rbegin(); riter != str.rend(); ++riter) {
		res.append(1, *riter);
	}
	return res;
}

int main() {
	int T;
	string A;
	string B;
	string C;
	string sum;

	scanf_s("%d", &T);
	bool flag;
	for (int i = 1; i <= T; i++) {
		cin >> A >> B >> C;
		if (A.at(0) == '-' && B.at(0) == '-') {
			sum = BigAdd(A, B);
			sum.append(1, '-');
		}
		else if (A.at(0) == '-') {
			sum = BigSubtract(B, A);
		}
		else if (B.at(0) == '-') {
			sum = BigSubtract(A, B);
		}
		else {
			sum = BigAdd(A, B);
		}
		sum = reverse(sum);
		flag = sum.compare(C) >= 0;
		printf("case #%d: %b\n", i, flag);
	}

	system("pause");
	return 0;
}