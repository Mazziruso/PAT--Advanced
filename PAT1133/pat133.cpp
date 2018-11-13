#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <map>

using namespace std;

int List[100002][2];

int main() {

	int root;
	int N, K;
	scanf_s("%d %d %d", &root, &N, &K);
	
	int addr, key, next;
	for (int i = 0; i < N; i++) {
		scanf_s("%d %d %d", &addr, &key, &next);
		List[addr][0] = key;
		List[addr][1] = next;
	}

	List[100001][1] = root; //the head of list

	//initialization and detect root
	int np = 100001;
	int pp = 100001;
	int node = root;
	int pre = 100001;
	if (List[root][0] < 0) {
		np = root;
		pp = root;
		node = List[root][1];
		pre = root;
	}
	else if (List[root][0] <= K) {
		pp = root;
		node = List[root][1];
		pre = root;
	}
	
	while (node != -1) {
		if (List[node][0] < 0) {
			List[pre][1] = List[node][1];
			List[node][1] = List[np][1];
			List[np][1] = node;
			np = node;
			pp = (List[pp][0] < 0) ? np : pp;
		}
		else if (List[node][0] <= K) {
			List[pre][1] = List[node][1];
			List[node][1] = List[pp][1];
			List[pp][1] = node;
			pp = node;
		}
		if (List[pre][1] == node) {
			pre = node;
		}
		node = List[pre][1];
	}

	//print out
	node = List[100001][1];
	while (node != -1) {
		printf("%05d %d", node, List[node][0]);
		if (List[node][1] == -1) {
			printf(" -1\n");
		}
		else {
			printf(" %05d\n", List[node][1]);
		}
		node = List[node][1];
	}

	system("pause");
	return 0;
}