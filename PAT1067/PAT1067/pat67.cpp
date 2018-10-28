#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

int main() {

	int N;
	map<int, int> sequence;
	set<int> unOrder;

	scanf_s("%d", &N);
	int num;
	for (int i = 0; i < N; i++) {
		scanf_s("%d", &num);
		sequence.insert(pair<int,int>(num, i));
		if (i != num) {
			unOrder.insert(num);
		}
	}

	set<int>::iterator setIter;
	map<int, int>::iterator mapIter;
	int tmp;
	int count = 0;
	int index = sequence.find(0)->second;
	while (!unOrder.empty()) {
		if (index != 0) {
			unOrder.erase(index);
			index = sequence.find(index)->second;
			count++;
		}
		else {
			setIter = unOrder.find(index);
			if (setIter != unOrder.end()) {
				unOrder.erase(setIter);
			}
			if (unOrder.empty()) {
				break;
			}
			else {
				index = *unOrder.begin();
				mapIter = sequence.find(index);
				tmp = mapIter->second;
				sequence.erase(mapIter);
				sequence.insert(pair<int, int>(index, 0));
				index = tmp;
				count++;
			}
		}
	}

	printf("%d\n", count);

	system("pause");
	return 0;
}