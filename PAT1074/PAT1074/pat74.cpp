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
};

map<int, int> addrID;
node *List = new node[100010];

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

	node *nodes = new node[100010];

	int key;
	int next;
	int addr;
	for (int i = 0; i < N; i++) {
		scanf_s("%d %d %d", &addr, &key, &next);
		nodes[i].addr = addr;
		nodes[i].key = key;
		nodes[i].next = next;
		addrID[addr] = i;
	}

	//construct List;
	map<int, int>::iterator iter;
	int index = 0;
	addr = root;
	while (addr != -1) {
		iter = addrID.find(addr);
		if (iter == addrID.end()) {
			break;
		}
		List[index] = nodes[iter->second];
		addr = List[index].next;
		if (index%K == K - 1) {
			reverseList(index - K + 1, index);
		}
		index++;
	}

	for (int j = 0; j < index; j++) {
		if (j < index - 1) {
			printf("%05d %d %05d\n", List[j].addr, List[j].key, List[j+1].addr);
		}
		else {
			printf("%05d %d -1\n", List[j].addr, List[j].key);
		}
	}

	system("pause");
	return 0;
}
