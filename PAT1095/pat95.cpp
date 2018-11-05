#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <string>

using namespace std;

struct carInfo {
	string id;
	int time;
	bool IO; //true denotes in status
	bool operator<(struct carInfo &c1) {
		if (this->id.compare(c1.id) == 0) {
			return this->time < c1.time;
		}
		else {
			return this->id.compare(c1.id) < 0;
		}
	}
};

struct carInfo *carRecord;
struct carInfo *validRecord;
int N;

int toTime(int hh, int mm, int ss) {
	return 3600 * hh + 60 * mm + ss;
}

int binaryFindCurrent(int current, int len) {
	int l = 0;
	int r = len - 1;
	int mid;
	while (l <= r) {
		mid = (l + r) / 2;
		if (validRecord[mid].time == current) {
			r = mid ;
			break;
		}
		else if(validRecord[mid].time > current) {
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}
	return r;
}

int main() {

	int K;
	scanf_s("%d %d", &N, &K);
	carRecord = new carInfo[N];
	validRecord = new carInfo[N];
	
	int hh, mm, ss;
	char id[8];
	char status[4];
	struct carInfo c;
	for (int i = 0; i < N; i++) {
		scanf_s("%s %d:%d:%d %s", id, 8, hh, mm, ss, status, 4);
		carRecord[i].id = string(id);
		carRecord[i].time = toTime(hh, mm, ss);
		carRecord[i].IO = (status[0] == 'i');
	}

	sort(carRecord, carRecord+N);

	int index = 0; //in pair with out , index turns to even
	for (int i = 0; i < N; i++) {
		if (carRecord[i].IO) {
			index = (index % 2 == 1) ? (index - 1) : index;
			validRecord[index] = carRecord[i];
			index++;
		}
		else if(index % 2 == 1) {
			validRecord[index] = carRecord[i];
			index++;
		}
	}

	//calculate longest period
	vector<int> carPeriod;
	int period;
	int maxPeriod = -1;
	string num = "";
	for (int i = 0; i < index; i+=2) {
		if (num.compare(validRecord[i].id) != 0) {
			carPeriod.push_back(period);
			if (maxPeriod < period) {
				maxPeriod = period;
			}
			num = validRecord[i].id;
			period = validRecord[i + 1].time - validRecord[i].time;
		}
		else {
			period += validRecord[i + 1].time - validRecord[i].time;
		}
	}

	int current;
	int pivot;
	int res;
	for (int i = 0; i < K; i++) {
		scanf_s("%d:%d:%d", &hh, &mm, &ss);
		current = toTime(hh, mm, ss);
		pivot = binaryFindCurrent(current, index);
		res += (validRecord[pivot].IO ? 1 : 0);
		pivot++;
		while (pivot < N) {
			if (validRecord[pivot].IO) {
				res--;
			}
			else {
				res++;
			}
			pivot++;
		}
		printf("%d\n", res);
	}

	system("pause");
	return 0;
}
