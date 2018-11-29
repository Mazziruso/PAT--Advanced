#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
#define maxn 86500
#define lowbit(x) (x & -x)

using namespace std;

int C[maxn] = { 0 };

void update(int s, int e, int key) {
	for (int i = e; i > 0; i -= lowbit(i)) {
		C[i] += key;
	}
	for (int i = s - 1; i > 0; i -= lowbit(i)) {
		C[i] -= key;
	}
}

int getSum(int x) {
	int sum = 0;
	for (int i = x; i < maxn; i += lowbit(i)) {
		sum += C[i];
	}
	return sum;
}

struct record {
	char id[10];
	int times;
	bool status;
	bool operator<(const struct record &r) {
		if (strcmp(this->id, r.id) == 0) {
			return this->times < r.times;
		}
		else {
			return strcmp(this->id, r.id) < 0;
		}
	}
};

record records[10001];

struct carInfo {
	char id[10];
	int len;
	bool operator<(const struct carInfo &c) {
		if (this->len == c.len) {
			return strcmp(this->id, c.id) < 0;
		}
		else {
			return this->len > c.len;
		}
	}
};
vector<carInfo> carLen;
vector<carInfo> res;

int toTime(int hh, int mm, int ss) {
	return hh * 3600 + mm * 60 + ss + 1;
}

int main() {
	
	int N, K;
	int hh, mm, ss;
	char status[5];

	scanf_s("%d %d", &N, &K);
	for (int i = 0; i < N; i++) {
		scanf_s("%s %d:%d:%d %s", records[i].id, 10, &hh, &mm, &ss, status, 5);
		records[i].times = toTime(hh, mm, ss);
		records[i].status = (strcmp(status, "in") == 0) ? true : false;
	}

	sort(records, records + N);

	int len = 0;
	int maxLen = -1;

	carInfo c;
	int i = 1;
	while (i < N) {
		if (strcmp(records[i].id, records[i - 1].id) == 0) {
			if (records[i - 1].status && !records[i].status) {
				len += records[i].times - records[i - 1].times ;
				update(records[i - 1].times, records[i].times - 1, 1); //
			}
		}
		else {
			c.len = len;
			strcpy_s(c.id, 10, records[i - 1].id);
			carLen.push_back(c);
			maxLen = (maxLen < len) ? len : maxLen;
			len = 0;
		}
		i++;
	}
	//加上最后的车牌号
	c.len = len;
	strcpy_s(c.id, 10, records[N - 1].id);
	carLen.push_back(c);
	maxLen = (maxLen < len) ? len : maxLen;

	while (K--) {
		scanf_s("%d:%d:%d", &hh, &mm, &ss);
		printf("%d\n", getSum(toTime(hh, mm, ss)));
	}

	sort(carLen.begin(), carLen.end());
	for (auto ca : carLen) {
		if (ca.len == maxLen) {
			printf("%s ", ca.id);
		}
	}
	printf("%02d:%02d:%02d\n", maxLen / 3600, (maxLen % 3600) / 60, maxLen % 60);

	system("pause");
	return 0;
}