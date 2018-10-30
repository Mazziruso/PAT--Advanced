#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>

using namespace std;

map<string, int> words;

bool check(char c) {
	if (c >= 'a' && c <= 'z') {
		return true;
	}
	if (c >= 'A' && c <= 'Z') {
		return true;
	}
	if (c >= '0' && c <= '9') {
		return true;
	}
	return false;
}

int main() {

	string str;
	getline(cin, str);

	int i = 0;
	while (i < str.length()) {
		string word;
		while (i < str.length() && check(str[i])) {
			if (str[i] >= 'A' && str[i] <= 'Z') {
				str[i] += 32; //transform to lowcase
			}
			word += str[i];
			i++;
		}
		if (word != "") {
			if (words.find(word) == words.end()) {
				words[word] = 1;
			}
			else {
				words[word]++;
			}
		}
		while (i < str.length() && !check(str[i])) {
			i++;
		}
	}

	string ans;
	int max = -1;
	for (map<string, int>::iterator iter = words.begin(); iter != words.end(); ++iter) {
		if (max < iter->second) {
			max = iter->second;
			ans = iter->first;
		}
	}

	cout << ans << " " << max << endl;

	system("pause");
	return 0;
}