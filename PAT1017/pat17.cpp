#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
#include <cmath>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

typedef struct aPTime {
	int arriveTime;
	int proceess;
} pTime;

int N;
int K;
pTime *userTime;
priority_queue<int,vector<int>,std::greater<int>> windows;

bool cmp(pTime p1, pTime p2) {
	return p1.arriveTime<p2.arriveTime;
}

double round(double x) {
	return (x>0.0) ? floor(x+0.5) : ceil(x-0.5);
}


int main() {

	scanf("%d %d", &N, &K);

	if(N==0 || K==0) {
		printf("0.0\n");
		return 0;
	}

	userTime = new pTime[N];

	//init windows
	for(int i=0; i<K; i++) {
		windows.push(8*60*60);
	}

	int temp;
	int seconds;
	int minutes;
	int hours;
	for(int i=0; i<N; i++) {
		scanf("%2d:%2d:%2d %d", &hours, &minutes, &seconds, &temp);
		userTime[i].arriveTime = hours*60*60+minutes*60+seconds;
		userTime[i].proceess = temp*60;
	}

	std::sort(userTime, userTime+N, cmp);

	int min = 0;
	int wTime = 0;
	int num = 0;
	for(int i=0; i<N; i++) {
		temp = userTime[i].arriveTime;
		if(temp>61200) {
			continue;
		}
		min = windows.top();
		windows.pop();
		if(temp<min) {
			wTime += (min-temp);
		}
		windows.push(min+userTime[i].proceess);
		num++;
	}

	if(num==0) {
		printf("0.0\n");
	} else {
		double res = wTime/(60.0*num);
		//res = round(res*10)/10.0;
		printf("%.1lf\n",res);
	}

	system("pause");
	return 0;

}
