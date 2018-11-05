#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;

string unit[13] = {"tret","jan","feb","mar","apr","may","jun","jly","aug","sep","oct","nov","dec"};
string ten[13] = {"","tam","hel","maa","huh","tou","kes","hei","elo","syy","lok","mer","jou"};

int findUnit(string str) {
	for (int i = 0; i < 13; i++) {
		if (str == unit[i]) {
			return i;
		}
	}
	return 0;
}

int findTen(string str) {
	for (int i = 0; i < 13; i++) {
		if (str == ten[i]) {
			return i;
		}
	}
	return 0;
}

int main() {

	int N;
	scanf_s("%d\n", &N);
	
	string strU;
	string strT;
	int Udigit;
	int Tdigit;
	while (N--) {
		getline(cin, strT);
		if (strT[0] <= '9') {
			Tdigit = stoi(strT,nullptr,10);
			Udigit = Tdigit % 13;
			Tdigit = Tdigit / 13;
			if (Tdigit == 0) {
				cout << unit[Udigit] << endl;
			}
			else {
				if (Udigit == 0) {
					cout << ten[Tdigit] << endl;
				}
				else {
					cout << ten[Tdigit] << " " << unit[Udigit] << endl;
				}
			}
		}
		else {
			if (strT.length() > 3) {
				strU = strT.substr(4);
				strT = strT.substr(0, 3);
				Tdigit = findTen(strT);
				Udigit = findUnit(strU);
				printf("%d\n", Tdigit * 13 + Udigit);
			}
			else if (findTen(strT) == 0) {
				printf("%d\n", findUnit(strT));
			}
			else {
				printf("%d\n", findTen(strT) * 13);
			}
		}
	}

	system("pause");
	return 0;
}
