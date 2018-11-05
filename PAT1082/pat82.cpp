#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

string digitToChinese(char digit) {
	string str;
	switch (digit) {
	case '0' :
		str = "ling";
		break;
	case '1':
		str = "yi";
		break;
	case '2':
		str = "er";
		break;
	case '3':
		str = "san";
		break;
	case '4':
		str = "si";
		break;
	case '5':
		str = "wu";
		break;
	case '6':
		str = "liu";
		break;
	case '7':
		str = "qi";
		break;
	case '8':
		str = "ba";
		break;
	case '9':
		str = "jiu";
		break;
	default:
		str = "";
	}
	return str;
}

string toMetric(int th) {
	string str;
	if (th == 4) {
		str = " Wan";
	}
	else if (th == 8) {
		str = " Yi";
	}
	else {
		switch (th % 4) {
		case 1:
			str = " Shi";
			break;
		case 2:
			str = " Bai";
			break;
		case 3:
			str = " Qian";
			break;
		default:
			str = "";
		}
	}
	return str;
}

int main() {

	string str;
	cin >> str;
	string res;
	
	int indexLast;
	int len = str.length();

	if (str[0] == '-') {
		res += "Fu";
	}
	else {
		res += digitToChinese(str[0]);
		res += toMetric(len - 1);
	}

	for (int i = 1; i < len; i++) {
		if (str[i] != '0') {
			res += " ";
			res += digitToChinese(str[i]);
			res += toMetric(len - i - 1);
		}
		else {
			indexLast = len - i - 1;
			while (i<len && str[i] == '0') {
				i++;
			}
			if (indexLast >= 8 && indexLast < 11 && (len - i - 1) <= 7) {
				res += " Yi";
			}
			else if (indexLast >= 4 && indexLast < 7 && (len - i - 1) <= 3) {
				res += " Wan";
			}
			if (i < len) {
				res += " ling";
				i--;
			}
		}
	}

	cout << res << endl;
	system("pause");

	return 0;
}