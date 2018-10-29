#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <map>
#include <string>

using namespace std;

char toLowCase(char a) {
	if (a >= 'A' && a <= 'Z') {
		return a - 'A' + 'a';
	}
	else {
		return a;
	}
}

string toLowCaseString(string str) {
	int len = str.size();
	string word;
	for (int i = 0; i < len; i++) {
		word.append(1, toLowCase(str.at(i)));
	}
	return word;
}

map<string, int> words;

int main() {

	string str;
	getline(cin, str);

	int num;
	string word;
	map<string, int>::iterator mapIt;
	size_t start = 0;
	size_t iter = str.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789", 0);
	while (start < str.size()) {
		word = toLowCaseString(str.substr(start, iter-start));
		mapIt = words.find(word);
		if (mapIt == words.end()) {
			words.insert(pair<string, int>(word, 1));
		}
		else {
			num = mapIt->second + 1;
			words.erase(mapIt);
			words.insert(pair<string, int>(word, num));
		}
		start = str.find_first_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789", iter);
		iter = str.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789", start);
	}

	int max = -1;
	for (mapIt = words.begin(); mapIt != words.end(); ++mapIt) {
		if (max < mapIt->second) {
			word = mapIt->first;
			max = mapIt->second;
		}
	}

	cout << word << " " << max << endl;

	system("pause");
	return 0;
}
