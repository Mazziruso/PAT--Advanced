#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

//33, 3332这种情况没有考虑到
/*bool cmp(string s1, string s2) {
	if (s1.length() == s2.length()) {
		return s1.compare(s2) < 0;
	}
	else if(s1.length() < s2.length()) {
		s1.append(1, s2.at(0));
		return s1.compare(s2) < 0;
	}
	else {
		s2.append(1,s1.at(0));
		return s1.compare(s2) < 0;
	}
}*/

bool cmp(string s1, string s2) {
	return s1 + s2 < s2 + s1;
}

int main() {
	
	int N;
	string *ns;

	scanf_s("%d", &N);
	ns = new string[N];
	for (int i = 0; i < N; i++) {
		cin >> ns[i];
	}

	sort(ns, ns + N, cmp);

	int start = 0;
	while (start < N && stoi(ns[start]) == 0) {
		start++;
	}

	if (start == N) {
		printf("0\n");
		return 0;
	}

	printf("%d", stoi(ns[start]));
	for (int i = start+1; i < N; i++) {
		cout << ns[i];
	}
	cout << endl;

	system("pause");
	return 0;
}