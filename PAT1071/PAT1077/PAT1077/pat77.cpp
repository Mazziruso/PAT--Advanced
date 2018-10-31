#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

string LargestSuffix(string str1, string str2) {
	string common;

	int n1 = str1.size() - 1;
	int n2 = str2.size() - 1;

	while (n1 >= 0 && n2 >= 0) {
		if (str1[n1] == str2[n2]) {
			common += str1[n1];
		}
		else {
			break;
		}
		n1--;
		n2--;
	}

	reverse(common.begin(),common.end());

	return common;
}

int main() {

	int N;
	string str;
	string common;

	scanf_s("%d\n", &N);
	getline(cin, str);
	common = str;
	N--;

	while (N--) {
		getline(cin, str);
		if (!common.empty()) {
			common = LargestSuffix(str, common);
		}
	}

	if (common.empty()) {
		printf("nai\n");
	}
	else {
		cout << common << endl;
	}

	system("pause");
	return 0;
}