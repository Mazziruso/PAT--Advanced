#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <vector>

using namespace std;

map<int, int> addrID;

typedef struct nod {
	int addr;
	int val;
	int next;
} node;

node *nodes;
set<int> SingalVal;

vector<node> noDupNodes;
vector<node> dupNodes;

int main() {

	int N;
	int root;

	scanf_s("%d %d", &root, &N);

	if (N == 0) {
		return 0;
	}

	nodes = new node[N];
	int addr;
	int val;
	int next;
	for (int i = 0; i < N; i++) {
		scanf_s("%d %d %d", &addr, &val, &next);
		nodes[i].addr = addr;
		nodes[i].val = val;
		nodes[i].next = next;
		addrID.insert(make_pair(addr, i));
	}

	//special case N=1
	if (N == 1) {
		printf("%05d %d %d", addr, val, next);
		return 0;
	}

	//state and initial three pointer,
	//representing current node, previous node, previous duplicate node respectively
	node *nv_pre = (node *)malloc(sizeof(node));
	nv_pre->addr = 111111;
	node *v_pre = nodes + addrID.find(root)->second;
	SingalVal.insert(abs(v_pre->val));
	node *v = nodes + addrID.find(v_pre->next)->second;
	//loop along sing list
	while (v->next != -1) {
		if (SingalVal.find(abs(v->val)) == SingalVal.end()) {
			SingalVal.insert(abs(v->val));
			noDupNodes.push_back(*v_pre);
			v_pre = v;
		}
		else {
			if (nv_pre->addr != 111111) {
				nv_pre->next = v->addr;
				dupNodes.push_back(*nv_pre);
			}
			nv_pre = v;
			v_pre->next = v->next;
		}
		v = nodes + addrID.find(v->next)->second;
	}
	//finish loop
	if (SingalVal.find(abs(v->val)) == SingalVal.end()) {
		noDupNodes.push_back(*v_pre);
		noDupNodes.push_back(*v);
		nv_pre->next = -1;
		//if there is no duplicate node
		if (nv_pre->addr != 111111) {
			dupNodes.push_back(*nv_pre);
		}
	}
	else {
		//if there is no duplicate node before current node
		if (nv_pre->addr != 111111) {
			nv_pre->next = v->addr;
			dupNodes.push_back(*nv_pre);
		}
		dupNodes.push_back(*v);
		v_pre->next = -1;
		noDupNodes.push_back(*v_pre);
	}

	vector<node>::iterator it;
	for (it = noDupNodes.begin(); it != noDupNodes.end(); ++it) {
		if (it->next != -1) {
			printf("%05d %d %05d\n", it->addr, it->val, it->next);
		}
		else {
			printf("%05d %d %d\n", it->addr, it->val, it->next);
		}
	}
	for (it = dupNodes.begin(); it != dupNodes.end(); ++it) {
		if (it->next != -1) {
			printf("%05d %d %05d\n", it->addr, it->val, it->next);
		}
		else {
			printf("%05d %d %d\n", it->addr, it->val, it->next);
		}
	}

	system("pause");
	return 0;
}