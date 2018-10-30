#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <map>

using namespace std;

struct node {
	int addr;
	int key;
	node(int add, int k) : addr(add), key(k) {};
	node() : addr(0), key(0) {};
};

map<int, int> addrID;
node* List;

int main() {

	int N, K;
	int root;

	scanf_s("%d %d %d", &root, &N, &K);

	List = new node[N];
	node* nodes = new node[N];

	int key;
	int next;
	int addr;
	for (int i = 0; i < N; i++) {
		scanf_s("%d %d %d", &addr, &key, &next);
		nodes[i].addr = addr;
		nodes[i].key = key;
		addrID[addr] = i;
	}

	//construct List;

	system("pause");
	return 0;
}