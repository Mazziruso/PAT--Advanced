#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <map>

using namespace std;

struct node {
	int addr;
	int key;
	int next;
	node() : addr(-1), key(0), next(-1) {};
};

node *List;

inline void swap(int i, int j) {
	node tmp = List[i];
	List[i] = List[j];
	List[j] = tmp;
}

void reverseList(int i, int j) {
	int l = i;
	int r = j;
	while (l < r) {
		swap(l, r);
		l++;
		r--;
	}
}

int main() {

	int N, K;
	int root;

	scanf_s("%d %d %d", &root, &N, &K);

	node *nodes = new node[1000010]; //linear hash table stores nodes;
	List = new node[N];

	int key;
	int next;
	int addr;
	for (int i = 0; i < N; i++) {
		scanf_s("%d %d %d", &addr, &key, &next);
		nodes[addr].addr = addr;
		nodes[addr].key = key;
		nodes[addr].next = next;
	}

	//construct List;
	int index = 0;
	addr = root;
	while (addr != -1) {
		if (nodes[addr].addr == -1) {
			break;
		}
		List[index] = nodes[addr];
		addr = List[index].next;
		if (index%K == K - 1) {
			reverseList(index - K + 1, index);
		}
		index++;
	}

	for (int j = 0; j < index; j++) {
		if (j < index - 1) {
			printf("%05d %d %05d\n", List[j].addr, List[j].key, List[j + 1].addr);
		}
		else {
			printf("%05d %d -1\n", List[j].addr, List[j].key);
		}
	}

	system("pause");
	return 0;
}