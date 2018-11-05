#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <string>

using namespace std;

char toUpper(char c) {
	if (c >= 'a' && c <= 'z') {
		c = c - 'a' + 'A';
	}
	return c;
}

bool checkSame(char c1, char c2) {
	if (c1 >= 'a' && c1 <= 'z') {
		c1 = c1 - 'a' + 'A';
	}
	if (c2 >= 'a' && c2 <= 'z') {
		c2 = c2 - 'a' + 'A';
	}
	return c1 == c2;
}

int main() {

	string origin;
	string typeOut;

	cin >> origin >> typeOut;

	//construct intact key set
	set<char> intact;
	for (int i = 0; i < typeOut.length(); i++) {
		intact.insert(toUpper(typeOut[i]));
	}
	
	vector<char> res;
	set<char> wornKey;

	char c;
	for (int i = 0; i < origin.length(); i++) {
		c = toUpper(origin[i]);
		if (intact.count(c) == 0 && wornKey.count(c) == 0) {
			res.push_back(c);
			wornKey.insert(c);
		}
	}

	for (auto iter : res) {
		printf("%c", iter);
	}
	printf("\n");

	system("pause");
	return 0;
}