//考虑最后单身的客户为0的情况
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

int main() {

	int N, M;
	map<int, int> couples;
	set<int> singleG; //客人中单身的人
	set<int> coupleG; //客人中有伴侣但是只身前来的人
	int res[10001] = { 0 };

	scanf_s("%d", &N);
	int id1, id2;
	while (N--) {
		scanf_s("%d %d", &id1, &id2);
		couples.insert(pair<int, int>(id1, id2));
		couples.insert(pair<int, int>(id2, id1));
	}

	scanf_s("%d", &M);
	map<int, int>::iterator iter;
	set<int>::iterator iterSet;
	while (M--) {
		scanf_s("%d", &id1);
		iter = couples.find(id1);
		if (iter != couples.end()) {
			iterSet = coupleG.find(iter->second);
			if (iterSet != coupleG.end()) {
				coupleG.erase(iterSet);
			}
			else {
				coupleG.insert(id1);
			}
		}
		else {
			singleG.insert(id1);
		}
	}

	int len = 0;
	for (iterSet = coupleG.begin(); iterSet != coupleG.end(); ++iterSet) {
		res[len++] = *iterSet;
	}
	for (iterSet = singleG.begin(); iterSet != singleG.end(); ++iterSet) {
		res[len++] = *iterSet;
	}

	sort(res, res + len, less<int>());
	
	if (len == 0) {
		printf("0\n");
		return 0;
	}

	printf("%d\n%05d", len, res[0]);
	for (int i = 1; i < len; i++) {
		printf(" %05d", res[i]);
	}
	printf("\n");

	system("pause");
	return 0;
}