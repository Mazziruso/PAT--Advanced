#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

typedef struct nodee {
	int key;
	int addr;
	int next;
} node;

map<int, int> addrID;

bool cmp(node n1, node n2) {
	return n1.key < n2.key;
}

int main() {

	int N, root;
	scanf_s("%d %d", &N, &root);
	
	node *List = new node[N];
	for (int i = 0; i < N; i++) {
		scanf_s("%d %d %d", &List[i].addr, &List[i].key, &List[i].next);
		addrID.insert(pair<int, int>(List[i].addr, i));
	}

	map<int, int>::iterator iter;
	vector<node> LinkList;
	while (root != -1) {
		iter=addrID.find(root);
		if (iter == addrID.end()) {
			break;
		}
		LinkList.push_back(List[iter->second]);
		root = List[iter->second].next;
	}

	sort(LinkList.begin(), LinkList.end(), cmp);

	int size = LinkList.size();

	if (size == 0) {
		printf("0 -1\n");
		return 0;
	}

	if (size == 1) {
		printf("%d %05d\n", size, LinkList[0].addr);
		printf("%05d %d -1\n", LinkList[0].addr, LinkList[0].key);
		return 0;
	}

	LinkList[size - 1].next = -1;
	for (int i = size - 2; i >= 0; i--) {
		LinkList[i].next = LinkList[i + 1].addr;
	}

	printf("%d %05d\n", size, LinkList[0].addr);
	for (int i = 0; i < size - 1; i++) {
		printf("%05d %d %05d\n", LinkList[i].addr, LinkList[i].key, LinkList[i].next);
	}
	printf("%05d %d -1\n", LinkList[size - 1].addr, LinkList[size - 1].key);

	system("pause");
	return 0;
}