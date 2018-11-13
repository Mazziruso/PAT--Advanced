#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

int main() {

	int N;
	string str;

	scanf_s("%d", &N);

	int len;
	int A, B, Z;
	while (N--) {
		cin >> str;
		len = str.length();
		Z = stoi(str);
		A = stoi(str.substr(0, len / 2));
		B = stoi(str.substr(len / 2));
		printf("%s\n", (A == 0 || B == 0) ? "No" : (Z % (A*B) == 0) ? "Yes" : "No");
	}

	system("pause");
	return 0;
}