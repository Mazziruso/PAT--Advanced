#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <set>
#include <string>

using namespace std;

int main() {

	string s1;
	string s2;

	getline(cin, s1);
	getline(cin, s2);

	set<char> eraChar;
	for (auto iter : s2) {
		eraChar.insert(iter);
	}

	string res;
	for (auto iter : s1) {
		if (eraChar.count(iter) == 0) {
			res.append(1, iter);
		}
	}

	cout << res << endl;

	system("pause");
	return 0;
}