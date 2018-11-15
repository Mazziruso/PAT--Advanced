/*
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct friends {
	int id1;
	int id2;
	bool operator<(const struct friends &f1) {
		if (this->id1 == f1.id1) {
			return this->id2 < f1.id2;
		}
		else {
			return this->id1 < f1.id1;
		}
	}
} fri;

int m = 179407; //minimum prime greater than the size
int hashTable[180000];
vector<int> graph[20001];
int winman[300];
fri res[90000];

void hashInsert(int key) {
	int gk = (key + 1) % (m - 2);
	int hk = key % m;
	while (hashTable[hk] >= 0 && hashTable[hk] != key) {
		hk = (hk + gk) % m;
	}
	hashTable[hk] = key;
}

bool hashCount(int key) {
	int gk = (key + 1) % (m - 2);
	int hk = key % m;
	while (hashTable[hk] >= 0 && hashTable[hk] != key) {
		hk = (hk + gk) % m;
	}
	return hashTable[hk] == key;
}

int main() {
	//initialization
	fill_n(hashTable, 90000, -1);

	int N, M, K;
	scanf_s("%d %d", &N, &M);
	char c1[6];
	char c2[6];
	int id1, id2;
	int index = 0;
	for (int i = 0; i < M; i++) {
		scanf_s("%s %s", c1, 6, c2, 6);
		id1 = (c1[0] == '-') ? (atoi(c1) + 9999) : (atoi(c1) + 10000);
		id2 = (c2[0] == '-') ? (atoi(c2) + 9999) : (atoi(c2) + 10000);
		if ((id1 >= 10000 && id2 >= 10000) || (id1 < 10000 && id2 < 10000)) {
			graph[id1].push_back(id2);
			graph[id2].push_back(id1);
		}
		hashInsert(labs(id1) * 100000 + labs(id2));
		hashInsert(labs(id2) * 100000 + labs(id1));
	}

	scanf_s("%d", &K);
	int fid;
	int len;
	for (int i = 0; i < K; i++) {
		scanf_s("%s %s", c1, 6, c2, 6);
		id1 = (c1[0] == '-') ? (atoi(c1) + 9999) : (atoi(c1) + 10000);
		id2 = (c2[0] == '-') ? (atoi(c2) + 9999) : (atoi(c2) + 10000);
		index = 0;
		len = 0;
		for (int j = 0; j < graph[id1].size(); j++) {
			fid = graph[id1][j];
			if (fid != id2) {
				winman[len++] = fid;
			}
		}
		for (int j = 0; j < graph[id2].size(); j++) {
			fid = graph[id2][j];
			if (fid == id1) {
				continue;
			}
			for (int l = 0; l < len; l++) {
				if (hashCount(winman[l] * 100000 + fid)) {
					res[index].id1 = (winman[l] >= 10000) ? (winman[l] - 10000) : labs(winman[l] - 9999);
					res[index].id2 = (fid >= 10000) ? (fid - 10000) : labs(fid - 9999);
					index++;
				}
			}
		}
		sort(res, res + index);
		printf("%d\n", index);
		for (int j = 0; j < index; j++) {
			printf("%04d %04d\n", res[j].id1, res[j].id2);
		}
	}

	system("pause");
	return 0;
}
*/

//男女用4位数表示的ID，它们绝对值都唯一
//当ID为0000时，表示为男生；当ID为-0000时，表示为女生
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct friends {
	int id1;
	int id2;
	bool operator<(const struct friends &f1) {
		if (this->id1 == f1.id1) {
			return this->id2 < f1.id2;
		}
		else {
			return this->id1 < f1.id1;
		}
	}
} fri;

int m = 89753; //minimum prime greater than the size
int hashTable[90000];
vector<int> graph[10001];
int winman[300];
fri res[90000];

void hashInsert(int key) {
	int gk = (key + 1) % (m - 2);
	int hk = key % m;
	while (hashTable[hk] >= 0 && hashTable[hk] != key) {
		hk = (hk + gk) % m;
	}
	hashTable[hk] = key;
}

bool hashCount(int key) {
	int gk = (key + 1) % (m - 2);
	int hk = key % m;
	while (hashTable[hk] >= 0 && hashTable[hk] != key) {
		hk = (hk + gk) % m;
	}
	return hashTable[hk] == key;
}

int main() {
	//initialization
	fill_n(hashTable, 90000, -1);

	bool flag = false; //false denotes that ID 0 is boy, otherwise for girl
	int N, M, K;
	scanf_s("%d %d", &N, &M);
	char c1[6];
	char c2[6];
	int id1, id2;
	int index = 0;
	for (int i = 0; i < M; i++) {
		scanf_s("%s %s", c1, 6, c2, 6);
		id1 = atoi(c1);
		id2 = atoi(c2);
		if ((id1 == 0 && c1[0] == '-') || (id2 == 0 && c2[0] == '-')) {
			flag = true;
		}
		if (!flag && (id1 >= 0 && id2 >= 0) || (id1 < 0 && id2 < 0)) { //在构造邻接链表时，直接排除点异性ID，因为lovers中的每一方只会找同性好友
			graph[labs(id1)].push_back(labs(id2));
			graph[labs(id2)].push_back(labs(id1));
		}
		else if (flag && (id1 > 0 && id2 > 0) || (id1 <= 0 && id2 <= 0)) {
			graph[labs(id1)].push_back(labs(id2));
			graph[labs(id2)].push_back(labs(id1));
		}
		hashInsert(labs(id1) * 10000 + labs(id2));
		hashInsert(labs(id2) * 10000 + labs(id1));
	}

	scanf_s("%d", &K);
	int fid;
	int len;
	for (int i = 0; i < K; i++) {
		scanf_s("%d %d", &id1, &id2);
		index = 0;
		len = 0;
		id1 = labs(id1);
		id2 = labs(id2);
		for (int j = 0; j < graph[id1].size(); j++) {
			fid = graph[id1][j];
			if (fid != id2) { //防止同性时，两两直接选择而不依靠第三方
				winman[len++] = fid;
			}
		}
		for (int j = 0; j < graph[id2].size(); j++) {
			fid = graph[id2][j];
			if (fid == id1) {
				continue;
			}
			for (int l = 0; l < len; l++) {
				if (hashCount(winman[l] * 10000 + fid)) {
					res[index].id1 = winman[l];
					res[index].id2 = fid;
					index++;
				}
			}
		}
		sort(res, res + index);
		printf("%d\n", index);
		for (int j = 0; j < index; j++) {
			printf("%04d %04d\n", res[j].id1, res[j].id2);
		}
	}

	system("pause");
	return 0;
}
