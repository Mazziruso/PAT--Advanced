#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

struct rational {
	bool sign; //-1 for true;
	long long int integer;
	long long int numerator;
	long long int denominator;
};

long long int gcd(long long int a, long long int b) {
	return (b == 0) ? a : gcd(b, a%b);
}

pair<long long int, long long int> rationalOperator(pair<long long int, long long int> A, pair<long long int, long long int> B, char op) {
	pair<long long int, long long int> C;
	if (op == '+') {
		C.first = A.first*B.second + A.second*B.first;
		C.second = A.second*B.second;
	}
	else if (op == '-') {
		C.first = A.first*B.second - A.second*B.first;
		C.second = A.second*B.second;
	}
	else if (op == '*') {
		C.first = A.first*B.first;
		C.second = A.second*B.second;
	}
	else {
		C.first = A.first*B.second;
		C.second = A.second*B.first;
	}
	return C;
}

rational toSimple(pair<long long int, long long int> A) {
	if (A.second == 0) {
		rational B;
		B.denominator = 0;
		return B;
	}

	bool flag = (A.first*A.second < 0) ? true : false;
	A.first = labs(A.first);
	A.second = labs(A.second);

	long long int integer = A.first / A.second;
	A.first = A.first % A.second;
	long long int gcdVal = gcd(A.first, A.second);
	long long int numerator = A.first / gcdVal;
	long long int denominator = A.second / gcdVal;

	struct rational B;
	B.sign = flag;
	B.integer = integer;
	B.numerator = numerator;
	B.denominator = denominator;
	return B;
}

void printRational(rational A) {
	if (A.denominator == 0) {
		printf("Inf");
		return;
	}
	if (A.numerator == 0) {
		if (A.sign) {
			printf("(-%lld)", A.integer);
		}
		else {
			printf("%lld", A.integer);
		}
		return;
	}
	if (A.sign) {
		if (A.integer == 0) {
			printf("(-%lld/%lld)", A.numerator, A.denominator);
		}
		else {
			printf("(-%lld %lld/%lld)", A.integer, A.numerator, A.denominator);
		}
	}
	else {
		if (A.integer == 0) {
			printf("%lld/%lld", A.numerator, A.denominator);
		}
		else {
			printf("%lld %lld/%lld", A.integer, A.numerator, A.denominator);
		}
	}
}

void printResult(rational A, rational B, rational C, char op) {
	printRational(A);
	printf(" %c ", op);
	printRational(B);
	printf(" = ");
	printRational(C);
	printf("\n");
}

int main() {

	pair<long long int, long long int> A, B;

	scanf("%lld/%lld %lld/%lld", &A.first, &A.second, &B.first, &B.second);

	rational num1, num2;
	num1 = toSimple(A);
	num2 = toSimple(B);

	rational sum = toSimple(rationalOperator(A, B, '+'));
	rational diff = toSimple(rationalOperator(A, B, '-'));
	rational product = toSimple(rationalOperator(A, B, '*'));
	rational dividen = toSimple(rationalOperator(A, B, '/'));

	printResult(num1, num2, sum, '+');
	printResult(num1, num2, diff, '-');
	printResult(num1, num2, product, '*');
	printResult(num1, num2, dividen, '/');

	return 0;
}
