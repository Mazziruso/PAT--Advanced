#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

//每个按键有三个状态，0代表初始状态，1代表完好状态，2代表损坏状态
int hashTable[40] = { 0 }; //initial status keyboards
vector<char> struckedKey;

int hashTran(char c) {
	if (c <= '9') {
		return c - '0';
	}
	else if (c == '_') {
		return 10;
	}
	else {
		return c - 'a' + 11;
	}
}

int main() {

	int k;
	char s[1001];
	fill_n(hashTable, 40, 0);
	scanf_s("%d", &k);
	scanf_s("%s", s, 1001);

	int len = strlen(s);
	int num = 0;
	for (int i = 0; i < len - 1; i++) {
		num = 1;
		while (i < len && num < k &&s[i] == s[i + 1]) {
			i++;
			num++;
		}
		if (num < k) {
			hashTable[hashTran(s[i])] = 1; //this key is intact
		}
		else if (hashTable[hashTran(s[i])] == 0) {
			struckedKey.push_back(s[i]);
			hashTable[hashTran(s[i])] = 2; //the key is strucked
		}
	}

	for (auto iter : struckedKey) {
		if (hashTable[hashTran(iter)] == 2) {
			printf("%c", iter);
		}
	}
	printf("\n");

	int i = 0;
	while (i < len) {
		if (hashTable[hashTran(s[i])] == 2) {
			printf("%c", s[i]);
			i += k;
		}
		else {
			printf("%c", s[i]);
			i++;
		}
	}
	printf("\n");

	system("pause");
	return 0;
}