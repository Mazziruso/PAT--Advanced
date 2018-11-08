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

bool cmp(struct carInfo c1, struct carInfo c2) {
    return c1.time < c2.time;
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
	scanf("%d %d", &N, &K);
	carRecord = new carInfo[N];
	validRecord = new carInfo[N];
	
	int hh, mm, ss;
	char id[8];
	char status[4];
	struct carInfo c;
	for (int i = 0; i < N; i++) {
		scanf("%s %d:%d:%d %s", id, &hh, &mm, &ss, status);
		carRecord[i].id = string(id);
		carRecord[i].time = toTime(hh, mm, ss);
		carRecord[i].IO = (status[0] == 'i');
	}

	sort(carRecord, carRecord+N);

    //record max period and valid record
    int maxPeriod = -1;
    int index = 0;
    int period;
    map<string,int> parkTime;
    for(int i=0; i<N-1; i++) {
        if(carRecord[i].id.compare(carRecord[i+1].id)==0 &&
            carRecord[i].IO && !carRecord[i+1].IO) {
            validRecord[index++] = carRecord[i];
            validRecord[index++] = carRecord[i+1];
            period = carRecord[i+1].time-carRecord[i].time;
            if(parkTime.find(carRecord[i].id)==parkTime.end()) {
                parkTime[carRecord[i].id] = 0;
            }
            parkTime[carRecord[i].id] += period;
            maxPeriod = max(maxPeriod,parkTime[carRecord[i].id]);
        }
    }

    sort(validRecord,validRecord+index,cmp);

    //当前驻留车辆
	int current;
	int pivot;
	int res;
	for (int i = 0; i < K; i++) {
		scanf("%d:%d:%d", &hh, &mm, &ss);
		current = toTime(hh, mm, ss);
		pivot = binaryFindCurrent(current, index);
		res = 0;
		while (pivot < index) {
            if(validRecord[pivot].time>current) {
			    if (validRecord[pivot].IO) {
				    res--;
			    }
			    else {
				    res++;
			    }
            }
			pivot++;
		}
		printf("%d\n", res);
	}

    string *maxPerCar = new string[parkTime.size()];
    int ii=0;
    for(auto iter : parkTime) {
        if(iter.second == maxPeriod) {
            maxPerCar[ii++] = iter.first;
        }
    }
    sort(maxPerCar,maxPerCar+ii);
    for(int i=0; i<ii; i++) {
        printf("%s ", maxPerCar[i].c_str());
    }
    printf("%02d:%02d:%02d\n", maxPeriod/3600, (maxPeriod%3600)/60, maxPeriod%60);

	return 0;
}