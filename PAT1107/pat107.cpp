#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int N;
int father[1001];
int hashTable[1001] = { 0 };
int hobby[1001] = { 0 };

int findFather(int key) {
	if (father[key] == key) {
		return key;
	}
	else {
		father[key] = findFather(father[key]);
		return father[key];
	}
}

void unionSet(int key1, int key2) {
	int a = findFather(key1);
	int b = findFather(key2);
	if (a != b) {
		father[b] = a;
	}
}

int main() {

	scanf_s("%d", &N);

	//initialization father array
	for (int i = 0; i < 1001; i++) {
		father[i] = i;
	}

	int K;
	int hob;
	for (int i = 1; i <= N; i++) {
		scanf_s("%d: ", &K);
		while (K--) {
			scanf_s("%d", &hob);
			if (hobby[hob] != 0) {
				unionSet(hobby[hob], i);
			}
			hobby[hob] = i;
		}
	}

	//统一计算所有节点的集合标识
	for (int i = 1; i <= N; i++) {
		findFather(i);
	}

	//count set fathers with hashTable
	for (int i = 1; i <= N; i++) {
		hashTable[father[i]]++;
	}
	//linear scanning hashTable to find valid sets
	int index = 0;
	for (int i = 1; i <= N; i++) {
		if (hashTable[i] != 0) {
			hashTable[index] = hashTable[i];
			index++;
		}
	}
	sort(hashTable, hashTable + index, greater<int>());

	//print out
	printf("%d\n%d", index, hashTable[0]);
	for (int i = 1; i < index; i++) {
		printf(" %d", hashTable[i]);
	}
	printf("\n");

	system("pause");
	return 0;
}
