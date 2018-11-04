#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <map>
#include <vector>

using namespace std;

struct timeSta {
	int time;
	bool IO; //if in then true;
};

typedef map<string, int>::iterator iter;

int N;
map<string, int> nameID;
vector<timeSta> *carTime;
string *car;

int toTime(int hh, int mm, int ss) {
	return hh * 3600 + mm * 60 + ss;
}

int main() {
	int K;
	scanf_s("%d %d", &N, &K);

	carTime = new vector<timeSta>[N];
	car = new string[N];

	struct timeSta carT;
	int hh, mm, ss;
	string ID, status;
	int index = 0;
	iter it;
	for (int i = 0; i < N; i++) {
		cin >> ID;
		scanf_s("%d:%d:%d", &hh, &mm, &ss);
		cin >> status;
		carT.time = toTime(hh, mm, ss);
		carT.IO = (status == "in") ? true : false;
		it = nameID.find(ID);
		if (it == nameID.end()) {
			nameID.insert(pair<string,int>(ID,index));
			carTime[index].push_back(carT);
			car[index] = ID;
			index++;
		}
		else {
			carTime[it->second].push_back(carT);
			car[it->second]=ID:
		}
	}

	system("pause");
	return 0;
}
