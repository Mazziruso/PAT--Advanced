#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

string toDay(char day) {
	string d;
	switch (day - 'A')
	{
	case 0:
		d = "MON";
		break;
	case 1:
		d = "TUE";
		break;
	case 2:
		d = "WED";
		break;
	case 3:
		d = "THU";
		break;
	case 4:
		d = "FRI";
		break;
	case 5:
		d = "SAT";
		break;
	case 6:
		d = "SUN";
		break;
	default:
		d = "";
		break;
	}
	return d;
}

int toHour(char hour) {
	if (hour <= '9' && hour >= '0') {
		return hour - '0';
	}
	else {
		return hour - 'A' + 10;
	}
}

int main() {

	string s1;
	string s2;
	string s3;
	string s4;

	cin >> s1 >> s2 >> s3 >> s4;

	char day;
	char hour;
	unsigned long int minute;
	bool first = false;
	for (unsigned long int i = 0; i < s1.size() && i < s2.size(); i++) {
		if (first && s1.at(i) == s2.at(i) && ((s1.at(i) >= '0' && s1.at(i) <= '9') || (s1.at(i) >= 'A' && s1.at(i) <= 'N'))) {
			hour = s1.at(i);
			break;
		}
		if (!first && s1.at(i) == s2.at(i) && s1.at(i) >= 'A' && s1.at(i) <= 'G') {
			first = true;
			day = s1.at(i);
		}
	}

	for (unsigned long int i = 0; i < s3.size() && i < s4.size(); i++) {
		if (s3.at(i) == s4.at(i) && ((s3.at(i) >= 'a' && s3.at(i) <= 'z') || (s3.at(i) >= 'A' && s3.at(i) <= 'Z'))) {
			minute = i;
			break;
		}
	}

	printf("%s %02d:%02lu\n", toDay(day).c_str(), toHour(hour), minute);

	return 0;
}