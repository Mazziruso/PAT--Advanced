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
	bool operator<(timeSta s1) {
		return this->time < s1.time;
	}
};

typedef map<string, int>::iterator iter;

int N;
map<string, int> nameID;
vector<timeSta> *carTime;
string *car;
vector<int> *res;

int toTime(int hh, int mm, int ss) {
	return hh * 3600 + mm * 60 + ss;
}

bool checkIn(int car, int time) {
	int start = 0;
	int end = res[car].size() - 1;
	int mid;
	while (start <= end) {
		mid = (start + end) / 2;
		if (res[car][mid] == time) {
			end = mid;
			break;
		}
		else if (res[car][mid] > time) {
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}
	return end % 2 == 0;
}

int main() {
	int K;
	scanf_s("%d %d", &N, &K);

	carTime = new vector<timeSta>[N];
	car = new string[N];

	struct timeSta carT;
	int hh, mm, ss;
	char IDc[8]; 
	char statusc[4];
	string ID, status;
	int index = 0;
	iter it;
	for (int i = 0; i < N; i++) {
		scanf_s("%s", IDc, 8);
		scanf_s("%d:%d:%d", &hh, &mm, &ss);
		scanf_s("%s", statusc, 4);
		ID = string(IDc);
		status = string(statusc);
		carT.time = toTime(hh, mm, ss);
		carT.IO = (status == "in") ? true : false;
		it = nameID.find(ID);
		if (it == nameID.end()) {
			nameID.insert(pair<string, int>(ID, index));
			carTime[index].push_back(carT);
			car[index] = ID;
			index++;
		}
		else {
			carTime[it->second].push_back(carT);
			car[it->second] = ID;
		}
	}

	res = new vector<int>[index];

	int i1 = 0; //in
	int *periodArray = new int[index];
	int periodCar = -1; //longest period per car
	int period = -1; //longest time period
	for (int i = 0; i < index; i++) {
		sort(carTime[i].begin(), carTime[i].end());
		i1 = 0;
		periodCar = 0;
		for (int j = 0; j < carTime[i].size(); j++) {
			if (carTime[i][j].IO) { //in
				i1 = j;
			}
			if (!carTime[i][j].IO && carTime[i][i1].IO) { //in-out pair
				periodCar += (carTime[i][j].time - carTime[i][i1].time);
				res[i].push_back(carTime[i][i1].time);
				res[i].push_back(carTime[i][j].time);
				i1 = j;
			}
		}
		if (period < periodCar) {
			period = periodCar;
		}
		periodArray[i] = periodCar;
	}

	int count = 0;
	int stime;
	for (int i = 0; i < K; i++) {
		scanf_s("%d:%d:%d", &hh, &mm, &ss);
		stime = toTime(hh, mm, ss);
		count = 0;
		for (int j = 0; j < index; j++) {
			count += (checkIn(j, stime) ? 1 : 0);
		}
		printf("%d\n", count);
	}

	vector<string> resCar;
	for (int i = 0; i < index; i++) {
		if (periodArray[i] == period) {
			resCar.push_back(car[i]);
		}
	}

	sort(resCar.begin(), resCar.end());
	for (auto it : resCar) {
		printf("%s ", it.c_str());
	}
	printf("%02d:%02d:%02d\n", period / 3600, (period % 3600) / 60, period % 60);

	system("pause");
	return 0;
}