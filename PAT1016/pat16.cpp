#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <list>

using namespace std;

class NameID {
public :
	string name;
	int id;
	int recordTime;
	bool line;
	NameID();
	static bool cmp(NameID nID1, NameID nID2);
};

NameID::NameID(void) {
}

bool NameID::cmp(NameID nID1, NameID nID2) {
	if(nID1.name.compare(nID2.name)==0) {
		return (nID1.recordTime<nID2.recordTime);
	} else {
		return (nID1.name.compare(nID2.name)<0);
	}
}


//global variables
int N;
double *fee;
NameID *nID;
string month;
double Dayfee;

double charge(int start, int end) {
	int startD = start/(24*60);
	start %= (24*60);
	int startH = start/60;
	int startM = start%60;
	int endD = end/(24*60);
	end %= (24*60);
	int endH = end/60;
	int endM = end%60;

	double cost = 0;

	if(startD!=endD) {
		for(int i=startD; i<endD; i++) {
			cost += Dayfee;
		}
		for(int i=0; i<startH; i++) {
			cost -= fee[i]*60;
		}
		cost -= fee[startH]*startM;
		for(int i=0; i<endH; i++) {
			cost += fee[i]*60;
		}
		cost += fee[endH]*endM;
	} else {
		for(int i=startH; i<endH; i++) {
			cost += fee[i]*60;
		}
		cost = cost + endM*fee[endH] - startM*fee[startH];
	}

	return cost;
}

void toTime(int time) {
	string dhm;
	int minutes;
	int hours;
	int days;

	days = time/(24*60);
	time %= (24*60);
	hours = time/60;
	time %= 60;
	minutes = time;

	printf("%02d:%02d:%02d ",days,hours,minutes);
}

int main() {

	double temp;
	fee = new double[24];
	Dayfee = 0.0;
	for(int i=0; i<24; i++) {
		scanf("%lf", &temp);
		temp /= 100.0;
		fee[i] = temp;
		Dayfee += (temp*60.0);
	}

	scanf("%d", &N);

	nID = new NameID[N];

	string name;
	string time;
	string line;

	for(int i=0; i<N; i++) {
		cin>>name>>time>>line;
		month = (month.empty()) ? time.substr(0,2) : month;

		nID[i].name = name;
		nID[i].id = i;

		nID[i].recordTime = stoi(time.substr(3,2))*24*60 + stoi(time.substr(6,2))*60 + stoi(time.substr(9,2));
		nID[i].line = (line.compare("on-line")==0);
	}

	sort(nID, nID+N,NameID::cmp);

	int startT;
	int endT;
	double cost;
	bool flag;
	int index=0;
	double total;
	while(index<N-1) {
		flag = true;
		total = 0.0;
		while((index<N-1) && nID[index].name==nID[index+1].name) {
			if(nID[index].line && !nID[index+1].line) {
				if(flag) {
					printf("%s %s\n", nID[index].name.c_str(), month.c_str());
					flag = false;
				}
				startT = nID[index].recordTime;
				endT = nID[index+1].recordTime;
				cost = charge(startT, endT);
				toTime(startT);
				toTime(endT);
				printf("%d $%.2lf\n", (endT-startT), cost);
				total += cost;
			}
			index++;
		}
		if(!flag) {
			printf("Total amount: $%.2lf\n", total);
		}
		index++;
	}

	return 0;
}