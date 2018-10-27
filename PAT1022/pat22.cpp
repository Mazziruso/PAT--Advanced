#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <map>
#include <vector>

using namespace std;

typedef multimap<string, int>::iterator iter;
typedef pair<iter, iter> Range;

multimap<string, int> titleID;
multimap<string, int> authorID;
multimap<string, int> keywID;
multimap<string, int> publishID;
multimap<string, int> yearID;
int N;

vector<int> res;

int main() {

	scanf("%d", &N);

	int ID;
	int year;
	string str;
	string keyw;
	int strSize;
	unsigned long pos;
	for (int i = 0; i < N; i++) {
		scanf("%d\n", &ID);

		getline(cin, str);
		titleID.insert(make_pair(str, ID));

		getline(cin, str);
		authorID.insert(make_pair(str, ID));

		getline(cin, str);
		strSize = str.size();
		str.append(" ");
		for (unsigned long p = 0; p < strSize; p++) {
			pos = str.find(" ", p);
			if (pos <= strSize) {
				keyw = str.substr(p, pos - p);
				keywID.insert(make_pair(keyw, ID));
				p = pos;
			}
		}

		getline(cin, str);
		publishID.insert(make_pair(str, ID));

		getline(cin, str);
		yearID.insert(make_pair(str, ID));
	}

	int M;
	scanf("%d\n", &M);
	int index;

	Range range;
	while (M--) {
		scanf("%d: ", &index);
		res.clear();
		switch (index) {
		case 1:
			getline(cin, str);
			cout << index << ": " << str << endl;
			range = titleID.equal_range(str);
			if (range.first == range.second) {
				printf("Not Found\n");
			}
			else {
				for (iter it = range.first; it != range.second; ++it) {
					res.push_back(it->second);
				}
				sort(res.begin(), res.end());
				for (vector<int>::iterator it = res.begin(); it != res.end(); ++it) {
					printf("%07d\n", *it);
				}
			}
			break;
		case 2:
			getline(cin, str);
			cout << index << ": " << str << endl;
			range = authorID.equal_range(str);
			if (range.first == range.second) {
				printf("Not Found\n");
			}
			else {
				for (iter it = range.first; it != range.second; ++it) {
					res.push_back(it->second);
				}
				sort(res.begin(), res.end());
				for (vector<int>::iterator it = res.begin(); it != res.end(); ++it) {
					printf("%07d\n", *it);
				}
			}
			break;
		case 3:
			getline(cin, str);
			cout << index << ": " << str << endl;
			range = keywID.equal_range(str);
			if (range.first == range.second) {
				printf("Not Found\n");
			}
			else {
				for (iter it = range.first; it != range.second; ++it) {
					res.push_back(it->second);
				}
				sort(res.begin(), res.end());
				for (vector<int>::iterator it = res.begin(); it != res.end(); ++it) {
					printf("%07d\n", *it);
				}
			}
			break;
		case 4:
			getline(cin, str);
			cout << index << ": " << str << endl;
			range = publishID.equal_range(str);
			if (range.first == range.second) {
				printf("Not Found\n");
			}
			else {
				for (iter it = range.first; it != range.second; ++it) {
					res.push_back(it->second);
				}
				sort(res.begin(), res.end());
				for (vector<int>::iterator it = res.begin(); it != res.end(); ++it) {
					printf("%07d\n", *it);
				}
			}
			break;
		case 5:
			getline(cin, str);
			cout << index << ": " << str << endl;
			range = yearID.equal_range(str);
			if (range.first == range.second) {
				printf("Not Found\n");
			}
			else {
				for (iter it = range.first; it != range.second; ++it) {
					res.push_back(it->second);
				}
				sort(res.begin(), res.end());
				for (vector<int>::iterator it = res.begin(); it != res.end(); ++it) {
					printf("%07d\n", *it);
				}
			}
			break;
		default:
			printf("Not Found\n");
		}
	}

	return 0;
}
