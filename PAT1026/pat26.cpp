#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <string>
#include <queue>
#include <hash_map>

#define INT_MAX 2147483647

using namespace std;

typedef struct play {
	int arrTime;
	int serTime;
	int playTime;
	int waitTime;

	friend bool operator<(const play &p1, const play &p2) {
		return p1.arrTime > p2.arrTime;
	}
} player;


int *table;
int *counter;
int *VIPTable;
priority_queue<player> VIP;
priority_queue<player> NVIP;
vector<player> res;

int findMin(int K) {
	int min = INT_MAX;
	int index = 0;
	for (int i = 0; i < K; i++) {
		if (min > table[i]) {
			min = table[i];
			index = i;
		}
	}

	return index;
}

int findVIPMin(int K) {
	int min = INT_MAX;
	int index = 0;
	for (int i = 0; i < K; i++) {
		if (min > table[i] && VIPTable[i]) {
			min = table[i];
			index = i;
		}
	}
	return index;
}

int findMinNQ(int K, int arrTime) {
	for (int i = 0; i < K; i++) {
		if (arrTime >= table[i]) {
			return i;
		}
	}
	return -1;
}

int findVIPMinNQ(int K, int arrTime) {
	for (int i = 0; i < K; i++) {
		if (VIPTable[i] && arrTime >= table[i]) {
			return i;
		}
	}

	return -1;
}

bool inQueue(int K, int arrTime) {
	int min = INT_MAX;
	for (int i = 0; i < K; i++) {
		if (arrTime > table[i]) {
			return false;
		}
	}
	return true;
}

int toTime(int HH, int MM, int SS) {
	return HH * 3600 + MM * 60 + SS;
}

void printHMS(int time) {
	int HH = time / 3600;
	time %= 3600;
	int MM = time / 60;
	time %= 60;
	int SS = time;

	printf("%02d:%02d:%02d", HH, MM, SS);
}

int main() {

	int N;
	int K;
	int VIPK;

	scanf("%d", &N);

	int HH;
	int MM;
	int SS;
	int playT;
	int flag;
	player althe;
	for (int i = 0; i < N; i++) {
		scanf("%d:%d:%d %d %d", &HH, &MM, &SS, &playT, &flag);
		althe.arrTime = toTime(HH, MM, SS);
		althe.playTime = (playT > 120) ? 120 * 60 : playT * 60;
		if (flag == 1) {
			VIP.push(althe);
		}
		else {
			NVIP.push(althe);
		}
	}

	scanf("%d %d", &K, &VIPK);
	VIPTable = new int[110];
	fill(VIPTable, VIPTable + 110, 0);
	for (int i = 0; i < VIPK; i++) {
		scanf("%d", &flag);
		VIPTable[flag - 1] = 1;
	}

	table = new int[K];
	fill(table, table + K, 28800);
	counter = new int[K];
	fill(counter, counter + K, 0);

	int minVIPTable;
	int minTable;
	player VIPer;
	player NVIPer;
	bool flagVIP;
	bool flagNVIP;

	while (!VIP.empty() && !NVIP.empty()) {
		VIPer = VIP.top();
		NVIPer = NVIP.top();

		flagVIP = inQueue(K, VIPer.arrTime);
		flagNVIP = inQueue(K, NVIPer.arrTime);

		if (flagNVIP && flagVIP) {
			minVIPTable = findVIPMin(K);
			minTable = findMin(K);
			if (table[minTable] == table[minVIPTable]) {
				VIPer.serTime = table[minVIPTable];
				VIPer.waitTime = (int)round((VIPer.serTime - VIPer.arrTime) / 60.0);
				table[minVIPTable] = VIPer.serTime + VIPer.playTime;
				res.push_back(VIPer);
				VIP.pop();
				if (VIPer.serTime < 75600) {
					counter[minVIPTable]++;
				}
			}
			else if (VIPer.arrTime <= NVIPer.arrTime) {
				VIPer.serTime = table[minTable];
				VIPer.waitTime = (int)round((VIPer.serTime - VIPer.arrTime) / 60.0);
				table[minTable] = VIPer.serTime + VIPer.playTime;
				res.push_back(VIPer);
				VIP.pop();
				if (VIPer.serTime < 75600) {
					counter[minTable]++;
				}
			}
			else {
				NVIPer.serTime = table[minTable];
				NVIPer.waitTime = (int)round((NVIPer.serTime - NVIPer.arrTime) / 60.0);
				table[minTable] = NVIPer.serTime + NVIPer.playTime;
				res.push_back(NVIPer);
				NVIP.pop();
				if (NVIPer.serTime < 75600) {
					counter[minTable]++;
				}
			}
		}
		else if (flagVIP && !flagNVIP) {
			minVIPTable = findVIPMin(K);
			minTable = findMin(K);
			if (table[minTable] == table[minVIPTable]) {
				VIPer.serTime = table[minVIPTable];
				VIPer.waitTime = (int)round((VIPer.serTime - VIPer.arrTime) / 60.0);
				table[minVIPTable] = VIPer.serTime + VIPer.playTime;
				res.push_back(VIPer);
				VIP.pop();
				if (VIPer.serTime < 75600) {
					counter[minVIPTable]++;
				}
			}
			else {
				VIPer.serTime = table[minTable];
				VIPer.waitTime = (int)round((VIPer.serTime - VIPer.arrTime) / 60.0);
				table[minTable] = VIPer.serTime + VIPer.playTime;
				res.push_back(VIPer);
				VIP.pop();
				if (VIPer.serTime < 75600) {
					counter[minTable]++;
				}
			}
		}
		else if (flagNVIP && !flagVIP) {
			minTable = findMin(K);
			NVIPer.serTime = table[minTable];
			NVIPer.waitTime = (int)round((NVIPer.serTime - NVIPer.arrTime) / 60.0);
			table[minTable] = NVIPer.serTime + NVIPer.playTime;
			res.push_back(NVIPer);
			NVIP.pop();
			if (NVIPer.serTime < 75600) {
				counter[minTable]++;
			}
		}
		else {
			if (VIPer.arrTime <= NVIPer.arrTime) {
				minVIPTable = findVIPMinNQ(K, VIPer.arrTime);
				minTable = (minVIPTable == -1) ? findMinNQ(K, VIPer.arrTime) : minVIPTable;
				VIPer.serTime = VIPer.arrTime;
				VIPer.waitTime = 0;
				table[minTable] = VIPer.serTime + VIPer.playTime;
				res.push_back(VIPer);
				VIP.pop();
				if (VIPer.serTime < 75600) {
					counter[minTable]++;
				}
			}
			else {
				minTable = findMinNQ(K, NVIPer.arrTime);
				NVIPer.serTime = NVIPer.arrTime;
				NVIPer.waitTime = 0;
				table[minTable] = NVIPer.serTime + NVIPer.playTime;
				res.push_back(NVIPer);
				NVIP.pop();
				if (NVIPer.serTime < 75600) {
					counter[minTable]++;
				}
			}
		}
	}

	while (!VIP.empty()) {
		VIPer = VIP.top();

		flagVIP = inQueue(K, VIPer.arrTime);

		if (flagVIP) {
			minVIPTable = findVIPMin(K);
			minTable = findMin(K);
			if (table[minVIPTable] == table[minTable]) {
				VIPer.serTime = table[minVIPTable];
				VIPer.waitTime = (int)round((VIPer.serTime - VIPer.arrTime) / 60.0);
				table[minVIPTable] = VIPer.serTime + VIPer.playTime;
				res.push_back(VIPer);
				if (VIPer.serTime < 75600) {
					counter[minVIPTable]++;
				}
			}
			else {
				VIPer.serTime = table[minTable];
				VIPer.waitTime = (int)round((VIPer.serTime - VIPer.arrTime) / 60.0);
				table[minTable] = VIPer.serTime + VIPer.playTime;
				res.push_back(VIPer);
				if (VIPer.serTime < 75600) {
					counter[minTable]++;
				}
			}
		}
		else {
			minVIPTable = findVIPMinNQ(K, VIPer.arrTime);
			minTable = (minVIPTable == -1) ? findMinNQ(K, VIPer.arrTime) : minVIPTable;
			VIPer.serTime = VIPer.arrTime;
			VIPer.waitTime = 0;
			table[minTable] = VIPer.serTime + VIPer.playTime;
			res.push_back(VIPer);
			if (VIPer.serTime < 75600) {
				counter[minTable]++;
			}
		}

		VIP.pop();
	}

	while (!NVIP.empty()) {
		NVIPer = NVIP.top();
		flagNVIP = inQueue(K, NVIPer.arrTime);
		if (flagNVIP) {
			minTable = findMin(K);
			NVIPer.serTime = table[minTable];
			NVIPer.waitTime = (int)round((NVIPer.serTime - NVIPer.arrTime) / 60.0);
			table[minTable] = NVIPer.serTime + NVIPer.playTime;
			res.push_back(NVIPer);
			if (NVIPer.serTime < 75600) {
				counter[minTable]++;
			}
		}
		else {
			minTable = findMinNQ(K, NVIPer.arrTime);
			NVIPer.serTime = NVIPer.arrTime;
			NVIPer.waitTime = 0;
			table[minTable] = NVIPer.serTime + NVIPer.playTime;
			res.push_back(NVIPer);
			if (NVIPer.serTime < 75600) {
				counter[minTable]++;
			}
		}
		NVIP.pop();
	}

	for (auto it = res.begin(); it != res.end(); ++it) {
		if (it->serTime < 75600) {
			printHMS(it->arrTime);
			printf(" ");
			printHMS(it->serTime);
			printf(" %d\n", it->waitTime);
		}
	}

	for (int i = 0; i < K - 1; i++) {
		printf("%d ", counter[i]);
	}
	printf("%d\n", counter[K - 1]);

	return 0;
}
