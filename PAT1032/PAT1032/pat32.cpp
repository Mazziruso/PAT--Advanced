#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<int, int> addrID;

//可能会有多余的冗余结点，会使得统计数据超过两次（多个单词）
int main() {

	int N;
	int addr = -1;
	int rootA;
	int rootB;
	scanf("%d %d %d", &rootA, &rootB, &N);

	int **word = new int*[N];
	bool *flag = new bool[N];
	for (int i = 0; i < N; i++) {
		word[i] = new int[2];
	}
	fill(flag, flag + N, false);

	char letter;
	for (int i = 0; i < N; i++) {
		scanf("%d %c %d", &word[i][0], &letter, &word[i][1]);
		addrID.insert(pair<int, int>(word[i][0], i));
	}

	//Traversal word A
	int index;
	addr = rootA;
	while (addr != -1) {
		index = addrID.find(addr)->second;
		flag[index] = true;
		addr = word[index][1];
	}

	//Traversal word B, find the first common joint point
	addr = rootB;
	while (addr != -1) {
		index = addrID.find(addr)->second;
		if (flag[index]) {
			break;
		}
		addr = word[index][1];
	}

	if (addr == -1) {
		printf("%d\n", addr);
	}
	else {
		printf("%05d\n", addr);
	}

	return 0;
}